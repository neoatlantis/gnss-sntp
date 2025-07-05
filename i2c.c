#include <xc.h>
#include "system_config.h"
#include "i2c.h"

// https://aidanmocke.com/blog/2018/11/27/i2c/


void i2c_release_bus(){
    I2C2CONbits.ON = 0;

    // make SCL & SDA as gpio
    I2C_PIN_TRIS(I2C_PIN_SCL) = 0;
    I2C_PIN_TRIS(I2C_PIN_SDA) = 0;

    for (int i = 0; i < 9; ++i) {
        I2C_PIN_LAT(I2C_PIN_SCL) = 0;    // SCL low
        I2C_RESET_DELAY;
        I2C_PIN_LAT(I2C_PIN_SCL) = 1;    // SCL high
        I2C_RESET_DELAY;

        // break when SDA is released
        if (I2C_PIN_PORT(I2C_PIN_SDA) == 1) break;
    }

    // STOP: SDA from 0 to 1, SCL is 1
    I2C_PIN_LAT(I2C_PIN_SDA) = 0;
    I2C_RESET_DELAY;

    I2C_PIN_LAT(I2C_PIN_SCL) = 1;
    I2C_RESET_DELAY;

    I2C_PIN_LAT(I2C_PIN_SDA) = 1;
    I2C_RESET_DELAY;

    // resume function on SCL & SDA
    I2C_PIN_TRIS(I2C_PIN_SCL) = 1;
    I2C_PIN_TRIS(I2C_PIN_SDA) = 1;
}



void i2c2_init(){
    I2C2CONbits.ON = 0;
    i2c_release_bus();
    I2C2CONbits.ON = 1;         // enable I2C module 2
    I2C2BRG = I2C_BRG_CONSTANT; // set baudrate
}

// Waits until the I2C peripheral is no longer doing anything  
i2c_result i2c2_wait_for_idle(){
    if(I2C2STATbits.BCL){
        syslog_report("i2c error! master bus collision.");
        return I2C_MASTER_BUS_COLLISION;
    }

    while(I2C2CON & 0b00011111);
    // Acknowledge sequence not in progress
    // Receive sequence not in progress
    // Stop condition not in progress
    // Repeated Start condition not in progress
    // Start condition not in progress
    while(I2C2STATbits.TRSTAT); // Bit = 0 ? Master transmit is not in progress

    return I2C_OK;
}

i2c_result i2c2_start(){
    i2c_result start_attempt = i2c2_wait_for_idle();
    if(I2C_OK != start_attempt){
        return start_attempt;
    }

    I2C2CONbits.SEN = 1;
    // "The SEN bit is automatically cleared at completion of the Start
    // condition"
    while(I2C2CONbits.SEN);

    return I2C_OK;
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


void i2c2_transfer(uint8_t byte, char wait_ack){
    I2C2TRN = byte; 
    while (I2C2STATbits.TBF);           // Wait until transmit buffer is empty
    i2c2_wait_for_idle();               // Wait until I2C bus is idle
    if(wait_ack){
        while(I2C2STATbits.ACKSTAT);    // Wait until ACK is received
    }
}


void i2c2_receive(uint8_t *value, char ack_nack){
    I2C2CONbits.RCEN = 1;               // Receive enable
    while (I2C2CONbits.RCEN);           // Wait until RCEN is cleared (automatic)  
    while (!I2C2STATbits.RBF);          // Wait until Receive Buffer is Full (RBF flag)  
    *value = I2C2RCV;                   // Retrieve value from I2C2RCV

    if (!ack_nack)                      // Do we need to send an ACK or a NACK?  
        i2c2_ack();                      // Send ACK  
    else
        i2c2_nack();                     // Send NACK  
}