#include "main.h"
#include "Velocity.cpp"

class position {
public:
  float x_pos=0;
  float y_pos=0;
  float z_pos=0;

  std::string x_equation;
  std::string y_equation;
  std::string z_equation;

  void integrate(velocity one, position prev, float ms) {
    velocity temp;
    ms = ms/1000;
    x_equation = std::to_string(one.x_velocity) + "X + " + std::to_string(prev.x_pos);
    y_equation = std::to_string(one.y_velocity) + "X + " + std::to_string(prev.y_pos);
    z_equation = std::to_string(one.z_velocity) + "X + " + std::to_string(prev.z_pos);

    x_pos = (one.x_velocity*ms) + (prev.x_pos);
    y_pos = (one.y_velocity*ms) + (prev.y_pos);
    z_pos = (one.z_velocity*ms) + (prev.z_pos);
  }

  void add_position(position p) {
    x_pos += p.x_pos;
    y_pos += p.y_pos;
    z_pos += p.z_pos;
  }
};
