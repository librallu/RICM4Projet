#ifndef INTERFACE__H
#define INTERFACE__H

	/* returns the answer to life, the universe, and everything */
	# ifdef __cplusplus 
		extern "C" int answer();
	#endif 
	# ifndef __cplusplus 
		int answer();
	#endif 

#endif
