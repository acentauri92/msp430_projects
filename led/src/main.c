#include "led.h"

int main(void){
    volatile unsigned int i = 0;

    WDTCTL = WDTPW + WDTHOLD;

    ledInit();

    while(1){
        ledToggle();
        for(i = 10000; i > 0; i++){
            ;
        }
    }
}