/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H

#include "system_config.h"
#include <xc.h>

#define BAUDRATE 115200
#define BRG_VAL  (PBCLK / 16 / BAUDRATE - 1)


#define BAUDRATE_GPS_UART  38400
#define BRG_VAL_GPS_UART   (PBCLK/16/BAUDRATE_GPS_UART-1)


#define UART_ERROR_EMPTY      -1
#define UART_ERROR_RECV       -2



void putch(char);
void uart2_enable();
void uart_gps_enable();
int16_t getch_gps();

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
