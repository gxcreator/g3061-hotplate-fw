#ifndef UI_H
#define UI_H
#include <stdint.h>
uint8_t ui_home(void);
void ui_input(uint8_t events);
void ui_render(uint8_t graph_tick);
void ui_fault(void);
#endif
