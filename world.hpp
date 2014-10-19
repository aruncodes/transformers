#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include "robot.hpp"
#include "blocks.hpp"
#include "texture.hpp"

class World {

public:
	Robot robot;
	GLuint* texture;
    int Camera;

	World() {
		
		initTexture();
		robot = Robot();
		
		Camera=1;
	}

	void initTexture();
	void makeScene();
	void drawScene();
	void selectCamera();
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};


#endif