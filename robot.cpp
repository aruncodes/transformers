#include <cmath>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>

#include "robot.hpp"
#include "blocks.hpp"

using namespace Blocks;

void Robot::initHip()
{
    Hip=glGenLists(1); 
    glNewList(Hip,GL_COMPILE);
    defineTrapizoid(0.2,0.15,0.15,0.15);
    glEndList();
}

void Robot::initBust()
{
    Bust=glGenLists(1);
    glNewList(Bust,GL_COMPILE);
    defineCuboid(0.3,0.5,0.15);
    glEndList();
}

void Robot::initNeck()
{
    Neck=glGenLists(1);
    glNewList(Neck,GL_COMPILE);
    defineTrapizoid(0.15+0.05/3,0.15,0.15,0.05);
    glEndList();
}
  
void Robot::initHead()
{
    Head=glGenLists(1);
    glNewList(Head,GL_COMPILE);
    defineTrapizoid(0.2,0.15+0.05/3,0.15,0.1);
    glEndList();
}

void Robot::initLeftShoulder()
{
    LeftShoulder=glGenLists(1);
    glNewList(LeftShoulder,GL_COMPILE);
      defineCuboid(0.05,0.15,0.15);
	glBegin(GL_TRIANGLES);
	    glVertex3f(-0.025,0.075,-0.075);
	    glVertex3f(-0.05,-0.075,-0.075);
	    glVertex3f(-0.025,-0.075,-0.075);

	    glVertex3f(-0.025,0.075,0.075);
	    glVertex3f(-0.05,-0.075,0.075);
	    glVertex3f(-0.025,-0.075,0.075);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(-0.025,0.075,-0.075);
	    glVertex3f(-0.025,0.075,0.075);
	    glVertex3f(-0.05,-0.075,-0.075);
	     glVertex3f(-0.05,-0.075,0.075);
	glEnd();
    glEndList();
}
void Robot::initRightShoulder()
{
    RightShoulder=glGenLists(1);
    glNewList(RightShoulder,GL_COMPILE);
	defineCuboid(0.05,0.15,0.15);
	glBegin(GL_TRIANGLES);
	    glVertex3f(0.025,0.075,-0.075);
	    glVertex3f(0.05,-0.075,-0.075);
	    glVertex3f(0.025,-0.075,-0.075);

	    glVertex3f(0.025,0.075,0.075);
	    glVertex3f(0.05,-0.075,0.075);
	    glVertex3f(0.025,-0.075,0.075);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.025,0.075,-0.075);
	    glVertex3f(0.025,0.075,0.075);
	    glVertex3f(0.05,-0.075,-0.075);
	     glVertex3f(0.05,-0.075,0.075);
	glEnd();
    glEndList();
}
void Robot::initLeftUpperArm()
{
    LeftUpperArm=glGenLists(1);
    glNewList(LeftUpperArm,GL_COMPILE);
    defineCuboid(0.15,0.25,0.05);
    glEndList();
}

void Robot::initLeftLowerArm()
{
    LeftLowerArm=glGenLists(1);
    glNewList(LeftLowerArm,GL_COMPILE);
    defineCuboid(0.15,0.25,0.05);
    glEndList();
}

void Robot::initRightUpperArm()
{
    RightUpperArm=glGenLists(1);
    glNewList(RightUpperArm,GL_COMPILE);
    defineCuboid(0.15,0.25,0.05);
    glEndList();
}

void Robot::initRightLowerArm()
{
    RightLowerArm=glGenLists(1);
    glNewList(RightLowerArm,GL_COMPILE);
    defineCuboid(0.15,0.25,0.05);
    glEndList();
}
  

void Robot::initLeftHand()
{
    LeftHand=glGenLists(1);
    glNewList(LeftHand,GL_COMPILE);

    glEndList();
}
  
void Robot::initRightHand()
{
    RightHand=glGenLists(1);
    glNewList(RightHand,GL_COMPILE);

    glEndList();
}


void Robot::initLeftUpperLeg()
{
    LeftUpperLeg=glGenLists(1);
    glNewList(LeftUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.25,0.15);
    glEndList();
}

void Robot::initLeftLowerLeg()
{
    LeftLowerLeg=glGenLists(1);
    glNewList(LeftLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.25,0.15);
    glEndList();
}
  
void Robot::initRightUpperLeg()
{
    RightUpperLeg=glGenLists(1);
    glNewList(RightUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.25,0.15);
    glEndList();
}
  
void Robot::initRightLowerLeg()
{
    RightLowerLeg=glGenLists(1);
    glNewList(RightLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.25,0.15);
    glEndList();
}
  
void Robot::initLeftFoot()
{
    LeftFoot=glGenLists(1);
    glNewList(LeftFoot,GL_COMPILE);

    glEndList();
}
  
void Robot::initRightFoot()
{
    RightFoot=glGenLists(1);
    glNewList(RightFoot,GL_COMPILE);

    glEndList();
}

void Robot::makeHip(double tx,double ty,double tz,double angle_y)
{
    //Tranformations
    glTranslatef(tx,ty-0.05,tz);	
    glRotatef(-angle_y,0,1,0);
    glCallList(Hip);
}
  
