#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

float control_motor(float omega){
    float PWM = a2*omega*omega + a1*omega; 
    return PWM;
}

int main()
{

    motor1.period(1.0/500.0);
    motor1 = control_motor(1000.0);

    motor2.period(1.0/500.0);
    motor2 = control_motor(2000.0);

    motor3.period(1.0/500.0);
    motor3 = control_motor(1000.0);

    motor4.period(1.0/500.0);
    motor4 = control_motor(2000.0);

    wait(2);

    motor1=0;
    motor2=0;
    motor3=0;
    motor4=0;
    
    while(true)
    { 
    }
}
