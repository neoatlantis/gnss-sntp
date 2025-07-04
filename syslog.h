#ifndef _SYSLOG
#define _SYSLOG

#include <stdio.h>

#define SYSLOG_MAX_SIZE 500
extern char syslog_buffer[SYSLOG_MAX_SIZE];


#define syslog_sprintf(fmt, ...) \
    snprintf(syslog_buffer, SYSLOG_MAX_SIZE, fmt, __VA_ARGS__); \
    syslog_report(syslog_buffer);

void syslog_setup(NIC* nic_ptr);
bool syslog_report(uint8_t string[]);

#define SYSLOG_PRI(facility, level) ((facility) * 8 + (level))


#endif