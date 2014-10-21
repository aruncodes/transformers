#include <stdio.h>
#include <unistd.h>

#include "robot.hpp"

void Robot::animate() {
	
	if(!keys.startAnim)
		return;

	if(keys.stage == 0) keys.frame =  0;
	if(keys.stage == 10) keys.frame = 1;
	if(keys.stage == 20) keys.frame = 2;
	if(keys.stage == 30) keys.frame = 3;
	if(keys.stage == 40) keys.frame = 4;
	if(keys.stage == 50) keys.frame = 5;
	if(keys.stage == 60) keys.frame = 6;
	if(keys.stage == 70) keys.frame = 7;
	if(keys.stage == 80) keys.frame = 8;
	if(keys.stage == 90) keys.frame = 9;
	
	if(keys.stage == 25) {
		if( !keys.isCarMode){
			// glRotatef(90,0,1,0);
			keys.hip_Y += 0;
		} else {
			// glRotatef(-90,0,1,0);
			keys.hip_Y += 0;
		}
	}

	if(keys.stage == 75) {
		if( !keys.isCarMode){
			// glRotatef(-90,1,0,0);
			keys.hip_X += -90;
		} else {
			// glRotatef(90,1,0,0);
			keys.hip_X += 90;
		}
	}
	if(keys.stage == 95) {
		if( !keys.isCarMode){
			// glTranslatef(0,0,-0.5);
			keys.hip_TY = -1.0;
		} else {
			// glTranslatef(0,0,0.5);
			keys.hip_TY = -0.5;
		}
	}

	if(keys.stage == 100) {
	}

	if( keys.isCarMode )
		keys.stage -= 5; // Decrement stage for convertion from car to robot
	else
		keys.stage += 5; // Increment stage for convertion from robot to car

	keys.key_callback(0,-1,-1,-1,-1);

	if(keys.stage > 100){
		// End animation when stage gone above 100
		keys.startAnim=0;
		// keys.stage=100;
		keys.isCarMode = 1;
	}
	if(keys.stage < 0 ) {
		// End animation when stage gone below 0
		keys.startAnim=0;
		// keys.stage=0;
		keys.isCarMode = 0;	
	}

	if(keys.stage%10 == 0 || keys.stage%10 == 5) {
		glfwSwapBuffers(glfwGetCurrentContext());  
	  	sleep(0.1);	
	}

}
