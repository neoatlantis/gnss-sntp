#include "uart.h"
#include <xc.h>

void uart2_enable(){
    U2BRG = BRG_VAL;
    U2MODEbits.UEN = 0b00;
    U2MODEbits.ON = 1;
}

void uart_gps_enable(){
    U1BRG = BRG_VAL_GPS_UART;
    U1STAbits.URXEN = 1;
    U1MODEbits.UEN = 0b00;
    U1MODEbits.ON = 1;
}


void putch(char ch){
    while(U2STAbits.UTXBF);             // Wait until buffer is empty
    U2TXREG = ch;                       // Transmit character
}

int16_t getch_gps(){
    if(U1STAbits.OERR){
        U1STAbits.OERR = 0;
        return UART_ERROR_RECV;
    }
    if(!U1STAbits.URXDA){
        return UART_ERROR_EMPTY;
    }
    return U1RXREG & 0xFF;
}