#ifndef __SYSCALL_H__
#define __SYSCALL_H__

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
