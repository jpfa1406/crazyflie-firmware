
#include "crazyflie.h"
#include "mbed.h"

// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

// Define angular velocities ( rad / s )
float omega_1;
float omega_2;
float omega_3;
float omega_4;

// Converts desired angular velocity ( rad / s ) to PWM signal (%)
float control_motor(float omega){
    float PWM = a2*omega*omega + a1*omega; 
    return PWM;
}

// Converts total trust force ( N ) and torques ( N . m ) to angular velocities
// ( rad / s )
void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) { //omega_1
    omega_1 = (1/(4*kl))*f_t - (1/(4*kl*l))*tau_phi - (1/(4*kl*l))*tau_theta - (1/(4*kd))*tau_psi;
    if (omega_1 < 0){
        omega_1 = 0.0;
    }
    else {
        omega_1 = sqrt(omega_1);
    }

    //omega_2
    omega_2 = (1/(4*kl))*f_t - (1/(4*kl*l))*tau_phi + (1/(4*kl*l))*tau_theta + (1/(4*kd))*tau_psi;
    if (omega_2 < 0){
        omega_2 = 0.0;
    }
    else {
        omega_2 = sqrt(omega_2);
    }

    //omega_3
    omega_3 = (1/(4*kl))*f_t + (1/(4*kl*l))*tau_phi + (1/(4*kl*l))*tau_theta - (1/(4*kd))*tau_psi;
    if (omega_3 < 0){
        omega_3 = 0.0;
    }
    else {
        omega_3 = sqrt(omega_3);
    }

    //omega_4
    omega_4 = (1/(4*kl))*f_t + (1/(4*kl*l))*tau_phi - (1/(4*kl*l))*tau_theta + (1/(4*kd))*tau_psi;
    if (omega_4 < 0){
        omega_4 = 0.0;
    }
    else {
        omega_4= sqrt(omega_4);
    }
}

// Actuate motors with desired total trust force ( N ) and torques ( N . m )
void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  mixer(f_t, tau_phi, tau_theta, tau_psi);
  motor_1 = control_motor(omega_1);
  motor_2 = control_motor(omega_2);
  motor_3 = control_motor(omega_3);
  motor_4 = control_motor(omega_4);
}

// Main program
int main() {
  // Set all PWM frequencies to 500 Hz
  motor_1.period(1.0 / 500.0);
  motor_2.period(1.0 / 500.0);
  motor_3.period(1.0 / 500.0);
  motor_4.period(1.0 / 500.0);
  // Actuate motor with 50% mg total thrust force ( N ) and zero torques ( N . m
  // )
  actuate(0.15, 0, 0, -0.001);
  wait(5);
  // Turn off all motors
  actuate(0, 0, 0, 0);
  // End of program
  while (true) {
  }
}
