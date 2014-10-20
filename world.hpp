#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include "robot.hpp"
#include "blocks.hpp"
#include "texture.hpp"

class World {

public:
	Robot robot;
	GLuint* texture;
	KeyControls keys;

	World() {
		initTexture();
		robot = Robot();		
	}
	void selectCamera();
	void initTexture();
	void makeScene();
	void drawScene();
};


#endif
