#include "main.h"

class XDrive {
  /*

  */
private:
  pros::Motor a;
  pros::Motor b;
  pros::Motor c;
  pros::Motor d;

  int ot;

public:

  XDrive(pros::Motor front_left, pros::Motor front_right, pros::Motor back_left, pros::Motor back_right, int o): a(front_left), b(front_right), c(back_left), d(back_right), ot(o) {};


  void stop() {
      a.move_velocity(0);
      b.move_velocity(0);
      c.move_velocity(0);
      d.move_velocity(0);
  }


  void forward_rpm(int q) {
    a.move_velocity(q);
    b.move_velocity(q);
    c.move_velocity(q);
    d.move_velocity(q);
  }

  void back_rpm(int q) {
    a.move_velocity(-q);
    b.move_velocity(-q);
    c.move_velocity(-q);
    d.move_velocity(-q);
  }

  void right_rpm(int q) {
    a.move_velocity(q);
    b.move_velocity(-q);
    c.move_velocity(-q);
    d.move_velocity(q);
  }

  void left_rpm(int q) {
    a.move_velocity(-q);
    b.move_velocity(q);
    c.move_velocity(q);
    d.move_velocity(-q);
  }

  void turn_rpm(int dir, int q) {
    a.move(dir*q);
    b.move(dir*-q);
    c.move(dir*q);
    d.move(dir*-q);
  }

  void forward_encoder(float dist, int r) {

  }

  void backward_encoder(float dist, int r) {

  }

  void left_encoder(float dist, int r) {

  }

  void right_encoder(float dist, int r) {

  }

  void turn_encoder(int deg, int r) {

  }


  void forward_inertia(float dist, int r) {

  }

  void backward_inertia(float dist, int r) {

  }

  void left_inertia(float dist, int r) {

  }

  void right_inertia(float dist, int r) {

  }

  void turn_inertia(int deg, int r) {

  }

};
