#ifndef _TASKS_TIMESYNC    /* Guard against multiple inclusion */
#define _TASKS_TIMESYNC

#include <stdbool>
#include "../../m9n/ubx_msg_def.h"

void timesync_start();
void timesync_stop();
void timesync_reset();

// User shall call this when received a new UBX-TIME-TP message ASAP.
void timesync_interface_on_ubx_time_tp(UBX_MSG_TIME_TP_t* ubxmsg);

// User shall implement this to enable GNSS interrupt
extern void timesync_interface_enable_extint();

// User shall call this in interrupt service routine
void timesync_interface_on_extint();

// User shall implement this to disable GNSS interrupt
extern void timesync_interface_disable_extint();

// User shall implement this to start a timer that counts up to given
// milliseconds.
extern void timesync_interface_start_timer(uint16_t ms);

// User shall implement this to answer if the count is over given duration.
extern bool timesync_interface_timer_is_overflow();

// User shall implement this to stop above timer
extern void timesync_interface_stop_timer();






#endif