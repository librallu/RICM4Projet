Test de micropython sur STM32
-----------------------------

Après avoir suivi la méthode d'installation décrite ici (https://github.com/micropython/micropython).
La carte STM32 fonctionnait avec micropython et un shell interactif était disponible
sur nos machines pour lancer des commandes python sur la carte.


Installation du toolchain
-------------------------

Installer le toolchain pour utiliser la carte :

 - récupérer les sources ici (*git clone https://github.com/pfalcon/esp-open-sdk*).
 - cd *esp-open-sdk*.
 - *make STANDALONE=y* ou *make STANDALONE=n* (temps estimé 30 à 40 min). 
   Il y a deux options car certains composants
   du sdk ne sont pas libres, en indiquant l'option *y* tout sera intégré en un tout
   ce qui sera simple pour compiler des programmes mais rend les mises à jour de ceux-ci
   plus difficile. 
 - ajouter *export PATH=[chemin vers le sdk]/esp-open-sdk/xtensa-lx106-elf/bin:$PATH*
   dans le **.bashrc** ou l'entrer dans le terminal
 - les commandes *xtensa-lx106-elf-gcc*, *xtensa-lx106-elf-g++*, ...
   sont maintenant disponibles.


 
Plus d'informations ici : https://github.com/pfalcon/esp-open-sdk


Nodemcu
-------

Nous avons également jetté un oeil à **nodemcu** qui permet de programmer
l'ESP8266 en *Lua* : https://github.com/nodemcu/nodemcu-firmware.

Cela permettrait d'avoir une manière simple de réaliser des programmes 
tout en ayant des exécutables petits. Ce qui peut être intéressant.

Pour l'installer, il est nécessaire d'avoir installé xtensa avant (voir section
ci-dessus)



**procédure d'installation :**

 - Commençons par récupérer le firmware ici : *git clone https://github.com/nodemcu/nodemcu-firmware*
 - Nous pouvons maintenant le compiler en se déplaçant dans le répertoire en question et en entrant la 
   commande *make*




**Problèmes résolus : **

Lors d'une première compilation sur *archlinux*, nous avons obtenu le
message d'erreur suivant pendant l'exécution de la commande *make* :

	  File "../tools/esptool.py", line 131
		print 'Connecting...'
							^
Cela vient du fait que dans le fichier *tools/esptool.py*, la
première ligne : *#!/usr/bin/env python* fait référence à l'interpréteur
python ayant la version 3.4. Or dans cette version, l'instruction *print*
devient une fonction comme une autre et il est nécessaire de forcer le passage
a python2.7 en remplaçant la ligne *#!/usr/bin/env python* par *#!/usr/bin/env python2.7*

Note : Ce correctif ne devrait pas être nécessaire pour des distributions comme
ubuntu.


Ressources Utiles
-----------------

- http://gpio.kaltpost.de/?p=2082
- https://en.wikipedia.org/wiki/Garbage_collection_%28computer_science%29
- http://mercurylang.org/documentation/papers/CW2004_03_mazur.pdf

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



