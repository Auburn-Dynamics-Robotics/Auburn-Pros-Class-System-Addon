#include "main.h"
#include "TYPES.h"
class acceleration {
public:

  float x_accel_inch=0;
  float y_accel_inch=0;
  float z_accel_inch=0;
  //float conversion_constant = 386.0886;
  float conversion_constant=386.0886;

  void convert_to_inches(pros::c::imu_accel_s_t a, pros::c::imu_accel_s_t b) {
    x_accel_inch = (a.x-b.x)*conversion_constant;
    y_accel_inch = (a.y-b.y)*conversion_constant;
    z_accel_inch = (a.z-b.y)*conversion_constant;
  }
  float get_axis(int axis) {
    if(axis == X_AXIS) {
      return x_accel_inch;
    } else if(axis == Y_AXIS) {
      return y_accel_inch;
    } else if(axis == Z_AXIS) {
      return z_accel_inch;
    } else {
      return INVALID_AXIS;
    }
  }
};
