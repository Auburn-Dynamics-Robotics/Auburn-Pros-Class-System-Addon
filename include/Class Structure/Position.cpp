#include "TYPES.h"
#include "Velocity.cpp"

class position {
public:

  float x_displacement=0;
  float y_displacement=0;
  float z_displacement=0;

  float x_pos=0;
  float y_pos=0;
  float z_pos=0;

  std::string x_equation;
  std::string y_equation;
  std::string z_equation;

  void integrate(velocity one, position prev, float ms) {
    float seconds = ms/1000;

    x_equation = std::to_string(one.x_velocity) + "X + " + std::to_string(prev.x_pos);
    y_equation = std::to_string(one.y_velocity) + "X + " + std::to_string(prev.y_pos);
    z_equation = std::to_string(one.z_velocity) + "X + " + std::to_string(prev.z_pos);

    x_displacement = one.x_velocity*seconds;
    y_displacement = one.y_velocity*seconds;
    z_displacement = one.z_velocity*seconds;

    x_pos = x_displacement + prev.x_pos;
    y_pos = y_displacement + prev.y_pos;
    z_pos = z_displacement + prev.z_pos;
  }

};
