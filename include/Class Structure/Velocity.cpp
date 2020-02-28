#include "main.h"

class velocity {
public:
  float x_velocity=0;
  float y_velocity=0;
  float z_velocity=0;

  float x_c=0;
  float y_c=0;
  float z_c=0;

  std::string x_equation;
  std::string y_equation;
  std::string z_equation;

  void integrate(pros::c::imu_accel_s_t one, velocity prev, int ms) {

    x_c=prev.x_velocity;
    y_c=prev.y_velocity;
    z_c=prev.z_velocity;


    x_equation = std::to_string(one.x) + "X + " + std::to_string(x_c);
    y_equation = std::to_string(one.y) + "X + " + std::to_string(y_c);
    z_equation = std::to_string(one.z) + "X + " + std::to_string(z_c);

    x_velocity = (one.x*ms) + x_c;
    y_velocity = (one.y*ms) + y_c;
    z_velocity = (one.z*ms) + z_c;

  }

};
