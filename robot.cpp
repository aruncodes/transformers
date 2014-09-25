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
void Robot::initLeftUpperArmFront()
    {
    LeftUpperArmFront=glGenLists(1);
    glNewList(LeftUpperArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initLeftLowerArmFront()
    {
    LeftLowerArmFront=glGenLists(1);
    glNewList(LeftLowerArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initRightUpperArmFront()
    {
    RightUpperArmFront=glGenLists(1);
    glNewList(RightUpperArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initRightLowerArmFront()
    {
    RightLowerArmFront=glGenLists(1);
    glNewList(RightLowerArmFront,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}
  

void Robot::initLeftUpperArmBehind()
    {
    LeftUpperArmBehind=glGenLists(1);
    glNewList(LeftUpperArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initLeftLowerArmBehind()
    {
    LeftLowerArmBehind=glGenLists(1);
    glNewList(LeftLowerArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initRightUpperArmBehind()
    {
    RightUpperArmBehind=glGenLists(1);
    glNewList(RightUpperArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initRightLowerArmBehind()
    {
    RightLowerArmBehind=glGenLists(1);
    glNewList(RightLowerArmBehind,GL_COMPILE);
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initLeftFrontHand()
    {
    LeftFrontHand=glGenLists(1);
    glNewList(LeftFrontHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1);
       glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.175,0.05);

	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	    glVertex3f(0.0375,-0.175,0.05);
	glEnd();
    glEndList();
}
  
void Robot::initRightFrontHand()
{
    RightFrontHand=glGenLists(1);
    glNewList(RightFrontHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1);
      glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.175,0.05);

	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.175,0.05);
	    glVertex3f(0.0375,-0.175,0.05);
	glEnd();
    glEndList();
}


void Robot::initLeftBehindHand()
    {
    LeftBehindHand=glGenLists(1);
    glNewList(LeftBehindHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1);
       glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.175,-0.05);

	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.175,-0.05);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.175,-0.05);
	    glVertex3f(0.0375,-0.175,-0.05);
	glEnd();
    glEndList();
}
  
void Robot::initRightBehindHand()
{
    RightBehindHand=glGenLists(1);
    glNewList(RightBehindHand,GL_COMPILE);
    defineCuboid(0.075,0.15,0.1);
      glBegin(GL_TRIANGLES);
	    glVertex3f(0.0375,-0.075,-0.05);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(0.0375,-0.175,-0.05);

	    glVertex3f(-0.0375,-0.075,-0.05);
	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.175,-0.05);
	glEnd();
	glBegin(GL_QUADS);
	    glVertex3f(0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.075,0.05);
	    glVertex3f(-0.0375,-0.175,-0.05);
	    glVertex3f(0.0375,-0.175,-0.05);
	glEnd();
    glEndList();
}




void Robot::initLeftUpperLeg()
    {
    LeftUpperLeg=glGenLists(1);
    glNewList(LeftUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.2,0.15);
    glEndList();
}

void Robot::initLeftLowerLeg()
    {
    LeftLowerLeg=glGenLists(1);
    glNewList(LeftLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.3,0.15);
    glEndList();
}
  
void Robot::initRightUpperLeg()
{
    RightUpperLeg=glGenLists(1);
    glNewList(RightUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.2,0.15);
    glEndList();
}
  
void Robot::initRightLowerLeg()
{
    RightLowerLeg=glGenLists(1);
    glNewList(RightLowerLeg,GL_COMPILE);
    defineCuboid(0.15,0.3,0.15);
    glEndList();
}
  
void Robot::initLeftFoot()
{
    LeftFoot=glGenLists(1);
    glNewList(LeftFoot,GL_COMPILE);
    defineCuboid(0.15,0.05,0.15);
    glEndList();
}
  
void Robot::initRightFoot()
{
    RightFoot=glGenLists(1);
    glNewList(RightFoot,GL_COMPILE);
    defineCuboid(0.15,0.05,0.15);
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
  
void Robot::makeLeftUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(LeftShoulder_LeftUpperArmFront_Joint.x,LeftShoulder_LeftUpperArmFront_Joint.y,LeftShoulder_LeftUpperArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0.0375,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftUpperArmFront);
}  
void Robot::makeLeftLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.125,-0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftLowerArmFront);
}
  
void Robot::makeRightUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(RightShoulder_RightUpperArmFront_Joint.x,RightShoulder_RightUpperArmFront_Joint.y,RightShoulder_RightUpperArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-0.0375,-0.125,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightUpperArmFront);
}
  
void Robot::makeRightLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.125,-0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightLowerArmFront);
}


void Robot::makeLeftUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftUpperArmBehind_Joint.x,LeftUpperArmFront_LeftUpperArmBehind_Joint.y,LeftUpperArmFront_LeftUpperArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-0.0375,0,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftUpperArmBehind);
}

void Robot::makeLeftLowerArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftLowerArmFront_LeftLowerArmBehind_Joint.x,LeftLowerArmFront_LeftLowerArmBehind_Joint.y,LeftLowerArmFront_LeftLowerArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-0.0375,0,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftLowerArmBehind);
}

