#include <stdio.h>
#include <unistd.h>

#include "robot.hpp"


void Robot::transform() {
	
	if(!keys.startTransform)
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
	
	// printf("X = %f, Y= %f, Z+ %f\n", keys.hip_X,keys.hip_Y,keys.hip_Z);
	
	if(keys.stage == 25) {
		if( keys.isCarMode){
			keys.key_frame.hip_Y = keys.prev_angle;
		}
	}

	if(keys.stage == 75) {
		double cur = keys.key_frame.hip_X;
		if( !keys.isCarMode){
			keys.key_frame.hip_X += -90;
			keys.prev_angle = keys.key_frame.hip_Y;
			keys.key_frame.hip_Y = 0;
		} else {
			keys.key_frame.hip_X += 90;
			keys.prev_angle = keys.key_frame.hip_Z;
			keys.key_frame.hip_Z = 0;
		}
	}

	if(keys.stage == 85) {
		if( !keys.isCarMode){
			keys.key_frame.hip_Z = keys.prev_angle;
		}
	}
	
	if(keys.stage == 95) {
		if( !keys.isCarMode){
			keys.key_frame.hip_TY = -1.0;
		} else {
			keys.key_frame.hip_TY = -0.5;
		}
	}

	if(keys.stage == 100) {
	}

	if( keys.isCarMode )
		keys.stage -= 5; // Decrement stage for convertion from car to robot
	else
		keys.stage += 5; // Increment stage for convertion from robot to car

	keys.key_callback(glfwGetCurrentContext(),-1,-1,-1,-1);

	if(keys.stage > 100){
		// End animation when stage gone above 100
		keys.startTransform=0;
		// keys.stage=100;
		keys.isCarMode = 1;
	}
	if(keys.stage < 0 ) {
		// End animation when stage gone below 0
		keys.startTransform=0;
		// keys.stage=0;
		keys.isCarMode = 0;	
	}

	if(keys.stage%10 == 0 || keys.stage%10 == 5) {
		glfwSwapBuffers(glfwGetCurrentContext());  
	  	// sleep(0.8);	
	  	// usleep(1 * 100 * 1000);
	}

}
