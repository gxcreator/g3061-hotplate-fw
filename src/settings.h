#ifndef SETTINGS_H
#define SETTINGS_H
#include <stdint.h>

typedef enum { SET_TARGET, SET_KP, SET_KI, SET_KD, SET_MAX, SET_MIN, SET_MODE } Setting;
void settings_load(void);
uint16_t settings_get(Setting field);
void settings_edit(Setting field, int8_t direction);
/* Caller must pause realtime before committing and resume afterward. */
uint8_t settings_dirty(void);
void settings_commit(void);
#endif
