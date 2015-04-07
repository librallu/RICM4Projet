
##################### USER CONFIGURATION PART ##########################
CC			=	xtensa-lx106-elf-gcc
AR			=	xtensa-lx106-elf-ar
LD			=	xtensa-lx106-elf-gcc
SDK			= 	/home/librallu/esp8266/esp-open-sdk/sdk/
ESPTOOL		=	esptool.py
ESPPORT		=	/dev/ttyUSB0
FW_TOOL		=  /home/librallu/esp8266/esp-open-sdk/esptool-ck/esptool
LD_SCRIPT	=	eagle.app.v6.ld

BUILD_BASE	=	build
FW_BASE		=	firmware

SRC			=	user_init.c
SRC_CPP		=	main.cpp
SRC_PY		=	main.py


###################### DO NOT TOUCH THIS PART ##########################


# for files that are uploaded to the card
FW_FILE_1		=	0x00000.bin
FW_FILE_1_ARGS	=	-bo $@ -bs .text -bs .data -bs .rodata -bc -ec
FW_FILE_2		=	0x40000.bin
FW_FILE_2_ARGS	=	-es .irom0.text $@ -ec

# list all objects
OBJ				=	$(SRC:.c=.o)

# Some directories in the SDK
SDK_INCLUDE		=	$(SDK)/include
SDK_INC_JSON	=	$(SDK_INCLUDE)/json
SDK_LIB			=	$(SDK)/lib
SDK_LD			=	$(SDK)/ld

# some output names
TARGET			=	app
TARGET_OUT		=	$(addprefix $(BUILD_BASE)/,$(TARGET).out)
APP_AR			=	$(addprefix $(BUILD_BASE)/,$(TARGET)_app.a)

# some flags
LDFLAGS			=	-nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static
CFLAGS			=	-Os -g -O2 -Wpointer-arith -Wundef -Werror -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals  -D__ets__ -DICACHE_FLASH
LIBFLAGS		=	-lc -lgcc -lhal -lpp -lphy -lnet80211 -llwip -lwpa -lmain

# path to the LD
LD_SCRIPT2		=	-T $(SDK_LD)/$(LD_SCRIPT)

all: checkdirs $(TARGET_OUT) $(FW_FILE_1) $(FW_FILE_2)

.PHONY: all checkdirs flash clean

$(SRC_CPP): $(SRC_PY)
	python genC++.py $^ | indent -kr -nut -ts4 > $@

syscall.o: syscall.c syscall.h
	$(CC) -c $< $(CFLAGS) -I $(SDK_INCLUDE) -I $(SDK_INC_JSON) -I . -L $(SDK_LIB)

#~ %.o: %.c 
#~ 	$(CC) -o $@ -c $< $(CFLAGS) -I $(SDK_INCLUDE) -I $(SDK_INC_JSON) -I . -L $(SDK_LIB)
$(OBJ): $(SRC) syscall.o main.cpp interface.h
	$(CC) -c $(SRC) syscall.o -x c++ main.cpp interface.h $(CFLAGS) -I $(SDK_INCLUDE) -I $(SDK_INC_JSON) -I . -L $(SDK_LIB)


# STEP 1 : For creating output directories if necessary
checkdirs: $(FW_BASE) $(BUILD_BASE)

$(BUILD_BASE):
	mkdir -p $@


$(FW_BASE):
	mkdir -p $@



# STEP 2 : making target

$(APP_AR): $(OBJ)
	$(AR) cru $@ $^
	
$(TARGET_OUT): $(APP_AR)
	$(LD) -Wl,-v -L $(SDK_LIB) $(LD_SCRIPT2) $(LDFLAGS) -Wl,--start-group $(LIBFLAGS) $(APP_AR) syscall.o main.cpp interface.h -Wl,--end-group -o $@


# STEP 3 : FILE 1

$(FW_FILE_1): $(TARGET_OUT)
	$(FW_TOOL) -eo $(TARGET_OUT) $(FW_FILE_1_ARGS)


# STEP 4 : FILE 2

$(FW_FILE_2): $(TARGET_OUT)
	$(FW_TOOL) -eo $(TARGET_OUT) $(FW_FILE_2_ARGS)


flash: 0x00000.bin 0x40000.bin
	-$(ESPTOOL) --port $(ESPPORT) write_flash 0x00000 0x00000.bin 0x40000 0x40000.bin


clean:
	-@rm $(SRC_CPP)
	-@rm -r $(FW_BASE)
	-@rm -r $(BUILD_BASE)
	-@rm *.o *.gch
	-@rm $(FW_FILE_1)
	-@rm $(FW_FILE_2)

