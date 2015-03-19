#include "syscall.h"
#include "interface.h"


int main(){
	GPIO2_SET(HIGH);
	while(1){
		for ( int i = 0 ; i < 3 ; i++ ){
			GPIO2_TOGGLE();
			WAIT(1000);
		}
		for ( int i = 0 ; i < 8 ; i++ ){
			GPIO2_TOGGLE();
			WAIT(100);
		}
	}
	
	return 0;
}
