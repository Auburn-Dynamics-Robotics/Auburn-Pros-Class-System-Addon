#include "main.h"
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


  bool calibrating = true;

  
public:
  Inertia(pros::Imu a): i(a) {
    this->init();
    acc.convert_to_inches(i.get_accel());
    vel.integrate(acc, prev_vel, 0);
    pos.integrate(vel, prev_pos, 0);
  }

  void init() {
    i.reset();
    while(i.is_calibrating()) {
      pros::delay(2);
    }
    calibrating = false;
  }

  void update(int msDelay) {
    prev_accel=acc;
    prev_vel=vel;
    prev_pos=pos;

    acc.convert_to_inches(i.get_accel());
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

};
