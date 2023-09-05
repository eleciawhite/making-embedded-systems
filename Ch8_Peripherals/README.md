# Chapter 8: Putting Together a System
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 


# Following Along in the Book
## Matrices and Charlieplexing:
 * [Charlieplexing on Wikpedia](https://en.wikipedia.org/wiki/Charlieplexing) with Atmel demo code
 * A website about [Charlieplexing](http://pcbheaven.com/wikipages/Charlieplexing/) uses excellent animations to walk through how it works. (They also walk through [the row/column method](http://pcbheaven.com/wikipages/How_Key_Matrices_Works/) with good animations.)
 *  Driving Matrix LEDs: [Code](https://github.dev/Thakaa/HUB75E-Driver/), [explanation video](https://github.dev/Thakaa/HUB75E-Driver/). You may need a DWT instead of a TIM, see [this blog post](https://github.dev/Thakaa/HUB75E-Driver/).

## Displays
[ST Microelectronics AN1447 Application Note for a Software Driver for 4-Multiplexed LCD with a standard ST62 controller](ATAN1447_software-driver-for-4-multiplexed-lcd-with-a-standard-st62-stmicroelectronics.pdf) retrieved from [ST](http://www.st.com/stonline/books/pdf/docs/8187.pdf).

 Working out all the pieces to make a display work is tough. Adafruit is an excellent resource for this. Their [Adafruit GFX documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library?view=all) explains how to draw on the screen, display bitmaps, using bitmapped fonts that are compiled into the code, and adding new fonts. The library is targeted toward Arduino but the library is in C, well organized and encapsulated, and the license is permissive. See also the [Adafruit GFX Library code on github](https://github.com/adafruit/Adafruit-GFX-Library). See also [how to create new fonts (and symbol libraries)](https://learn.adafruit.com/creating-custom-symbol-font-for-adafruit-gfx-library?view=all)

(LVGL: Light and Versatile Embedded Graphics Library)[https://github.com/lvgl] is another graphics library for embedded systems.

Some advice on [Displaying text on embedded devices)[https://allthingsembedded.com/2018/09/02/displaying-text-on-embedded-devices/] - a blog post, gives a good overview of the fonts on embedded displays. This came up because of a question about anti-aliasing in fonts which makes them look nicer. It is a technique available when you have more than two colors to make the curves on the letters look smooth.

This [Aliasing and Moire patterns post](https://matthews.sites.wfu.edu/misc/DigPhotog/alias/index.html) describes aliasing and how it looks in images.

LCD Font and image generation:
 * [Adafruit font packing](https://github.com/adafruit/Adafruit-GFX-Library/blob/master/fontconvert/fontconvert.c)
 * Use python: [fonttools](https://fonttools.readthedocs.io/en/latest/)
 * [Dot factory](http://www.eran.io/the-dot-factory-an-lcd-font-and-image-generator/) turns images into code
 * [Segger EmWin’s Font Converter](https://www.segger.com/products/user-interface/emwin/tools/tools-overview/) is very expensive but there is a [knockoff](http://www.pixfonter.net/font-converter/for-segger-emwin.html)
* Some I haven't tried but seem interesting
  * [Font Builder](https://github.com/andryblack/fontbuilder) is Qt based and has open source code that shows what you need to do


Getting fonts:
 * [Adobe Fonts](https://fonts.adobe.com/) includes the Open Hans Sans
 * [Google Fonts](https://fonts.google.com/)
 * [Free Fonts & Popular Downloads for Word | FontSpace](https://www.fontspace.com/popular/fonts)
 * [fntlistall · olikraus/u8g2 Wiki · GitHub](https://github.com/olikraus/u8g2/wiki/fntlistall)
Watch the licenses though! Fonts are like code, you can't use it unless it says really really free.


## Flash Memory
* [ST AN4894 EEPROM emulation techniques and software for STM32 microcontrollers](STAN4894-eeprom-emulation-techniques-and-software-for-stm32-microcontrollers-stmicroelectronics.pdf) from [ST](https://www.st.com/resource/en/application_note/an4894-eeprom-emulation-techniques-and-software-for-stm32-microcontrollers-stmicroelectronics.pdf)
and associated [code](https://www.st.com/en/embedded-software/x-cube-eeprom.html)
* An good description of [how a KVStore should work from the users perspective](https://os.mbed.com/docs/mbed-os/v6.16/apis/kvstore.html) ( and [some code](https://github.com/ARMmbed/mbed-os-example-kvstore) to go with it)
 * Little file systems: [littlefs](https://github.com/littlefs-project/littlefs) and a [list on Wikipedia](https://en.wikipedia.org/wiki/List_of_file_systems#File_systems_optimized_for_flash_memory.2C_solid_state_media) of other file systems optimized for flash

# Analog Signals
**Aliasing** is a really big thing but easier to understand in terms of simpler signals like audio where it isn’t two dimensional. (Though even [Wikipedia](https://en.wikipedia.org/wiki/Aliasing) presents it as a visual problem.) See chapter 3 of this excellent, free, and online book [The Scientist and Engineer's Guide to Digital Signal Processing By Steven W. Smith, Ph.D.](http://www.dspguide.com/pdfbook.htm)

It is often very handy to output data via serial and be able to see it as though it was on an oscilloscope: [Serial Oscilloscope](https://github.com/xioTechnologies/Serial-Oscilloscope)

# Code For This Chapter
* [Speeds and Feeds Throughput Calculator](Speeds_and_Feeds_Throughput_Calculators.xlsx) Excel sheet


# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
