#ifndef MBED_H
#include "mbed.h"
#endif

#ifndef BLINK_H
#define BLINK_H

#include "board.h"
#include <stdlib.h>

#define BLINK_RATE_MS 500ms

void blink_loop(DigitalOut *led);

void blink(DigitalOut *led);

#endif