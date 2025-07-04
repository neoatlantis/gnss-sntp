#include <xc8>
#include "system_config.h"
#include "i2c.h"

// https://aidanmocke.com/blog/2018/11/27/i2c/


void i2c2_init(){
    I2C2CONbits.ON = 1;         // enable I2C module 2
    I2C2BRG = I2C_BRG_CONSTANT; // set baudrate
}

// Waits until the I2C peripheral is no longer doing anything  
void i2c2_wait_for_idle(){
    while(I2C2CON & 0b00011111);
    // Acknowledge sequence not in progress
    // Receive sequence not in progress
    // Stop condition not in progress
    // Repeated Start condition not in progress
    // Start condition not in progress
    while(I2C2STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress
}

void i2c2_start(){
    i2c2_wait_for_idle();
    I2C2CONbits.SEN = 1;
    // "The SEN bit is automatically cleared at completion of the Start
    // condition"
    while(I2C2CONbits.SEN);
}

void i2c2_stop(){
    i2c2_wait_for_idle();
    I2C2CONbits.PEN = 1;
    while(I2C2CONbits.PEN);
}

void i2c2_restart(){
    i2c2_wait_for_idle();
    I2C2CONbits.RSEN = 1;
    while (I2C2CONbits.RSEN);
}

void i2c2_ack(void){
    i2c2_wait_for_idle();
    I2C2CONbits.ACKDT = 0; // Set hardware to send ACK bit
    I2C2CONbits.ACKEN = 1; // Send ACK bit, will be automatically cleared by hardware when sent  
    while(I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning ACK bit has been sent
}

void i2c2_nack(void){ // sends a NACK condition
    i2c2_wait_for_idle();
    I2C2CONbits.ACKDT = 1; // Set hardware to send NACK bit
    I2C2CONbits.ACKEN = 1; // Send NACK bit, will be automatically cleared by hardware when sent  
    while(I2C2CONbits.ACKEN); // Wait until ACKEN bit is cleared, meaning NACK bit has been sent
}


void i2c2_write(uint8_t address, char wait_ack){
    I2C2TRN = address | 0;              // Send slave address with Read/Write bit cleared
    while (I2C2STATbits.TBF);           // Wait until transmit buffer is empty
    i2c2_wait_for_idle();               // Wait until I2C bus is idle
    if(wait_ack){
        while(I2C2STATbits.ACKSTAT);    // Wait until ACK is received
    }
}


void i2c2_read(uint8_t *value, char ack_nack){
    I2C2CONbits.RCEN = 1;               // Receive enable
    while (I2C2CONbits.RCEN);           // Wait until RCEN is cleared (automatic)  
    while (!I2C2STATbits.RBF);          // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C2RCV;                   // Retrieve value from I2C2RCV

    if (!ack_nack)                      // Do we need to send an ACK or a NACK?  
        I2C_ack();                      // Send ACK  
    else
        I2C_nack();                     // Send NACK  
}