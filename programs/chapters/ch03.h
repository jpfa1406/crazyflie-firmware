#include "mbed.h"
#include "crazyflie.h"
PwmOut motor3(MOTOR3);
int main()
{
    motor3.period(1.0/500.0);
    for(int i = 0; i<3; i++)
    {
        motor3 = 1;
        wait(5);
        motor3 = 0.0;
        wait(20);
    }
    while(true)
    {  
    }
}
