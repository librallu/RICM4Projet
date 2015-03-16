all: test

test: test.c module.cpp syscall.h
	gcc test.c syscall.h -x c++ module.cpp -o $@

clean:
	-rm test