void Robot::makeRightUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightUpperArmFront_RightUpperArmBehind_Joint.x,RightUpperArmFront_RightUpperArmBehind_Joint.y,RightUpperArmFront_RightUpperArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(0.0375,0,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightUpperArmBehind);
}

void Robot::makeRightLowerArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightLowerArmBehind_Joint.x,RightLowerArmFront_RightLowerArmBehind_Joint.y,RightLowerArmFront_RightLowerArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(0.0375,0,0.025);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightLowerArmBehind);
}
  
void Robot::makeLeftFrontHand(double angle_x)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftFrontHand_Joint.x,LeftLowerArmFront_LeftFrontHand_Joint.y,LeftLowerArmFront_LeftFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.075,-0.05);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftFrontHand);
}
  
void Robot::makeRightFrontHand(double angle_x)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightFrontHand_Joint.x,RightLowerArmFront_RightFrontHand_Joint.y,RightLowerArmFront_RightFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(0,-0.075,-0.05);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightFrontHand);
}

void Robot::makeLeftBehindHand(double angle_y)
{
    //Tranformations
    glTranslatef(LeftFrontHand_LeftBehindHand_Joint.x,LeftFrontHand_LeftBehindHand_Joint.y,LeftFrontHand_LeftBehindHand_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-0.0375,0,0.05);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftBehindHand);
}
  
void Robot::makeRightBehindHand(double angle_y)
{
    //Tranformations
     glTranslatef(RightFrontHand_RightBehindHand_Joint.x,RightFrontHand_RightBehindHand_Joint.y,RightFrontHand_RightBehindHand_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(0.0375,0,0.05);	
    glColor3f(0.9,0.91,0.98);
    glCallList(RightBehindHand);
}



  
void Robot::makeLeftUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_LeftUpperLeg_Joint.x,Hip_LeftUpperLeg_Joint.y,Hip_LeftUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(0,-0.1,0);	
    glColor3f(0.9,0.91,0.98);
    glCallList(LeftUpperLeg);
}
  
void Robot::makeLeftLowerLeg(double angle_x)
{
    glTranslatef(LeftUpperLeg_LeftLowerLeg_Joint.x,LeftUpperLeg_LeftLowerLeg_Joint.y,LeftUpperLeg_LeftLowerLeg_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(0,-0.15,0.075);
    glColor3f(0.8,0.8,0.88);
    glCallList(LeftLowerLeg);
}



  
void Robot::makeRightUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_RightUpperLeg_Joint.x,Hip_RightUpperLeg_Joint.y,Hip_RightUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(0,-0.1,0);
    glColor3f(0.9,0.9,0.98);
    glCallList(RightUpperLeg);
}
  
void Robot::makeRightLowerLeg(double angle_x)
{
   glTranslatef(RightUpperLeg_RightLowerLeg_Joint.x,RightUpperLeg_RightLowerLeg_Joint.y,RightUpperLeg_RightLowerLeg_Joint.z);
   glRotatef(-angle_x,1,0,0);
   glTranslatef(0,-0.15,0.075);
   glColor3f(0.8,0.8,0.88);
   glCallList(RightLowerLeg);
}
  
void Robot::makeLeftFoot(double angle_x)
{
  //Tranformations
   glTranslatef(LeftLowerLeg_LeftFoot_Joint.x,LeftLowerLeg_LeftFoot_Joint.y,LeftLowerLeg_LeftFoot_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(0,-0.025,0);
   glColor3f(0.8,0.8,0.88);
  glCallList(LeftFoot);
}
  
void Robot::makeRightFoot(double angle_x)
{
  //Tranformations
  glTranslatef(RightLowerLeg_RightFoot_Joint.x,RightLowerLeg_RightFoot_Joint.y,RightLowerLeg_RightFoot_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(0,-0.025,0);
   glColor3f(0.8,0.8,0.88);
  glCallList(RightFoot);
}


void Robot::makeRobot(void)
{
    //glLoadIdentity();

    glPushMatrix();
    makeHip(0,0,0,0);

    glPushMatrix();
        makeLeftUpperLeg(0,0,30);
        makeLeftLowerLeg(0);
        makeLeftFoot(0);
    glPopMatrix();

    glPushMatrix();
        makeRightUpperLeg(0,0,30);
        makeRightLowerLeg(0);
        makeRightFoot(0);
    glPopMatrix();

    glPushMatrix();
        makeBust(0,0,0);

        glPushMatrix();
	    makeLeftShoulder();
            makeLeftUpperArmFront(0,0,0);
		glPushMatrix();
		    makeLeftUpperArmBehind(0);
		glPopMatrix();
            makeLeftLowerArmFront(0);
		glPushMatrix();
		    makeLeftLowerArmBehind(0);
		glPopMatrix();
            makeLeftFrontHand(0);
		glPushMatrix();
		    makeLeftBehindHand(0);
		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
	    makeRightShoulder();
            makeRightUpperArmFront(0,0,0);
		glPushMatrix();
		    makeRightUpperArmBehind(0);
		glPopMatrix();
            makeRightLowerArmFront(0);
		glPushMatrix();
		    makeRightLowerArmBehind(0);
		glPopMatrix();
            makeRightFrontHand(0);
		glPushMatrix();
		    makeRightBehindHand(0);
		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(0,0,0);
        glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}
