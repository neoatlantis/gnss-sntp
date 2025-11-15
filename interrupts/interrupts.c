#include <xc.h>
#include <sys/attribs.h>
#include "interrupts.h"

void interrupt_enable_int1(void){
    INTCONbits.INT1EP = 1;

    IFS0bits.INT1IF = 0;

    IPC1bits.INT1IP = 3;
    IPC1bits.INT1IS = 1;    

    IEC0bits.INT1IE = 1;
}

void interrupt_disable_int1(void){
    IEC0bits.INT1IE = 0;
}

void __ISR(_EXTERNAL_1_VECTOR, IPL3) INT1Interrupt(void){
    IFS0bits.INT1IF = 0;
    interrupt_isr_int1();
}



void interrupt_enable_rtcc(void){
    IFS1bits.RTCCIF = 0;

    IPC8bits.RTCCIP = 3;
    IPC8bits.RTCCIS = 1;

    IEC1bits.RTCCIE = 1;
}

void interrupt_disable_rtcc(void){
    IEC1bits.RTCCIE = 0;
}

void __ISR(_RTCC_VECTOR, IPL3) RTCCInterrupt(void){
    IFS1bits.RTCCIF = 0;
    interrupt_isr_rtcc();
}