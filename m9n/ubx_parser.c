#include <xc.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "ubx_parser.h"

/*
ubx parser

after init, bytes are feed into ubx_parser_feed() for updating the context.
The function will return either UBX_PARSER_CONTINUE for continued update,
or UBX_PARSER_NEW_MESSAGE when a new message is received.

If a new message is received, user should proceed it and call init() again.
Otherwise updating on the context with following bytes will result in these
new bytes be discarded, and the state machine still paused.
*/

void ubx_parser_reset_context(ubx_parser_context_t* context){
    context->state = UBX_PARSER_START;
    context->bufferSize = 0;
    context->bufferPointer = 0;
}


void ubx_parser_init(ubx_parser_context_t* context){
    ubx_parser_reset_context(context);
}

void __ubx_parser_update_checksum(ubx_parser_context_t* context, uint8_t byte){
    context->INTERNAL_CK_A += byte;
    context->INTERNAL_CK_B += context->INTERNAL_CK_A;
}

ubx_parser_result_t ubx_parser_feed(
    ubx_parser_context_t* context,
    uint8_t byte
){
    if(0xFF == byte){
        // invalid byte, cannot appear
        ubx_parser_reset_context(context);
        return UBX_PARSER_CONTINUE;
    }

    switch(context->state){

    case UBX_PARSER_WAITING_CLS:
        context->state = UBX_PARSER_WAITING_MSGID;
        context->CLS = byte;
        __ubx_parser_update_checksum(context, byte);
        break;

    case UBX_PARSER_WAITING_MSGID:
        context->state = UBX_PARSER_WAITING_LEN0;
        context->MSGID = byte;
        __ubx_parser_update_checksum(context, byte);
        break;

    case UBX_PARSER_WAITING_LEN0:
        context->state = UBX_PARSER_WAITING_LEN1;
        context->bufferSize = byte;
        __ubx_parser_update_checksum(context, byte);
        break;

    case UBX_PARSER_WAITING_LEN1:
        context->state = UBX_PARSER_BUFFERING;
        context->bufferPointer = 0;
        context->bufferSize += (byte << 8);
        __ubx_parser_update_checksum(context, byte);
        if(context->bufferSize > UBX_PARSER_BUFFER_SIZE){
            ubx_parser_reset_context(context);
        }
        break;

    case UBX_PARSER_BUFFERING:
        __ubx_parser_update_checksum(context, byte);
        context->buffer[context->bufferPointer] = byte;
        context->bufferPointer++;
        if(context->bufferPointer >= context->bufferSize){
            // after storing this byte, full length is received
            context->state = UBX_PARSER_WAITING_CK_A;
        }
        break;

    case UBX_PARSER_WAITING_CK_A:
        context->state = UBX_PARSER_WAITING_CK_B;
        context->EXTERNAL_CK_A = byte;
        break;

    case UBX_PARSER_WAITING_CK_B:
        context->EXTERNAL_CK_B = byte;

        if(
            context->EXTERNAL_CK_A == context->INTERNAL_CK_A &&
            context->EXTERNAL_CK_B == context->INTERNAL_CK_B
        ){
            context->state = UBX_PARSER_PAUSE;
            return UBX_PARSER_NEW_MESSAGE; // when checksum pass    
        }
        ubx_parser_reset_context(context);
        break;

    case UBX_PARSER_WAITING_SECOND_CHAR:
        if(0x62 == byte){
            context->state = UBX_PARSER_WAITING_CLS;
            // and reset checksum calc
            context->INTERNAL_CK_A = context->INTERNAL_CK_B = 0;
        } else {
            ubx_parser_reset_context(context);
        }
        break;

    case UBX_PARSER_PAUSE:
        return UBX_PARSER_NEW_MESSAGE;

    case UBX_PARSER_START:
    default:
        // state -> WAITING_SECOND_CHAR if byte is 0xb5
        if(0xb5 == byte){
            context->state = UBX_PARSER_WAITING_SECOND_CHAR;
        } else {
            ubx_parser_reset_context(context);
        }
    }
    return UBX_PARSER_CONTINUE;
}