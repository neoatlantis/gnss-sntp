#include "../i2c.h"
#include "../syslog.h"
#include "i2c_reader.h"

uint8_t m9n_i2c_buffer[M9N_I2C_BUFFER_SIZE];


void m9n_i2c_read_one_byte(uint8_t register_addr, uint8_t* result){
    i2c2_start();

    i2c2_transfer(M9N_I2C_ADDRESSING_W, I2C_TX_WAIT_ACK);
    i2c2_transfer(register_addr,        I2C_TX_WAIT_ACK);

    i2c2_restart();

    i2c2_transfer(M9N_I2C_ADDRESSING_R,          I2C_TX_WAIT_ACK);

    I2C2CONbits.RCEN = 1;               // Receive enable
    i2c2_receive(result, I2C_RX_ENDWITH_NACK);
    i2c2_stop();
}


void m9n_i2c_read(){

    uint8_t bytescount_h, bytescount_l;
    uint16_t bytescount;

    m9n_i2c_read_one_byte(M9N_I2C_REGISTER_BYTESCOUNT_H, &bytescount_h);
    m9n_i2c_read_one_byte(M9N_I2C_REGISTER_BYTESCOUNT_L, &bytescount_l);

    bytescount = (bytescount_h << 8) + bytescount_l;

    syslog_sprintf("<6> %d bytes exist in M9N i2c buffer.", bytescount);

}