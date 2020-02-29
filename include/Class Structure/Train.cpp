#include "TYPES.h"

class Train {
private:
  pros::Motor fm;
  pros::Motor bm;
  pros::Motor mm;
  int ot;
  bool pl;

public:
  Train(pros::Motor a, int o, bool p): fm(a), bm(a), mm(a), ot(o), pl(p) {};
  Train(pros::Motor a, pros::Motor b, int o, bool p): fm(a), bm(b), mm(b), ot(o), pl(p) {};
  Train(pros::Motor a, pros::Motor b, pros::Motor m, int o, bool p): fm(a), bm(b), mm(m), ot(o), pl(p) {};
  void stop() {
      fm.move_velocity(0);
      bm.move_velocity(0);
  }


  void forward_rpm(int a) {
    fm.move_velocity(a);
    bm.move_velocity(a);
    mm.move_velocity(a);
  }


  void backward_rpm(int a) {
    fm.move_velocity(-a);
    bm.move_velocity(-a);
    mm.move_velocity(-a);
  }


  void forward_encoder(float dist, int r) {
    float toMove = dist*ot;
    fm.move_relative(toMove, r);
    bm.move_relative(toMove, r);
    mm.move_relative(toMove, r);

  }


  void backward_encoder(float dist, int r) {
    float toMove = -dist*ot;
    fm.move_relative(toMove, r);
    bm.move_relative(toMove, r);
    mm.move_relative(toMove, r);
  }


  int get_one_tile() {
    return ot;
  }

  bool is_stopped() {
    if(fm.is_stopped() && bm.is_stopped() && mm.is_stopped()) {
      return true;
    }
    return false;
  }

  void pause_until_moved() {
    while(!is_stopped()) {
      pros::delay(2);
    }
  }
};
