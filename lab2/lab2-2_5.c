#include <wiringPi.h>

#define ON 1
#define OFF 0

const int Led[16] = {
    4, 17, 18, 27, 22, 23, 24, 25,
    6, 12, 13, 16, 19, 20, 26, 21
};

void LEDControl(int pinnum){
    int i;
    for(i=0;i<16;i++){
        if(i==pinnum){
            digitalWrite(Led[i], ON);
            digitalWrite(Led[i+1], ON);
            i++;
        }
        else
            digitalWrite(Led[i], OFF);

    }
}

int main(void){
    int i;

    if(wiringPiSetupGpio()==-1)
        return 1;

    for(i=0;i<16;i++){
        pinMode(Led[i], OUTPUT);
        digitalWrite(Led[i], OFF);
    }
    
    while(1){
        for(i=0;i<16;i+=2){
            LEDControl(i);
            delay(500);
        }
    }

    return 0;
}
