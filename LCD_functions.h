#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

#define TEXT_CHANGE_SPEED 500ms
#define BUTTON_TIMEOUT 2s
#define LCD_timeout 200ms

#ifndef MBED_H
#include "mbed.h"
#endif

#ifndef __LCD_DISCO_F469NI_H
#include "LCD_DISCO_F469NI.h"
#endif

void LCD_text(LCD_DISCO_F469NI *lcd);

void button_react(DigitalIn *button,LCD_DISCO_F469NI *lcd);

#endif
