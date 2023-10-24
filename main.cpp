#include "mbed.h"
#include "board.h"
#include "blink.h"
#include "LCD_DISCO_F469NI.h"
#include "stm32469i_discovery_lcd.h"
#include "LCD_functions.h"




LCD_DISCO_F469NI lcd;

DigitalOut led1(LED1);
DigitalIn btn(BUTTON1);



Thread blink_thread;
Thread LCD_thread;

// main() runs in its own thread in the OS


void init(){
    lcd.Clear(LCD_COLOR_BLACK);
    blink_thread.start(callback(blink_loop,&led1));
    LCD_thread.start(callback(LCD_text,&lcd));
}

void exit(){

}

int main()
{
    init();
    bool run = true;
    while (run) {
        button_react(&btn,&lcd);
    }
    exit();
}

