**THIS PROJECT IS DEFUNCT**

BMS
===

A cross platform BMS player project (codename "Revolution")


## What is this?

Be-Music Source (BMS) is a music format presented by Urao Yane (commonly refered to as just Yaneurao in Japan) in 1998.

(For more explanations see: http://en.wikipedia.org/wiki/Be-Music_Source)

BMS Players are game platforms developed to play BMS files, especially mimicking the popular arcade and PlayStation game "Beatmania" and "Beatmania IIDX".

One of the most sophisticated BMS players existing today is called "Lunatic Rave 2" (LR2 for short) which is widely used throughout the world.

However LR2 is implemented only for Windows machines, and there are no other BMS players which have equivalent functionality for OS X/Linux computers.

The goal of this project is to develop a BMS player with (at minimum) the capability to provide the same user experience as LR2 for Windows/OS X/Linux computers.

## Compiling

### OS X/Linux

Prerequisites for building this project are
- cmake (> 2.8.7)
- SDL2
- SDL2 Image
- SDL2 Mixer

(Note that for OS X users it is recommended you try installing these dependencies using Homebrew.)

If you have the dependencies installed run:
````
mkdir build
cd build
cmake ..
make
````

to build the runtime and testing binaries.

To run the test, execute the `RunAllTests` in the `bin` directory.
To run the game, execute the `RevolutionBMS` in the `bin` directory.
