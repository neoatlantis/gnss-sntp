#ifndef _INTERRUPTS
#define _INTERRUPTS

#include <xc.h>

#define INTERRUPT_IRQ_INT1      8
#define INTERRUPT_IRQ_INT2      13
#define INTERRUPT_IRQ_T1        4


#define interrupts_general_enable       __builtin_enable_interrupts()
#define interrupts_general_disable      __builtin_disable_interrupts()

void interrupt_enable_int1(void);
void interrupt_disable_int1(void);
extern void interrupt_isr_int1(void);

#endif