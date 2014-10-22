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
	DirectionalLight Dir_light1;
	DirectionalLight Dir_light2;
	SpotLight Head_light1;
	SpotLight Head_light2;
	bool light1;
	bool light2;
	bool light3;
	bool light4;

	World() {
		
		initTexture();
		setLights();
		robot = Robot();
		Camera=1;
		initTexture();
		light1=true;
		light2=true;
		light3=true;
		light4=true;
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
	void setSceneProperties();
	void setRobotProperties();
};


#endif
