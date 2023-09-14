# Chapter 11: Doing More with Less
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 


Have you ever done something that pleases you whenever you look at it? Well, I gave a talk about memory maps that makes me happy. The talk and the graphics I created make me laugh. I’d love to [share it with you](https://embedded.fm/blog/mapfiles)

# Following Along in the Book
 * There is no single C library. Instead there are many implementations that work to conserve some balance of RAM, code space, and processing cycles. 
   * Embedded Artistry has a C standard library (LibC) specifically for embedded systems usage. It has a reduced set of functionality appropriate for very constrained environments. It is designed for portability and quick bring up. Its documentation is also excellent, good code to read. [Related blog posts](https://embeddedartistry.com/blog/tag/libc/)and [Code] (https://github.com/embeddedartistry/libc). Note it is MIT licensed.


Although I have attempted to give you some tools to take care of the largest problems, there are almost always ways to squeak out a little bit more. For more optimization techniques, look at your processor vendor’s application notes and your compiler manual. Atmel has a particularly good application note for one of their 8-bit processors: [AVR035: Efficient C Coding for AVR](http://www.atmel.com/dyn/resources/prod_documents/doc1497.pdf).

Another great resource showing how to wring the most out of your limited resources is the [Stanford Graphics Bithacks site](https://graphics.stanford.edu/~seander/bithacks.html). It shows how different algorithms can be implemented with different resources. If you enjoy that, I highly recommend finding _Hacker’s Delight_ by Henry S. Warren.

To compare how these different implementations work (or different versions of your own implementation), take a look at [Compiler Explorer](https://godbolt.org/) also known as Godbolt as it is named after its creator Matt Godbolt. This web tool lets you compile functions and see the assembly output. Many compilers and languages are supported. The assembly is documented and interspersed with the code. The goal is to let you see how your coding choices affect your assembly. It is a growing tool with ever expanding features, here is [the introduction](https://github.com/compiler-explorer/compiler-explorer/blob/main/docs/WhatIsCompilerExplorer.md).

# My Favorite Optimization Quotes
"We should forget about small efficiencies, say about 97% of the time: premature optimization is the root of all evil. Yet we should not pass up our opportunities in that critical 3%. A good programmer will not be lulled into complacency by such reasoning, he will be wise to look carefully at the critical code; but only after that code has been identified." — [Donald Knuth](http://en.wikipedia.org/wiki/Donald_Knuth)


"More computing sins are committed in the name of efficiency (without necessarily achieving it) than for any other single reason — including blind stupidity." — [W.A. Wulf](http://en.wikipedia.org/wiki/W.A._Wulf)


"Bottlenecks occur in surprising places, so don't try to second guess and put in a speed hack until you have proven that's where the bottleneck is." — [Rob Pike](http://en.wikipedia.org/wiki/Rob_Pike)


"The First Rule of Program Optimization: Don't do it. The Second Rule of Program Optimization (for experts only!): Don't do it yet." — [Michael A. Jackson](https://en.wikipedia.org/wiki/Michael_A._Jackson_(computer_scientist))


# Code For This Chapter

FIXME: Script for reading gcc map files into html or some other viz

# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
