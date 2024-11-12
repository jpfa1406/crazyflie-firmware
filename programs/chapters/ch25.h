#include "mbed.h"
#include "crazyflie.h"
#include "attitude_estimator.h"
#include "attitude_controller.h"
#include "vertical_estimator.h"
#include "vertical_controller.h"
#include "horizontal_estimator.h"
#include "horizontal_controller.h"



// Crazyflie controller objects
Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;
VerticalEstimator ver_est;
VerticalController ver_cont;
HorizontalEstimator hor_est;
HorizontalController hor_cont;

// Ticker objects
Ticker tic, tic_range;
Timer _timer;

// Interrupt flag and counter variables
bool flag, flag_range;

// Callback functions
void callback() { 
    flag = true; 
}

void callback_range() { 
    flag_range = true; 
}

// Main program
int main() {
    // Set references
    float z_r = 0.0;
    float x_r = 0.0;
    float y_r = 0.0;
    float psi_r = 0.0;

    float td = 3.0;
    float tv = 3.0;
    float tp = 3.0;
    float h = 1.0;
    float d = 3.0;

    // Initialize estimator objects
    att_est.init();
    ver_est.init();
    hor_est.init();

    // Initialize interrupts
    tic.attach(&callback, dt);
    tic_range.attach(&callback_range, dt_range);

    float time = 0.0;
    float flight = 10.0;
    _timer.start();

    // Arm motors and run controller while stable
    mixer.arm();
    while ((abs(att_est.phi) <= pi / 4.0 && 
           abs(att_est.theta) <= pi / 4.0 && 
           abs(att_est.p) <= 4.0 * pi && 
           abs(att_est.q) <= 4.0 * pi && 
           abs(att_est.r) <= 4.0 * pi) && time < flight + 1) 
    {
        if (flag) {
            flag = false;
            time = _timer.read();
            if (time < td) {
                z_r = h*time/td;
                x_r=0;
            }
            else if (time < tv + td) {
                z_r = h;
                x_r = d*(time - td)/tv;
            }
            else {
                z_r = - h*(time-td-tv-tp)/tp;
            };
            att_est.estimate();
            ver_est.predict(ver_cont.f_t);

            if (flag_range) {
                flag_range = false;
                ver_est.correct(att_est.phi, att_est.theta);
            }

            hor_est.predict(att_est.phi, att_est.theta);

            if (ver_est.z >= 0.05) {
                hor_est.correct(att_est.phi, att_est.theta, att_est.p, att_est.q, ver_est.z);
                hor_cont.control(x_r, y_r, hor_est.x, hor_est.y, hor_est.u, hor_est.v);
            }

            ver_cont.control(z_r, ver_est.z, ver_est.w);
            att_cont.control(hor_cont.phi_r, hor_cont.theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi, att_est.p, att_est.q, att_est.r);

            mixer.actuate(ver_cont.f_t / (cos(att_est.phi) * cos(att_est.theta)), att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);
        }
    }

    // Disarm motors and end program
    mixer.disarm();
    while (true);
}
