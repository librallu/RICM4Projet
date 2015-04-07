Week 11 report (last week)
==========================

In this week, we conclude what we have done in this project.




STM32 discovery memory
======================

192 kB of RAM

ESP8266 memory
==============

80 kb of DRAM
32 kb of SRAM

therefore 112 kb of RAM (14 kB of RAM) 


Shedskin requirements
=====================

we see the size of object files of the project :

size -d -t *.o
   text	   data	    bss	    dec	    hex	filename
  78515	      8	   4213	  82736	  14330	builtin.o
    323	      0	      0	    323	    143	esp.o
   4419	      8	     29	   4456	   1168	main.o
  30712	      8	      9	  30729	   7809	re.o
    192	      0	      0	    192	     c0	syscall.o
     79	      0	      0	     79	     4f	user_init.o
 114240	     24	   4251	 118515	  1cef3	(TOTALS)


We are far that the ESP8266 limit size.



