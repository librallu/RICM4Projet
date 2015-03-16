#include "answer.hpp"

// include for using the SDK
#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_config.h"

namespace __led__ {
	
	int timer;
	
		
		/* to understand */
	#define user_procTaskPrio        0
	#define user_procTaskQueueLen    1
	os_event_t    user_procTaskQueue[user_procTaskQueueLen];
	static void user_procTask(os_event_t *events);

	static volatile os_timer_t some_timer;
	
	//Do nothing function
	static void ICACHE_FLASH_ATTR
	user_procTask(os_event_t *events)
	{
		os_delay_us(10);
	}
		/* end */
	

	void __init() {
		timer = 500;
	}
	
	void toggle() {
		if ( GPIO_REG_READ(GPIO_OUT_ADDRESS) & BIT2 ) { // if led is on
			gpio_output_set(0, BIT2, BIT2, 0); // set led to off
		} else {
			gpio_output_set(BIT2, 0, BIT2, 0); // set led to on
		}
		
	}
	
	void ICACHE_FLASH_ATTR user_init() {
		gpio_init(); // initialize gpio system
		
		PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2); // gpio2 in output mode
		
		gpio_output_set(0, BIT2, BIT2, 0); // set led to off
		
		os_timer_disarm(&some_timer);
		
		os_timer_setfn(&some_timer, (os_timer_func_t *)some_timerfunc, NULL);
		
		os_timer_arm(&some_timer, timer, 1);
		
		system_os_task(user_procTask, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
	}

} // module namespace
