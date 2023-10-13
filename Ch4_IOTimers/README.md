# Chapter 4: Input, Output, and Timers
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 

# Following Along in the Book
 Some example processor documents, obtained from their vendors:
   * [ATtiny AVR Microcontroller Datasheet](Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf)
   * [TI MSP430x2xx User's Guide](TI_MSP430x2xx_Users_Guide_slau144k.pdf)
   * [STM32F103 Reference Manual](stmicroelectrics-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus.pdf) and [github repository](https://github.com/STMicroelectronics/STM32Cube_MCU_Overall_Offer), specifically [stm32f103x6.h](https://github.com/STMicroelectronics/cmsis_device_f1/blob/master/Include/stm32f103x6.h)

## Timer Calculations
Showing my math for the timer calculation section:
  * [Timer calculations](TimerCalculations.xlsx)
  * [Timer flowchart](TimerFlowchart.md)

See also [STM32 Delay Microsecond Millisecond Utility](https://deepbluembedded.com/stm32-delay-microsecond-millisecond-utility-dwt-delay-timer-delay/): a blog post about different ways to set up timer delays 


## Debouncing
 [A Guide to Debouncing](http://www.ganssle.com/debouncing.htm) by Jack Ganssle. Hackaday has [code for multiple different implementations](https://hackaday.com/2010/11/09/debounce-code-one-post-to-rule-them-all/)

## Hex and Bits
For understanding and practicing hex and bitwise operations:
  * [YouTube: Bit Hacks from Beginner to Advanced](https://www.youtube.com/watch?v=ZRNO-ewsNcQ) is an excellent video
  * [calc.50x.ca](https://calc.50x.ca/) provides a hex calculator showing the binary values
  * [bitwiseCmd](https://bitwisecmd.com/) lets you try out bitwise operations online
  * For more bit twiddling hacks and seeing how you can do optimal things (usually at the cost of readability), check out [Stanford Graphics Bithacks](https://graphics.stanford.edu/~seander/bithacks.html)

# Code For This Chapter
* PWM on Raspberry Pi Pico, [example on Wokwi](https://wokwi.com/projects/327332892021621331)
* More complex PWM on Raspberry Pi Pico [example on Wokwi](https://wokwi.com/projects/327213213504504402)

* FIXME: Button interface with debouncing
* FIXME: Dependency injection example
# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
