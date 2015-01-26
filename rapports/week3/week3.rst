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
    - Simple to install on ESP8266 and run programs
    
   Cons :
    - Lack of performance and uses a lot of memory space
    - It has not libraries to use wifi
 
 
 - **Python to C++ via Shedskin :** Allows to program ESP8266 with python 2.7
   by compiling it to C++.
   
   Pro :
    - Coding with Python language (user friendly) and compiling C++ (performance)
    
   Cons :
    - It is working with a python subset
    - It has not libraries to use wifi
    - We need to use an another garbage collector
 

 
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


Useful Links
------------

 - http://rayshobby.net/first-impression-on-the-esp8266-serial-to-wifi-module/
 - https://www.youtube.com/watch?v=pWo-ErpVZC4
 - https://github.com/nodemcu/nodemcu-firmware
 - http://hackaday.com/2014/12/08/compiling-your-own-programs-for-the-esp8266/
 - https://github.com/esp8266/esp8266-wiki/wiki/Memory-Map
