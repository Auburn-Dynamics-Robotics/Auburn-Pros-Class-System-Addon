#include "main.h"
#include "Class Structure/global.hpp"

void opcontrol() {
  position total_position;
  inertia.init();
  while(inertia.is_initializing()) {
    pros::delay(20);
  }
  while(true) {
    inertia.update(10);
    acceleration current_accel = inertia.get_acceleration();
    velocity current_vel = inertia.get_velocity();
    position current_pos = inertia.get_position();
    pros::c::imu_accel_s_t raw = inertia.raw_accel();

    total_position.add_position(current_pos);

    pros::lcd::set_text(1, std::to_string(current_accel.x_accel_inch));
    pros::lcd::set_text(2, std::to_string(current_vel.x_velocity));
    pros::lcd::set_text(3, std::to_string(current_pos.x_pos));
    pros::lcd::set_text(4, std::to_string(total_position.x_pos));
    pros::lcd::set_text(5, std::to_string(raw.x));
    pros::delay(10);

  }
}
