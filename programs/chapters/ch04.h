#include "mbed.h"
#include "crazyflie.h"

PwmOut motor3(MOTOR1);

float control_motor(float omega){
    float PWM = a2*omega*omega + a1*omega; 
    return PWM;
}

int main()
{
    motor3.period(1.0/500.0);
    motor3 = control_motor(1000.0);
    wait(5);
    motor3 = 0;
    while(true)
    { 
    }
}
