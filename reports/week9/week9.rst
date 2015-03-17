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
