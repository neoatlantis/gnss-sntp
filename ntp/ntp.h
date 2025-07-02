#ifndef _NTP
#define _NTP


typedef union {
    uint8_t value[4];
    struct {
        unsigned LI:2;
        unsigned VN:3;
        unsigned MODE:3;
        unsigned Stratum:8;
        unsigned Poll:8;
        unsigned Precision:8;
    };
} NTP_HEADER;

#define NTP_HEADER_MODE_BROADCAST   5
#define NTP_HEADER_MODE_SERVER      4

#define NTP_HEADER_STRATUM_PRIMARY  1





#endif