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

	if( key == GLFW_KEY_UP ) {
		glRotatef(-5,1,0,0);
	}
	else if( key == GLFW_KEY_DOWN ) {
		glRotatef(5,1,0,0);
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

/*stage 0*/
	if(key == GLFW_KEY_0)
	{
                frame0=1;
		frame1=frame2=frame3=frame4=frame5=frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_1)
	{
		frame0=frame1=1;
		frame2=frame3=frame4=frame5=frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_2)
	{
		frame0=frame1=frame2=1;
		frame3=frame4=frame5=frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_3)
	{
		frame0=frame1=frame2=frame3=1;
		frame4=frame5=frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_4)
	{
		frame0=frame1=frame2=frame3=frame4=1;
		frame5=frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_5)
	{
		frame0=frame1=frame2=frame3=frame4=frame5=1;
		frame6=frame7=frame8=0;
	}
	if(key == GLFW_KEY_6)
	{
		frame0=frame1=frame2=frame3=frame4=frame5=frame6=1;
		frame7=frame8=0;
	}
	if(key == GLFW_KEY_7)
	{
		frame0=frame1=frame2=frame3=frame4=frame5=frame6=frame7=1;
		frame8=0;
	}
	if(key == GLFW_KEY_8)
	{
		frame0=frame1=frame2=frame3=frame4=frame5=frame6=frame7=frame8=1;
	}
	if(frame0==1){
		//Arms and Hands
                leftUpperArm_X=leftUpperArm_Y=leftUpperArm_Z=0;
		leftLowerArm_X = 0;
		leftHand_X=0;

		rightUpperArm_X=rightUpperArm_Y=rightUpperArm_Z=0;
		rightLowerArm_X = 0;
		rightHand_X=0;

		//Bust
		bust_X=bust_Y=bust_Z=0;

		//Leg
		leftUpperLeg_X=0;
	        leftUpperLeg_Y=0;
		leftUpperLeg_Z=45;
		leftLowerLeg_X =0;
		leftFoot_X = 0;

		rightUpperLeg_X=0;
	        rightUpperLeg_Y=0;
		rightUpperLeg_Z=45;
		rightLowerLeg_X = 0;
		rightFoot_X = 0;
		//Head
		head_X=head_Y=head_Z=00;
		//Hip
		hip_TX=hip_TY=hip_TZ=0;
		hip_Y=0;
        }

	if(frame2==1){
	leftHand_X=180;
	rightHand_X=180;
	}
	
	if(frame3==1){
	leftUpperLeg_Z=0;
	rightUpperLeg_Z=0;
	}

	if(frame5==1){
	leftFoot_X=-180;
	rightFoot_X=-180;
	}

	if(frame7==1){
	rightUpperArm_Y=leftUpperArm_Y=180;
	}
	
	if(frame8==1){
	rightLowerLeg_X=leftLowerLeg_X=-180;
	}		

}
