#include <xc8>
#include <stdbool>
#include "timesync.h"

/*
    Start time synchronisation

    1. we wait for a UBX-TIME-TP info
    2. and set up a timer of expiration
    3. also prepare for a ntp broadcast packet
    4. when 1pps comes within expiration period, we send the packet
*/

bool timesync_timer_started;
bool timesync_broadcast_ready;

void timesync_start(){
    timesync_reset();
    timesync_interface_enable_extint();   
}

void timesync_reset(){
    timesync_broadcast_ready = false;
    timesync_timer_started = false;
    timesync_interface_stop_timer();
}

void timesync_stop(){
    timesync_interface_disable_extint();
    timesync_reset();
}

void timesync_interface_on_ubx_time_tp(UBX_MSG_TIME_TP_t* ubxmsg){
    timesync_interface_start_timer(1200);
    timersync_timer_started = true;
    // TODO prepare NTP broadcast packet upon next pulse, send it to NIC
}

void timesync_interface_on_extint(){
    if( !(
        !timesync_interface_timer_is_overflow() &&
        timesync_timer_started &&
        timesync_broadcast_ready
    ) ){
        timesync_reset();
        return; // won't use this pulse
    }

    // TODO  ask NIC to send packet immediately


    // finally
    timesync_reset();
}