Test of micropython on STM32
----------------------------

After following the installation method presented here (https://github.com/micropython/micropython),
the STM32 card worked well with micropython and an interactive shell was available.



Xtensa Toolchain installation
-----------------------------

Used to install the toolchain for using the card :

 - get sources here (*git clone https://github.com/pfalcon/esp-open-sdk*).
 - cd *esp-open-sdk*.
 - *make STANDALONE=y* or *make STANDALONE=n* (estimated time 30 à 40 min).
 - There is two options because some parts of the SDK are not free. *y* option
   integrates all, which is easier to install but makes updates more difficult.
 - add *export PATH=[path to sdk]/esp-open-sdk/xtensa-lx106-elf/bin:$PATH*
   in your **~/.bashrc**
 - commands like *xtensa-lx106-elf-gcc*, *xtensa-lx106-elf-g++*, ... are now available !


More informations here : https://github.com/pfalcon/esp-open-sdk



Nodemcu
-------

We also looked at **nodemcu** which allows to program the ESP8266 with
*Lua* language : https://github.com/nodemcu/nodemcu-firmware.

It make it possible to have a simple way to make programs and having
small executables. It can be interesting.

To install it, it is necessary to have xtensa (e.g. precedent section)



**Installation :**

 - First of all, we need to get the firmware here : *git clone https://github.com/nodemcu/nodemcu-firmware*
 - Now, we can compile it by moving to the repository directory and launch the command *make*.



**Solved problems :**

In the first compilation on *archlinux*, we get the following error message
when executing the command *make* :

	  File "../tools/esptool.py", line 131
		print 'Connecting...'
							^

It comes that in the file *tools/esptools.py*, the first line : *#!/usr/bin/env python*
references the version 3.4 of python and the script needs python2.7.
That is why print does not work. If we want to stay in python3.4, we
need to replace *print 'hello'* by *print('hello')*.
Or, we can replace *#!/usr/bin/env python* py *#!/usr/bin/env python2.7*

Note : Those changes are not necessary for distributions like Ubuntu because
their current version of the python interpreter is the 2.7



Research on garbage collectors
------------------------------

One of the problems of compiling python to C++ is that whereas python,
C++ has no garbage collector (GC) and has to allocate (and deallocate) memory
manually.
Such problematics cannot be resolved throught compilation as the termination
problem isn't solvable - we can't decide when a variable won't be referenced
ever again just by 'reading' the source code - so we decided to implement
a system of inbeded garbage collecting for our code.

We first reached the cheney algorithm in an idea of speed performance in a real time aproach.
This algorithm is a prototype of all the tracing algorithms we found further,
it consists in evaluating the memory links between the heap and the stack
of the program, when the heap does not references a zone in the stack anymore
it automatically deallocate this zone.
the cheney algorithm works by splitting the free space in the stack into
two equal parts. The memory allocation begins in one of them, when it's 
nearly full or when the GC is forced, the GC evaluates the memory links
and when one is found a copy of the referenced memory zone is made to the
second part of the memory which is void. After evaluating all the current
stack, the active part is cleaned and the second becomes active. 
One advantage of this algorithm is that by copying the memory we can avoid
memory fragmentation but a substential amount of memory is needed in the 
first place.
With the ESP8266 we cannot afford this expense in memory as we only have
80kb of RAM inbound.

We do have to use another algorithm of garbage collectingif we want to use C++ in fine, 
but still a tracing algorithm, reference counting algorithms are not viable
for our project for the same memory reasons as the cheney algorithm 
(each object generates another of constant size). Moreover these algorithms
need atomicity, wich cannot be provided by the ESP8266 platform.

The second problem we faced is the real time factor.
Indeed this platform has to manage real time actions such as any interuption
for garbage collecting will impact performance, and cause errors in transfers.

We stumbled upon a method of garbage collecting that does not necessitates
the interuption of activity, the *compile-time* garbage collecting.
we read a thesis on this subject adapted to the mercury language wich is
a pure declarative logical language.
This language is way more strict and hard to handle than python, and in the
scope of end user programing it is impossible to propose such a language.

In conclusion of this research we must find another way to handle the memory,
maybe by dropping the idea of using python and C++ and switch to another
language who will be able to generate code directly runable without garbage
collecting.


Ressources and links used
-------------------------

- http://gpio.kaltpost.de/?p=2082
- https://en.wikipedia.org/wiki/Garbage_collection_%28computer_science%29
- http://mercurylang.org/documentation/papers/CW2004_03_mazur.pdf
- http://courses.cs.washington.edu/courses/csep521/07wi/prj/rick.pdf
- http://spin.atomicobject.com/2014/09/03/visualizing-garbage-collection-algorithms/

