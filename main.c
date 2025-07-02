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

#include "uart.h"
#include "spi.h"
#include "nic/nic.h"
#include "w5500/new.h"
#include "w5500/udp_socket.h"
#include "system_config.h"
#include "customized_params.h"

NIC nic;

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
    memcpy(&nic.ip_device.octet, &(uint8_t[4]){ SNTP_LOCAL_IP }, 4);
    memcpy(&nic.ip_gateway.octet,&(uint8_t[4]){ 0, 0, 0, 0 }, 4);
    memcpy(&nic.ip_netmask.octet,&(uint8_t[4]){ 255, 255, 255, 0 }, 4);
    nic.driver.spi_select = w5500_nic_select;
    nic.driver.spi_deselect = w5500_nic_deselect;
    nic.driver.spi_exchange_register = spi2_exchange_buffer;
    
    w5500_new(&nic);
    
    printf("Initialize W5500...\n\r");
    nic.init(&nic);
    
    printf("Opening UDP port...\n\r");
    w5500_open_udp_socket(&nic, 0, SNTP_LOCAL_PORT);
    
    printf("Init done.\n\r");
    
    NICUDPPacket udp_outgoing = { .bufferSize = 0 };
    
    
    while(1){
        WDTCONbits.WDTCLR = 1;
        
        /*
        NICUDPPacket udpp = w5500_udp_socket_read(&nic[0], 0);
        if(udpp.bufferSize > 0){
            printf(
                "Read %d bytes from %d.%d.%d.%d:%d\n\r", udpp.bufferSize,
                    udpp.src_addr.octet0,
                    udpp.src_addr.octet1,
                    udpp.src_addr.octet2,
                    udpp.src_addr.octet3,
                    (udpp.src_port.octetH << 8 | udpp.src_port.octetL)
            );
            
            // modify udpp for reply, test purpose.
            memcpy(udpp.dst_addr.octet, udpp.src_addr.octet, 4);
            memcpy(udpp.dst_port.octet, udpp.src_port.octet, 2);
            w5500_udp_socket_send(nic, 0, &udpp);
            
            udpp.bufferSize = 0;
        }*/
    }
    
    return;
}
