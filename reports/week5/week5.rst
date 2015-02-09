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


It seems that there is an installation problem with xtensa. For fixing this,
we create a new folder in *~/esp8266/xtensa-toolchain-build/build-lx106/root/xtensa-lx106-elf/ld*
and copy into it *~/esp8266/esp_iot_sdk_v0.9.3/ld/eagle.rom.addr.v6.ld*



Error when burning :

    FW 0x00000.bin
    ~/esp8266/other/esptool/esptool -eo image.elf -bo 0x00000.bin -bs .text -bs .data -bs .rodata -bc -ec
    FW 0x40000.bin
    ~/esp8266/other/esptool/esptool -eo image.elf -es .irom0.text 0x40000.bin -ec
    (~/esp8266/esptool/esptool.py --port /dev/ttyUSB0 write_flash 0x00000 0x00000.bin 0x40000 0x40000.bin)||(true)
    Traceback (most recent call last):
      File "/home/librallu/esp8266/esptool/esptool.py", line 470, in <module>
        esp = ESPROM(args.port, args.baud)
      File "/home/librallu/esp8266/esptool/esptool.py", line 66, in __init__
        self._port = serial.Serial(port, baud)
      File "/usr/lib/python2.7/dist-packages/serial/serialutil.py", line 261, in __init__
        self.open()
      File "/usr/lib/python2.7/dist-packages/serial/serialposix.py", line 278, in open
        raise SerialException("could not open port %s: %s" % (self._port, msg))
    serial.serialutil.SerialException: could not open port /dev/ttyUSB0: [Errno 13] Permission denied: '/dev/ttyUSB0'

For fixing this, we need to add user to with *usermod* this command

    sudo usermod -a -G dialout $USER

and reboot.
    
    sudo reboot


Another error when burning :

    (^_^)[librallu@Tomoyo:~/esp8266/ws2812esp8266]$ make burn
    (~/esp8266/esptool/esptool.py --port /dev/ttyUSB0 write_flash 0x00000 0x00000.bin 0x40000 0x40000.bin)||(true)
    Connecting...
    Traceback (most recent call last):
      File "/home/librallu/esp8266/esptool/esptool.py", line 471, in <module>
        esp.connect()
      File "/home/librallu/esp8266/esptool/esptool.py", line 149, in connect
        raise Exception('Failed to connect')
    Exception: Failed to connect

This problem comes from a bad wiring :

We need to put GPIO0 low and CH_PD high.
we also plug RX, TX, VCC, GND.


Conclusions
===========

We are now able to compile images from C, C++ and burn it on the card.
In the next week, we will focus on how code programs to run on the card.

Another work
============


 - We made a svg image of the ESP8266 to integrate it with fritzing.
 
 
Useful Links
============

 - http://41j.com/blog/2015/01/esp8266-sdk-library-symbols/
