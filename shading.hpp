#ifndef _SHADING_HPP_
#define _SHADING_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader {


public:
bool light;
GLfloat light_position[4];
GLfloat light_diffuse[4];
GLfloat light_specular[4];
	Shader(){
	}

	Shader(GLfloat* l_pos,GLfloat* l_diffuse,GLfloat* l_specular) {
		for(int i=0;i<4;i++){
			light_position[i]=l_pos[i];
			light_diffuse[i]=l_diffuse[i];
			light_specular[i]=l_specular[i];
		}
		light=false;
	}
	void initScene();
	//void display(void);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


#endif
