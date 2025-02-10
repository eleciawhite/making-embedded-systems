# Chapter 14: Motors and Movement
This is a companion repository for _Making Embedded Systems, 2nd Ed._ by Elecia White. 

Exercise is good for you.

# Following Along in the Book

Adafruit has a [Motor Selection Guide](https://learn.adafruit.com/adafruit-motor-selection-guide?view=all) that gives pros and cons of each type, including [an excellent chart](https://learn.adafruit.com/adafruit-motor-selection-guide?view=all#motor-assembly-quick-selection-guide-685436). They follow it up with a whole bunch of specific tutorials about running each kind of motor including [stepper motors](https://learn.adafruit.com/all-about-stepper-motors?view=all) and [DC motors](https://learn.adafruit.com/adafruit-raspberry-pi-lesson-9-controlling-a-dc-motor).

Control theory is not for the faint of heart. This is an area kids are learning because they need it for FIRST Robotics. So instead of the rigorous and math-heavy tomes I'd usually suggest, I encourage you to look at 
 * [Ctrl Alt FTC](https://www.ctrlaltftc.com/) is a complete control theory class for First Tech Challenge. It includes code, diagrams, videos, and exercises. It starts with basic on/off control and builds up to PID controllers, motion profiles, and more advanced topics. 
 * [WPILib's Advanced Controls documentation](https://docs.wpilib.org/en/stable/docs/software/advanced-controls/index.html) describes how their library works which is great but the important information is how all this works together, something you can use on your system.

For a more book-based approach to motor control and other control schemes, I like The [Art of Control Engineering](https://www.amazon.com/Art-Control-Engineering-Ken-Dutton/dp/0201175452) by Ken Dutton, Steve Thompson, and Bill Barraclough (Addison-Wesley). It is a little more math-filled than it needs to be, but still pretty useful for  implementation.

Processor libraries (CMSIS has DSP, TI has extensive libariers, as does ST)
* [ARM CMSIS DSP libary](https://arm-software.github.io/CMSIS_5/DSP/html/group__groupController.html) has PID functions for Cortex-M processors.

* Microchip has some good application notes. The concepts are not specific to their processors. 
  * [AN696 PIC18CXXX/PIC16CXXX DC Servomotor Application](http://ww1.microchip.com/downloads/en/AppNotes/00696a.pdf) describes the circuit and control for a DC motor including the control interface, measuring position, PID, motion profile, and generating the drive signal.
  * [AN857 Brushless DC Motor Control Made Easy](http://ww1.microchip.com/downloads/en/AppNotes/00857A.pdf) describes commutation without and with sensors for open and closed loop control (respectively).

* TI has extensive resources to go with their processors
  * [Motor Control landing page](https://www.ti.com/technologies/motor-control.html) describes their extensive product lines in terms of how much control you need and how many motors. Then it has pointers to whole classes on  sensing and actuation, control algorithms, safety, and the math needed to do advanced control.
  * [MotorControl software development kit (SDK) for C2000™ MCUs](https://www.ti.com/tool/C2000WARE-MOTORCONTROL-SDK) contains software and documentation for motor control development: they've written the code for you and it is good code so use it (though it can be tough to understand, it is much worse to write your own).
  * [Brushless-DC motors video series](https://www.ti.com/video/series/precision-labs/ti-precision-labs-brushless-dc-motors.html) covers commutation, sensors, and motor control methods in about 90 minutes of video.


Vintage electronics books at [TubeBooks.Org](http://www.tubebooks.org/), the electronics don't change though sometimes simpler systems are easier to understand.


# Code For This Chapter

# Final Note
If you like what's here, please consider buying the book: [_Making Embedded Systems, 2nd Ed._](https://learning.oreilly.com/library/view/making-embedded-systems/9781098151539/) by Elecia White
