#include "horizontal_controller.h"

// Class constructor
HorizontalController::HorizontalController() {
    theta_r, phi_r = 0.0;
}

// Control reference roll and pitch angles (rad) given reference positions (m),
// current positions (m), and velocities (m/s)
void HorizontalController::control(float x_r, float y_r, float x, float y, float u, float v) {
    float x_rl = control_siso(x_r, x, u, kp_horizontal, kd_horizontal);
    float y_rl = control_siso(y_r, y, v, kp_horizontal, kd_horizontal);

    theta_r = x_rl/g;
    phi_r = -y_rl/g;
}

// Control acceleration given reference position (m), current position (m),
// and velocity (m/s) with given controller gains
float HorizontalController::control_siso(float pos_r, float pos, float vel, float kp, float kd) {
    float x_rl = kp*(pos_r - pos) + kd*(0.0 - vel);
    return x_rl;
}
