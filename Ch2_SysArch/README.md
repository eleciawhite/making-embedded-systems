# Chapter 2: Creating a System Architecture
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 

# Drawing Tools
Some tools for creating system and block diagrams: 
 * My favorite is Mermaid Markdown which can be created with text and used in Readme.md files. You can use it live: [mermaid.live](https://mermaid.live/) 
 * [draw.io](https://app.diagrams.net/) makes online flowcharts and diagrams ([its code](https://github.com/jgraph/drawio-desktop/releases/tag/v15.8.7)), no signup
 * [LucidChart](https://www.lucidchart.com/) is also very popular
 * [asciiflow.com](https://asciiflow.com/#/) creates diagrams that can be output to ASCII 

# Other Diagramming Methods
The [C4 Model](https://c4model.com/) of diagramming systems is different from the approach used in Elecia’s book but it is very useful. It focuses more on large scale software. See [Wikipedia](https://c4model.com/) and a good blog post from [InfoQ](https://www.infoq.com/articles/C4-architecture-model/)

Also the [The Art of Crafting Architectural Diagrams](https://www.infoq.com/articles/C4-architecture-model/) blog post describes some pitfalls and best practices.

# Hardware Abstraction Layers Example
STMicroelectronics has many popular processors. They also have a great deal of code on their github repository. Start with the [top-level microcontroller repository](https://github.com/STMicroelectronics/STM32Cube_MCU_Overall_Offer) and then dig into the HAL or BSP or CMSIS for a processor that interests you. 

Initially, the goal is just to figure out how it is all put together. Remember that you probably only care about the processor and features you want to use but they are trying to support hundreds of processor variants in many different markets. There is a reason it is so complicated.

# Code For This Chapter
FIXME
Not implemented. Planning to have examples for:
  * Singleton
  * Sandbox
  * MVC
  * Logging Interface

# New to Git?
 * [Learn Git Branching](https://learngitbranching.js.org/) is a puzzle solving tutorial game.
 * [Oh My Git](https://ohmygit.org/) is a game with virtual playing cards and repo visualization
 * [Zen of Git](https://www.youtube.com/watch?v=5Gq3KVvcfDk&ab_channel=CascadiaJS) video is a great talk by Tianyu Pu on the internals of git (and you thought the user interface was complicated!😊).


# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
