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
#include "world.hpp"
#include "frame.hpp"

std::string filename, progname;
World WORLD;
Frame nextFrame;
int record=0;

void renderGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    WORLD.drawScene();
}


void interpolateFrames(Frame prev_frame,Frame suc_frame){
	int no_of_inbetween_frames=10;
	double delta_bust_X=(suc_frame.bust_X-prev_frame.bust_X)/no_of_inbetween_frames;
	double delta_bust_Y=(suc_frame.bust_Y-prev_frame.bust_Y)/no_of_inbetween_frames;
	double delta_bust_Z=(suc_frame.bust_Z-prev_frame.bust_Z)/no_of_inbetween_frames;
	double delta_head_X=(suc_frame.head_X-prev_frame.head_X)/no_of_inbetween_frames;
	double delta_head_Y=(suc_frame.head_Y-prev_frame.head_Y)/no_of_inbetween_frames;
	double delta_head_Z=(suc_frame.head_Z-prev_frame.head_Z)/no_of_inbetween_frames;

	double delta_leftUpperArm_X=(suc_frame.leftUpperArm_X-prev_frame.leftUpperArm_X)/no_of_inbetween_frames;
	double delta_leftUpperArm_Y=(suc_frame.leftUpperArm_Y-prev_frame.leftUpperArm_Y)/no_of_inbetween_frames;
	double delta_leftUpperArm_Z=(suc_frame.leftUpperArm_Z-prev_frame.leftUpperArm_Z)/no_of_inbetween_frames;

	double delta_leftLowerArm_X=(suc_frame.leftLowerArm_X-prev_frame.leftLowerArm_X)/no_of_inbetween_frames;
	
	double delta_rightUpperArm_X=(suc_frame.rightUpperArm_X-prev_frame.rightUpperArm_X)/no_of_inbetween_frames;
	double delta_rightUpperArm_Y=(suc_frame.rightUpperArm_Y-prev_frame.rightUpperArm_Y)/no_of_inbetween_frames;
	double delta_rightUpperArm_Z=(suc_frame.rightUpperArm_Z-prev_frame.rightUpperArm_Z)/no_of_inbetween_frames;

	double delta_rightLowerArm_X=(suc_frame.rightLowerArm_X-prev_frame.rightLowerArm_X)/no_of_inbetween_frames;

	double delta_leftHand_X=(suc_frame.leftHand_X-prev_frame.leftHand_X)/no_of_inbetween_frames;
	double delta_rightHand_X=(suc_frame.rightHand_X-prev_frame.rightHand_X)/no_of_inbetween_frames;

	double delta_leftUpperLeg_X=(suc_frame.leftUpperLeg_X-prev_frame.leftUpperLeg_X)/no_of_inbetween_frames;
	double delta_leftUpperLeg_Y=(suc_frame.leftUpperLeg_Y-prev_frame.leftUpperLeg_Y)/no_of_inbetween_frames;
	double delta_leftUpperLeg_Z=(suc_frame.leftUpperLeg_Z-prev_frame.leftUpperLeg_Z)/no_of_inbetween_frames;
	
	double delta_leftLowerLeg_X=(suc_frame.leftLowerLeg_X-prev_frame.leftLowerLeg_X)/no_of_inbetween_frames;

	double delta_rightUpperLeg_X=(suc_frame.rightUpperLeg_X-prev_frame.rightUpperLeg_X)/no_of_inbetween_frames;
	double delta_rightUpperLeg_Y=(suc_frame.rightUpperLeg_Y-prev_frame.rightUpperLeg_Y)/no_of_inbetween_frames;
	double delta_rightUpperLeg_Z=(suc_frame.rightUpperLeg_Z-prev_frame.rightUpperLeg_Z)/no_of_inbetween_frames;
	
	double delta_rightLowerLeg_X=(suc_frame.rightLowerLeg_X-prev_frame.rightLowerLeg_X)/no_of_inbetween_frames;

	double delta_leftFoot_X=(suc_frame.leftFoot_X-prev_frame.leftFoot_X)/no_of_inbetween_frames;
	double delta_rightFoot_X=(suc_frame.rightFoot_X-prev_frame.rightFoot_X)/no_of_inbetween_frames;

	double delta_hip_TX=(suc_frame.hip_TX-prev_frame.hip_TX)/no_of_inbetween_frames;
	double delta_hip_TY=(suc_frame.hip_TY-prev_frame.hip_TY)/no_of_inbetween_frames;
	double delta_hip_TZ=(suc_frame.hip_TZ-prev_frame.hip_TZ)/no_of_inbetween_frames;

	double delta_hip_X=(suc_frame.hip_X-prev_frame.hip_X)/no_of_inbetween_frames;
	double delta_hip_Y=(suc_frame.hip_Y-prev_frame.hip_Y)/no_of_inbetween_frames;
	double delta_hip_Z=(suc_frame.hip_Z-prev_frame.hip_Z)/no_of_inbetween_frames;

	while(no_of_inbetween_frames!=0){
		glfwSetTime(0);
		
		WORLD.robot.keys.key_frame.bust_X+=delta_bust_X;
		WORLD.robot.keys.key_frame.bust_Y+=delta_bust_Y;
		WORLD.robot.keys.key_frame.bust_Z+=delta_bust_Z;

		WORLD.robot.keys.key_frame.head_X+=delta_head_X;
		WORLD.robot.keys.key_frame.head_Y+=delta_head_Y;
		WORLD.robot.keys.key_frame.head_Z+=delta_head_Z;
		
		WORLD.robot.keys.key_frame.leftUpperArm_X+=delta_leftUpperArm_X;
		WORLD.robot.keys.key_frame.leftUpperArm_Y+=delta_leftUpperArm_Y;
		WORLD.robot.keys.key_frame.leftUpperArm_Z+=delta_leftUpperArm_Z;

		WORLD.robot.keys.key_frame.leftLowerArm_X+=delta_leftLowerArm_X;

		WORLD.robot.keys.key_frame.rightUpperArm_X+=delta_rightUpperArm_X;
		WORLD.robot.keys.key_frame.rightUpperArm_Y+=delta_rightUpperArm_Y;
		WORLD.robot.keys.key_frame.rightUpperArm_Z+=delta_rightUpperArm_Z;

		WORLD.robot.keys.key_frame.rightLowerArm_X+=delta_rightLowerArm_X;

		WORLD.robot.keys.key_frame.leftHand_X+=delta_leftHand_X;
		WORLD.robot.keys.key_frame.rightHand_X+=delta_rightHand_X;

		
		WORLD.robot.keys.key_frame.leftUpperLeg_X+=delta_leftUpperLeg_X;
		WORLD.robot.keys.key_frame.leftUpperLeg_Y+=delta_leftUpperLeg_Y;
		WORLD.robot.keys.key_frame.leftUpperLeg_Z+=delta_leftUpperLeg_Z;

		WORLD.robot.keys.key_frame.leftLowerLeg_X+=delta_leftLowerLeg_X;

		WORLD.robot.keys.key_frame.rightUpperLeg_X+=delta_rightUpperLeg_X;
		WORLD.robot.keys.key_frame.rightUpperLeg_Y+=delta_rightUpperLeg_Y;
		WORLD.robot.keys.key_frame.rightUpperLeg_Z+=delta_rightUpperLeg_Z;

		WORLD.robot.keys.key_frame.rightLowerLeg_X+=delta_rightLowerLeg_X;

		WORLD.robot.keys.key_frame.leftFoot_X+=delta_leftFoot_X;
		WORLD.robot.keys.key_frame.rightFoot_X+=delta_rightFoot_X;

		WORLD.robot.keys.key_frame.hip_TX+=delta_hip_TX;
		WORLD.robot.keys.key_frame.hip_TY+=delta_hip_TY;
		WORLD.robot.keys.key_frame.hip_TZ+=delta_hip_TZ;

		WORLD.robot.keys.key_frame.hip_X+=delta_hip_X;
		WORLD.robot.keys.key_frame.hip_Y+=delta_hip_Y;
		WORLD.robot.keys.key_frame.hip_Z+=delta_hip_Z;

		renderGL();
		glfwSwapBuffers(glfwGetCurrentContext());
		double time;
		while((time=glfwGetTime())<=0.05);
		no_of_inbetween_frames--;
	}
}


