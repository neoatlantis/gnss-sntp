
#ifndef _SYSTEM_CONFIG_H    /* Guard against multiple inclusion */
#define _SYSTEM_CONFIG_H


// SYSCLK should now be 96 MHz.
#define SYSCLK 80000000
#define PBCLK  SYSCLK / 4

// I2C Baudrate Generator Value
#define I2C_BRG_CONSTANT     0x15  // 400kHz @ PBCLK=20MHz


#endif 