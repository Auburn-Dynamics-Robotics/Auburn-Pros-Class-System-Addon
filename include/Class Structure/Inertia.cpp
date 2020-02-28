#include "main.h"
#include "Position.cpp"

class Inertia {
private:
    pros::Imu i;
    pros::c::imu_accel_s_t acc;
    velocity vel;
    position pos;

    pros::c::imu_accel_s_t prev_accel;
    velocity prev_vel;
    position prev_pos;

public:
  Inertia(pros::Imu a): i(a) {
    this->init();
  }
  void init() {
    i.reset();
    while(i.is_calibrating()) {
      pros::delay(2);
    }
  }

  pros::c::imu_accel_s_t get_acceleration() {
    prev_accel=acc;
    acc=i.get_accel();
    return acc;
  }

  velocity get_velocity(int msDelay) {
    prev_accel=acc;
    prev_vel=vel;

    acc=i.get_accel();
    vel.integrate(acc,prev_vel,msDelay);
    return vel;
  }

  position get_position(int msDelay) {
    prev_accel=acc;
    prev_vel=vel;
    prev_pos=pos;

    acc=i.get_accel();
    vel.integrate(acc, prev_vel,msDelay);
    pos.integrate(vel, prev_pos, msDelay);
    return pos;
  }

};
