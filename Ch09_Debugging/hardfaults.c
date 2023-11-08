/*
 * hardfaults.c
 *
 * This file shows some hard fault errors.
 *
 * These are straightforward, with obvious errors. However, most hard faults
 * are not so obvious.
 *
 * Some of these examples are based on the ones from
 * https://mcuoneclipse.com/2012/11/24/debugging-hard-faults-on-arm-cortex-m/
 * Which also talks about how to debug hard faults on Cortex-M processors
 * though it is not an STM processor
 *
 * Another good source for how to debug hard faults is
 * https://www.nathantsoi.com/blog/stm32-hardfault-debugging/index.html
 * which is on an STM processor
 *
 * The best source for understanding and debugging hard faults is
 * https://interrupt.memfault.com/blog/cortex-m-fault-debug
 * It requires a GDB command line but that is available in Debugger Console.
 *
 * Arm has the true documentation... it isn't bad
 * https://developer.arm.com/documentation/dui0552/a/cortex-m3-peripherals/system-control-block/configurable-fault-status-register
 *
 */

#include <stdint.h>
#include "stm32l4xx.h"

#include "hardfaults.h"


int divide_by_zero(void)
{
	int a = 1;
	int c = 0;
	int b = a/c;
	return b; // forces compiler to actually run this
}

 // uninitalized global ends up initialized to 0
int* global_ptr_to_null = NULL;
int* global_ptr_unitialized;
void write_to_null(void) {
  int* ptr_to_null = NULL;
  int* ptr_unitialized;

  *global_ptr_to_null  = 10;    /* tries to write to address zero */
  *global_ptr_unitialized = 10; /* tries to write to address zero */
  *ptr_to_null  = 10;           /* tries to write to address zero */
  *ptr_unitialized = 10;    		/* tries to write ?? somewhere ?? */

  return *global_ptr_to_null + *global_ptr_unitialized + *ptr_to_null + *ptr_unitialized;
}

// Assuming 0xE0000000 is a bad instruction
int illegal_instruction_execution(void) {
  int instruction = 0xE0000000;
  int (*bad_instruction)(void) = (int(*)())(&instruction);
  return bad_instruction();
}

// simliar to the one below where an address is executed along with whatever is at that address
int illegal_address_execution(void) {
  int (*illegal_address)(void) = (int(*)())0xE0000000;
  return illegal_address();
}

void (*fun_ptr)(void);	// global defaults to zero
void call_null_pointer_function(void)
{
  fun_ptr(); /* will execute code at address zero, often the reset code */
}


int* dont_return_stack_memory(void) {
	int stack_memory[100];
	return stack_memory;
}

int* dont_return_malloc_and_freed_memory(void) {
	int memory = malloc(100);
	free(memory);
	return memory;
}

int this_is_ok(void) {
	int a = 0;
	int b = a+1;
	return b;
}

// this isn't failing, how to get it to fail?
int* ptr_to_null;     // uninitalized global ends up initialized to 0
void write_to_rom(void) {
  *ptr_to_null = 10; /* tries to write to address zero */
}


/******************************************************************************************************
* On an STM32 Cortex-M4 smallVariable is 0xdd but this depends on your
* processor and endianness.
*******************************************************************************************************/
uint8_t unaligned_access_ok(void)
{
	uint32_t bigVariable = 0xAABBCCDD;
	uint32_t  *ptr = &bigVariable;
	uint8_t  smallVariable = *ptr;
	return smallVariable;
}


