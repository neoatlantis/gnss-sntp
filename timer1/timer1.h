#ifndef _TIMER1_TIMER1
#define _TIMER1_TIMER1

#include <xc.h>

void timer1_init(void);
void timer1_start(void);
uint16_t timer1_stop(void);
uint16_t timer1_read(void);
#define TIMER1_FREQ  4096


#define TIMER1_TIME_1000ms  4096
#define TIMER1_TIME_10000ms 40960
#define TIMER1_TIME_1010ms  4137


#endif