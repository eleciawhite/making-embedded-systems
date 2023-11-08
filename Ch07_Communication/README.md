# Chapter 7: Communicating with Peripherals
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 

# Following Along in the Book
 OSI model of communication protocols on [Wikipedia](https://en.wikipedia.org/wiki/OSI_model)
 
 Calculations related to the SPI comparison in the chapter are in [SPI_clock_calculations.xlsx](SPI_clock_calculations.xlsx)

 For an example implementation of FIFO versus DMA, look for [James Lynch’s write-up on Atmel’s AT91SAM7 serial communications](at91sam7_serial_communications.pdf). 
 
 [STM32 DMA Cheat Sheet](https://adammunich.com/stm32-dma-cheat-sheet/) is an excellent blog post with an overview of DMA use and channel mapping in STM32


 Embedded Artistry has an excellent and lengthy [blog post about circular buffers](https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/) that includes a github repository of [working code in C](https://github.com/embeddedartistry/embedded-resources/tree/master/examples/c) and [C++](https://github.com/embeddedartistry/embedded-resources/tree/master/examples/cpp). 

 [How To Write A Driver (STM32, I2C, Datasheet) - Phil's Lab](https://youtu.be/_JQAve05o_0) is a video packed with lots of recommendations for writing a well structured driver. 


# Code For This Chapter
 * Embedded Artistry has an excellent and lengthy [blog post about circular buffers](https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/) that includes a github repository of [working code in C](https://github.com/embeddedartistry/embedded-resources/tree/master/examples/c) and [C++](https://github.com/embeddedartistry/embedded-resources/tree/master/examples/cpp). 


# Tools
Logic Analyzers:
 * [Need A Logic Analyzer? Use Your Pico!](https://hackaday.com/2022/03/02/need-a-logic-analyzer-use-your-pico/) (RPi Pico) 
 * [USB Logic Analyzer - 24MHz/8-Channel - TOL-18627 - SparkFun Electronics](https://hackaday.com/2022/03/02/need-a-logic-analyzer-use-your-pico/) works pretty well, very well given its price, it uses [sigrok](https://sigrok.org/wiki/Main_Page) interface which is versatile. 
 * [An Arduino logic analyzer repository](https://github.com/gillham/logic_analyzer) (interesting code, untested)

[CanUSB](https://www.canusb.com/) is a tool that lets you convert CAN to USB (they also have CAN to UART)



# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
