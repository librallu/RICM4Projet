SHEDSKIN_LIBDIR=/usr/share/shedskin/lib
CC=g++
CCFLAGS=-O2 -march=native -Wno-deprecated $(CPPFLAGS) -I. -I${SHEDSKIN_LIBDIR} -g -fPIC -D__SS_BIND -I/usr/include/python2.7 -I/usr/include/python2.7
LFLAGS=-lgc -lpcre $(LDFLAGS) -shared -Xlinker -export-dynamic -lpthread -ldl  -lutil -lm -lpython2.7

CPPFILES=/home/zit/Documents/RICM4/ProjetS8/RICM4Projet/lib/led.cpp \
	${SHEDSKIN_LIBDIR}/re.cpp \
	${SHEDSKIN_LIBDIR}/builtin.cpp

HPPFILES=/home/zit/Documents/RICM4/ProjetS8/RICM4Projet/lib/led.hpp \
	${SHEDSKIN_LIBDIR}/re.hpp \
	${SHEDSKIN_LIBDIR}/builtin.hpp

all:	led.so

led.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o led.so

clean:
	rm -f led.so

.PHONY: all clean

