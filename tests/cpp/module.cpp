#include "interface.h"

int i = 0;

int blinkTimer(){
	if ( i < CYCLE_VALUE ){
		i++;
		return HIGH_SPEED;
	} else if ( i == CYCLE_VALUE ){
		i++;
		return LOW_SPEED;
	} else {
		i = 0;
		return LOW_SPEED;
	}
}
