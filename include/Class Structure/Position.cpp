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

  void integrate(velocity one, position prev, int ms) {

    x_equation = std::to_string(one.x_velocity/2) + "X^2 + " + std::to_string(one.x_c) + "X + " + std::to_string(prev.x_pos);
    y_equation = std::to_string(one.y_velocity/2) + "X^2 + " + std::to_string(one.y_c) + "X + " + std::to_string(prev.y_pos);
    z_equation = std::to_string(one.z_velocity/2) + "X^2 + " + std::to_string(one.z_c) + "X + " + std::to_string(prev.z_pos);

    x_pos = (one.x_velocity/2*ms*ms) + (one.x_c*ms);
    y_pos = (one.y_velocity/2*ms*ms) + (one.y_c*ms);
    z_pos = (one.z_velocity/2*ms*ms) + (one.z_c*ms);
  }

  void add_position(position p) {
    x_pos += p.x_pos;
    y_pos += p.y_pos;
    z_pos += p.z_pos;
  }
};
