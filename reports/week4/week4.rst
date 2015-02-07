In this week, we want to compile a simple C or C++ program and execute
it on the ESP8266.

We tried to compile and flash the ESP with the programs here : 
https://github.com/esp8266/source-code-examples

Unfortunatly, due to incompatibility problems with our system (archlinux) 
we aren't yet able to compile programs.

	/home/librallu/esp8266/xtensa-toolchain-build/bin/../lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld: ne peut trouver -lc
	/home/librallu/esp8266/xtensa-toolchain-build/bin/../lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld: ne peut trouver -lhal

Next week, we will try on a more standard linux distribution : Linux Mint with
the hope that it will work this time.


Useful Links
------------

 - http://41j.com/blog/2015/01/esp8266-writing-internal-flash-basic-keyvalue-store/
 - https://github.com/nekromant/esp8266-frankenstein
 - https://github.com/esp8266/esp8266-wiki/wiki/Memory-Map

 - https://github.com/esp8266/esp8266-wiki/wiki/Toolchain
