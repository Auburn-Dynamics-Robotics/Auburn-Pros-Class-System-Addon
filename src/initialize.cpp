#include "apcsa.h"

pros::Motor mot_1(3);
pros::Motor mot_2(5);
pros::Motor mot_3(4);
pros::Motor mot_4(6);
pros::Motor mot_5(7);
pros::Imu inertia_sensor(15);
pros::Controller controller(pros::E_CONTROLLER_MASTER);

Train right_train(mot_1,mot_2,100,false);
Train left_train(mot_3,mot_4,100,false);
Train h_drive(mot_5,100,false);


Inertia inertia(inertia_sensor,0.2);

Base base(right_train,left_train,h_drive,inertia, X_AXIS, Z_AXIS, Y_AXIS);


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
  inertia.init();
  while(inertia.is_initializing()) {
    pros::delay(2);
  }
}
