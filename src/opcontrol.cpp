#include "main.h"
#include "Class Structure/global.hpp"

void opcontrol() {
  position total_position;
  while(true) {
    inertia.update(10);
    acceleration current_accel = inertia.get_acceleration();
    velocity current_vel = inertia.get_velocity();
    position current_pos = inertia.get_position();

    total_position.add_position(current_pos);

    pros::lcd::set_text(1, "Acceleration X: " + std::to_string(current_accel.x_accel_inch));
    pros::lcd::set_text(2, "Velocity X: " + std::to_string(current_vel.x_velocity));
    pros::lcd::set_text(3, "Position Change X: " + std::to_string(current_pos.x_pos));
    pros::lcd::set_text(4, "Position Current X: " + std::to_string(total_position.x_pos));
    pros::delay(10);

  }
}
