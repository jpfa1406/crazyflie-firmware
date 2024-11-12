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

const float Ts_phi = 0.3;
const float OS_phi = 0.005;
const float z_phi = abs( log(OS_phi))/sqrt( pow(log(OS_phi), 2) + pow(pi, 2) );
const float Wn_phi = 4.0/(z_phi*Ts_phi);
const float kp_phi = pow(Wn_phi, 2);
const float kd_phi = 2.0*z_phi*Wn_phi;

const float kp_theta = kp_phi;
const float kd_theta = kd_phi;


const float Ts_psi = 0.6;
const float OS_psi = 0.005;
const float z_psi = abs( log(OS_psi))/sqrt( pow(log(OS_psi), 2) + pow(pi, 2) );
const float Wn_psi = 4.0/(z_psi*Ts_psi);
const float kp_psi = pow(Wn_psi, 2);
const float kd_psi = 2.0*z_psi*Wn_psi;

const float dt_range = 0.05;
const float wc_range = 10.0;
const float l1 = wc_range*wc_range;
const float zeta = sqrt(2)/2;
const float l2 = 2*zeta*wc_range;


const float Ts_ver = 2.0;
const float OS_ver = 0.5/100.0;
const float zeta_ver = abs(log(OS_ver))/sqrt(pow(log(OS_ver),2)+pow(pi,2));
const float wn_ver = 4.0/(zeta_ver*Ts_ver);
const float kp_vertical = 2.0*zeta_ver*wn_ver;
const float kd_vertical = pow(wn_ver,2);

const float gamma = 42.0*(pi/180.0);
const float rho = 2.0*tan(gamma/2.0)/(420*dt);
const float l_h = 50.0;
const float wc_horizontal = 50.0;

const float Ts_hor = 2.0;
const float OS_hor = 0.5/100.0;
const float zeta_hor = abs(log(OS_hor))/sqrt(pow(log(OS_hor),2)+pow(pi,2));
const float wn_hor = 4.0/(zeta_hor*Ts_hor);
const float kp_horizontal = 2.0*zeta_hor*wn_hor;
const float kd_horizontal = pow(wn_hor,2);


#endif