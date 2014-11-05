#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include "shading.hpp"


void DirectionalLight::initScene() 
{
  glLightfv(light_enum, GL_POSITION, light_position);
  glLightfv(light_enum, GL_AMBIENT, light_ambient);
  glLightfv(light_enum, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_FRONT, GL_SPECULAR, light_specular);


  if(light){
    glEnable(light_enum);
  }
  else
    glDisable(light_enum);  

}

void SpotLight::initScene() 
{

  glLightfv(light_enum, GL_POSITION, light_position);
  glLightfv(light_enum, GL_DIFFUSE, light_diffuse);
  glLightfv(light_enum, GL_SPECULAR, light_specular);

  glLightfv(light_enum, GL_SPOT_DIRECTION, spot_direction);
  glLightf(light_enum, GL_SPOT_EXPONENT,10.0);
  glLightf(light_enum, GL_SPOT_CUTOFF,15.0);

  if(light){
    glEnable(light_enum);
  }
  else
    glDisable(light_enum);  

}

void Light::updatePosition(double x,double y,double z) {
  light_position[0] = x;
  light_position[1] = y;
  light_position[2] = z;
}

void SpotLight::updateDirection(double x,double y,double z) {
  spot_direction[0] = x;
  spot_direction[1] = y;
  spot_direction[2] = z;
}

