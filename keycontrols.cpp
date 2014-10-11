#include "keycontrols.hpp"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;

GLfloat* multiply(GLfloat* a,GLfloat b[])
{
     GLfloat* Result_Matrix;
     GLfloat a2D[4][4];
     GLfloat b2D[4][4];
     GLfloat result2D[4][4];
     Result_Matrix=new GLfloat[16];
     for(int i=0;i<16;i++){
	a2D[i%4][i/4]=a[i];
	b2D[i%4][i/4]=b[i];
     }
     for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	    result2D[i][j]=0;
	    for(int k=0;k<4;k++){
		result2D[i][j]+=a2D[i][k]*b2D[k][j];
	    }
	}
     }
     
     for(int i=0;i<16;i++){
	Result_Matrix[i]=result2D[i%4][i/4];
     }
     return Result_Matrix;
}

//!GLFW keyboard callback
void KeyControls::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
	//!Close the window if the ESC key was pressed
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
	  glfwSetWindowShouldClose(window, GL_TRUE);
	}

	

	//if( key == GLFW_KEY_P ) {
		//glRotatef(-5,1,0,0);
		//hip_TY+=0.02;
	//}
	//else if( key == GLFW_KEY_O ) {
		//glRotatef(5,1,0,0);
		//hip_TY-=0.02;
	//}

	if(key == GLFW_KEY_C) {
		startAnim = 1;
	}

//---------Arm Controls-----------------
/* Left lower arm control*/
	if( key == GLFW_KEY_X && mods == 0) {
		leftLowerArm_X += 5;
	} else if( key == GLFW_KEY_X && mods == GLFW_MOD_SHIFT ) {
		leftLowerArm_X -= 5;
	} 

/* right lower arm control*/
	if( key == GLFW_KEY_Z && mods == 0) {
		rightLowerArm_X += 5;
	} else if( key == GLFW_KEY_Z && mods == GLFW_MOD_SHIFT ) {
		rightLowerArm_X -= 5;
	} 

/* Left Upper arm X control*/
	if( key == GLFW_KEY_S && mods == 0) {
		leftUpperArm_X += 5;
	} else if( key == GLFW_KEY_S && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_X -= 5;
	} 

/* right Upper arm X control*/
	if( key == GLFW_KEY_A && mods == 0) {
		rightUpperArm_X += 5;
	} else if( key == GLFW_KEY_A && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_X -= 5;
	} 

/* Left Upper arm Y control*/
	if( key == GLFW_KEY_W && mods == 0) {
		leftUpperArm_Y += 5;
	} else if( key == GLFW_KEY_W && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_Y -= 5;
	} 

/* right Upper arm Y control*/
	if( key == GLFW_KEY_Q && mods == 0) {
		rightUpperArm_Y += 5;
	} else if( key == GLFW_KEY_Q && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_Y -= 5;
	} 

/* Left Upper arm Z control*/
	if( key == GLFW_KEY_D && mods == 0) {
		leftUpperArm_Z += 5;
	} else if( key == GLFW_KEY_D && mods == GLFW_MOD_SHIFT ) {
		leftUpperArm_Z -= 5;
	} 

/* right Upper arm Z control*/
	if( key == GLFW_KEY_E && mods == 0) {
		rightUpperArm_Z += 5;
	} else if( key == GLFW_KEY_E && mods == GLFW_MOD_SHIFT ) {
		rightUpperArm_Z -= 5;
	} 

//-------Leg cotrols-------------

/* Left lower Leg control*/
	if( key == GLFW_KEY_B && mods == 0) {
		leftLowerLeg_X += 5;
	} else if( key == GLFW_KEY_B && mods == GLFW_MOD_SHIFT ) {
		leftLowerLeg_X -= 5;
	} 

/* right lower Leg control*/
	if( key == GLFW_KEY_V && mods == 0) {
		rightLowerLeg_X += 5;
	} else if( key == GLFW_KEY_V && mods == GLFW_MOD_SHIFT ) {
		rightLowerLeg_X -= 5;
	} 

/* Left Upper Leg X control*/
	if( key == GLFW_KEY_G && mods == 0) {
		leftUpperLeg_X += 5;
	} else if( key == GLFW_KEY_G && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_X -= 5;
	} 

/* right Upper Leg X control*/
	if( key == GLFW_KEY_F && mods == 0) {
		rightUpperLeg_X += 5;
	} else if( key == GLFW_KEY_F && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_X -= 5;
	} 

/* Left Upper Leg Y control*/
	if( key == GLFW_KEY_T && mods == 0) {
		leftUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_T && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_Y -= 5;
	} 

/* right Upper Leg Y control*/
	if( key == GLFW_KEY_R && mods == 0) {
		rightUpperLeg_Y += 5;
	} else if( key == GLFW_KEY_R && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_Y -= 5;
	} 

/* Left Upper Leg Z control*/
	if( key == GLFW_KEY_H && mods == 0) {
		leftUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_H && mods == GLFW_MOD_SHIFT ) {
		leftUpperLeg_Z -= 5;
	} 

/* right Upper Leg Z control*/
	if( key == GLFW_KEY_Y && mods == 0) {
		rightUpperLeg_Z += 5;
	} else if( key == GLFW_KEY_Y && mods == GLFW_MOD_SHIFT ) {
		rightUpperLeg_Z -= 5;
	} 
//--------------------------------------------------

/* bust X control*/
	if( key == GLFW_KEY_U && mods == 0) {
		bust_X += 5;
	} else if( key == GLFW_KEY_U && mods == GLFW_MOD_SHIFT ) {
		bust_X -= 5;
	} 

