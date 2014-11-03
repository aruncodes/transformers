#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <GL/glew.h>

#include "robot.hpp"
#include "blocks.hpp"
#include "texture.hpp"

using namespace Blocks;
using namespace Texture;
using namespace std;

void Robot::initStructuralConstraints()
{
    //Hip_LeftUpperLeg_Joint=point(0.075,0,0);
    Hip_LeftUpperLeg_Joint=point(0.075,-0.075,0);
    LeftUpperLeg_LeftLowerLeg_Joint=point(0,-0.1,0.075);
    //Hip_RightUpperLeg_Joint=point(-0.075,0,0);
    Hip_RightUpperLeg_Joint=point(-0.075,-0.075,0);
    RightUpperLeg_RightLowerLeg_Joint=point(0,-0.1,0.075);
    //Bust_Hip_Joint=point(0,0,0);
    Bust_Hip_Joint=point(0,0.075,0);
    // RightShoulder_Bust_Joint=point(-0.1,0.25,0);
    //LeftShoulder_Bust_Joint=point(0.1,0.25,0);
    RightShoulder_Bust_Joint=point(-0.15,0.25,0);
    LeftShoulder_Bust_Joint=point(0.15,0.25,0);
    NeckBustJoint=point(0,0.25,0);
    HeadNeckJoint=point(0,0.015,0);
    LeftShoulder_LeftUpperArmFront_Joint=point(0.025,0.075,0.075);
    LeftUpperArmFront_LeftLowerArmFront_Joint=point(0,-0.125,-0.025);
    RightShoulder_RightUpperArmFront_Joint=point(-0.025,0.075,0.075);
    RightUpperArmFront_RightLowerArmFront_Joint=point(0,-0.125,-0.025);
    LeftUpperArmFront_LeftUpperArmBehind_Joint=point(0.0375,0,-0.025);
    LeftLowerArmFront_LeftLowerArmBehind_Joint=point(0.0375,0,-0.025);
    RightUpperArmFront_RightUpperArmBehind_Joint=point(-0.0375,0,-0.025);
    RightLowerArmFront_RightLowerArmBehind_Joint=point(-0.0375,0,-0.025);
    LeftLowerArmFront_LeftFrontHand_Joint=point(0,-0.125,-0.025);
    RightLowerArmFront_RightFrontHand_Joint=point(0,-0.125,-0.025);
    LeftLowerLeg_LeftFoot_Joint=point(0,-0.15,0.075);
    RightLowerLeg_RightFoot_Joint=point(0,-0.15,0.075);
    LeftFrontHand_LeftBehindHand_Joint=point(0.0375,0,-0.05);
    RightFrontHand_RightBehindHand_Joint=point(-0.0375,0,-0.05);

    Bust_Lower_Point=point(0,-0.25,0);
    Neck_Lower_Point=point(0,-0.015,0);
    Head_Lower_Point=point(0,-0.06,0);
    Left_Shoulder_Lower_Point=point(-0.025,-0.075,0);
    Right_Shoulder_Lower_Point=point(0.025,-0.075,0);
    LeftUpperArmFront_Upper_Point=point(-0.0375,0.125,0.025);
    LeftLowerArmFront_Upper_Point=point(0,0.125,-0.025);
    RightUpperArmFront_Upper_Point=point(0.0375,0.125,0.025);
    RightLowerArmFront_Upper_Point=point(0,0.125,-0.025);
    
    LeftUpperArmBehind_Right_Point=point(0.0375,0,0.025);
    LeftLowerArmBehind_Right_Point=point(0.0375,0,0.025);
    RightUpperArmBehind_Left_Point=point (-0.0375,0,0.025);
    RightLowerArmBehind_Left_Point=point(-0.0375,0,0.025);

    LeftFrontHand_Upper_Point=point(0,0.075,-0.05);
    RightFrontHand_Upper_Point=point(0,0.075,-0.05);
    LeftBehindHand_Upper_Point=point(0.0375,0,0.05);
    RightBehindHand_Upper_Point=point(-0.0375,0,0.05);

    LeftUpperLeg_Upper_Point=point(0,0.1,0);
    LeftLowerLeg_Upper_Point=point(0,0.15,0.075);
    RightUpperLeg_Upper_Point=point(0,0.1,0);
    RightLowerLeg_Upper_Point=point(0,0.15,0.075);
    LeftFoot_Behind_Point=point(0,-0.025,-0.075);
    RightFoot_Behind_Point=point(0,-0.025,-0.075);
}


