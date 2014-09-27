#include "keycontrols.hpp"

//!GLFW keyboard callback
void KeyControls::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//!Close the window if the ESC key was pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
	  glfwSetWindowShouldClose(window, GL_TRUE);
	}

	if( key == GLFW_KEY_LEFT ) {
		glRotatef(-5,0,1,0);
	}
	else if( key == GLFW_KEY_RIGHT ) {
		glRotatef(5,0,1,0);
	}

/* Left lower arm control*/
	if( key == GLFW_KEY_Q ) {
		leftLowerArm_X += 5;
	} else if( key == GLFW_KEY_A ) {
		leftLowerArm_X -= 5;
	} 

/* right lower arm control*/
	if( key == GLFW_KEY_W ) {
		rightLowerArm_X += 5;
	} else if( key == GLFW_KEY_S ) {
		rightLowerArm_X -= 5;
	} 
}
