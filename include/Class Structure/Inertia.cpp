#include "TYPES.h"
#include "Position.cpp"

class Inertia {
private:
    pros::Imu i;

    acceleration acc;
    velocity vel;
    position pos;

    acceleration prev_accel;
    velocity prev_vel;
    position prev_pos;

    float g_to_inch = 386.0886;
    pros::c::imu_accel_s_t initial_value;

    float acceleration_threshold;

    bool calibrating = true;


public:
  Inertia(pros::Imu a, float it): i(a), acceleration_threshold(it) {
  }

  void init() {
    i.reset();
    while(i.is_calibrating()) {
      pros::delay(2);
    }
    initial_value = i.get_accel();
    initial_value.x = floor((initial_value.x*10)+0.5)/10;
    initial_value.y = floor((initial_value.y*10)+0.5)/10;
    initial_value.z = floor((initial_value.z*10)+0.5)/10;
    pros::c::imu_accel_s_t abc = i.get_accel();
    abc.x = floor((abc.x*10)+0.5)/10;
    abc.y = floor((abc.y*10)+0.5)/10;
    abc.z = floor((abc.z*10)+0.5)/10;
    acc.convert_to_inches(abc,initial_value);
    vel.integrate(acc, prev_vel, 0);
    pos.integrate(vel, prev_pos, 0);
    calibrating = false;
  }

  bool is_initializing() {
    if(i.is_calibrating()) {
      return true;
    }
    return false;
  }
  void update(int msDelay) {
    prev_accel=acc;
    prev_vel=vel;
    prev_pos=pos;
    pros::c::imu_accel_s_t cr = i.get_accel();
    cr.x = floor((cr.x*10)+0.5)/10;
    cr.y = floor((cr.y*10)+0.5)/10;
    cr.z = floor((cr.z*10)+0.5)/10;

    if(cr.x < acceleration_threshold || cr.x > -acceleration_threshold) {
      cr.x=0;
    }
    if(cr.y < acceleration_threshold || cr.y > -acceleration_threshold) {
      cr.y=0;
    }
    if(cr.z < acceleration_threshold || cr.z > -acceleration_threshold) {
      cr.z=0;
    }
    acc.convert_to_inches(cr,initial_value);
    vel.integrate(acc, prev_vel,msDelay);
    pos.integrate(vel, prev_pos, msDelay);
  }

  acceleration get_acceleration() {
    //update(msDelay);
    return acc;
  }

  velocity get_velocity() {
    //update(msDelay);
    return vel;
  }

  position get_position() {
    //update(msDelay);
    return pos;
  }

  pros::c::imu_accel_s_t raw_accel() {
    return i.get_accel();
  }
};
