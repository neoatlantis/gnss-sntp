#ifndef _M9N_I2C_READER
#define _M9N_I2C_READER


#include "../i2c.h"
#include <xc.h>

void m9n_i2c_read_one_byte(uint8_t, uint8_t*);
void m9n_i2c_read_bytes(uint16_t, uint8_t*);
uint16_t m9n_i2c_read();


/* Max size for M9N i2c buffer. If more bytes are needed to be read, we will
truncate i2c buffer. */

#define M9N_I2C_BUFFER_SIZE 512

#define M9N_I2C_ADDRESSING_W        0x84 & 0b11111110
#define M9N_I2C_ADDRESSING_R        0x84 | 0b00000001

#define M9N_I2C_REGISTER_BYTESCOUNT_H  0xFD
#define M9N_I2C_REGISTER_BYTESCOUNT_L  0xFE
#define M9N_I2C_REGISTER_BUFFER        0xFF

extern uint8_t m9n_i2c_buffer[M9N_I2C_BUFFER_SIZE];

#endif