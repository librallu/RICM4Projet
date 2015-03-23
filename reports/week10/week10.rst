

Some facts about the ESP8266
============================

If you want to run the esp8266, you can put GPIO0 high,
if it's set to low, it can be flashed.


Integration of last year work
=============================

we integrate the last year work on shedskin.


we get the following link command for the sample project.
After some work, we can see there are a lot o 

.. code-block :: C

	/usr/bin/ld \
	--build-id --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker \
	/lib64/ld-linux-x86-64.so.2 -o test \
	/usr/lib/crt1.o /usr/lib/crti.o \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/crtbegin.o \
	-L/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2 \
	-L/usr/lib/ -v \
	builtin.o re.o test.o -lpcre \
	-lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/crtend.o \
	/usr/lib/crtn.o


Integration of current year work on xtensa toolchain
====================================================

we get the following ld command :

..code-block :: C

	/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld \
	--sysroot=/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot -o build/app.out \
	-u call_user_start \
	-L/home/librallu/esp8266/esp-open-sdk/sdk/lib \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2 \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/lib
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/lib \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/usr/lib -v \
	--no-check-sections -static --start-group -lc -lgcc -lhal -lpp -lphy -lnet80211 -llwip -lwpa \
	-lmain build/app_app.a syscall.o main.o --end-group -T /home/librallu/esp8266/esp-open-sdk/sdk//ld/eagle.app.v6.ld



Combining the two commands 
==========================

..code-block :: C

	/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld \
	--sysroot=/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot -o build/app.out \
	-u call_user_start \
	-L/home/librallu/esp8266/esp-open-sdk/sdk/lib \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2 \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/lib \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/lib \
	-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/usr/lib -v \
	--no-check-sections -static --start-group -lc -lgcc -lhal -lpp -lphy -lnet80211 -llwip -lwpa -lstdc++ -lm \
	-lmain build/app_app.a syscall.o main.o --end-group -T /home/librallu/esp8266/esp-open-sdk/sdk/ld/eagle.app.v6.ld

