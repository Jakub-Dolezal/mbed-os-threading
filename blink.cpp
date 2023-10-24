#ifndef MBED_H
#include "mbed.h"
#endif

#include "blink.h"

void blink_loop(DigitalOut *led){
    while(true){
        blink(led);
    }
}

void blink(DigitalOut *led){
    *led = LED_ON;
    ThisThread::sleep_for(BLINK_RATE_MS);
    *led = LED_OFF;
    ThisThread::sleep_for(BLINK_RATE_MS);
}