#include "timer1.h"


void timer1_init(void){
    T1CONbits.TCS = 1;   // use 32khz osc
    T1CONbits.TCKPS = 1; // 01-1:8 prescale, timer runs at 4096Hz
}

void timer1_start(void){
    T1CONbits.ON = 0;
    TMR1 = 0; // reset timer 1
    T1CONbits.ON = 1;
}

uint16_t timer1_stop(void){
    T1CONbits.ON = 0;
    return TMR1;
}

uint16_t timer1_read(void){
    return TMR1;
}