#ifndef __SYSCALL_H__
#define __SYSCALL_H__

	#ifdef __cplusplus
	extern "C" {
	#endif
	
	
	/* ~~~~~~~~~~~~~~~~~~ GPIO manipulation ~~~~~~~~~~~~~~~~~ */
	
	/*
	 * define a GPIO state :
	 *  - HIGH or DOWN
	 */
	typedef enum {
	HIGH,
	DOWN
	} gpio_state_t;
	
	
	/* set GPIO2 output to value 
	 * value can be : HIGH, DOWN
	 * */
	void GPIO2_SET(gpio_state_t value);
	
	
	/* return value of GPIO2 
	 * value can be HIGH or DOWN
	 * */
	gpio_state_t GPIO2_VAL();
	
	
	/* if GPIO2 is HIGH, set to DOWN else, set to DOWN */
	void GPIO2_TOGGLE();
	
	
	
	
	
	/* ~~~~~~~~~~~~~~~~~~ timer manipulation ~~~~~~~~~~~~~~~~~~~ */
	
	
	/* wait for ms milliseconds */
	void WAIT(unsigned int ms);
	
	
	
	/* ~~~~~~~~~~~~~~~~~~~~~~ say hello ~~~~~~~~~~~~~~~~~~~~~~~~ */
	
	/* display a "hello world !" string in the serial port */
	void TEST_SERIAL();
	
	
	
	#ifdef __cplusplus
	}
	#endif


#endif // __SYSCALL_H__
