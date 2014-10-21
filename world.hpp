#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include "robot.hpp"
#include "blocks.hpp"
#include "texture.hpp"
#include "shading.hpp"

class World {

public:
	Robot robot;
	GLuint* texture;
        int Camera;
        Shader shade_obj;

	World() {
		
		initTexture();
		setLights();
		robot = Robot();
		Camera=1;
	}

	void initTexture();
	void makeScene();
	void drawScene();
	void selectCamera();
	void initLights();
	void setLights();
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void debugCoord();

};


#endif
