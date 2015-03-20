In this week we will focus on making C++ work on the ESP8266.

We have two ways for doing that :

- changing the toolchain to integrate the SDK in C++. But it can be pretty
  hard because the SDK is not designed for C++.
- Making a decision module in C++ called in a C code. This ways is more 
  complex but allows to compile C++ sources separately from the SDK.
  
We will implement the second option.

Architecture
============

.. figure:: archi.png
	:alt: architecture of C drivers and C++ decision-taker.

In this way, we can easily add new modules in C++ simply by adding
new events and new result handlers in C.


How to integrate a C++ module
=============================

In this section, we will make a simple C++ module that allows the LED blinking
at different speeds.

First of all, we define the following interface (C header file).

.. code:: C

	#ifndef __INTERFACE_H__
	#define __INTERFACE_H__

	#ifdef __cplusplus
	extern "C" {
	#endif

		#define LOW_SPEED 1000
		#define HIGH_SPEED 100
		#define CYCLE_VALUE 8

		int blinkTimer();

	#ifdef __cplusplus
	}
	#endif

	#endif


We use #ifdef __cplusplus to add extern "C" if the file is compiled in C++
and do nothing if the file is compiled in C. 


We make the following C++ source :

.. code:: C++

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


We use the C++ function in the following C snippet :

.. code:: C

	#include "interface.h"

	void some_timerfunc(void *arg)
	{
		//Do blinky stuff
		if (GPIO_REG_READ(GPIO_OUT_ADDRESS) & BIT2)
		{
			//Set GPIO2 to LOW
			gpio_output_set(0, BIT2, BIT2, 0);
		}
		else
		{
			//Set GPIO2 to HIGH
			gpio_output_set(BIT2, 0, BIT2, 0);
		}

		os_timer_arm(&some_timer, blinkTimer(), 0);	
	}


In this way, we select the time when the next call to some_timerfunc.



Shedskin interaction
====================

TODO

About object files 
==================

In this project, we need to understand how object files work.

We can use some standard unix commands :

- ld : GNU linker
- nm : list symbols from object files
- size : size of an object



application
-----------

In this case, with the shedskin output, we have a lot of symbols in our
object files, some of them are missing. We can see which of them with the
command *nm main.o -u*.

While compiling object file from shedskin output, we get this

.. raw::

	nm test.o -u
				 U __cxa_allocate_exception
				 U __cxa_atexit
				 U __cxa_begin_catch
				 U __cxa_call_unexpected
				 U __cxa_end_catch
				 U __cxa_free_exception
				 U __cxa_throw
				 U __dso_handle
				 U GC_free
				 U GC_malloc
				 U GC_malloc_atomic
				 U __gxx_personality_v0
				 U memcpy
				 U memmove
				 U memset
				 w __pthread_key_create
				 U _Unwind_Resume
				 U _ZN12__shedskin__10__add_strsEiPNS_3strES1_S1_S1_
				 U _ZN12__shedskin__16cl_stopiterationE
				 U _ZN12__shedskin__22__throw_stop_iterationEv
				 U _ZN12__shedskin__26__throw_index_out_of_rangeEv
				 U _ZN12__shedskin__3strC1EPKc
				 U _ZN12__shedskin__4reprIiEEPNS_3strET_
				 U _ZN12__shedskin__4TrueE
				 U _ZN12__shedskin__5FalseE
				 U _ZN12__shedskin__5pyobj11__nonzero__Ev
				 U _ZN12__shedskin__5pyobj12__deepcopy__EPNS_4dictIPvPS0_EE
				 U _ZN12__shedskin__5pyobj6__eq__EPS0_
				 U _ZN12__shedskin__5pyobj6__ge__EPS0_
				 U _ZN12__shedskin__5pyobj6__gt__EPS0_
				 U _ZN12__shedskin__5pyobj6__le__EPS0_
				 U _ZN12__shedskin__5pyobj6__lt__EPS0_
				 U _ZN12__shedskin__5pyobj6__ne__EPS0_
				 U _ZN12__shedskin__5pyobj7__cmp__EPS0_
				 U _ZN12__shedskin__5pyobj7__int__Ev
				 U _ZN12__shedskin__5pyobj7__len__Ev
				 U _ZN12__shedskin__5pyobj7__str__Ev
				 U _ZN12__shedskin__5pyobj8__copy__Ev
				 U _ZN12__shedskin__5pyobj8__hash__Ev
				 U _ZN12__shedskin__5pyobj9__index__Ev
				 U _ZN12__shedskin__6___boxEi
				 U _ZN12__shedskin__6__initEv
				 U _ZN12__shedskin__6print2EPNS_4fileEiiz
				 U _ZN12__shedskin__7cl_listE
				 U _ZN12__shedskin__7__startEPFvvE
				 U _ZNSt8ios_base4InitC1Ev
				 U _ZNSt8ios_base4InitD1Ev
				 U _ZSt20__throw_length_errorPKc
				 U _ZTIN12__shedskin__5pyobjE
				 U _ZTVN10__cxxabiv119__pointer_type_infoE
				 U _ZTVN10__cxxabiv120__si_class_type_infoE
	

