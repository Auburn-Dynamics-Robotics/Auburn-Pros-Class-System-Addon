#include "main.h"
#include "TYPES.h"
class gyro {
private:
  float rate_x;
  float rate_y;
  float rate_z;

  float rotation_x;
  float rotation_y;
  float rotation_z;
public:
  void set(pros::c::imu_gyro_s_t g) {
    rate_x = g.x;
    rate_y = g.y;
    rate_z = g.z;
  }

  float get_rotation(int axis) {
    if(axis == Z_AXIS) {
      return rotation_z;
    } else if(axis == Y_AXIS) {
      return rotation_y;
    } else if(axis == Z_AXIS) {
      return rotation_x;
    } else {
      return INVALID_AXIS;
    }
  }

  void update(pros::c::imu_gyro_s_t g) {
    /*

      CODE TO UPDATE RATES AND ROTATIONS

    */
  }
};
