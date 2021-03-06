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
	SpotLight Top_Spot_light;

	World() {
		
		initLights();
		initTexture();
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

	std::string getLightVector();
	void setLightVector(std::string);
};


#endif
