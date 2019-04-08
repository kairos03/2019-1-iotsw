#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#define MOTOR_MT_N_PIN 17
#define MOTOR_MT_P_PIN 4 

#define LEFT_ROTATE 1
#define RIGHT_ROTATE 2

void MotorStop(){
    softPwmWrite(MOTOR_MT_P_PIN, 0);
    softPwmWrite(MOTOR_MT_N_PIN, 0);
}

void MotorControl(int speed) {
    digitalWrite(MOTOR_MT_P_PIN, LOW);
    softPwmWrite(MOTOR_MT_N_PIN, speed);
}

int main(){
    if(wiringPiSetupGpio() == -1)
        return -1;
    
    pinMode(MOTOR_MT_N_PIN, OUTPUT);
    pinMode(MOTOR_MT_P_PIN, OUTPUT);

    softPwmCreate(MOTOR_MT_N_PIN, 0, 100);
    softPwmCreate(MOTOR_MT_P_PIN, 0, 100);

    while(1){
        printf("25\n");
        MotorControl(25);
        delay(2000);
        MotorStop();
        delay(2000);

        printf("50\n");
        MotorControl(50);
        delay(2000);
        MotorStop();
        delay(2000);

        printf("75\n");
        MotorControl(75);
        delay(2000);
        MotorStop();
        delay(2000);
    }
    return 0;
}

