PYTHON on ESP8266: FINAL REPORT
-------------------------------

PREAMBLE: ROADMAP
=================

This project was a true challenge for us. To reach the point were we are at
we have been throug several steps.
The objective of our project was to be able to run python programs on the ESP8266.
We had to understand how this chip works and how to communicate with it to be able to
put code on it later. 
Then we had to process python code which is interpreted, to create an executable of this code.
This part was partially treated by our predecessors that were in charge of doing the same porting
to STM32. they were using the shedskin and Xtensa cross compiler toolchain.
We had to addapt this toolchain to our chip and its associated sdk.


INTRODUCTION: Presenting the card and toolchain
===============================================

specs

differences with stm32

shedskin

Xtensa


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
	https://github.com/esp8266
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







