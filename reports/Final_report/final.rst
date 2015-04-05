PYTHON on ESP8266: FINAL REPORT
-------------------------------

PREAMBLE: ROADMAP
=================

This project was a true challenge for us. To reach the point were we are at
we have been through many steps.
The objective of our project was to be able to run python programs on the ESP8266.
We had to understand how this chip works and how to communicate with it to be able to
put code on it later. 
Then we had to process python code which is interpreted, to create an executable of this code.
This part was partially treated by our predecessors that were in charge of doing the same porting
to STM32. they were using the shedskin and Xtensa cross compiler toolchain.
We had to addapt this toolchain to our chip and its associated sdk.


INTRODUCTION: Presenting the card and toolchain
===============================================

Core specs:
The ESP is a very light piece of hardware with ultra low power consumption (about 200 mA at full charge 
make it ideal for IoT purposes) ,providing WIFI capabilities and communicating by serial connection.
Here are some of the core specs of this cheap chip

	- 32-bit CPU running at 80MHz
	- 64KBytes of instruction RAM
	- 96KBytes of data RAM
	- 64KBytes boot ROM

detailed specs: https://github.com/esp8266/esp8266-wiki/wiki

These core specs were the most important subject of worying during our project.
In fact, it was the source of all our problems you will see why further in this report.
we will point out this weakness by comparing the ESP module with last year card.

differences with stm32:
Last year, our predecessors worked on the same subject of providing a python
compiled library for the STM32F4 Discovery card wich is a lot more powerful than
the ESP8266. Here are the core specs of the 
	
	- 32-bit ARM Cortex-M4F core running at 200Mhz
	- 1 MB Flash
	- 192KB RAM
	
you can see it is much more beefy than our module. Particularly on the available ROM
making it possible to use bigger codes 

shedskin
Shedskin is a python to C++ generator, allowing you to translate a subset
of python directly to C++, and to provide python interfaces that you personnally
code in C++ making you able to integrate them in the precedent subset.

Xtensa
Xtensa is a cross compiling toolchain making you able to process C/C++
into bytecode for the ESP 8266. it is based upon GCC.


FIRST STEPS: understanding the card
===================================


first experiences with arduino

getting rid of third party cards : UART connection

Flashing the card

The ESP SDK
 
 
Analysis of concurrent techniques
=================================

Interface with stm32

NodeMCU




The garbage collection problem
==============================



Shedskin
========




The other option, create a specific python compiler toward C/C++.
=================================================================







USEFULL LINKS
=============
	
	technical monitoring & watch: (chip provider's forum, partly in chinese) http://bbs.espressif.com/ 
	
	reStructuredText for the text layout (similar to Markdown) (http://docutils.sourceforge.net/rst.html)
	Fritzing for the electronic schemes (http://fritzing.org/home/)
	bounding ESP8266 and arduino : http://www.seeedstudio.com/wiki/WiFi_Serial_Transceiver_Module
	ESP8266 documentation : https://nurdspace.nl/ESP8266
	example with a moisture sensor added : http://zeflo.com/2014/esp8266-weather-display/
	Video tutorial for starting the ESP8266 : https://www.youtube.com/watch?v=9QZkCQSHnko
	https://www.youtube.com/watch?v=qU76yWHeQuw
	https://www.youtube.com/watch?v=uznq8W9sOKQ
	http://www.instructables.com/id/Using-the-ESP8266-module/
	http://hackaday.com/tag/esp8266/
	ESP8266 Community Forum : https://github.com/esp8266
	http://harizanov.com/2014/11/esp8266-powered-web-server-led-control-dht22-temperaturehumidity-sensor-reading/
    http://gpio.kaltpost.de/?p=2082
    https://en.wikipedia.org/wiki/Garbage_collection_%28computer_science%29
    http://mercurylang.org/documentation/papers/CW2004_03_mazur.pdf
    http://courses.cs.washington.edu/courses/csep521/07wi/prj/rick.pdf
    http://spin.atomicobject.com/2014/09/03/visualizing-garbage-collection-algorithms/
	http://rayshobby.net/first-impression-on-the-esp8266-serial-to-wifi-module/
	https://www.youtube.com/watch?v=pWo-ErpVZC4
	https://github.com/nodemcu/nodemcu-firmware
	http://hackaday.com/2014/12/08/compiling-your-own-programs-for-the-esp8266/
    http://41j.com/blog/2015/01/esp8266-writing-internal-flash-basic-keyvalue-store/
    https://github.com/nekromant/esp8266-frankenstein
    https://github.com/esp8266/esp8266-wiki/wiki/Memory-Map
    https://github.com/esp8266/esp8266-wiki/wiki/Toolchain
	(shedskin documentation) https://code.google.com/p/shedskin/wiki/docs
    http://www.google.fr/url?sa=t&rct=j&q=&esrc=s&source=web&cd=2&cad=rja&uact=8&ved=0CCsQFjAB&url=http%3A%2F%2Fesp8266.ru%2Fdownload%2Fesp8266-doc%2FESP8266_IoT_SDK_Programming%2520Guide_v0.9.1.pdf&ei=PLLgVJPyHMn0UOe-guAH&usg=AFQjCNEIYfRg5wNXwpyPy6dE4JyJ3JXCTw&sig2=Bfd64QeuhP8WIyXGnVnZNA&bvm=bv.85970519,d.d24
    https://github.com/nodemcu/nodemcu-firmware/wiki/nodemcu_api_en
	https://github.com/leon-anavi/esp-hello-world : Link with a simple serial
    https://pypi.python.org/pypi/astmonkey/0.1.1
    https://bitbucket.org/haypo/astoptimizer
    https://code.google.com/p/shedskin/wiki/docs#Compiling_a_Stand-Alone_Program