void Robot::initTexture() {

    int nTex = 45;
    texture = new GLuint[nTex];
    glGenTextures(nTex,texture);

    makeTexture("tex/bust.bmp",texture[LOGO]);
    makeTexture("tex/bustback.bmp",texture[43]);
    // makeTexture("tex/fire.bmp",texture[BLUE]);
    makeTexture("parts/side/lower_leg_left.bmp",texture[BLUE]);
    makeTexture("parts/side/shoulder_back.bmp",texture[RED]);
    // makeTexture("tex/blue_fire.bmp",texture[RED]);
    makeTexture("tex/head.bmp",texture[HEAD]);
    makeTexture("tex/wheel.bmp",texture[WHEEL]);
    makeTexture("tex/hip.bmp",texture[HIP]);

//-----Side----
    makeTexture("parts/side/bust_left.bmp",texture[BUST_LEFT]);
    makeTexture("parts/side/foot_left.bmp",texture[RIGHT_FOOT_RIGHT]);
    makeTexture("parts/side/lower_arm_front_left.bmp",texture[9]);
    makeTexture("parts/side/lower_leg_left.bmp",texture[10]);
    makeTexture("parts/side/shoulder_back.bmp",texture[11]);
    makeTexture("parts/side/upper_arm_front_left.bmp",texture[12]);
    makeTexture("parts/side/upper_leg_left.bmp",texture[13]);
    makeTexture("parts/side/hand_behind_left.bmp",texture[14]);
    makeTexture("parts/side/arm_left_tira.bmp",texture[15]);

//----Front---
    makeTexture("parts/front/head_top.bmp",texture[16]);
    makeTexture("parts/front/left_hand_behind.bmp",texture[17]);
    makeTexture("parts/front/left_hand_front.bmp",texture[18]);
    makeTexture("parts/front/left_upper_arm_behind_top.bmp",texture[19]);
    makeTexture("parts/front/left_upper_arm_front_top.bmp",texture[20]);
    makeTexture("parts/front/right_hand_behind.bmp",texture[21]);
    makeTexture("parts/front/right_hand_front.bmp",texture[22]);
    makeTexture("parts/front/right_upper_arm_behind_top.bmp",texture[23]);
    makeTexture("parts/front/right_upper_arm_front_top.bmp",texture[24]);
    makeTexture("parts/front/shoulder_top.bmp",texture[25]);
    makeTexture("parts/front/shoulder_top_right.bmp",texture[26]);

//-----BACK--------
    makeTexture("parts/back/left_lower_leg_top.bmp",texture[27]);
    makeTexture("parts/back/left_upper_leg_bottom.bmp",texture[28]);
    makeTexture("parts/back/right_lower_leg_top.bmp",texture[29]);
    makeTexture("parts/back/right_upper_leg_bottom.bmp",texture[30]);
//-----Top---------
    makeTexture("parts/top/left_lower_leg_back.bmp",texture[31]);
    makeTexture("parts/top/right_lower_leg_back.bmp",texture[32]);
    makeTexture("parts/top/left_foot_front.bmp",texture[33]);
    makeTexture("parts/top/right_foot_front.bmp",texture[34]);
    makeTexture("parts/top/left_hand_front_front.bmp",texture[35]);
    makeTexture("parts/top/left_hand_behind_back.bmp",texture[36]);
    makeTexture("parts/top/right_larm_behind_lower_back.bmp",texture[37]);
    makeTexture("parts/top/right_larm_front_lower_back.bmp",texture[38]);
    makeTexture("parts/top/left_uarm_behind_back.bmp",texture[39]);
    makeTexture("parts/top/left_uarm_front_back.bmp",texture[40]);
    makeTexture("parts/top/right_uarm_behind_back.bmp",texture[41]);
    makeTexture("parts/top/right_uarm_front_back.bmp",texture[42]);

}

void Robot::initHip()
{
    Hip=glGenLists(1); 
    glNewList(Hip,GL_COMPILE);

    TextureFaces tf;
    tf.back = texture[HIP];
    tf.front = texture[HIP];
    tf.left = texture[HIP];
    tf.right = texture[HIP];

    // glEnable(GL_TEXTURE_2D);
    defineTrapizoid(0.2,0.15,0.15,0.15,tf);
    // glDisable(GL_TEXTURE_2D);
    glEndList();
}

void Robot::initBust()
{
    Bust=glGenLists(1);
    
    TextureFaces tf(texture[LOGO]);

    tf.right = texture[BUST_LEFT];
    tf.left = texture[BUST_LEFT];
    tf.back = texture[43];

    glNewList(Bust,GL_COMPILE);
    defineCuboid(0.3,0.5,0.15,tf);
    glEndList();

}

void Robot::initNeck()
{
    Neck=glGenLists(1);
    glNewList(Neck,GL_COMPILE);
	glPushMatrix();
	   glRotatef(90,1,0,0);
     	   defineCylinder(0.075,0.03,20,1);
	glPopMatrix();
    glEndList();
}
  
