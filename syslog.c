#include <string.h>
#include "nic/nic.h"
#include "customized_params.h"
#include "w5500/udp_socket.h"
#include "syslog.h"

NIC* syslog_nic_ptr;
bool syslog_setup_done = false;

void syslog_setup(NIC* nic_ptr){
    syslog_nic_ptr = nic_ptr;
    w5500_open_udp_socket(nic_ptr, 7, SYSLOG_LOCAL_PORT);
    syslog_setup_done = true;
}

bool syslog_report(uint8_t string[]){
    if(!syslog_setup_done) return false;

    uint16_t string_length = strlen(string);
    if(string_length > SYSLOG_MAX_SIZE){
        string_length = SYSLOG_MAX_SIZE;
    }

    NICUDPPacket dgram = { .bufferSize = string_length };
    memcpy(&dgram.buffer, string, string_length);

    memcpy(&dgram.src_addr.octet, &(uint8_t[4]){ UDP_LOCAL_IP }, 4);
    dgram.src_port.octetH = SYSLOG_LOCAL_PORT >> 8;
    dgram.src_port.octetL = SYSLOG_LOCAL_PORT & 0xFF;
    
    memcpy(&dgram.dst_addr.octet, &(uint8_t[4]){ UDP_BCAST_IP }, 4);
    dgram.dst_port.octetH = SYSLOG_BCAST_PORT >> 8;
    dgram.dst_port.octetL = SYSLOG_BCAST_PORT & 0xFF;

    w5500_udp_socket_send(syslog_nic_ptr, 7, &dgram);
    return true;
}