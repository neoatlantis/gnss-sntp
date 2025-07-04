#ifndef _I2C
#define _I2C

#include <xc8>

void i2c2_init();
void i2c2_wait_for_idle();
void i2c2_start();
void i2c2_stop();
void i2c2_restart();
void i2c2_ack();
void i2c2_nack();

void i2c2_write(uint8_t, char);
void i2c2_read(uint8_t*, char);


#endif