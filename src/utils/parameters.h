#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

const float a2 = 1.076e-07;
const float a1 = 7.081e-12;

const float kl = 1.468e-8;

const float kd = 1.267e-10;

const float dt = 0.002;
const float wc = 1.0; //Rad/s
const float a = (wc*dt)/(1+wc*dt);


#endif