void Robot::makeBust(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(Bust_Hip_Joint.x,Bust_Hip_Joint.y,Bust_Hip_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0,0.25,0);	
    glColor3f(0.9,0.91,0.98);
    glCallList(Bust);
}

  
void Robot::makeNeck(void)
{
    //Tranformations
    glTranslatef(NeckBustJoint.x,NeckBustJoint.y,NeckBustJoint.z);
    glTranslatef(0,0.025,0);
    glCallList(Neck);
}
  
void Robot::makeHead(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(HeadNeckJoint.x,HeadNeckJoint.y,HeadNeckJoint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0,0.05,0);
    glCallList(Head);
}

void Robot::makeLeftShoulder()
{
    //Tranformations
     glTranslatef(LeftShoulder_Bust_Joint.x,LeftShoulder_Bust_Joint.y,LeftShoulder_Bust_Joint.z);
    glTranslatef(0.025,0.075,0);
    glCallList(LeftShoulder);
}
void Robot::makeRightShoulder()
{
   //Tranformations
    glTranslatef(RightShoulder_Bust_Joint.x,RightShoulder_Bust_Joint.y,RightShoulder_Bust_Joint.z);
    glTranslatef(-0.025,0.075,0);	
    glCallList(RightShoulder);
}
  
void Robot::makeLeftUpperArm(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(LeftShoulder_LeftUpperArm_Joint.x,LeftShoulder_LeftUpperArm_Joint.y,LeftShoulder_LeftUpperArm_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0.075,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftUpperArm);
}  
void Robot::makeLeftLowerArm(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArm_LeftLowerArm_Joint.x,LeftUpperArm_LeftLowerArm_Joint.y,LeftUpperArm_LeftLowerArm_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftLowerArm);
}
  
void Robot::makeRightUpperArm(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(RightShoulder_RightUpperArm_Joint.x,RightShoulder_RightUpperArm_Joint.y,RightShoulder_RightUpperArm_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-0.075,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightUpperArm);
}
  
void Robot::makeRightLowerArm(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArm_LeftLowerArm_Joint.x,LeftUpperArm_LeftLowerArm_Joint.y,LeftUpperArm_LeftLowerArm_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightLowerArm);
}
  
void Robot::makeLeftHand(double angle_x)
{
    //Tranformations
    glCallList(LeftHand);
}
  
void Robot::makeRightHand(double angle_x)
{
    //Tranformations
    glCallList(RightHand);
}


  
void Robot::makeLeftUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_LeftUpperLeg_Joint.x,Hip_LeftUpperLeg_Joint.y,Hip_LeftUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(0,-0.125,0);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftUpperLeg);
}
  
void Robot::makeLeftLowerLeg(double angle_x)
{
    glTranslatef(LeftUpperLeg_LeftLowerLeg_Joint.x,LeftUpperLeg_LeftLowerLeg_Joint.y,LeftUpperLeg_LeftLowerLeg_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(0,-0.125,-0.075);
    glColor3f(0.8,0.8,0.88);
    glCallList(LeftLowerLeg);
}



  
void Robot::makeRightUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_RightUpperLeg_Joint.x,Hip_RightUpperLeg_Joint.y,Hip_RightUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0,-0.125,0);
    glColor3f(0.9,0.9,0.98);
    glCallList(RightUpperLeg);
}
  
void Robot::makeRightLowerLeg(double angle_x)
{
   glTranslatef(RightUpperLeg_RightLowerLeg_Joint.x,RightUpperLeg_RightLowerLeg_Joint.y,RightUpperLeg_RightLowerLeg_Joint.z);
   glRotatef(-angle_x,1,0,0);
   glTranslatef(0,-0.125,-0.075);
   glColor3f(0.8,0.8,0.88);
   glCallList(RightLowerLeg);
}
  
void Robot::makeLeftFoot(double angle_x)
{
  //Tranformations
  glCallList(LeftFoot);
}
  
void Robot::makeRightFoot(double angle_x)
{
  //Tranformations
  glCallList(RightFoot);
}


void Robot::makeRobot(void)
{
    //glLoadIdentity();

    glPushMatrix();
    makeHip(keys.hip_TX,keys.hip_TY,keys.hip_TZ,keys.hip_Y);

    glPushMatrix();
        makeLeftUpperLeg(keys.leftUpperLeg_X,keys.leftUpperLeg_Y,keys.leftUpperLeg_Z);
        makeLeftLowerLeg(keys.leftLowerLeg_X);
        makeLeftFoot(keys.leftFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeRightUpperLeg(keys.rightUpperLeg_X,keys.rightUpperLeg_Y,keys.rightUpperLeg_Z);
        makeRightLowerLeg(keys.rightLowerLeg_X);
        makeRightFoot(keys.rightFoot_X);
    glPopMatrix();

    glPushMatrix();
        makeBust(keys.bust_X,keys.bust_Y,keys.bust_Z);

        glPushMatrix();
	    makeLeftShoulder();
            makeLeftUpperArm(keys.leftUpperArm_X,keys.leftUpperArm_Y,keys.leftUpperArm_Z);
            makeLeftLowerArm(keys.leftLowerArm_X);
            makeLeftHand(keys.leftHand_X);
        glPopMatrix();

        glPushMatrix();
	    makeRightShoulder();
            makeRightUpperArm(keys.rightUpperArm_X,keys.rightUpperArm_Y,keys.rightUpperArm_Z);
            makeRightLowerArm(keys.rightLowerArm_X);
            makeRightHand(keys.rightHand_X);
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(keys.head_X,keys.head_Y,keys.head_Z);
        glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}
