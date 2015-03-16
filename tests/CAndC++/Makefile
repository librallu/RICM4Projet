
all: test

call.o: call.cpp interface.h
	g++ -c $^ -o $@

test: call.o test.c
	gcc -v test.c call.o -o $@

clean:
	-@rm call.o test
