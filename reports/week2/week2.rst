Testing micropython on STM32
-----------------------------

After following the setup method descibed here: (https://github.com/micropython/micropython).
The STM32 was funtionning with micropython and an interactive shell was availale
on our computers to launch python commands on the card.


Installation of the toolchain
-----------------------------

Toolchain setup :

 - fetch sources here (*git clone https://github.com/pfalcon/esp-open-sdk*).
 - cd *esp-open-sdk*.
 - *make STANDALONE=y* or *make STANDALONE=n* (estimated time 30 - 40 min). 
   there are two options because of certain components of the sdk wich
   are proprietary, selecting the *y* option everything will be integrated
   that will be easier to compile to compile programs but making their update
   harder.  
 - add *export PATH=[path to sdk]/esp-open-sdk/xtensa-lx106-elf/bin:$PATH*
   within **.bashrc** or putting it via terminal (session only)
 - commands *xtensa-lx106-elf-gcc*, *xtensa-lx106-elf-g++*,etc... available.


 
More info : https://github.com/pfalcon/esp-open-sdk


Nodemcu
-------

We also had a look at **nodemcu** wich allowsto program the ESP8266 in *Lua* :
https://github.com/nodemcu/nodemcu-firmware.

This makes us able to create programs with shorter bytecode, wich is very interesting
To install it, it is necessary to install Xtensa first (see above)



**installation procedure:**

 - Clone the firmware sources : *git clone https://github.com/nodemcu/nodemcu-firmware*
 - Compile with *make*

**Problems solved : **

During a prior compilation under *archlinux*, we obtained this error output
executing *make* :

	  File "../tools/esptool.py", line 131
		print 'Connecting...'
							^
This error comes from the fact that in the file *tools/esptool.py*
the first line *#!/usr/bin/env python* making reference to the python interpreter
in its 3.4 version. Yet, in this version, the instruction *print* becomes 
an ordinary function and we mus switch to python2.7 replacing *#!/usr/bin/env python* 
by *#!/usr/bin/env python2.7* 

Nb : this corrective wont be necessary for ubuntu distributions.


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

Throughout this research, we asserted that we must find another way to handle the memory,
maybe by dropping the idea of using python and C++ and switch to another
language who will be able to generate code directly runable without garbage
collecting (Lua via nodemcu).

After discussing the subject with the project responsible we will keep
trying to implement python on the wifi module in spite of the limitations
we brought up with our analysis, for python is the most widespread.

Useful Links
------------

- http://gpio.kaltpost.de/?p=2082
- https://en.wikipedia.org/wiki/Garbage_collection_%28computer_science%29
- http://mercurylang.org/documentation/papers/CW2004_03_mazur.pdf
- http://courses.cs.washington.edu/courses/csep521/07wi/prj/rick.pdf
- http://spin.atomicobject.com/2014/09/03/visualizing-garbage-collection-algorithms/

