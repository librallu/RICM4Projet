#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"
#include "user_config.h"
#include "interface.h"
#include "syscall.h"

//~ #define user_procTaskPrio        0
//~ #define user_procTaskQueueLen    1
//~ os_event_t    user_procTaskQueue[user_procTaskQueueLen];
//~ static void user_procTask(os_event_t *events);

//~ static volatile os_timer_t some_timer;



//Call the C++ main here
//~ static void ICACHE_FLASH_ATTR user_main(os_event_t *events) {
    //~ main();
//~ }

//Init function 
void ICACHE_FLASH_ATTR
user_init()
{
    // Initialize the GPIO subsystem.
    gpio_init();

    //Set GPIO2 to output mode
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

    //Set GPIO2 low
    gpio_output_set(0, BIT2, BIT2, 0);

    //Disarm timer
    //~ os_timer_disarm(&some_timer);

    //Setup timer
    //~ os_timer_setfn(&main, (os_timer_func_t *)some_timerfunc, NULL);

    //Arm the timer
    //&some_timer is the pointer
    //1000 is the fire time in ms
    //0 for once and 1 for repeating
    //~ os_timer_arm(&some_timer, 1000, 0);
    
    //~ while(1){
		//~ GPIO2_SET(HIGH);
		//~ WAIT(100);
		//~ GPIO2_SET(DOWN);
		//~ WAIT(100);
		//~ TEST_SERIAL();
		//~ GPIO2_TOGGLE();
	//~ }
    
    main();
    
    //Start os task
    //~ system_os_task(user_procTask, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
    //~ system_os_task(user_main, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
}
