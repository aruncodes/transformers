/*
 * CS475/CS675 - Computer Graphics
 *  Transformers Assignment Base Code
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <string>

#include "gl_framework.hpp"
#include "animator.hpp"

 std::string filename, progname;
 Animator animator(512,512);

 void key_callback_wrapper(GLFWwindow* window, int key, int scancode, int action, int mods) {
 	animator.WORLD.robot.keys.key_callback(window,key,scancode,action,mods);
 	animator.WORLD.key_callback(window,key,scancode,action,mods);
 	animator.key_callback(window,key,scancode,action,mods);

    //!Close the window if the ESC key was pressed
 	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
 		glfwSetWindowShouldClose(window, GL_TRUE);
 }

 int main (int argc, char *argv[]) 
 {
 	progname=argv[0];

  	//! The pointer to the GLFW window
 	GLFWwindow* window;
  	//! Setting up the GLFW Error callback
 	glfwSetErrorCallback(csX75::error_callback);

  	//! Initialize GLFW
 	if (!glfwInit())
 		return -1;

 	int win_width=512;
 	int win_height=512;

  	//! Create a windowed mode window and its OpenGL context
 	window = glfwCreateWindow(win_width, win_height, "Transformers", NULL, NULL);
 	if (!window)
 	{
 		glfwTerminate();
 		return -1;
 	}

  	//! Make the window's context current 
 	glfwMakeContextCurrent(window);

  	//Keyboard Callback
 	glfwSetKeyCallback(window, key_callback_wrapper);
  	//Framebuffer resize callback
 	glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

  	// Ensure we can capture the escape key being pressed below
 	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

 	glfwGetFramebufferSize(window, &win_width, &win_height);
 	csX75::framebuffer_size_callback(window, win_width, win_height);
  	//Initialize GL state
 	csX75::initGL();

  	// Initialize animator, world and robot
 	animator = Animator(win_width,win_height);

 	glScalef(0.5,0.5,0.5);
  	// Loop until the user closes the window
 	while (glfwWindowShouldClose(window) == 0)
 	{
    // Render here
 		animator.renderFrame();
 	}

 	glfwDestroyWindow(window);
 	glfwTerminate();
 	return 0;
 }
