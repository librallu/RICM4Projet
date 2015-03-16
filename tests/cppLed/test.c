#include <stdio.h>

#include "syscall.h"

int main(){
	int i;
	for ( i = 0 ; i < 20 ; i++ ){
		printf("value : %d\n", blinkTimer());
	}
}
