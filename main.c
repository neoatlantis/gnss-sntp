/*
 * File:   main.c
 * Author: standard
 *
 * Created on 2023年10月18日, 下午10:27
 */

#include "config_bits.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <xc.h>

#include "nic/nic.h"
#include "syslog.h"

#include "uart.h"
#include "spi.h"
#include "i2c.h"

#include "w5500/new.h"
#include "w5500/udp_socket.h"
#include "m9n/i2c_reader.h"
#include "m9n/ubx_parser.h"
#include "system_config.h"
#include "customized_params.h"


NIC nic;
ubx_parser_context_t ubx_msg_context;

void delay_us(unsigned int us){
    us *= SYSCLK / 1000000 / 2;
    _CP0_SET_COUNT(0);
    while (us > _CP0_GET_COUNT()){
        WDTCONbits.WDTCLR = 1;
    };
}

void delay_ms(int ms){
    delay_us(ms * 1000);
}

void w5500_nic_select(){
    spi2_set_mode_8();
    SPI_SLOT1_CS_BIT = 1;
    SPI_SLOT2_CS_BIT = 0;
}

void w5500_nic_deselect(){
    SPI_SLOT1_CS_BIT = SPI_SLOT2_CS_BIT = 1;
}

void main(void) {
    INTCONSET = _INTCON_MVEC_MASK;
    //__builtin_enable_interrupts();
    
    spi2_enable();
    uart2_enable();

    printf("\033[2J----\n\r");
    printf("NeoAtlantis GPS Time Broadcaster\n\r");
    
    nic.id = 0;
    memcpy(&nic.mac.octet,       &(uint8_t[6]){ 0x02, 0xDE, 0xAD, 0xBE, 0xEF, 0x01 }, 6);
    memcpy(&nic.ip_device.octet, &(uint8_t[4]){ UDP_LOCAL_IP }, 4);
    memcpy(&nic.ip_gateway.octet,&(uint8_t[4]){ 0, 0, 0, 0 }, 4);
    memcpy(&nic.ip_netmask.octet,&(uint8_t[4]){ 255, 255, 255, 0 }, 4);
    nic.driver.spi_select = w5500_nic_select;
    nic.driver.spi_deselect = w5500_nic_deselect;
    nic.driver.spi_exchange_register = spi2_exchange_buffer;
    
    w5500_new(&nic);
    
    printf("Initialize W5500...\n\r");
    nic.init(&nic);

    printf("Setting up Syslog for UDP based report...\n\r");
    syslog_setup(&nic);
    
    printf("Opening UDP port...\n\r");
    w5500_open_udp_socket(&nic, 0, SNTP_LOCAL_PORT);

    syslog_report("<6>Initializing i2c...");
    i2c2_init();    

    syslog_report("<6>Setup ubx parser.");
    ubx_parser_init(&ubx_msg_context);

    syslog_report("<6>NeoAtlantis GPS Time Broadcaster initialized.");

    /*syslog_report("<6>Opening serial input for GPS data...");
    uart_gps_enable();*/

    syslog_report("<6>Init done.");
    


    /*NICUDPPacket dgram_template = { .bufferSize = 10 };
    memcpy(&dgram_template.src_addr.octet, &(uint8_t[4]){ UDP_LOCAL_IP }, 4);
    dgram_template.src_port.octetH = SNTP_LOCAL_PORT >> 8;
    dgram_template.src_port.octetL = SNTP_LOCAL_PORT & 0xFF;
    
    memcpy(&dgram_template.dst_addr.octet, &(uint8_t[4]){ UDP_BCAST_IP }, 4);
    dgram_template.dst_port.octetH = SNTP_BCAST_PORT >> 8;
    dgram_template.dst_port.octetL = SNTP_BCAST_PORT & 0xFF;

    for(uint8_t i=0; i<dgram_template.bufferSize; i++){
        dgram_template.buffer[i] = i + 17;
    }*/

        
    while(1){
        delay_ms(10);

        uint16_t m9n_i2c_bytes_read = m9n_i2c_read();
        if(m9n_i2c_bytes_read >= 0){
            for(uint16_t i=0; i<m9n_i2c_bytes_read; i++){
                ubx_parser_result_t result = ubx_parser_feed(
                    &ubx_msg_context,
                    *(m9n_i2c_buffer + i)
                );
                if(result == UBX_PARSER_NEW_MESSAGE){
                    syslog_sprintf(
                        "<6>M9N new message(%x,%x)",
                        ubx_msg_context.CLS,
                        ubx_msg_context.MSGID
                    );

                    ubx_parser_reset_context(&ubx_msg_context);
                }
            }
        }

        /*NICUDPPacket dgram;
        memcpy(&dgram, &dgram_template, sizeof(NICUDPPacket));

        w5500_udp_socket_prepare_send(&nic, 0, &dgram);

        delay_ms(600);
        printf("++");

        w5500_udp_socket_do_send(&nic, 0, &dgram);

        delay_ms(400);
        printf(">!  ");*/

    }
    
    return;
}
