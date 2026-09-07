#ifndef BUTTONS_H
#define BUTTONS_H
#include <stdint.h>
#define BUTTON_EVENT_LEFT_RELEASE 1
#define BUTTON_EVENT_RIGHT_RELEASE 2
#define BUTTON_EVENT_BOTH_TAP 4
#define BUTTON_EVENT_BOTH_HOLD 8
#define BUTTON_STATE_LEFT_HELD 16
#define BUTTON_STATE_RIGHT_HELD 32
#define BUTTON_EVENT_ALL_RELEASED 64
/* tick is ISR-only; take consumes events and snapshots held states in one byte.
 * ALL_RELEASED is initially pending, then one-shot on release. A new press
 * cancels an unconsumed ALL_RELEASED so persistence cannot use a stale release. */
/* pressed bits: bit 0 = LEFT, bit 1 = RIGHT. */
void buttons_tick(uint8_t pressed);
uint8_t buttons_take(void);
#endif
