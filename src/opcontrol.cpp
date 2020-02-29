#include "main.h"
#include "Class Structure/global.hpp"

void opcontrol() {
  while(true) {
    
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
      base.move(FORWARD, 100);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
      base.move(RIGHT, 100);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      base.move(BACKWARD, 100);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      base.move(LEFT, 100);
    } else {
      base.stop();
    }


    inertia.update(10);
    acceleration current_accel = inertia.get_acceleration();
    velocity current_vel = inertia.get_velocity();
    position current_pos = inertia.get_position();
    pros::c::imu_accel_s_t raw = inertia.raw_accel();


    pros::lcd::set_text(1, std::to_string(current_accel.x_accel_inch));
    pros::lcd::set_text(2, std::to_string(current_vel.x_velocity));
    pros::lcd::set_text(3, std::to_string(current_pos.x_displacement));
    pros::lcd::set_text(4, std::to_string(current_pos.x_pos));
    pros::lcd::set_text(5, std::to_string(raw.x));
    pros::delay(10);

  }
}
