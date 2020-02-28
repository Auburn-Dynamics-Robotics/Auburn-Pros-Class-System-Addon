#include "main.h"
#include "Base.cpp"
#ifndef GLOBALS
#define GLOBALS

extern std::string team_color, field_side, auton_type;
extern pros::Motor mot_1, mot_2, mot_3, mot_4, mot_5, mot_6, mot_7, mot_8;
extern pros::Imu inertia_sensor;

extern XDrive x_drive;
extern Train right_train, left_train, h_drive;
extern Base base;
extern Inertia inertia;
#endif
