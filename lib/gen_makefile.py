
d = {}
d["shedskin"] = "/usr/lib/python2.7/site-packages/shedskin/lib"
d["objs"] = "driver/uart.o user/mystuff.o user/ws2812.o user/user_main.o"
d["srcs"] = "driver/uart.c user/mystuff.c user/ws2812.c user/user_main.c"
d["gcc_folder"] = "~/esp8266/xtensa-toolchain-build/build-lx106"
d["esp_tool"] = "~/esp8266/esptool/esptool.py"
d["fw_tool"] = "~/esp8266/other/esptool/esptool"
d["sdk"] = "~/esp8266/esp_iot_sdk_v0.9.3"
d["port"] = "/dev/ttyUSB0"
d["out"] = "test"


def gen_makefile(d):
	"""
	Generates Makefile with parameters in d.
	d must contain :
	- objs : objects we want to generate
	- srcs : source objects we want to generate
	- gcc_folder : where the xtensa compiler is installated
	- esp_tool : location of esptool.py
	- fw_tool : esptool directory
	- sdk : sdk directory
	- port : port where the card is (for burning it). In general, it's /dev/ttyUSB0
	"""
	
	print(
	"""
all : image.elf
FW_FILE_1:=0x00000.bin
FW_FILE_2:=0x40000.bin

TARGET_OUT:=image.elf
SHEDSKIN_LIBDIR:={0}

CPPFILES:=/home/librallu/esp8266/shedskin/{8}.cpp \
	$(SHEDSKIN_LIBDIR)/re.cpp \
	$(SHEDSKIN_LIBDIR)/builtin.cpp

HPPFILES:=/home/librallu/esp8266/shedskin/{8}.hpp \
	$(SHEDSKIN_LIBDIR)/re.hpp \
	$(SHEDSKIN_LIBDIR)/builtin.hpp
	
OBJS:={1}

SRCS:={2}

GCC_FOLDER:={3}
ESPTOOL_PY:={4}
FW_TOOL:={5}
SDK:={6}
PORT:={7}

XTLIB:=$(SDK)/lib
XTGCCLIB:=$(GCC_FOLDER)/gcc-4.9.1-elf/xtensa-lx106-elf/libgcc/libgcc.a
FOLDERPREFIX:=$(GCC_FOLDER)/root/bin
PREFIX:=$(FOLDERPREFIX)/xtensa-lx106-elf-
CC:=$(PREFIX)g++

CFLAGS:=-mlongcalls -I $(SDK)/include -I myclib -I include -I user -Os -I $(SDK)/include/

#	   \
#

LDFLAGS_CORE:=\
	-nostdlib \
	-Wl,--relax -Wl,--gc-sections \
	-L$(XTLIB) \
	-L$(XTGCCLIB) \
	$(SDK)/lib/liblwip.a \
	$(SDK)/lib/libssl.a \
	$(SDK)/lib/libupgrade.a \
	$(SDK)/lib/libnet80211.a \
	$(SDK)/lib/liblwip.a \
	$(SDK)/lib/libwpa.a \
	$(SDK)/lib/libnet80211.a \
	$(SDK)/lib/libphy.a \
	$(SDK)/lib/libmain.a \
	$(SDK)/lib/libpp.a \
	$(XTGCCLIB) \
	-T $(SDK)/ld/eagle.app.v6.ld

LINKFLAGS:= \
	$(LDFLAGS_CORE) \
	-B$(XTLIB)

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
	""".format(d["shedskin"], d["objs"], d["srcs"], d["gcc_folder"], d["esp_tool"], d["fw_tool"], d["sdk"], d["port"], d["out"]))


gen_makefile(d)
