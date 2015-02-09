In this week, we will retry to install the toolchain for compiling C or C++ 
programs on the ESP8266. This time, we will use a standard linux distribution
based on Ubuntu (Linux Mint).

we follow the instructions here : https://github.com/cnlohr/ws2812esp8266

In the xtensa compilation, we need to recompile gcc.
For this, we need three modules : 

 - gmp
 - mpc
 - mpfr

To install those modules, we need to go on their websites, download the
zip containing the sources, unzip it.

Then type:
 
 - ./configure
 - make
 - make install


Once we have installed those modules, we can compile gcc.
It can take nearly 30 minutes.



Some issues with compiling test program
---------------------------------------


    driver/uart.c:12:19: erreur fatale: osapi.h: No such file or directory
     #include <osapi.h>
                       ^
    compilation terminée.
    In file included from user/ws2812.c:1:0:
    user/ws2812.h:6:21: erreur fatale: c_types.h: No such file or directory
     #include "c_types.h"
                         ^
    compilation terminée.
    user/user_main.c:1:17: erreur fatale: mem.h: No such file or directory
     #include "mem.h"
                     ^
    compilation terminée.
    make: *** [image.elf] Error 1

We modify the Makefile and add a space line 29 :

    CFLAGS:=-mlongcalls -I$(SDK)/include -Imyclib -Iinclude -Iuser -Os -I$(SDK)/include/

to 

    CFLAGS:=-mlongcalls -I$(SDK)/include -Imyclib -Iinclude -Iuser -Os -I $(SDK)/include/


Error with ld :

    /home/librallu/esp8266/xtensa-toolchain-build/build-lx106/root/lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld: ne peut ouvrir le fichier de scripts de l'éditeur de liens ../ld/eagle.rom.addr.v6.ld: No such file or directory
    collect2: erreur: ld a retourné 1 code d'état d'exécution
    make: *** [image.elf] Error 1

