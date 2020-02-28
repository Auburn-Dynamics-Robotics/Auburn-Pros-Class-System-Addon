#include "main.h"
#include "X-Drive.cpp"
#include "Train.cpp"
#include "Inertia.cpp"

class Base {
private:
  Train rt = Train(pros::Motor(1),pros::Motor(1),0);
  Train lt = Train(pros::Motor(1),pros::Motor(1),0);
  Train hd = Train(pros::Motor(1),pros::Motor(1),0);
  Inertia is = pros::Imu(1);

  bool hasInertia=false;
  int type = 0;
  float current_pos;


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


  void tfi(int dist, int b) {
    int one_tile = rt.get_one_tile();
    rt.forward_rpm(b);
    lt.forward_rpm(b);

    //Inertia will integrate position; wait until inertia has reached distance "dist"

    rt.stop();
    lt.stop();
  }

  void tbi(int dist, int b) {
    int one_tile = rt.get_one_tile();
    rt.forward_rpm(b);
    lt.forward_rpm(b);

    //Inertia will integrate position; wait until inertia has reached distance "dist"

    rt.stop();
    lt.stop();
  }

  void hri(int dist, int b) {
    int one_tile = hd.get_one_tile();
    hd.forward_rpm(b);

    //Inertia will integrate position; wait until inertia has reached distance "dist"

    hd.stop();
  }

  void hli(int dist, int b) {
    int one_tile = hd.get_one_tile();
    hd.backward_rpm(b);

    //Inertia will integrate position; wait until inertia has reached distance "dist"

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

public:
  Base(Train r, Train l): rt(r), lt(l) {
    type=2;
  };
  Base(Train r, Train l, Inertia s): rt(r), lt(l), is(s) {
    type=2;
    hasInertia=true;
  };
  Base(Train r, Train l, Train h): rt(r), lt(l), hd(h) {
    type=3;
  };
  Base(Train r, Train l, Train h, Inertia s): rt(r), lt(l), hd(h), is(s) {
    type=3;
    hasInertia=true;
  };

  void forward_rpm(int rpm) {
      tfr(rpm);
  }

  void backward_rpm(int rpm) {
      tbr(rpm);
  }


  void right_rpm(int rpm) {
    if(type==3) {
      hrr(rpm);
    }
  }

  void left_rpm(int rpm) {
    if(type==3) {
      hlr(rpm);
    }
  }

  void turn_rpm(int rpm) {
      trr(rpm);
  }


  void forward_encoder(float tiles, int rpm) {
      tft(tiles,rpm);
  }

  void backward_encoder(float tiles, int rpm) {
      tbt(tiles,rpm);
  }

  void left_encoder(float tiles, int rpm) {
    if(type==3) {
      hrt(tiles,rpm);
    }
  }

  void right_encoder(float tiles, int rpm) {
    if(type==3) {
      hlt(tiles,rpm);
    }
  }

  void turn_encoder(int degrees, int rpm) {
    trt(degrees,rpm);
  }


  void forward_inertia(float tiles, int rpm) {
    if(!hasInertia) {
      return;
    }
    tfi(tiles,rpm);
  }

  void backward_inertia(float tiles, int rpm) {
    if(!hasInertia) {
      return;
    }
    tbi(tiles,rpm);
  }

  void right_inertia(float tiles, int rpm) {
    if(!hasInertia) {
      return;
    }
    hri(tiles,rpm);
  }

  void left_inertia(float tiles, int rpm) {
    if(!hasInertia) {
      return;
    }
    hli(tiles,rpm);
  }

  void turn_inertia(int degrees, int rpm) {
    if(!hasInertia) {
      return;
    }
    tri(degrees, rpm);
  }
};
