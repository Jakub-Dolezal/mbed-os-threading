#include "LCD_functions.h"

Mutex LCD_lock;

void LCD_text(LCD_DISCO_F469NI *lcd){
    while(true){
        LCD_lock.lock();
        (*lcd).SetBackColor(LCD_COLOR_BLACK);
        (*lcd).SetTextColor(LCD_COLOR_WHITE);
        (*lcd).DisplayStringAt(0, LINE(1), (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
        ThisThread::sleep_for(LCD_timeout);
        LCD_lock.unlock();

        ThisThread::sleep_for(TEXT_CHANGE_SPEED);

        LCD_lock.lock();
        (*lcd).SetBackColor(LCD_COLOR_WHITE);
        (*lcd).SetTextColor(LCD_COLOR_BLACK);
        (*lcd).DisplayStringAt(0, LINE(1), (uint8_t *)"MBED EXAMPLE", CENTER_MODE);
        ThisThread::sleep_for(LCD_timeout);
        LCD_lock.unlock();

        ThisThread::sleep_for(TEXT_CHANGE_SPEED);
    }
}

void button_react(DigitalIn *button,LCD_DISCO_F469NI *lcd){
    if((*button).read()){
        LCD_lock.lock();
        (*lcd).SetBackColor(LCD_COLOR_RED);
        (*lcd).SetTextColor(LCD_COLOR_BLACK);
        (*lcd).DisplayStringAt(0, LINE(2), (uint8_t *)"TLACITKO!", CENTER_MODE);
        LCD_lock.unlock();

        ThisThread::sleep_for(BUTTON_TIMEOUT);

        LCD_lock.lock();
        (*lcd).Clear(LCD_COLOR_BLACK);
        ThisThread::sleep_for(LCD_timeout);
        LCD_lock.unlock();
    }
}
