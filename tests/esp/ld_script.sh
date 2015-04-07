/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/bin/ld \
--sysroot=/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot -o build/app.out -u call_user_start \
-L/home/librallu/esp8266/esp-open-sdk/sdk//lib -L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2 \
-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/lib/gcc/xtensa-lx106-elf/4.8.2/../../../../xtensa-lx106-elf/lib \
-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/lib \
-L/home/librallu/esp8266/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/sysroot/usr/lib -v --no-check-sections \
-static --start-group -lc -lgcc -lhal -lpp -lphy -lnet80211 -llwip -lwpa -lmain build/app_app.a syscall.o main.o interface.o \
--end-group -T /home/librallu/esp8266/esp-open-sdk/sdk//ld/eagle.app.v6.ld
