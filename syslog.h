#ifndef _SYSLOG
#define _SYSLOG

#define SYSLOG_MAX_SIZE 1000

void syslog_setup(NIC* nic_ptr);
bool syslog_report(uint8_t string[]);

#define SYSLOG_PRI(facility, level) ((facility) * 8 + (level))


#endif