/******************************************************************************************************
 * Unaligned access is automatically a hardfault on CM0s.
 *
 * This M4 will let us run this code just fine... but if we want a
 * hardfault to avoid this slow-down, then we'll need to set
 * CCR.UNALIGN_TRP or use the compile time flag -mno-unaligned-access
 *
 * On an STM32 Cortex-M4 val_BB_to_EE is 0xeeddccbb but this depends on your
 * processor and endianness.
*******************************************************************************************************/
uint32_t unaligned_access_bad(int index)
{
	uint8_t buffer[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
	uint8_t i = index;
    uint32_t val_BB_to_EE = *((uint32_t *)( &buffer[i] ));
    return val_BB_to_EE;
}

// For ARM GCC
// -munaligned-access is the default and should reach into the buffer and
// pull out the unalighned variable in a couple assembly comamnds
// However, -mno-unaligned-access should lead to longer code with more instructions
// to avoid the unaligned memory access


void do_some_hardfaults(void)
{
//	divide_by_zero(); 			  // look at registers
//  write_to_null();					// null and uninitialized

/* UNALIGNED ACCESS * /
	unaligned_access_bad(1);
	unaligned_access_ok();
	SCB->CCR |= (1<<3);			  	// turn on the hard fault that disallows unaligned access
	unaligned_access_ok();			// works
	unaligned_access_bad(0);		// works
	unaligned_access_bad(1);		// hardfault
/**/

	illegal_instruction_execution2(); // look at memfault blog
//  call_null_pointer_function(); // look at building a handler

//	write_to_rom();				//
//	SCB->CCR |= (1<<8);
//	write_to_rom();

}


/******************************************************************************************************
 * Below here is some code to help you understand the hard fault given the processor's registers
 * In class, I'll be using this code to debug my hard faults above
*******************************************************************************************************/

// Initially, the error goes to a blank void HardFault_Handler(void) in stm32f4xx_it.c
// This connection is set in the Startup/startup_stm32f429zitx.s
// Being in that function, we can see the call stack and track the error down in our code
// In the SFRs registers, we can look at Cortex_M4 -> Control -> CFSR
// and Control -> CCR Control SHCSR

// But that function doesn't do much so let's add some useful stuff to it


// From https://www.freertos.org/Debugging-Hard-Faults-On-Cortex-M-Microcontrollers.html
#ifdef NEW_HANLDER_1
void HardFault_Handler(void)
{
	__asm volatile
	(
		" movs r0,#4    \n"
		" movs r1, lr   \n"
		" tst r0, r1    \n"
		" beq _MSP		\n"
		" mrs r0, psp	\n"
		" b _HALT		\n"
		"_MSP:			\n"
		" mrs r0, msp	\n"
		"_HALT:			\n"
		" ldr r1,[r0,#20] \n"
		"  b hard_fault_handler_c \n"
		"  bkpt #0 \n"
	  );
}
void hard_fault_handler_c(unsigned long *hardfault_args){
  volatile unsigned long stacked_r0 ;
  volatile unsigned long stacked_r1 ;
  volatile unsigned long stacked_r2 ;
  volatile unsigned long stacked_r3 ;
  volatile unsigned long stacked_r12 ;
  volatile unsigned long stacked_lr ;
  volatile unsigned long stacked_pc ;
  volatile unsigned long stacked_psr ;
  volatile unsigned long _CFSR ;
  volatile unsigned long _HFSR ;
  volatile unsigned long _DFSR ;
  volatile unsigned long _AFSR ;
  volatile unsigned long _BFAR ;
  volatile unsigned long _MMAR ;

  stacked_r0 = ((unsigned long)hardfault_args[0]) ;
  stacked_r1 = ((unsigned long)hardfault_args[1]) ;
  stacked_r2 = ((unsigned long)hardfault_args[2]) ;
  stacked_r3 = ((unsigned long)hardfault_args[3]) ;
  stacked_r12 = ((unsigned long)hardfault_args[4]) ;
  stacked_lr = ((unsigned long)hardfault_args[5]) ;
  stacked_pc = ((unsigned long)hardfault_args[6]) ;
  stacked_psr = ((unsigned long)hardfault_args[7]) ;

  // Configurable Fault Status Register
  // Consists of MMSR, BFSR and UFSR
  _CFSR = (*((volatile unsigned long *)(0xE000ED28))) ;

  // Hard Fault Status Register
  _HFSR = (*((volatile unsigned long *)(0xE000ED2C))) ;

  // Debug Fault Status Register
  _DFSR = (*((volatile unsigned long *)(0xE000ED30))) ;

  // Auxiliary Fault Status Register
  _AFSR = (*((volatile unsigned long *)(0xE000ED3C))) ;

  // Read the Fault Address Registers. These may not contain valid values.
  // Check BFARVALID/MMARVALID to see if they are valid values
  // MemManage Fault Address Register
  _MMAR = (*((volatile unsigned long *)(0xE000ED34))) ;
  // Bus Fault Address Register
  _BFAR = (*((volatile unsigned long *)(0xE000ED38))) ;

  __asm("BKPT #0\n") ; // Break into the debugger
}
#endif // NEW_HANDLER2


#if NEW_HANDLER_MEMFAULT

// NOTE: If you are using CMSIS, the registers can also be
// accessed through CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk
#define HALT_IF_DEBUGGING()                              \
  do {                                                   \
    if ((*(volatile uint32_t *)0xE000EDF0) & (1 << 0)) { \
      __asm("bkpt 1");                                   \
    }                                                    \
} while (0)

typedef struct __attribute__((packed)) ContextStateFrame {
  uint32_t r0;
  uint32_t r1;
  uint32_t r2;
  uint32_t r3;
  uint32_t r12;
  uint32_t lr;
  uint32_t return_address;
  uint32_t xpsr;
} sContextStateFrame;

#define HARDFAULT_HANDLING_ASM(_x)               \
  __asm volatile(                                \
      "tst lr, #4 \n"                            \
      "ite eq \n"                                \
      "mrseq r0, msp \n"                         \
      "mrsne r0, psp \n"                         \
      "b my_fault_handler_c \n"                  \

)

// Disable optimizations for this function so "frame" argument
// does not get optimized away
__attribute__((optimize("O0")))
void my_fault_handler_c(sContextStateFrame *frame) {
  // If and only if a debugger is attached, execute a breakpoint
  // instruction so we can take a look at what triggered the fault
  HALT_IF_DEBUGGING();

  // Logic for dealing with the exception. Typically:
  //  - log the fault which occurred for postmortem analysis
  //  - If the fault is recoverable,
  //    - clear errors and return back to Thread Mode
  //  - else
  //    - reboot system
}

#endif // NEW_HANDLER_MEMFAULT