void Robot::initHead()
{
    Head=glGenLists(1);

    TextureFaces tf(texture[HEAD]);
    tf.top = texture[16];

    glNewList(Head,GL_COMPILE);
    defineTrapizoid(0.2,0.15+0.03/3,0.15,0.12,tf);
    glEndList();
}

void Robot::initLeftShoulder()
{
    TextureFaces tf(texture[BLUE]);
    tf.left=texture[11];
    tf.top=texture[25];

    LeftShoulder=glGenLists(1);
    glNewList(LeftShoulder,GL_COMPILE);
      defineCuboid(0.05,0.15,0.15,tf);
	glBegin(GL_TRIANGLES);
	    glVertex3f(-0.025,0.075,0.075);
	    glVertex3f(-0.05,-0.075,0.075);
	    glVertex3f(-0.025,-0.075,0.075);

	    glVertex3f(-0.025,0.075,-0.075);
	    glVertex3f(-0.05,-0.075,-0.075);
	    glVertex3f(-0.025,-0.075,-0.075);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(-0.025,0.075,0.075);
	    glVertex3f(-0.025,0.075,-0.075);
	    glVertex3f(-0.05,-0.075,0.075);
	     glVertex3f(-0.05,-0.075,-0.075);
	glEnd();
    glEndList();
}
void Robot::initRightShoulder()
{
    TextureFaces tf(texture[BLUE]);
    tf.right=texture[11];
    tf.top=texture[26];

    RightShoulder=glGenLists(1);
    glNewList(RightShoulder,GL_COMPILE);
	defineCuboid(0.05,0.15,0.15,tf);
	glBegin(GL_TRIANGLES);
	    glVertex3f(0.025,0.075,0.075);
	    glVertex3f(0.05,-0.075,0.075);
	    glVertex3f(0.025,-0.075,0.075);

	    glVertex3f(0.025,0.075,-0.075);
	    glVertex3f(0.05,-0.075,-0.075);
	    glVertex3f(0.025,-0.075,-0.075);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.025,0.075,0.075);
	    glVertex3f(0.025,0.075,-0.075);
	    glVertex3f(0.05,-0.075,0.075);
	     glVertex3f(0.05,-0.075,-0.075);
	glEnd();
    glEndList();
}
void Robot::initLeftUpperArmFront()
{
    TextureFaces tf(texture[RED]);
    tf.right=texture[12];
    tf.top=texture[20];
    tf.back=texture[39];

    LeftUpperArmFront=glGenLists(1);
    glNewList(LeftUpperArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initLeftLowerArmFront()
{
    TextureFaces tf(texture[BLUE]);
    tf.right=texture[9];

    LeftLowerArmFront=glGenLists(1);
    glNewList(LeftLowerArmFront,GL_COMPILE);	
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initRightUpperArmFront()
{
    TextureFaces tf(texture[RED]);
    tf.left=texture[12];
    tf.top=texture[24];
    tf.back=texture[41];

    RightUpperArmFront=glGenLists(1);
    glNewList(RightUpperArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initRightLowerArmFront()
{
    TextureFaces tf(texture[BLUE]);
    tf.left=texture[9];

    RightLowerArmFront=glGenLists(1);
    glNewList(RightLowerArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}
  
void Robot::initLeftUpperArmBehind()
{
    TextureFaces tf(texture[RED]);
    tf.top=texture[19];
    tf.front=texture[40];

    LeftUpperArmBehind=glGenLists(1);
    glNewList(LeftUpperArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initLeftLowerArmBehind()
{
    TextureFaces tf(texture[BLUE]);

    LeftLowerArmBehind=glGenLists(1);
    glNewList(LeftLowerArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initRightUpperArmBehind()
{
    TextureFaces tf(texture[RED]);
    tf.top=texture[23];
    tf.front=texture[42];

    RightUpperArmBehind=glGenLists(1);
    glNewList(RightUpperArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initRightLowerArmBehind()
{
    TextureFaces tf(texture[BLUE]);

    RightLowerArmBehind=glGenLists(1);
    glNewList(RightLowerArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05,tf);
    glEndList();
}

void Robot::initLeftFrontHand()
{
    TextureFaces tf(texture[RED]);
    tf.right= texture[14];
    tf.front=texture[35];

    LeftFrontHand=glGenLists(1);
    glNewList(LeftFrontHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1,tf);
    glBindTexture(GL_TEXTURE_2D,texture[15]);
       glBegin(GL_TRIANGLES);
        glVertex3f(0.0375,-0.075,-0.05);
        glVertex3f(0.0375,-0.075,0.05);
        glVertex3f(0.0375,-0.175,-0.05);

        glTexCoord2d(1,0);
        glVertex3f(-0.0375,-0.075,-0.05);
        glTexCoord2d(1,1);
        glVertex3f(-0.0375,-0.075,0.05);
        glTexCoord2d(0,0);
	    glVertex3f(-0.0375,-0.175,-0.05);
	glEnd();

    glBindTexture(GL_TEXTURE_2D,texture[18]);
	glBegin(GL_QUADS);
        glTexCoord2d(0,0);
        glVertex3f(0.0375,-0.075,0.05);
        glTexCoord2d(1,0);
        glVertex3f(-0.0375,-0.075,0.05);
        glTexCoord2d(1,1);
        glVertex3f(-0.0375,-0.175,-0.05);
        glTexCoord2d(0,1);
	    glVertex3f(0.0375,-0.175,-0.05);
	glEnd();
    glEndList();
}
  
void Robot::initRightFrontHand()
{
    TextureFaces tf(texture[RED]);
    tf.left= texture[14];
    tf.front= texture[37];

    RightFrontHand=glGenLists(1);
    glNewList(RightFrontHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1,tf);
    glBindTexture(GL_TEXTURE_2D,texture[15]);
      glBegin(GL_TRIANGLES);
        glTexCoord2d(1,0);
        glVertex3f(0.0375,-0.075,-0.05);
        glTexCoord2d(1,1);
        glVertex3f(0.0375,-0.075,0.05);
        glTexCoord2d(0,0);
	    glVertex3f(0.0375,-0.175,-0.05);

	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.175,-0.05);
	glEnd();
    
    glBindTexture(GL_TEXTURE_2D,texture[22]);
	glBegin(GL_QUADS);
        glTexCoord2d(0,0);
	    glVertex3f(0.0375,-0.075,0.05);
        glTexCoord2d(1,0);
        glVertex3f(-0.0375,-0.075,0.05);
        glTexCoord2d(1,1);
        glVertex3f(-0.0375,-0.175,-0.05);
        glTexCoord2d(0,1);
	    glVertex3f(0.0375,-0.175,-0.05);
	glEnd();
    glEndList();
}

void Robot::initLeftBehindHand()
{
    TextureFaces tf(texture[RED]);
    tf.back=texture[36];

    LeftBehindHand=glGenLists(1);
    glNewList(LeftBehindHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1,tf);
       glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.175,0.05);

	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	glEnd();
    glBindTexture(GL_TEXTURE_2D,texture[17]);
	glBegin(GL_QUADS);
        glTexCoord2d(0,0);
	    glVertex3f(0.0375,-0.075,-0.05);
        glTexCoord2d(1,0);
	    glVertex3f(-0.0375,-0.075,-0.05);
        glTexCoord2d(1,1);
	    glVertex3f(-0.0375,-0.175,0.05);
        glTexCoord2d(0,1);
	    glVertex3f(0.0375,-0.175,0.05);
	glEnd();
    glEndList();
}
  
void Robot::initRightBehindHand()
{
    TextureFaces tf(texture[RED]);
    tf.back=texture[38];

    RightBehindHand=glGenLists(1);
    glNewList(RightBehindHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1,tf);
      glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.175,0.05);

	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	glEnd();
    glBindTexture(GL_TEXTURE_2D,texture[21]);
	glBegin(GL_QUADS);
        glTexCoord2d(0,0);
        glVertex3f(0.0375,-0.075,-0.05);
        glTexCoord2d(1,0);
        glVertex3f(-0.0375,-0.075,-0.05);
        glTexCoord2d(1,1);
        glVertex3f(-0.0375,-0.175,0.05);
        glTexCoord2d(0,1);
	    glVertex3f(0.0375,-0.175,0.05);
	glEnd();
    glEndList();
}

void Robot::initLeftUpperLeg()
{
    TextureFaces tf(texture[BLUE]);
    tf.left= texture[13];
    tf.bottom= texture[28];

    LeftUpperLeg=glGenLists(1);
    glNewList(LeftUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.2,0.15,tf);
    glEndList();
}

void Robot::initLeftLowerLeg()
{
    TextureFaces tf(texture[RED]);
    tf.left=texture[10];
    tf.top=texture[27];
    tf.back=texture[31];

    LeftLowerLeg=glGenLists(1);
    glNewList(LeftLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.3,0.15,tf);
    glEndList();
}
  
void Robot::initRightUpperLeg()
{
    TextureFaces tf(texture[BLUE]);
    tf.right= texture[13];
    tf.bottom= texture[30];

    RightUpperLeg=glGenLists(1);
    glNewList(RightUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.2,0.15,tf);
    glEndList();
}
  
void Robot::initRightLowerLeg()
{
    TextureFaces tf(texture[RED]);
    tf.right=texture[10];
    tf.top=texture[29];
    tf.back=texture[32];

    RightLowerLeg=glGenLists(1);
    glNewList(RightLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.3,0.15,tf);
    glEndList();
}
  
void Robot::initLeftFoot()
{
    TextureFaces tf(texture[BLUE]);
    tf.left= texture[RIGHT_FOOT_RIGHT];
    tf.front=texture[33];

    LeftFoot=glGenLists(1);
    glNewList(LeftFoot,GL_COMPILE);
    defineCuboid(0.15,0.05,0.15,tf);
    glEndList();
}
  
void Robot::initRightFoot()
{
    TextureFaces tf(texture[BLUE]);
    tf.right= texture[RIGHT_FOOT_RIGHT];
    tf.front=texture[34];

    RightFoot=glGenLists(1);
    glNewList(RightFoot,GL_COMPILE);
    defineCuboid(0.15,0.05,0.15,tf);
    glEndList();
}

void Robot::makeHip(double tx,double ty,double tz,double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    //glTranslatef(0,-0.05,0);
     glTranslatef(0,-0.5,0);
    glTranslatef(tx,ty,tz);	
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glRotatef(angle_z,0,0,1);
   
    glEnable(GL_TEXTURE_2D);
    glCallList(Hip);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeBust(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(Bust_Hip_Joint.x,Bust_Hip_Joint.y,Bust_Hip_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-Bust_Lower_Point.x,-Bust_Lower_Point.y,-Bust_Lower_Point.z);	

    glEnable(GL_TEXTURE_2D);
    glCallList(Bust);
    
    glBindTexture(GL_TEXTURE_2D,texture[WHEEL]);
    glTranslatef(0.150,0.19,-0.075);
    glRotatef(keys.key_frame.wheel_angle,0,0,1);
    glRotatef(keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-90,0,1,0);
    defineCylinder(0.075,0.1,24,1);
    glRotatef(90,0,1,0);
    glRotatef(-keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-keys.key_frame.wheel_angle,0,0,1);
    glTranslatef(-0.15,-0.19,0.075);
    
    glTranslatef(-0.150,0.19,-0.075);
    glRotatef(keys.key_frame.wheel_angle,0,0,1);
    glRotatef(keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-90,0,1,0);
    defineCylinder(0.075,0.1,24,1);
    glRotatef(90,0,1,0);
    glRotatef(-keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-keys.key_frame.wheel_angle,0,0,1);
    glTranslatef(0.15,-0.19,0.075);
    
    glDisable(GL_TEXTURE_2D);
}

  
void Robot::makeNeck(void)
{
    //Tranformations
    glTranslatef(NeckBustJoint.x,NeckBustJoint.y,NeckBustJoint.z);
    glTranslatef(-Neck_Lower_Point.x,-Neck_Lower_Point.y,-Neck_Lower_Point.z);
    
    // glEnable(GL_TEXTURE_2D);
    glCallList(Neck);
    // glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeHead(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(HeadNeckJoint.x,HeadNeckJoint.y,HeadNeckJoint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-Head_Lower_Point.x,-Head_Lower_Point.y,-Head_Lower_Point.z);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(Head);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftShoulder()
{
    //Tranformations
    glTranslatef(LeftShoulder_Bust_Joint.x,LeftShoulder_Bust_Joint.y,LeftShoulder_Bust_Joint.z);
    glTranslatef(-Left_Shoulder_Lower_Point.x,-Left_Shoulder_Lower_Point.y,-Left_Shoulder_Lower_Point.z);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftShoulder);
    glDisable(GL_TEXTURE_2D);
}
void Robot::makeRightShoulder()
{
   //Tranformations
    glTranslatef(RightShoulder_Bust_Joint.x,RightShoulder_Bust_Joint.y,RightShoulder_Bust_Joint.z);
    glTranslatef(-Right_Shoulder_Lower_Point.x,-Right_Shoulder_Lower_Point.y,-Right_Shoulder_Lower_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightShoulder);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(LeftShoulder_LeftUpperArmFront_Joint.x,LeftShoulder_LeftUpperArmFront_Joint.y,LeftShoulder_LeftUpperArmFront_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftUpperArmFront_Upper_Point.x,-LeftUpperArmFront_Upper_Point.y,-LeftUpperArmFront_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperArmFront);
    glDisable(GL_TEXTURE_2D);
}  
void Robot::makeLeftLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-LeftLowerArmFront_Upper_Point.x,-LeftLowerArmFront_Upper_Point.y,-LeftLowerArmFront_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerArmFront);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(RightShoulder_RightUpperArmFront_Joint.x,RightShoulder_RightUpperArmFront_Joint.y,RightShoulder_RightUpperArmFront_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperArmFront_Upper_Point.x,-RightUpperArmFront_Upper_Point.y,-RightUpperArmFront_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperArmFront);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-RightLowerArmFront_Upper_Point.x,-RightLowerArmFront_Upper_Point.y,-RightLowerArmFront_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightLowerArmFront);
    glDisable(GL_TEXTURE_2D);
}


void Robot::makeLeftUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftUpperArmBehind_Joint.x,LeftUpperArmFront_LeftUpperArmBehind_Joint.y,LeftUpperArmFront_LeftUpperArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftUpperArmBehind_Right_Point.x,-LeftUpperArmBehind_Right_Point.y,-LeftUpperArmBehind_Right_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftLowerArmBehind(double angle_y)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftLowerArmBehind_Joint.x,LeftLowerArmFront_LeftLowerArmBehind_Joint.y,LeftLowerArmFront_LeftLowerArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftLowerArmBehind_Right_Point.x,-LeftLowerArmBehind_Right_Point.y,-LeftLowerArmBehind_Right_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeRightUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightUpperArmFront_RightUpperArmBehind_Joint.x,RightUpperArmFront_RightUpperArmBehind_Joint.y,RightUpperArmFront_RightUpperArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperArmBehind_Left_Point.x,-RightUpperArmBehind_Left_Point.y,-RightUpperArmBehind_Left_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeRightLowerArmBehind(double angle_y)
{
    //Tranformations
    glTranslatef(RightLowerArmFront_RightLowerArmBehind_Joint.x,RightLowerArmFront_RightLowerArmBehind_Joint.y,RightLowerArmFront_RightLowerArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightLowerArmBehind_Left_Point.x,-RightLowerArmBehind_Left_Point.y,-RightLowerArmBehind_Left_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightLowerArmBehind);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftFrontHand(double angle_x)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftFrontHand_Joint.x,LeftLowerArmFront_LeftFrontHand_Joint.y,LeftLowerArmFront_LeftFrontHand_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-LeftFrontHand_Upper_Point.x,-LeftFrontHand_Upper_Point.y,-LeftFrontHand_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftFrontHand);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightFrontHand(double angle_x)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightFrontHand_Joint.x,RightLowerArmFront_RightFrontHand_Joint.y,RightLowerArmFront_RightFrontHand_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-RightFrontHand_Upper_Point.x,-RightFrontHand_Upper_Point.y,-RightFrontHand_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightFrontHand);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftBehindHand(double angle_y)
{
    //Tranformations
    glTranslatef(LeftFrontHand_LeftBehindHand_Joint.x,LeftFrontHand_LeftBehindHand_Joint.y,LeftFrontHand_LeftBehindHand_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftBehindHand_Upper_Point.x,-LeftBehindHand_Upper_Point.y,-LeftBehindHand_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftBehindHand);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightBehindHand(double angle_y)
{
    //Tranformations
     glTranslatef(RightFrontHand_RightBehindHand_Joint.x,RightFrontHand_RightBehindHand_Joint.y,RightFrontHand_RightBehindHand_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightBehindHand_Upper_Point.x,-RightBehindHand_Upper_Point.y,-RightBehindHand_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightBehindHand);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_LeftUpperLeg_Joint.x,Hip_LeftUpperLeg_Joint.y,Hip_LeftUpperLeg_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftUpperLeg_Upper_Point.x,-LeftUpperLeg_Upper_Point.y, -LeftUpperLeg_Upper_Point.z);	
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperLeg);

    glBindTexture(GL_TEXTURE_2D,texture[WHEEL]);
    glTranslatef(0.075,0,-0.075);
    glRotatef(keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-90,0,1,0);
    defineCylinder(0.075,0.1,24,1);    
    glRotatef(90,0,1,0);
    glRotatef(-keys.key_frame.wheel_rotate,1,0,0);
    glTranslatef(-0.075,0,0.075);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftLowerLeg(double angle_x)
{
    glTranslatef(LeftUpperLeg_LeftLowerLeg_Joint.x,LeftUpperLeg_LeftLowerLeg_Joint.y,LeftUpperLeg_LeftLowerLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftLowerLeg_Upper_Point.x,-LeftLowerLeg_Upper_Point.y,-LeftLowerLeg_Upper_Point.z);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerLeg);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_RightUpperLeg_Joint.x,Hip_RightUpperLeg_Joint.y,Hip_RightUpperLeg_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-RightUpperLeg_Upper_Point.x,-RightUpperLeg_Upper_Point.y,-RightUpperLeg_Upper_Point.z);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperLeg);

    glBindTexture(GL_TEXTURE_2D,texture[WHEEL]);
    glTranslatef(-0.075,0,-0.075);
    glRotatef(keys.key_frame.wheel_rotate,1,0,0);
    glRotatef(-90,0,1,0);
    defineCylinder(0.075,0.1,24,1);    
    glRotatef(90,0,1,0);
    glRotatef(-keys.key_frame.wheel_rotate,1,0,0);
    glTranslatef(0.075,0,0.075);
    
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightLowerLeg(double angle_x)
{
   glTranslatef(RightUpperLeg_RightLowerLeg_Joint.x,RightUpperLeg_RightLowerLeg_Joint.y,RightUpperLeg_RightLowerLeg_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(-RightLowerLeg_Upper_Point.x,-RightLowerLeg_Upper_Point.y,-RightLowerLeg_Upper_Point.z);
    
   glEnable(GL_TEXTURE_2D);
   glCallList(RightLowerLeg);
   glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftFoot(double angle_x)
{
  //Tranformations
   glTranslatef(LeftLowerLeg_LeftFoot_Joint.x,LeftLowerLeg_LeftFoot_Joint.y,LeftLowerLeg_LeftFoot_Joint.z);
   glRotatef(-angle_x,1,0,0);
   glTranslatef(-LeftFoot_Behind_Point.x,-LeftFoot_Behind_Point.y,-LeftFoot_Behind_Point.z);
    
   glEnable(GL_TEXTURE_2D);
  glCallList(LeftFoot);
  glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightFoot(double angle_x)
{
  //Tranformations
    glTranslatef(RightLowerLeg_RightFoot_Joint.x,RightLowerLeg_RightFoot_Joint.y,RightLowerLeg_RightFoot_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-RightFoot_Behind_Point.x,-RightFoot_Behind_Point.y,-RightFoot_Behind_Point.z);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(RightFoot);
    glDisable(GL_TEXTURE_2D);
}

void Robot::setFrameConstraints()
{
    if(keys.frame >= 2)
    {
        behindArmAngle=180;
        RightShoulder_Bust_Joint=point(-0.15,0.25,0);
        LeftShoulder_Bust_Joint=point(0.15,0.25,0);
        Hip_LeftUpperLeg_Joint=point(0.075,-0.075,0);
        Hip_RightUpperLeg_Joint=point(-0.075,-0.075,0);
        Bust_Hip_Joint=point(0,0.075,0);
    }
    else
    {
        behindArmAngle=0;
        RightShoulder_Bust_Joint=point(-0.15,0.25,0);
        LeftShoulder_Bust_Joint=point(0.15,0.25,0);
        Hip_LeftUpperLeg_Joint=point(0.075,-0.075,0);
        Hip_RightUpperLeg_Joint=point(-0.075,-0.075,0);
        Bust_Hip_Joint=point(0,0.075,0);
    }
    if(keys.frame >= 5)
    {
        RightShoulder_Bust_Joint=point(-0.1,0.25,0);
        LeftShoulder_Bust_Joint=point(0.1,0.25,0);
        Hip_LeftUpperLeg_Joint=point(0.075,-0.075,0);
        Hip_RightUpperLeg_Joint=point(-0.075,-0.075,0);
        Bust_Hip_Joint=point(0,0.075,0);
    }
    if(keys.frame >= 7)
    { 
        Hip_LeftUpperLeg_Joint=point(0.075,0,0);
        Hip_RightUpperLeg_Joint=point(-0.075,0,0);
        Bust_Hip_Joint=point(0,0,0);
    }
    if(keys.frame >= 9)
    {
        // glTranslatef(0,-1.8,0);
        // glRotatef(90,0,0,1);
        // glRotatef(90,0,1,0);
        // glTranslatef(0,1.4,0);
    }

}

void Robot::initLights() {
    //HeadLight1
    GLfloat light_position3[4]={0,-1.37,0,1};
    GLfloat light_diffuse3[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular3[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat spot_direction3[4]={0,-1.5,0};
    Head_light1=SpotLight(light_position3,light_diffuse3,light_specular3,spot_direction3,GL_LIGHT2);

    //HeadLight2
    GLfloat light_position4[4]={0,-1.37,0,1};
    GLfloat light_diffuse4[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular4[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat spot_direction4[4]={0,-1.5,0};
    Head_light2=SpotLight(light_position4,light_diffuse4,light_specular4,spot_direction4,GL_LIGHT3);

}

void Robot::setLights() {
    if(!keys.isCarMode){
        Head_light1.light = false;
        Head_light2.light = false;
    }
    if(keys.isCarMode){
        //Headlight position calculations
        double x = keys.key_frame.hip_TX;
        double y = keys.key_frame.hip_TZ;

        double dist = 0.67-0.02;
        double angle = keys.key_frame.hip_Z;
        double delta_x = dist * sin( angle * M_PI / 180);
        double delta_y = dist * cos( angle * M_PI / 180);

        double dist_centre = 1.2;
        double delta_x_centre = dist_centre * sin( angle * M_PI / 180);
        double delta_y_centre = dist_centre * cos( angle * M_PI / 180);

        double dist2=0.13-0.03;
        double angle2=keys.key_frame.hip_Z;
        double delta_x2 = dist2 * cos( angle2 * M_PI / 180);
        double delta_y2 = dist2 * sin( angle2 * M_PI / 180);

        //HeadLight1
        Head_light1.updatePosition((x-delta_x-delta_x2),-1.47,(y-delta_y+delta_y2));
        Head_light1.updateDirection(-delta_x_centre,0-0.2,-delta_y_centre);

        //HeadLight2
        Head_light2.updatePosition(x-delta_x+delta_x2,-1.47,y-delta_y-delta_y2);
        Head_light2.updateDirection(-delta_x_centre,0-0.2,-delta_y_centre);
        
        double color = 0;
        glPushMatrix();
            glTranslatef((x-delta_x-delta_x2),-1.47,(y-delta_y+delta_y2));
            if(!Head_light1.light)
                color = 0.1;
            else
                color = 0.91;
            glRotatef(angle,0,1,0);
            defineCylinder(0.03,0.03,20,color);
         glPopMatrix();
        
        
          glPushMatrix();
            glTranslatef((x-delta_x+delta_x2),-1.47,(y-delta_y-delta_y2));
            if(!Head_light2.light)
                color = 0.1;
            else
                color = 0.91;
            glRotatef(angle,0,1,0);
            defineCylinder(0.03,0.03,20,color);
          glPopMatrix();
    }


    Head_light1.initScene();
    Head_light2.initScene();
}

void Robot::setRobotProperties(){
    GLfloat scene_specular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat scene_diffuse[4]={1.0, 0.7, 0.7, 1.0};
    glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
    glMaterialfv(GL_FRONT, GL_SPECULAR, scene_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, scene_diffuse);
}

// void Robot::makeHeadLights() {
        
// }

void Robot::makeRobot(void)
{   
    keys.movement(glfwGetCurrentContext());
    setLights();

    glPushMatrix();
    setFrameConstraints();
    makeHip(keys.key_frame.hip_TX,keys.key_frame.hip_TY,keys.key_frame.hip_TZ,keys.key_frame.hip_X,keys.key_frame.hip_Y,keys.key_frame.hip_Z);

    glPushMatrix();
        makeLeftUpperLeg(keys.key_frame.leftUpperLeg_X,keys.key_frame.leftUpperLeg_Y,keys.key_frame.leftUpperLeg_Z);
        makeLeftLowerLeg(keys.key_frame.leftLowerLeg_X);
        makeLeftFoot(keys.key_frame.leftFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeRightUpperLeg(keys.key_frame.rightUpperLeg_X,keys.key_frame.rightUpperLeg_Y,keys.key_frame.rightUpperLeg_Z);
        makeRightLowerLeg(keys.key_frame.rightLowerLeg_X);
        makeRightFoot(keys.key_frame.rightFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeBust(keys.key_frame.bust_X,keys.key_frame.bust_Y,keys.key_frame.bust_Z);

        glPushMatrix();
	        makeLeftShoulder();
            makeLeftUpperArmFront(keys.key_frame.leftUpperArm_X,keys.key_frame.leftUpperArm_Y,keys.key_frame.leftUpperArm_Z);
    		glPushMatrix();
    		    makeLeftUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftLowerArmFront(keys.key_frame.leftLowerArm_X);
    		glPushMatrix();
    		    makeLeftLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeLeftFrontHand(keys.key_frame.leftHand_X);
    		glPushMatrix();
    		    makeLeftBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
	        makeRightShoulder();
            makeRightUpperArmFront(keys.key_frame.rightUpperArm_X,keys.key_frame.rightUpperArm_Y,keys.key_frame.rightUpperArm_Z);
    		glPushMatrix();
    		    makeRightUpperArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightLowerArmFront(keys.key_frame.rightLowerArm_X);
    		glPushMatrix();
    		    makeRightLowerArmBehind(behindArmAngle);
    		glPopMatrix();
                makeRightFrontHand(keys.key_frame.rightHand_X);
    		glPushMatrix();
    		    makeRightBehindHand(behindArmAngle);
    		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(keys.key_frame.head_X,keys.key_frame.head_Y,keys.key_frame.head_Z);
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

string Robot::getHeadLightVector() {
    ostringstream str;

    str << Head_light1.light << " " << Head_light2.light ;

    string out = str.str();

    return out;
}

void Robot::setHeadLightVector(string vector) {
    istringstream str(vector);
    
    str >> Head_light1.light >> Head_light2.light ;
}