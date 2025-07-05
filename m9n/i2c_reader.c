#include "../i2c.h"
#include "../syslog.h"
#include "i2c_reader.h"
#include <stdbool.h>

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


void m9n_i2c_read_bytes(uint16_t count, uint8_t* buffer){
    i2c2_start();

    i2c2_transfer(M9N_I2C_ADDRESSING_W, I2C_TX_WAIT_ACK);
    i2c2_transfer(0xFF,                 I2C_TX_WAIT_ACK);

    i2c2_restart();

    i2c2_transfer(M9N_I2C_ADDRESSING_R,          I2C_TX_WAIT_ACK);

    for(uint16_t i=0; i<count; i++){
        bool last_byte = (i == count-1);

        I2C2CONbits.RCEN=1;

        if(!last_byte){
            i2c2_receive(buffer+i,    I2C_RX_ENDWITH_ACK);
        } else {
            i2c2_receive(buffer+i,    I2C_RX_ENDWITH_NACK);
        }
    }

    i2c2_stop();
}


uint16_t m9n_i2c_read(){

    uint8_t bytescount_h, bytescount_l;
    uint16_t bytescount;

    m9n_i2c_read_one_byte(M9N_I2C_REGISTER_BYTESCOUNT_H, &bytescount_h);
    m9n_i2c_read_one_byte(M9N_I2C_REGISTER_BYTESCOUNT_L, &bytescount_l);

    bytescount = (bytescount_h << 8) + bytescount_l;

    //syslog_sprintf("<6> %d bytes in M9N i2c buffer.", bytescount);

    if(bytescount > M9N_I2C_BUFFER_SIZE){
        m9n_i2c_read_bytes(bytescount, m9n_i2c_buffer);
        return 0;
    }

    m9n_i2c_read_bytes(bytescount, m9n_i2c_buffer);
    return bytescount;
}