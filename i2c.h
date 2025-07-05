#ifndef _I2C
#define _I2C

#include <xc.h>

typedef enum {
    I2C_OK = 0,
    I2C_MASTER_BUS_COLLISION = -2
} i2c_result;

#define I2C_PIN_SCL     A,2
#define I2C_PIN_SDA     A,3

#define __I2C_PIN_TRIS(P,N)     TRIS##P##bits.TRIS##P##N
#define __I2C_PIN_PORT(P,N)     PORT##P##bits.R##P##N
#define __I2C_PIN_LAT(P,N)      LAT##P##bits.LAT##P##N

#define I2C_PIN_TRIS(x)     __I2C_PIN_TRIS(x)
#define I2C_PIN_PORT(x)     __I2C_PIN_PORT(x)
#define I2C_PIN_LAT(x)      __I2C_PIN_LAT(x)


#define I2C_RESET_DELAY  _nop();_nop();_nop();_nop()

void i2c_release_bus();
void i2c2_init();
i2c_result i2c2_wait_for_idle();
i2c_result i2c2_start();
void i2c2_stop();
void i2c2_restart();
void i2c2_ack();
void i2c2_nack();

void i2c2_transfer(uint8_t, char);
void i2c2_receive(uint8_t*, char);

#define I2C_RX_ENDWITH_NACK 1
#define I2C_RX_ENDWITH_ACK  0
#define I2C_TX_WAIT_ACK     1
#define I2C_TX_NO_WAIT_ACK  0


#endif