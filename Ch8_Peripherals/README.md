# Chapter 8: Putting Together a System
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 


# Following Along in the Book
 Matrices and Charlieplexing:
 * [Charlieplexing on Wikpedia](https://en.wikipedia.org/wiki/Charlieplexing) with Atmel demo code
 * A website about [Charlieplexing](http://pcbheaven.com/wikipages/Charlieplexing/) uses excellent animations to walk through how it works. (They also walk through [the row/column method](http://pcbheaven.com/wikipages/How_Key_Matrices_Works/) with good animations.)

Displays
* [ST Microelectronics AN1447 Application Note for a Software Driver for 4-Multiplexed LCD with a standard ST62 controller](ATAN1447_software-driver-for-4-multiplexed-lcd-with-a-standard-st62-stmicroelectronics.pdf) retrieved from [ST](http://www.st.com/stonline/books/pdf/docs/8187.pdf).

 * Working out all the pieces to make a display work is tough. Adafruit is an excellent resource for this. Their [Adafruit GFX documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library?view=all) explains how to draw on the screen, display bitmaps, using bitmapped fonts that are compiled into the code, and adding new fonts. The library is targeted toward Arduino but the library is in C, well organized and encapsulated, and the license is permissive. See also the [Adafruit GFX Library codeon github](https://github.com/adafruit/Adafruit-GFX-Library). See also [how to create new fonts (and symbol libraries)](https://learn.adafruit.com/creating-custom-symbol-font-for-adafruit-gfx-library?view=all)

Flash Memory
* [ST AN4894 EEPROM emulation techniques and software for STM32 microcontrollers](STAN4894-eeprom-emulation-techniques-and-software-for-stm32-microcontrollers-stmicroelectronics.pdf) from [ST](https://www.st.com/resource/en/application_note/an4894-eeprom-emulation-techniques-and-software-for-stm32-microcontrollers-stmicroelectronics.pdf)
and associated[code](https://www.st.com/en/embedded-software/x-cube-eeprom.html)
* An good description of [how a KVStore should work from the users perspective](https://os.mbed.com/docs/mbed-os/v6.16/apis/kvstore.html) (and [some code](https://github.com/ARMmbed/mbed-os-example-kvstore) to go with it)
 * Little file systems: [littlefs](https://github.com/littlefs-project/littlefs) and a [list on Wikipedia](https://en.wikipedia.org/wiki/List_of_file_systems#File_systems_optimized_for_flash_memory.2C_solid_state_media) of other file systems optimized for flash

# Code For This Chapter
* [Speeds and Feeds Throughput Calculator](Speeds_and_Feeds_Throughput_Calculators.xlsx) Excel sheet


# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
