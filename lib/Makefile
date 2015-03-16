
all : image.elf
FW_FILE_1:=0x00000.bin
FW_FILE_2:=0x40000.bin

TARGET_OUT:=image.elf
SHEDSKIN_LIBDIR:=/usr/lib/python2.7/site-packages/shedskin/lib

CPPFILES:=/home/librallu/esp8266/shedskin/test.cpp 	$(SHEDSKIN_LIBDIR)/re.cpp 	$(SHEDSKIN_LIBDIR)/builtin.cpp

HPPFILES:=/home/librallu/esp8266/shedskin/test.hpp 	$(SHEDSKIN_LIBDIR)/re.hpp 	$(SHEDSKIN_LIBDIR)/builtin.hpp
	
OBJS:=driver/uart.o user/mystuff.o user/ws2812.o user/user_main.o

SRCS:=driver/uart.c user/mystuff.c user/ws2812.c user/user_main.c

GCC_FOLDER:=~/esp8266/xtensa-toolchain-build/build-lx106
ESPTOOL_PY:=~/esp8266/esptool/esptool.py
FW_TOOL:=~/esp8266/other/esptool/esptool
SDK:=~/esp8266/esp_iot_sdk_v0.9.3
PORT:=/dev/ttyUSB0

XTLIB:=$(SDK)/lib
XTGCCLIB:=$(GCC_FOLDER)/gcc-4.9.1-elf/xtensa-lx106-elf/libgcc/libgcc.a
FOLDERPREFIX:=$(GCC_FOLDER)/root/bin
PREFIX:=$(FOLDERPREFIX)/xtensa-lx106-elf-
CC:=$(PREFIX)g++

CFLAGS:=-mlongcalls -I $(SDK)/include -I myclib -I include -I user -Os -I $(SDK)/include/

#	   #

LDFLAGS_CORE:=	-nostdlib 	-Wl,--relax -Wl,--gc-sections 	-L$(XTLIB) 	-L$(XTGCCLIB) 	$(SDK)/lib/liblwip.a 	$(SDK)/lib/libssl.a 	$(SDK)/lib/libupgrade.a 	$(SDK)/lib/libnet80211.a 	$(SDK)/lib/liblwip.a 	$(SDK)/lib/libwpa.a 	$(SDK)/lib/libnet80211.a 	$(SDK)/lib/libphy.a 	$(SDK)/lib/libmain.a 	$(SDK)/lib/libpp.a 	$(XTGCCLIB) 	-T $(SDK)/ld/eagle.app.v6.ld

LINKFLAGS:= 	$(LDFLAGS_CORE) 	-B$(XTLIB)

#image.elf : $(OBJS)
#	$(PREFIX)ld $^ $(LDFLAGS) -o $@

$(TARGET_OUT) : $(CPPFILES) $(HPPFILES) $(SRCS)
	$(PREFIX)gcc $(CFLAGS) $^  -flto $(LINKFLAGS) -o $@



$(FW_FILE_1): $(TARGET_OUT)
	@echo "FW $@"
	$(FW_TOOL) -eo $(TARGET_OUT) -bo $@ -bs .text -bs .data -bs .rodata -bc -ec

$(FW_FILE_2): $(TARGET_OUT)
	@echo "FW $@"
	$(FW_TOOL) -eo $(TARGET_OUT) -es .irom0.text $@ -ec

burn : $(FW_FILE_1) $(FW_FILE_2)
	($(ESPTOOL_PY) --port $(PORT) write_flash 0x00000 0x00000.bin 0x40000 0x40000.bin)||(true)


clean :
	rm -rf user/*.o driver/*.o $(TARGET_OUT) $(FW_FILE_1) $(FW_FILE_2)
	
