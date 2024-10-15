#include "attitude_estimator.h"
#include <cmath>

// Class constructor
AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) { 
    phi, theta, psi = 0.0;
    p, q, r = 0;
    pb, qb, rb = 0;
 }
// Initialize class
void AttitudeEstimator::init() { 
    imu.init();
    for(int i=0; i<500; i++){
        imu.read();
        pb += imu.gx/500.0;
        qb += imu.gy/500.0;
        rb += imu.gz/500.0;
        wait(dt);
    }
 }

// Estimate Euler angles ( rad ) and angular velocities ( rad / s )
void AttitudeEstimator::estimate() { 
    imu.read();
    p = imu.gx - pb;
    q = imu.gy - qb;
    r = imu.gz - rb;

    float phi_g = phi+(p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
    float theta_g = theta+(cos(theta)*q-sin(phi)*r)*dt;
    float psi_g = psi+(sin(phi)*(1/cos(theta))*q+cos(phi)*(1/cos(theta))*r)*dt;

    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2(imu.ax,-((imu.az>0)-(imu.az<0))*sqrt(imu.ay*imu.ay + imu.az*imu.az));

    phi = (1-a)*phi_g + a*phi_a;
    theta = (1-a)*theta_g + a*theta_a;
    psi = psi_g;
 }
