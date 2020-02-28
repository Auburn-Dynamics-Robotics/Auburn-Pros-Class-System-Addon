#include "main.h"

class Train {
private:
  pros::Motor fm;
  pros::Motor bm;
  int ot;

public:
  Train(pros::Motor a, int o): fm(a), bm(a), ot(o) {};
  Train(pros::Motor a, pros::Motor b, int o): fm(a), bm(b), ot(o) {};


  void stop() {
      fm.move_velocity(0);
      bm.move_velocity(0);
  }


  void forward_rpm(int a) {
    fm.move_velocity(a);
    bm.move_velocity(a);
  }


  void backward_rpm(int a) {
    fm.move_velocity(-a);
    bm.move_velocity(-a);
  }


  void forward_encoder(float dist, int r) {

  }

  void backward_encoder(float dist, int r) {

  }

  int get_one_tile() {
    return ot;
  }
};
