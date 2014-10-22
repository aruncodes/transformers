#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include "shading.hpp"


void DirectionalLight::initScene(bool light) 
{
  glEnable(GL_DEPTH_TEST);
  glLightfv(this->light_enum, GL_AMBIENT, this->light_ambient);
  glLightfv(this->light_enum, GL_DIFFUSE, this->light_diffuse);
  glLightfv(GL_FRONT, GL_SPECULAR, this->light_specular);

  glewInit();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if(light){
    glEnable(this->light_enum);
}
  else
    glDisable(this->light_enum);	
  glShadeModel(GL_SMOOTH);
  glEnable(GL_NORMALIZE);
  glLightfv(light_enum, GL_POSITION, this->light_position);

}

void SpotLight::initScene(bool light) 
{
  glEnable(GL_DEPTH_TEST);

  glEnable(light_enum);

  glLightf(light_enum, GL_SPOT_CUTOFF,10.0);
  glLightf(light_enum, GL_SPOT_EXPONENT,2.0);
  glLightfv(light_enum, GL_SPOT_DIRECTION, spot_direction);
  glLightfv(light_enum, GL_DIFFUSE, light_diffuse);
  glLightfv(light_enum, GL_SPECULAR, light_specular);

  glewInit();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHTING);
  if(light){
    glEnable(this->light_enum);
  }
  else
    glDisable(this->light_enum);	

  glShadeModel(GL_SMOOTH);
  glEnable(GL_NORMALIZE);
  glLightfv(light_enum, GL_POSITION, light_position);

}



/*void DirectionalLight::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_L && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT ) 
		light = !light; 
}*/

