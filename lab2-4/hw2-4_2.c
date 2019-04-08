#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define LED_PIN 4

int main(){
    if(wiringPiSetupGpio() == -1)
        return -1;
    
    pinMode(LED_PIN, OUTPUT);

    softPwmCreate(LED_PIN, 0, 128);

    int i;
    while(1){
        for(i=0; i <128; i++){
            softPwmWrite(LED_PIN, i);
            delay(10);
        }
        for(i=128; i >=0; i--){
            softPwmWrite(LED_PIN, i);
            delay(10);
        }

    }
    return 0;
}

