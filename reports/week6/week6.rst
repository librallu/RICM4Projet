

Last week, we made a simple C program that blinks a led on the ESP8266.
Now, we want to use shedskin in the process. We will develop a simple
shedskin module for adding a blink logic in the ESP8266 and make it 
compile to C++, and flash the ESP with it.


How to make a shedskin module ?
-------------------------------

in *build/lib/shedskin/lib/*, we add three files : 

- **module.py :** that contains python specifications
- **module.cpp & module.hpp :** that contains C++ implementation

We can make a test module : 

answer.py

.. code:: python

	r = 42

	def answer(): return 1

answer.cpp

.. code:: cpp

	#include "answer.hpp"

	namespace __answer__ {

		int r;

		void __init() {
			r = 42;
		}

	} // module namespace


answer.hpp

.. code:: cpp

	#ifndef __ANSWER_HPP
	#define __ANSWER_HPP

	#include "builtin.hpp"

	using namespace __shedskin__;
	namespace __answer__ {
		
		extern int r;

		void __init();

		inline int answer() {
			return r;
		}

	} // module namespace
	#endif


