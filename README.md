# Making Embedded Systems

This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White.

Interested in developing embedded systems? Since they don't tolerate inefficiency, these systems require a disciplined approach to programming. This easy-to-read guide helps you cultivate good development practices based on classic software design patterns and new patterns unique to embedded programming. You'll learn how to build system architecture for processors, not operating systems, and discover techniques for dealing with hardware difficulties, changing designs, and manufacturing requirements.

Written by Elecia White, an expert who's created embedded systems ranging from DNA scanners to children's toys, this book is ideal for intermediate and experienced programmers, no matter what platform you use. This expanded update includes new chapters on IoT and networked sensors, motors and movement, and data handling strategies.

Optimize your system to reduce cost and increase performance

* Develop an architecture that makes your software robust in resource-constrained environments
* Explore sensors, displays, motors, and other I/O devices
* Reduce RAM and power consumption, code space, and processor cycles
* Learn how to interpret schematics, datasheets, and power requirements
* Discover how to implement complex mathematics and machine learning on small processors
* Design effective embedded systems for IoT and networked sensors

You can purchase the book (physical, electronic, and audiobook versions) on [Amazon](https://www.audiobooks.com/audiobook/making-embedded-systems-design-patterns-for-great-software/814297) or whereever you buy books including [O'Reilly](https://www.oreilly.com/library/view/making-embedded-systems/9781098151539/), [Audiobooks.com](https://www.audiobooks.com/audiobook/making-embedded-systems-design-patterns-for-great-software/814297), [ebooks.com](https://www.ebooks.com/en-us/book/211248416/making-embedded-systems/elecia-white/) and [Bookshop.org](https://bookshop.org/p/books/making-embedded-systems-design-patterns-for-great-software/20544051).

# This Repository

This repository is a companion to the book. While there is code in this repository, there are other resources that are critical so expect to see lots of links and some spreadsheets.

* [Chapter 1, Introduction](Ch01_Intro/README.md): This chapter describes what an embedded system is and how development is different from traditional software.
* [Chapter 2, Creating a System Architecture](Ch02_Architecture/README.md): Whether you are trying to understand a system or creating one from scratch, there are tools to help.
* [Chapter 3, Getting Your Hands on the Hardware](Ch03_Hardware/README.md): Hardware/software integration during board bring-up can be scary, but there are some ways to make it smoother.
* [Chapter 4, Outputs, Inputs, and Timers](Ch04_IOTimers/README.md): The embedded systems version of “Hello World” is making an LED blink. It can be more complex than you might expect.
* [Chapter 5, Interrupts](Ch05_Interrupts/README.md): Interrupts are one of the most confusing topics in embedded systems: code that gets called asynchronously on events that happen inside the processor. A chicken is used to make this easier.
* [Chapter 6, Managing the Flow of Activity](Ch06_Flow/README.md): This chapter describes methods for setting up the main loop of your system, where to use interrupts (and how not to), and how to make a state machine.
* [Chapter 7, Communicating with Peripherals](Ch07_Communication/README.md): Peripherals are where the processor touches the physical world. Different serial communication methods rule embedded systems: UART, SSP, SPI, I2C, USB, and so on. While you can look up the details for each, this chapter looks at what makes them different from each other and how to make them work more efficiently.
* [Chapter 8, Putting Together a System](Ch08_Externals/README.md): Common peripherals such as LCDs, ADCs, flash memory, and digital sensors have common implementation needs such as buffer handling, bandwidth requirements, and pipelines.
* [Chapter 9, Getting Into Trouble](Ch09_Debugging/README.md): Debugging is a skill every developer needs. Figuring out how to cause problems will teach you how to solve bugs, stack problems, hard faults, and cleverness.
* [Chapter 10,  Building Connected Devices](Ch10_Connected/README.md): Whether you have consumer IoT devices or industrial networked systems, managing many devices means dealing with firmware updates, security, and monitoring health.
* [Chapter 11, Doing More with Less](Ch11_Resources/README.md): Optimization is not for the faint of heart. This chapter shows methods for reducing consumption of RAM, code space, and processor cycles. 
* [Chapter 12, Math](Ch12_Math/README.md): Most embedded systems need to do some form of analysis. Understanding how mathematical operations and floating points work (and don’t work) will make your system faster and more robust.
* [Chapter 13, Reducing Power Consumption](Ch13_Power/README.md): From reducing processor cycles to system architecture suggestions, this chapter will help you if your system runs on batteries.
* [Chapter 14, Motors and Movement](Ch14_Movement/README.md): This chapter is a basic introduction to motors and movement. Or the introduction to an entirely new book.

# Some Links

[Wokwi](https://wokwi.com/) simulates processors in embedded systems, giving you board level control. If you aren't ready to buy a dev board, look here. Some of my sample code will be for Wokwi for use with the [ST Nucleo L031K6](https://wokwi.com/projects/new/st-nucleo-l031k6) and [Raspberry Pi Pico](https://wokwi.com/projects/new/pi-pico-w-sdk). Note that the Wokwi landing site shows all kinds of languages including Processing (Arduino), Rust, and MicroPython. You may have to dig for the C++ interfaces.

Here are some of my current favorite blogs:  

* The [Embedded Artistry Blog and Site](https://embeddedartistry.com/first-time-here/) has a wealth of information about design, implementation, and planning. While there are pay-for classes, a great deal of the information is free. One of my favorites here is where [the author looks at old games to get practice reading code](https://embeddedartistry.com/blog/2019/05/06/programmers-lets-study-source-code-classics/).
  
* [Memfault’s Interrupt Blog](https://interrupt.memfault.com/blog/) is a useful source of information about IoT and Cortex processors. Memfault also has a lively Slack channel, check their website for a link.
  
* [Miro Samek's YouTube Channel](https://www.youtube.com/c/StateMachineCOM) shows Miro coding systems. He focuses a lot on state machines, you can find more on his Quantum Leaps site at [state-machine.com](https://www.state-machine.com/).
  
* The [Embedded Software Engineering 101](https://embedded.fm/blog/ese101) blog series by Chris Svec shows getting started from a lower level system using an MSP430.

Here are some C++ learning resources:
* The best book is [C++ Primer](https://www.amazon.com/Primer-5th-Stanley-B-Lippman/dp/0321714113). Whatever the latest edition is though embedded compilers may not be up on the latest C++ standards.

* I also liked [Thinking in C++](https://www.amazon.com/dp/0139798099) which has some author-approved online (free) website copies. 

* There is a good list for specific areas on stackoverflow's [The Definitive C++ Book Guide and List](https://stackoverflow.com/questions/388242/the-definitive-c-book-guide-and-list)

* [C++ Weekly with Jason Turner](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw) is a video series taught by someone who really knows C++ and loves to share it.
  
* [Learncpp.com](http://Learncpp.com) is a free website teaching C++ programming.

* [C++ on Exercism](https://exercism.org/tracks/cpp/exercises) provides exercises you can use to practice C++.

Finally, if you are looking for inspiration or a place to post your projects, [Hackaday.io](https://hackaday.io/) and [Hackster.io](https://www.hackster.io/) are sites where you can post your project, get comments, and enter contests (for hardware or cash).

# Final Note

If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
