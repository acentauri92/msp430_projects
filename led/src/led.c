#include "led.h"

void ledInit(void){
    P1DIR |= 0x01;
}

void ledToggle(void){
    P1OUT ^= 0x01;
}