#ifndef __UBX_MSG_DEF
#define __UBX_MSG_DEF

#pragma pack(push, 1)


// UBX-TIME-TP definition

typedef union {
    uint8_t value;
    struct {
        unsigned timeBase:1;
        unsigned utc:1;
        unsigned raim:2;
        unsigned qErrInvalid:1;
        unsigned TpNotLocked:1;
        unsigned :2;
    };
} UBX_MSG_TIME_TP_FLAGS_t;

typedef union {
    uint8_t value;
    struct {
        unsigned timeRefGnss:4;
        unsigned utcStandard:4;
    };
} UBX_MSG_TIME_TP_REFINFO_t;

typedef union {
    uint8_t buffer[16];
    struct {
        uint32_t towMS;
        uint32_t towSubMS;
        int32_t  qErr;
        uint16_t week;
        UBX_MSG_TIME_TP_FLAGS_t   flags;
        UBX_MSG_TIME_TP_REFINFO_t refInfo;
    } fields;
} UBX_MSG_TIME_TP_t;



// UBX-NAV-TIMEUTC definition

typedef union {
    uint8_t value;
    struct {
        unsigned validTow:1;
        unsigned validWKN:1;
        unsigned validUTC:1;
        unsigned authStatus:1;
        unsigned utcStandard:4;
    };
} UBX_MSG_NAV_TIMEUTC_VALID_t;

typedef union {
    uint8_t buffer[20];
    struct {
        uint32_t iTOW;
        uint32_t tAcc;
        int32_t  nano;
        uint16_t year;
        uint8_t  month;
        uint8_t  day;
        uint8_t  hour;
        uint8_t  min;
        uint8_t  sec;
        UBX_MSG_NAV_TIMEUTC_VALID_t valid;
    } fields;
} UBX_MSG_NAV_TIMEUTC_t;


#pragma pack(pop)
#endif