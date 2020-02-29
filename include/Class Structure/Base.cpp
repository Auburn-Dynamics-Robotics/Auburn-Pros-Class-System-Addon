#include "TYPES.h"
#include "Train.cpp"
#include "Inertia.cpp"

class Base {
private:
  Train rt = Train(pros::Motor(1),0,false);
  Train lt = Train(pros::Motor(1),0,false);
  Train hd = Train(pros::Motor(1),0,false);
  Inertia is = Inertia(pros::Imu(1),2);

  bool hasInertia=false;
  int type = 0;
  float current_pos;
  int forward_axis = Z_AXIS;

  void tfr(int a) {
    rt.forward_rpm(a);
    lt.forward_rpm(a);
  }
  void tbr(int a) {
    rt.backward_rpm(a);
    lt.backward_rpm(a);
  }

  void hrr(int a) {
    hd.forward_rpm(a);
  }
  void hlr(int a) {
    hd.backward_rpm(a);
  }

  void trr(int a) {
    rt.forward_rpm(a);
    lt.backward_rpm(a);
  }


  void tft(float a, int b) {
    rt.forward_encoder(a,b);
    lt.forward_encoder(a,b);
  }

  void tbt(float a, int b) {
    rt.backward_encoder(a,b);
    lt.forward_encoder(a,b);
  }

  void hrt(float a, int b) {
    hd.forward_encoder(a,b);
  }

  void hlt(float a, int b) {
    hd.backward_encoder(a,b);
  }

  void trt(int a, int b) {
    rt.forward_encoder(a,b);
    lt.backward_encoder(a, b);
  }


  void tfi(float inch, int b) {
    float dist = inch;

    position start = is.get_position();
    position moved=is.get_position();

    float net_moved = moved.x_pos-start.x_pos;
    if(forward_axis==Z_AXIS) {
      net_moved = moved.z_pos-start.z_pos;
    }

    rt.forward_rpm(b);
    lt.forward_rpm(b);

    while(net_moved < dist) {
      pros::delay(5);
      is.update(5);
      moved=is.get_position();
      net_moved = moved.x_pos-start.x_pos;
      if(forward_axis==Z_AXIS) {
        net_moved = moved.z_pos-start.z_pos;
      }
    }

    rt.stop();
    lt.stop();
  }



  void tbi(int inch, int b) {
    float dist = -inch;

    position start = is.get_position();
    position moved=is.get_position();

    float net_moved = moved.x_pos-start.x_pos;
    if(forward_axis ==Z_AXIS) {
      net_moved = moved.z_pos-start.z_pos;
    }

    rt.backward_rpm(b);
    lt.backward_rpm(b);

    while(net_moved > dist) {
      pros::delay(5);
      is.update(5);
      moved=is.get_position();
      net_moved = moved.x_pos-start.x_pos;
      if(forward_axis==Z_AXIS) {
        net_moved = moved.z_pos-start.z_pos;
      }
    }

    rt.stop();
    lt.stop();
  }

  void hri(int inch, int b) {
    float dist = inch;

    position start = is.get_position();
    position moved=is.get_position();

    float net_moved = moved.z_pos-start.z_pos;
    if(forward_axis ==Z_AXIS) {
      net_moved = moved.x_pos-start.x_pos;
    }

    hd.forward_rpm(b);

    while(net_moved < dist) {
      pros::delay(5);
      is.update(5);
      moved=is.get_position();
      net_moved = moved.z_pos-start.z_pos;
      if(forward_axis==Z_AXIS) {
        net_moved = moved.x_pos-start.x_pos;
      }
    }

    hd.stop();
  }

  void hli(int inch, int b) {
    float dist = -inch;

    position start = is.get_position();
    position moved= is.get_position();

    float net_moved = moved.z_pos-start.z_pos;
    if(forward_axis ==Z_AXIS) {
      net_moved = moved.x_pos-start.x_pos;
    }

    hd.backward_rpm(b);

    while(net_moved > dist) {
      pros::delay(5);
      is.update(5);
      moved=is.get_position();
      net_moved = moved.z_pos-start.z_pos;
      if(forward_axis==Z_AXIS) {
        net_moved = moved.x_pos-start.x_pos;
      }
    }

    hd.stop();

  }


  void tri(int dist, int b) {
    int one_tile = rt.get_one_tile();
    rt.forward_rpm(b);
    lt.backward_rpm(b);

    //Inertia will integrate position; wait until inertia has reached distance "dist"

    rt.stop();
    lt.stop();
  }



/*



PUBLIC FUNCTIONS



*/



public:

  Base(Train r, Train l): rt(r), lt(l) {
    type=2;
  }
  Base(Train r, Train l, Inertia s, int fw): rt(r), lt(l), is(s), forward_axis(fw) {
    type=2;
    hasInertia=true;
  }
  Base(Train r, Train l, Train h): rt(r), lt(l), hd(h) {
    type=3;
  }
  Base(Train r, Train l, Train h, Inertia s, int fw): rt(r), lt(l), hd(h), is(s), forward_axis(fw) {
    type=3;
    hasInertia=true;
  }





  void move(int direction, int rpm) {
    if(direction==FORWARD) {
      tfr(rpm);
    } else if(direction==BACKWARD) {
      tbr(rpm);
    } else if(direction==RIGHT && type==3) {
      hrr(rpm);
    } else if(direction==LEFT && type==3) {
      hlr(rpm);
    }
  }



  void move(int type, int direction, int distance, int units, int rpm) {
    if(units==TILES) {
      distance=distance*24;
    }

    if(type==INERTIA) {
      if(direction==FORWARD) {
        tfi(distance,rpm);
      } else if(direction==BACKWARD) {
        tbi(distance,rpm);
      } else if(direction==RIGHT && type==3) {
        hri(distance,rpm);
      } else if(direction==LEFT && type==3) {
        hli(distance,rpm);
      }
    } else if(type==ENCODER) {
      if(direction==FORWARD) {
        tft(distance,rpm);
      } else if(direction==BACKWARD) {
        tbt(distance,rpm);
      } else if(direction==RIGHT && type==3) {
        hrt(distance,rpm);
      } else if(direction==LEFT && type==3) {
        hlt(distance,rpm);
      }
    }
  }

  void turn_rpm(int rpm) {
      trr(rpm);
  }



  void turn_encoder(int degrees, int rpm) {
    trt(degrees,rpm);
  }


  void turn_inertia(int degrees, int rpm) {
    if(!hasInertia) {
      return;
    }
    tri(degrees, rpm);
  }


  void stop() {
    rt.stop();
    lt.stop();
    hd.stop();
  }


  bool is_stopped() {
    if(rt.is_stopped() && lt.is_stopped() && hd.is_stopped()) {
      return true;
    }
    return false;
  }
};
