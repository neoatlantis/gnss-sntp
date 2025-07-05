#ifndef __UBX_PARSER
#define __UBX_PARSER

#include <stdint.h>
#include <stdbool.h>

#define UBX_PARSER_BUFFER_SIZE                  1024


enum UBX_PARSER_STATES {
    UBX_PARSER_START,
    UBX_PARSER_WAITING_SECOND_CHAR,
    UBX_PARSER_WAITING_CLS,
    UBX_PARSER_WAITING_MSGID,
    UBX_PARSER_WAITING_LEN0,
    UBX_PARSER_WAITING_LEN1,
    UBX_PARSER_BUFFERING,
    UBX_PARSER_WAITING_CK_A,
    UBX_PARSER_WAITING_CK_B
};

typedef struct {
    UBX_PARSER_NEW_MESSAGE,
    UBX_PARSER_CONTINUE,
} ubx_parser_result_t;

typedef struct {
    enum UBX_PARSER_STATES state;
    uint8_t CLS;
    uint8_t MSGID;
    uint8_t EXTERNAL_CK_A;
    uint8_t EXTERNAL_CK_B;
    uint8_t buffer[UBX_PARSER_BUFFER_SIZE];
    uint16_t bufferSize;
    uint16_t bufferPointer;
} ubx_parser_context_t;

UBX_PARSER_STATE* ubx_message_parser_recv_char(uint8_t c);

#define read16LE(buf, i) (buf[i] | (buf[i+1]<<8))


#endif