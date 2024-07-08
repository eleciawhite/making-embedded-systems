# Chapter 3: Getting Your Hands on Hardware
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 


# Following Along in the Book
In order of when they appear in the book:
 * Example Schematic FIXME
 * Slides that show the progression from [Arduino Block Diagram to Schematic to Board](ArduinoBlockDiagramToSchematics.pdf) 
 * [Ardunio Schematic](UNO-TH_Rev3e_sch.pdf) on its own was obtained from [Arduino](https://content.arduino.cc/assets/UNO-TH_Rev3e_sch.pdf)
 * [ATmega328 Datasheet](ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061B.pdf) (obtained from [Microchip](https://www.microchip.com/en-us/product/ATmega328#document-table))
  * Command and Response Example (FIXME folder) and on [Wokwi with the Raspberry Pi Pico C SDK](https://wokwi.com/projects/324879108372693587). Of course, there are ways to go well beyond this simple command interpreter including [MicroPython](https://micropython.org/) and the command line already part of the [Zephry RTOS](https://docs.zephyrproject.org/latest/services/shell/index.html).

# Digging Deeper into Electronics
EE Basics:
 * Make: Electronics by Charles Platt is a good getting-started-with electronics book. 
 * Forest Mims books are classic, they tend to have a solution for any given problem
 * [Free textbook for Electrical Engineering & Electronics](https://www.allaboutcircuits.com/textbook/)
 * [Combinational Logic Circuits using Logic Gates](https://www.electronics-tutorials.ws/combination/comb_1.html)
* For learning to make boards, try out Getting to Blinky by [Contextual Electronics](https://contextualelectronics.com/), a good place for how-to electronics education
* [ConnectorBook.com](https://connectorbook.com/) has a wealth of information about what kinds of connectors are out there. I particularly like [the connector identification tool](https://connectorbook.com/identification.html?m=NN) that lets you mouse over types of connectors to get pictures, then click down until you find the one you are looking for.
* Handy python tool for making cables diagrams [WireViz](https://github.com/wireviz/WireViz)

 # Fun and  Games
  * [nand2tetris](https://www.nand2tetris.org/) is a series of lectures and projects about how to go from logic gates to software ( there is a book that is part of this as well: The Elements of Computing Systems: Building a Modern Computer from First Principles )
  * [Human Resource Machine]((https://tomorrowcorporation.com/humanresourcemachine)) by Tomorrow Corporation is about optimizing resources, it turns out to be a lot like assembly programming.
  * [Turing Complete](https://store.steampowered.com/app/1444480/Turing_Complete/) shows how logic and logic gates work, building up a processor. 
  * Zachtronics’ [TIS-100]((https://www.zachtronics.com/tis-100/)) is another logic and processor design game. It is a little ugly in spots (too real world) but it is a really deep dive into learning assembly. It is the precursor to Shenzhen IO but  harder to finish.
  * Zachtronics’ [Shenzhen IO](https://www.zachtronics.com/shenzhen-io/) is about circuits and how they work .

The book doesn't cover logic gates or assembly so this is all about the amusement. These games are all good for building intuition about the lowest layers of what the computer is doing. I mean, if they aren't fun, don't continue, they aren't lessons. But if they are fun and you progress through the levels, you'll learn more about the lower levels of processors and how they work which will look familiar if you work with them. 

## MicroMadness Tournament
If you want to get a broad overview of a bunch of different boards, look at the [MicroMadness Spreadsheet](MicroMadnessTournament.xlsx). Find 32 (or 16) friends/classmates. Randomly assign dev boards. Go off and look up some basic information about the dev board. Then have the boards compete based on the arbitrary (and randomly chosen) criteria. When a board loses a round, the "owner" becomes part of the winning team to help look up data. 

The winner (and their newly formed team) gets bragging rights. 

# Code For This Chapter
  * Command and Response Example (FIXME folder) and on [Wokwi with the Raspberry Pi Pico C SDK](https://wokwi.com/projects/324879108372693587).

FIXME
Not implemented. Planning to have examples for:
  * Flash test
  * Error handling


The [ARM GNU toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain) is very popular and can be run under Visual Studio Code. It may also be run underneath some other IDEs. 

# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
