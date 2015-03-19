/**
 * defines the effects of syscalls.
 */

/* syscall definitions */
#include "syscall.h"

/* SDK includes */
#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"





void GPIO2_SET(gpio_state_t value){
	if ( value == HIGH ){ // set to HIGH
		gpio_output_set(BIT2, 0, BIT2, 0);
	} else { // set to DOWN
		gpio_output_set(0, BIT2, BIT2, 0); 
	}
}


gpio_state_t GPIO2_VAL(){
	return (GPIO_REG_READ(GPIO_OUT_ADDRESS) & BIT2) ? HIGH : DOWN;
}



void GPIO2_TOGGLE(){
	GPIO2_SET(!GPIO2_VAL());
}



void WAIT(unsigned int ms){
	os_delay_us(ms*1000);
}


void TEST_SERIAL(){
		os_printf("Hello world !\n");
}
