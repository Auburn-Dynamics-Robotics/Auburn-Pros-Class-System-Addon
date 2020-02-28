#include "main.h"
#include "Class Structure/global.hpp"

pros::Imu inertia_sensor(15);
Inertia inertia(inertia_sensor);

void left_button_press() {

}

void center_button_press() {

}

void right_button_press() {

}

void initialize() {
  pros::lcd::initialize();
  while(!pros::lcd::is_initialized()) {
    pros::delay(2);
  }
}
