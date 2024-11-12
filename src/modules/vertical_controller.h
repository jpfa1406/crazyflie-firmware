#ifndef VERTICAL_CONTROLLER_H
#define VERTICAL_CONTROLLER_H

#include "mbed.h"
#include "crazyflie.h"

// Vertical controller class
class VerticalController {
public:
    // Class constructor
    VerticalController();
    
    // Control total thrust force (N) given reference vertical position (m),
    // current vertical position (m), and velocity (m/s)
    void control(float z_r, float z, float w);
    
    // Total thrust force (N)
    float f_t;

private:
    // Control acceleration given reference position (m), current position (m),
    // and velocity (m/s) with given controller gains
    float control_siso(float pos_r, float pos, float vel, float kp, float kd);
};

#endif
