#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include "shading.hpp"


void Shader::initScene() 
{
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_LIGHT0);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

  glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
  glMaterialfv(GL_FRONT, GL_SPECULAR, light_specular);

  glewInit();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  if (light)
    glEnable(GL_LIGHTING);
  else
    glDisable(GL_LIGHTING);

  glShadeModel(GL_SMOOTH);
  glUseProgram(0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}



void Shader::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_L && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT ) 
		light = !light; 
}

