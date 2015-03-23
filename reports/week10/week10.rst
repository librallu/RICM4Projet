

Some facts about the ESP8266
============================

If you want to run the esp8266, you can put GPIO0 high,
if it's set to low, it can be flashed.


Integration of last year work
=============================

we integrate the last year work on shedskin.


we get the following link command for the sample project

.. code-block :: C

	/usr/bin/ld -plugin /usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/liblto_plugin.so \
	-plugin-opt=/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/lto-wrapper \
	-plugin-opt=-fresolution=/tmp/ccxUiji8.res -plugin-opt=-pass-through=-lgcc_s \
	-plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc \
	-plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc \
	--build-id --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker \
	/lib64/ld-linux-x86-64.so.2 -o test \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib/crt1.o \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib/crti.o \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/crtbegin.o \
	-L/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2 \
	-L/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib \
	-L/lib/../lib -L/usr/lib/../lib \
	-L/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/../../.. -v \
	/tmp/cc8kYW57.o /tmp/cc9SO1yG.o /tmp/cc8zUtlp.o -lgc -lpcre \
	-lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/crtend.o \
	/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/../../../../lib/crtn.o
