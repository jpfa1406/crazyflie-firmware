#include "vertical_controller.h"

// Class constructor
VerticalController::VerticalController() {
    f_t = 0;
}

// Control thrust force (N) given vertical position (m) and velocity (m/s)
void VerticalController::control(float z_r, float z, float w) {
    float z_rl =  control_siso(z_r, z, w, kp_vertical, kd_vertical);
    f_t = m*(g+z_rl);
}

// Control acceleration given reference position (m), current position (m),
// and velocity (m/s) with given controller gains
float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd) {
    float result = kp * (pos_r - pos) + kd * (0 - vel);
    return result;
}
