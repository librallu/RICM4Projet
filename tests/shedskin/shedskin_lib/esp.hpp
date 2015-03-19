#ifndef __ESP_HPP
#define __ESP_HPP

#include "builtin.hpp"

using namespace __shedskin__;

namespace __esp__ {
	
	void __init();

	void gpio2_up();
	
	void gpio2_down();
	
	void gpio2_toggle();
	
	bool gpio2_value();
	
	void wait(int i);
	
	void test_serial();

} // module namespace
#endif



