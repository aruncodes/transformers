#include <stdio.h>
#include <unistd.h>

#include "robot.hpp"

// int keys.stage = 0;
void Robot::animate() {
	
	if(!keys.startAnim)
		return;

	if(keys.stage == 0)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 5) {
		glRotatef(45,0,1,0);		
	}
	if(keys.stage == 10)
	{
        keys.frame1=1;
		keys.frame9=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=0;
	}
	if(keys.stage == 20)
	{
		keys.frame1=keys.frame2=1;
		keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=keys.frame9=0;

	}
	if(keys.stage == 25) {
		glRotatef(-45,1,0,0);
	}
	if(keys.stage == 30)
	{
		keys.frame1=keys.frame2=keys.frame3=1;
		keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 35) {
		glRotatef(45,0,0,1);
	}
	if(keys.stage == 40)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=1;
		keys.frame5=keys.frame6=keys.frame7=keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 50)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=1;
		keys.frame6=keys.frame7=keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 60)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=1;
		keys.frame7=keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 65) {
		glRotatef(45,0,0,1);
	}
	if(keys.stage == 70)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=1;
		keys.frame8=keys.frame9=0;
	}
	if(keys.stage == 80)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=1;
		keys.frame9=0;
	}
	if(keys.stage == 90)
	{
		keys.frame1=keys.frame2=keys.frame3=keys.frame4=keys.frame5=keys.frame6=keys.frame7=keys.frame8=keys.frame9=1;
		
	}
	if(keys.stage == 100) {
		glRotatef(-25,1,0,0);
		glRotatef(25,0,1,0);
	}
	if(keys.stage == 101) {
		glRotatef(1,0,0,1);
		keys.rotateCount++;
	}

	keys.stage++;
	keys.key_callback(0,-1,-1,-1,-1);

	int x=101;
	if(keys.stage >x) keys.stage=x;

	if(keys.stage%10 == 0 || keys.stage%10 == 5) {
		glfwSwapBuffers(glfwGetCurrentContext());  
	  	usleep(50*1000);	
	}

	if(keys.rotateCount > 360) {
		keys.startAnim=0;
		keys.stage=0;
		keys.rotateCount=0;
	}
}