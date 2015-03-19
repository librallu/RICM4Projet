#include "esp.hpp"

#include "syscall.h"

namespace __esp__ {
	
	void __init(){
		
	}

	void gpio2_up(){
		GPIO2_SET(HIGH);
	}
	
	void gpio2_down(){
		GPIO2_SET(DOWN);
	}
	
	void gpio2_toggle(){
		GPIO2_TOGGLE();
	}
	
	bool gpio2_value(){
		return GPIO2_VAL()?HIGH ? true : false;
	}
	
	void wait(int i){
		WAIT(i);
	}
	
	void test_serial(){
		TEST_SERIAL();
	}
	
} // module namespace