/* bust Y control*/
	if( key == GLFW_KEY_J && mods == 0) {
		bust_Y += 5;
	} else if( key == GLFW_KEY_J && mods == GLFW_MOD_SHIFT ) {
		bust_Y -= 5;
	} 

/* bust Z control*/
	if( key == GLFW_KEY_M && mods == 0) {
		bust_Z += 5;
	} else if( key == GLFW_KEY_M && mods == GLFW_MOD_SHIFT ) {
		bust_Z -= 5;
	} 
//-------Head----------------------
/* head X control*/
	if( key == GLFW_KEY_I && mods == 0) {
		head_X += 5;
	} else if( key == GLFW_KEY_I && mods == GLFW_MOD_SHIFT ) {
		head_X -= 5;
	} 

/* head Y control*/
	if( key == GLFW_KEY_K && mods == 0) {
		head_Y += 5;
	} else if( key == GLFW_KEY_K && mods == GLFW_MOD_SHIFT ) {
		head_Y -= 5;
	} 
/* head Z control*/
	if( key == GLFW_KEY_COMMA && mods == 0) {
		head_Z += 5;
	} else if( key == GLFW_KEY_COMMA && mods == GLFW_MOD_SHIFT ) {
		head_Z -= 5;
	} 
//----------Transformation--------------------------
/*stage 0*/
	if(key == GLFW_KEY_0)
	{
		frame1=frame2=frame3=frame4=frame5=frame6=frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_1 )
	{
        	frame1=1;
		frame9=frame2=frame3=frame4=frame5=frame6=frame7=frame8=frame10=frame11=0;
	}
	if(key == GLFW_KEY_2 )
	{
		frame1=frame2=1;
		frame3=frame4=frame5=frame6=frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_3)
	{
		frame1=frame2=frame3=1;
		frame4=frame5=frame6=frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_4)
	{
		frame1=frame2=frame3=frame4=1;
		frame5=frame6=frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_5)
	{
		frame1=frame2=frame3=frame4=frame5=1;
		frame6=frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_6)
	{
		frame1=frame2=frame3=frame4=frame5=frame6=1;
		frame7=frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_7)
	{
		frame1=frame2=frame3=frame4=frame5=frame6=frame7=1;
		frame8=frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_8)
	{
		
		frame1=frame2=frame3=frame4=frame5=frame6=frame7=frame8=1;
		frame9=frame10=frame11=0;
	}
	if(key == GLFW_KEY_9 && action == GLFW_PRESS)
	{
		frame1=frame2=frame3=frame4=frame5=frame6=frame7=frame8=frame9=1;
		frame10=frame11=0;
	}

	if(frame1==1){
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
		//hip_TX=hip_TY=hip_TZ=0;
		hip_Y=0;
        }

	if(frame3==1){
	leftHand_X=180;
	rightHand_X=180;
	}
	
	if(frame4==1){
	leftUpperLeg_Z=0;
	rightUpperLeg_Z=0;
	}

	if(frame6==1){
	leftFoot_X=-180;
	rightFoot_X=-180;
	}

	if(frame8==1){
	rightUpperArm_Y=leftUpperArm_Y=180;
	}
	
	if(frame9==1){
	rightLowerLeg_X=leftLowerLeg_X=-180;
	}


	if( key == GLFW_KEY_UP  && frame9==1) {
		wheel_angle=0;
		//glTranslatef(0,0.02,0);
		GLfloat Translate[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,0.02,0,1};
		PreMatrixMult=multiply(PreMatrixMult,Translate);
	}
	else if( key == GLFW_KEY_DOWN  && frame9==1) {
		wheel_angle=0;
		//glTranslatef(0,-0.02,0);
		GLfloat Translate[16]={1,0,0,0,0,1,0,0,0,0,1,0,0,-0.02,0,1};
		PreMatrixMult=multiply(PreMatrixMult,Translate);
	}

	if( key == GLFW_KEY_LEFT  && frame9==1) {
		if(wheel_angle!=20)
		    wheel_angle=20;
		else{
		    //glTranslatef(0,-1.4,0);
		    //glRotatef(5,0,0,1);
		    //glTranslatef(0,1.4,0);
		    float theta=5*3.14/180;
		    GLfloat ITRT[16]={cos(theta),sin(theta),0,0,-sin(theta),cos(theta),0,0,0,0,1,0,-1.4*sin(theta),1.4*cos(theta)-1.4,0,1};
		    PreMatrixMult=multiply(PreMatrixMult,ITRT);
		}
	}
	else if( key == GLFW_KEY_RIGHT && frame9==1 ) {
		if(wheel_angle!=-20)
		    wheel_angle=-20;
		else{
		    //glTranslatef(0,-1.4,0);
		    //glRotatef(-5,0,0,1);
		    //glTranslatef(0,1.4,0);
		    float theta=-5*3.14/180;
		    GLfloat ITRT[16]={cos(theta),sin(theta),0,0,-sin(theta),cos(theta),0,0,0,0,1,0,-1.4*sin(theta),1.4*cos(theta)-1.4,0,1};
		    PreMatrixMult=multiply(PreMatrixMult,ITRT);
		}
	}
  
        if(key == GLFW_KEY_F1 && action == GLFW_PRESS)
	{
		Camera1=1;
		Camera2=Camera3=0;
	}

	if(key == GLFW_KEY_F2 && action == GLFW_PRESS)
	{
		Camera2=1;
		Camera1=Camera3=0;
	}		

	if(key == GLFW_KEY_F3 && action == GLFW_PRESS)
	{
		Camera3=1;
		Camera1=Camera2=0;
	}

}
