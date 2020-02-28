#include "main.h"

class acceleration {
public:
  float x_accel_inch=0;
  float y_accel_inch=0;
  float z_accel_inch=0;
  float conversion_constant = 386.0886;

  void convert_to_inches(pros::c::imu_accel_s_t a) {
    x_accel_inch = a.x*conversion_constant;
    y_accel_inch = a.y*conversion_constant;
    z_accel_inch = a.z*conversion_constant;
  }

};
