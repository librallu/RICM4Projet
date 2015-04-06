week 3
======


We have several ways to make applications on the ESP8266 :


 - **C with Xtensa Toolchain :** A simple way to run programs on ESP8266.
   For it, we need to install the Xtensa Toolchain (we need to compile it on
   Linux, it takes nearly 30 min). Then, we can compile executables for ESP8266.
     
   Pro :
    - Simplest way known to run compiled programs on ESP8266
    
   Cons :
    - We need to use C language, it's not very user friendly !



 - **Micropython framework :** Allows to program ESP8266 with a recent
   version of python (3.4).
   
   Pro :
    - Simple to install on a third party dev card communicating with the ESP8266
    and making it run programs
    
   Cons :
    - Lack of performance and uses a lot of memory space
    - It has not libraries to use wifi
 
 
 - **Python to C++ via Shedskin :** Allows to program ESP8266 with python 2.7
   by compiling it to C++.
   
   Pro :
    - Coding with Python language (user friendly) and compiling C++ (performance)
    
   Cons :
    - It is working with a python subset
    - It has no libraries to use wifi
    - We need to use a garbage collector
 

 
 - **NodeMCU :** A way to program ESP8266 with *Lua* language.
   
   Pro :
    - Coding with Lua language (user friendly) and has a great performance 
    
   Cons :
    - 



Some informations about ESP8266
-------------------------------

 - 802.11 b/g/n protocols
 - integrated TCP/IP stack
 - integrated temperature sensor
 - low power 32 bit processor
 - SDIO 2.0, SPI, UART
 - clock frequency : 26 to 52 MHz
 - 200kb of ROM
 - 32kb sram
 - 80kb dram
 
 
Translations
------------
 
 After reading the specs we stumbled upon the fact that our documents have
 to be writen in english. So we had to translate all of our documents produced
 since the begining of the project.
 

Using the UART of the ESP8266
-----------------------------

In order to connect directly to the ESP module, avoiding the third party
card solution, we thought to use a Serial to UART converter to use an USB
port to communicate with the module.
The solution is rather easy as many USB to serial converter are existing.
The problem is that they are probably providing too much voltage, as the
ESP8266 runs on 3,3V and the USB port is on 5V.
We where orientated toward making a reducer bridge for switching from 5V
to 3,3V to adapt a USB to RS232 plug that we were provided after asking 
for UART to USB converter. After making several measurements at the FABLab

.. figure:: resource/RS232measurements.svg
	:alt: RS232 serial output voltage
	
	we reached two conclusion:
		- first that every pin on the RS232 plug (except ground)
		is giving either 5V in UP mode, or 0v in DOWN mode
		- and secondly that it will be to much work converting **every** pin
		with a dedicated bridge, without speaking of the "user friendly"
		side of our project.
	
With these conclusions we have been able to push serious argument to obtain
a USB to 3,3V UART module. We will normaly have access to this piece of
hardware next week.  	
 


Useful Links
------------

 - http://rayshobby.net/first-impression-on-the-esp8266-serial-to-wifi-module/
 - https://www.youtube.com/watch?v=pWo-ErpVZC4
 - https://github.com/nodemcu/nodemcu-firmware
 - http://hackaday.com/2014/12/08/compiling-your-own-programs-for-the-esp8266/
 - https://github.com/esp8266/esp8266-wiki/wiki/Memory-Map
