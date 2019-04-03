#include <wiringPi.h>

#define ON 1
#define OFF 0

#define RED 2
#define GREEN 3

const int LedRed[8] = {4, 17, 18, 27, 22, 23, 24, 25};
const int LedGreen[8] = {6, 12, 13, 16, 19, 20, 26, 21};

void LEDControl(int color){
    int i;
    if(color==RED){
        for(i=0;i<8;i++){
            digitalWrite(LedRed[i], ON);
            digitalWrite(LedGreen[i], OFF);
        }
    }
    if(color==GREEN){
        for(i=0;i<8;i++){
            digitalWrite(LedRed[i], OFF);
            digitalWrite(LedGreen[i], ON);
        }
    }
}

int main(void){
    int i;

    if(wiringPiSetupGpio()==-1)
        return 1;

    for(i=0;i<8;i++){
        pinMode(LedRed[i], OUTPUT);
        pinMode(LedGreen[i], OUTPUT);

        digitalWrite(LedRed[i], OFF);
        digitalWrite(LedGreen[i], OFF);
    }

    while(1){
        LEDControl(RED);
        delay(500);
        LEDControl(GREEN);
        delay(500);
    }

    return 0;
}
