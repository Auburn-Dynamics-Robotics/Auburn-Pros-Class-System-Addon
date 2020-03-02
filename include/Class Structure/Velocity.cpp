#include "TYPES.h"
#include "Acceleration.cpp"

class velocity {
public:
  float x_velocity=0;
  float y_velocity=0;
  float z_velocity=0;


  std::string x_equation;
  std::string y_equation;
  std::string z_equation;

  void integrate(acceleration one, velocity prev, float ms) {
    float seconds = ms/1000;

    x_equation = std::to_string(one.x_accel_inch) + "X + " + std::to_string(prev.x_velocity);
    y_equation = std::to_string(one.y_accel_inch) + "X + " + std::to_string(prev.y_velocity);
    z_equation = std::to_string(one.z_accel_inch) + "X + " + std::to_string(prev.z_velocity);

    x_velocity = (one.x_accel_inch*ms) + prev.x_velocity;
    y_velocity = (one.y_accel_inch*ms) + prev.y_velocity;
    z_velocity = (one.z_accel_inch*ms) + prev.z_velocity;

  }

  float get_axis(int axis) {
    if(axis == X_AXIS) {
      return x_velocity;
    } else if(axis == Y_AXIS) {
      return y_velocity;
    } else if(axis == Z_AXIS) {
      return z_velocity;
    } else {
      return INVALID_AXIS;
    }
  }
};
