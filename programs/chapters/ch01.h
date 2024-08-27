#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
//DigitalOut led(LED_BLUE_L,!false);
//DigitalOut ledr(LED_RED_L,!false);

//PwmOut motor(MOTOR1);
//PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
//PwmOut motor4(MOTOR4);

// Define all motors as PWM objects

// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)
    
    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)
    
    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program


    motor3 = 0.1;
    wait(5);
    motor3 = 0.0;

    while(true)
    {
//        led = !led;
//        wait(0.5);  
//        ledr = ledr;

//        motor = 0.2;
 //       motor2 = 0.2;
//        motor3 = 0.2;
 //       motor4 = 0.2;
//        wait(5);


//        motor = 0.0;
//        motor3 = 0.0;
//        motor3 = 0.0;
//        motor4 = 0.0;
            
      
    }
}