void startAnimation(void){
	FILE *file=fopen("keyframes.txt","r");
	int no_of_frames_left=10;
	while(no_of_frames_left!=0){
		fscanf(file,"%lg",&nextFrame.bust_X);
		fscanf(file,"%lg",&nextFrame.bust_Y);
		fscanf(file,"%lg",&nextFrame.bust_Z);
		fscanf(file,"%lg",&nextFrame.head_X);
		fscanf(file,"%lg",&nextFrame.head_Y);
		fscanf(file,"%lg",&nextFrame.head_Z);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_X);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_Y);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_Z);
		fscanf(file,"%lg",&nextFrame.leftLowerArm_X);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_X);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_Y);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_Z);
		fscanf(file,"%lg",&nextFrame.rightLowerArm_X);
		fscanf(file,"%lg",&nextFrame.leftHand_X);
		fscanf(file,"%lg",&nextFrame.rightHand_X);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_X);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_Y);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_Z);
		fscanf(file,"%lg",&nextFrame.leftLowerLeg_X);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_X);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_Y);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_Z);
		fscanf(file,"%lg",&nextFrame.rightLowerLeg_X);
		fscanf(file,"%lg",&nextFrame.leftFoot_X);
		fscanf(file,"%lg",&nextFrame.rightFoot_X);
		fscanf(file,"%lg",&nextFrame.hip_TX);
		fscanf(file,"%lg",&nextFrame.hip_TY);
		fscanf(file,"%lg",&nextFrame.hip_TZ);
		fscanf(file,"%lg",&nextFrame.hip_X);
		fscanf(file,"%lg",&nextFrame.hip_Y);
		fscanf(file,"%lg",&nextFrame.hip_Z);
		fscanf(file,"%d",&nextFrame.startAnim);
		interpolateFrames(WORLD.robot.keys.key_frame,nextFrame);
		WORLD.robot.keys.key_frame.startAnim=nextFrame.startAnim;
		no_of_frames_left--;
	}
	record=0;
	fclose(file);
}




void key_callback_wrapper(GLFWwindow* window, int key, int scancode, int action, int mods) {
    WORLD.robot.keys.key_callback(window,key,scancode,action,mods);
    WORLD.key_callback(window,key,scancode,action,mods);
    /* Start animation */
	if(key == GLFW_KEY_F8 && action == GLFW_PRESS) {
		record=1;
	}
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
  
  // Initialize world and robot
  nextFrame=Frame();
  WORLD=World();
  glScalef(0.5,0.5,0.5);
  // Loop until the user closes the window
  while (glfwWindowShouldClose(window) == 0)
    {
       if(record!=1){
  	    // Render here
      	  renderGL();

          // Swap front and back buffers
          glfwSwapBuffers(window);
      
          // Poll for and process events
          glfwPollEvents();
	}
	else{
	   startAnimation();
	}

    }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
