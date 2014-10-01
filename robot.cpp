#include <cmath>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <GL/glew.h>

#include "robot.hpp"
#include "blocks.hpp"

using namespace Blocks;


void Robot::initStructuralConstraints()
{
    //Hip_LeftUpperLeg_Joint=point(0.075,0,0);
    Hip_LeftUpperLeg_Joint=point(0.075,-0.075,0);
    LeftUpperLeg_LeftLowerLeg_Joint=point(0,-0.1,-0.075);
    //Hip_RightUpperLeg_Joint=point(-0.075,0,0);
    Hip_RightUpperLeg_Joint=point(-0.075,-0.075,0);
    RightUpperLeg_RightLowerLeg_Joint=point(0,-0.1,-0.075);
    //Bust_Hip_Joint=point(0,0,0);
    Bust_Hip_Joint=point(0,0.075,0);
    // RightShoulder_Bust_Joint=point(-0.1,0.25,0);
    //LeftShoulder_Bust_Joint=point(0.1,0.25,0);
    RightShoulder_Bust_Joint=point(-0.15,0.25,0);
    LeftShoulder_Bust_Joint=point(0.15,0.25,0);
    NeckBustJoint=point(0,0.25,0);
    HeadNeckJoint=point(0,0.025,0);
    LeftShoulder_LeftUpperArmFront_Joint=point(0.025,0.075,-0.075);
    LeftUpperArmFront_LeftLowerArmFront_Joint=point(0,-0.125,0.025);
    RightShoulder_RightUpperArmFront_Joint=point(-0.025,0.075,-0.075);
    RightUpperArmFront_RightLowerArmFront_Joint=point(0,-0.125,0.025);
    LeftUpperArmFront_LeftUpperArmBehind_Joint=point(0.0375,0,0.025);
    LeftLowerArmFront_LeftLowerArmBehind_Joint=point(0.0375,0,0.025);
    RightUpperArmFront_RightUpperArmBehind_Joint=point(-0.0375,0,0.025);
    RightLowerArmFront_RightLowerArmBehind_Joint=point(-0.0375,0,0.025);
    LeftLowerArmFront_LeftFrontHand_Joint=point(0,-0.125,0.025);
    RightLowerArmFront_RightFrontHand_Joint=point(0,-0.125,0.025);
    LeftLowerLeg_LeftFoot_Joint=point(0,-0.15,-0.075);
    RightLowerLeg_RightFoot_Joint=point(0,-0.15,-0.075);
    LeftFrontHand_LeftBehindHand_Joint=point(0.0375,0,0.05);
    RightFrontHand_RightBehindHand_Joint=point(-0.0375,0,0.05);

    Bust_Lower_Point=point(0,-0.25,0);
    Neck_Lower_Point=point(0,-0.025,0);
    Head_Lower_Point=point(0,-0.05,0);
    Left_Shoulder_Lower_Point=point(-0.025,-0.075,0);
    Right_Shoulder_Lower_Point=point(0.025,-0.075,0);
    LeftUpperArmFront_Upper_Point=point(-0.0375,0.125,-0.025);
    LeftLowerArmFront_Upper_Point=point(0,0.125,0.025);
    RightUpperArmFront_Upper_Point=point(0.0375,0.125,-0.025);
    RightLowerArmFront_Upper_Point=point(0,0.125,0.025);
    
    LeftUpperArmBehind_Right_Point=point(0.0375,0,-0.025);
    LeftLowerArmBehind_Right_Point=point(0.0375,0,-0.025);
    RightUpperArmBehind_Left_Point=point (-0.0375,0,-0.025);
    RightLowerArmBehind_Left_Point=point(-0.0375,0,-0.025);

    LeftFrontHand_Upper_Point=point(0,0.075,0.05);
    RightFrontHand_Upper_Point=point(0,0.075,0.05);
    LeftBehindHand_Upper_Point=point(0.0375,0,-0.05);
    RightBehindHand_Upper_Point=point(-0.0375,0,-0.05);

    LeftUpperLeg_Upper_Point=point(0,0.1,0);
    LeftLowerLeg_Upper_Point=point(0,0.15,-0.075);
    RightUpperLeg_Upper_Point=point(0,0.1,0);
    RightLowerLeg_Upper_Point=point(0,0.15,-0.075);
    LeftFoot_Behind_Point=point(0,-0.025,0.075);
    RightFoot_Behind_Point=point(0,-0.025,0.075);
}


void Robot::initTexture() {
    texture = new GLuint[4];
    glGenTextures(2,texture);

    makeTexture("tex/trans.bmp",400,400,texture[LOGO]);
    makeTexture("tex/blue.bmp",320,480,texture[BLUE]);
    makeTexture("tex/green.bmp",320,480,texture[RED]);
    makeTexture("tex/head.bmp",300,300,texture[HEAD]);
}

void Robot::makeTexture(const char* FilePath,int width,int height, GLuint gltexture)
{
    TextureImage=fopen(FilePath,"rb");
    TextureData=(unsigned char *)malloc(width*height*3);
    
    fread(TextureData,width*height*3,1,TextureImage);
    fclose(TextureImage);
    
    glBindTexture(GL_TEXTURE_2D,gltexture);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_COLOR,GL_REPLACE);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,TextureData);
    
    delete TextureData;
}


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
    
    ////glColor3f(1,1,1);
    glTranslatef(0.150,0.175,0.075);
    glRotatef(90,0,1,0);
    defineCylinder(0.075,0.1,24);
    glRotatef(-90,0,1,0);
    glTranslatef(-0.15,-0.175,-0.075);
    
    glTranslatef(-0.150,0.175,0.075);
    glRotatef(90,0,1,0);
    defineCylinder(0.075,0.1,24);
    glRotatef(-90,0,1,0);
    glTranslatef(0.15,-0.175,-0.075);
    
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
    //defineSphere(0.1,10,10);
    //defineCylinder(0.1,0.3,100);
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
    	//glPushMatrix();
	   //glTranslatef(-0.0325,0.05,0.05);
        //defineSphere(0.05,180,180);
    	//glPopMatrix();
    defineCuboid(0.075,0.25,0.05);
    glEndList();
}

void Robot::initLeftLowerArmFront()
    {
    LeftLowerArmFront=glGenLists(1);
    glNewList(LeftLowerArmFront,GL_COMPILE);	
    defineCuboid(0.075,0.25,0.05);
	   //glPushMatrix();
	   //glTranslatef(0,0.125,0);
        //defineSphere(0.05,180,180);
    	//glPopMatrix();
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
    
    //glColor3f(1,1,1);
    glTranslatef(0.075,0,0.075);
    glRotatef(90,0,1,0);
    defineCylinder(0.075,0.1,24);    
    glRotatef(-90,0,1,0);
    glTranslatef(-0.075,0,-0.075);

    glEndList();
}

void Robot::initLeftLowerLeg()
{
    LeftLowerLeg=glGenLists(1);
    glNewList(LeftLowerLeg,GL_COMPILE);
    //glPushMatrix();
	//glTranslatef(0,0.15,0);
        //defineSphere(0.075,180,180);
    //glPopMatrix();
    defineCuboid(0.15,0.3,0.15);
    glEndList();
}
  
void Robot::initRightUpperLeg()
{
    RightUpperLeg=glGenLists(1);
    glNewList(RightUpperLeg,GL_COMPILE);
    defineCuboid(0.15,0.2,0.15);

    //glColor3f(1,1,1);
    glTranslatef(-0.075,0,0.075);
    glRotatef(90,0,1,0);
    defineCylinder(0.075,0.1,24);    
    glRotatef(-90,0,1,0);
    glTranslatef(0.075,0,-0.075);

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

//    glEnable(GL_TEXTURE_2D);
    glCallList(Hip);
//    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeBust(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(Bust_Hip_Joint.x,Bust_Hip_Joint.y,Bust_Hip_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-Bust_Lower_Point.x,-Bust_Lower_Point.y,-Bust_Lower_Point.z);	

    glBindTexture(GL_TEXTURE_2D,texture[LOGO]);
    
    glEnable(GL_TEXTURE_2D);
    glCallList(Bust);
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
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-Head_Lower_Point.x,-Head_Lower_Point.y,-Head_Lower_Point.z);
    
    glBindTexture(GL_TEXTURE_2D,texture[HEAD]);
    glEnable(GL_TEXTURE_2D);
    glCallList(Head);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftShoulder()
{
    //Tranformations
    glTranslatef(LeftShoulder_Bust_Joint.x,LeftShoulder_Bust_Joint.y,LeftShoulder_Bust_Joint.z);
    glTranslatef(-Left_Shoulder_Lower_Point.x,-Left_Shoulder_Lower_Point.y,-Left_Shoulder_Lower_Point.z);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftShoulder);
    glDisable(GL_TEXTURE_2D);
}
void Robot::makeRightShoulder()
{
   //Tranformations
    glTranslatef(RightShoulder_Bust_Joint.x,RightShoulder_Bust_Joint.y,RightShoulder_Bust_Joint.z);
    glTranslatef(-Right_Shoulder_Lower_Point.x,-Right_Shoulder_Lower_Point.y,-Right_Shoulder_Lower_Point.z);	
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightShoulder);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(LeftShoulder_LeftUpperArmFront_Joint.x,LeftShoulder_LeftUpperArmFront_Joint.y,LeftShoulder_LeftUpperArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftUpperArmFront_Upper_Point.x,-LeftUpperArmFront_Upper_Point.y,-LeftUpperArmFront_Upper_Point.z);	
    //glColor3f(0.1,0.91,0.3);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperArmFront);
    glDisable(GL_TEXTURE_2D);
}  
void Robot::makeLeftLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftLowerArmFront_Upper_Point.x,-LeftLowerArmFront_Upper_Point.y,-LeftLowerArmFront_Upper_Point.z);	
    //glColor3f(0.1,0.3,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerArmFront);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightUpperArmFront(double angle_x,double angle_y,double angle_z)
{
    //Tranformations
    glTranslatef(RightShoulder_RightUpperArmFront_Joint.x,RightShoulder_RightUpperArmFront_Joint.y,RightShoulder_RightUpperArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-RightUpperArmFront_Upper_Point.x,-RightUpperArmFront_Upper_Point.y,-RightUpperArmFront_Upper_Point.z);	
    //glColor3f(0.9,0.91,0.3);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperArmFront);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightLowerArmFront(double angle_x)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftLowerArmFront_Joint.x,LeftUpperArmFront_LeftLowerArmFront_Joint.y,LeftUpperArmFront_LeftLowerArmFront_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightLowerArmFront_Upper_Point.x,-RightLowerArmFront_Upper_Point.y,-RightLowerArmFront_Upper_Point.z);	
    //glColor3f(0.3,0.91,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightLowerArmFront);
    glDisable(GL_TEXTURE_2D);
}


void Robot::makeLeftUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftUpperArmFront_LeftUpperArmBehind_Joint.x,LeftUpperArmFront_LeftUpperArmBehind_Joint.y,LeftUpperArmFront_LeftUpperArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftUpperArmBehind_Right_Point.x,-LeftUpperArmBehind_Right_Point.y,-LeftUpperArmBehind_Right_Point.z);	
    //glColor3f(0.9,0.1,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftLowerArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(LeftLowerArmFront_LeftLowerArmBehind_Joint.x,LeftLowerArmFront_LeftLowerArmBehind_Joint.y,LeftLowerArmFront_LeftLowerArmBehind_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftLowerArmBehind_Right_Point.x,-LeftLowerArmBehind_Right_Point.y,-LeftLowerArmBehind_Right_Point.z);	
    //glColor3f(0.1,0.1,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeRightUpperArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightUpperArmFront_RightUpperArmBehind_Joint.x,RightUpperArmFront_RightUpperArmBehind_Joint.y,RightUpperArmFront_RightUpperArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-RightUpperArmBehind_Left_Point.x,-RightUpperArmBehind_Left_Point.y,-RightUpperArmBehind_Left_Point.z);	
    //glColor3f(0.4,0.21,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperArmBehind);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeRightLowerArmBehind(double angle_y)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightLowerArmBehind_Joint.x,RightLowerArmFront_RightLowerArmBehind_Joint.y,RightLowerArmFront_RightLowerArmBehind_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-RightLowerArmBehind_Left_Point.x,-RightLowerArmBehind_Left_Point.y,-RightLowerArmBehind_Left_Point.z);	
    //glColor3f(0.3,0.1,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightLowerArmBehind);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftFrontHand(double angle_x)
{
    //Tranformations
    glTranslatef(LeftLowerArmFront_LeftFrontHand_Joint.x,LeftLowerArmFront_LeftFrontHand_Joint.y,LeftLowerArmFront_LeftFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-LeftFrontHand_Upper_Point.x,-LeftFrontHand_Upper_Point.y,-LeftFrontHand_Upper_Point.z);	
    //glColor3f(0.5,0.91,0.8);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftFrontHand);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightFrontHand(double angle_x)
{
    //Tranformations
     glTranslatef(RightLowerArmFront_RightFrontHand_Joint.x,RightLowerArmFront_RightFrontHand_Joint.y,RightLowerArmFront_RightFrontHand_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightFrontHand_Upper_Point.x,-RightFrontHand_Upper_Point.y,-RightFrontHand_Upper_Point.z);	
    //glColor3f(0.9,0.1,0.58);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightFrontHand);
    glDisable(GL_TEXTURE_2D);
}

void Robot::makeLeftBehindHand(double angle_y)
{
    //Tranformations
    glTranslatef(LeftFrontHand_LeftBehindHand_Joint.x,LeftFrontHand_LeftBehindHand_Joint.y,LeftFrontHand_LeftBehindHand_Joint.z);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-LeftBehindHand_Upper_Point.x,-LeftBehindHand_Upper_Point.y,-LeftBehindHand_Upper_Point.z);	
    //glColor3f(0.4,0.21,0.48);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftBehindHand);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightBehindHand(double angle_y)
{
    //Tranformations
     glTranslatef(RightFrontHand_RightBehindHand_Joint.x,RightFrontHand_RightBehindHand_Joint.y,RightFrontHand_RightBehindHand_Joint.z);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-RightBehindHand_Upper_Point.x,-RightBehindHand_Upper_Point.y,-RightBehindHand_Upper_Point.z);	
    //glColor3f(0.5,0.31,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightBehindHand);
    glDisable(GL_TEXTURE_2D);
}



  
void Robot::makeLeftUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_LeftUpperLeg_Joint.x,Hip_LeftUpperLeg_Joint.y,Hip_LeftUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_z,0,0,1);
    glRotatef(-angle_y,0,1,0);
    glTranslatef(-LeftUpperLeg_Upper_Point.x,-LeftUpperLeg_Upper_Point.y, -LeftUpperLeg_Upper_Point.z);	
    //glColor3f(0.9,0.1,0.8);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftUpperLeg);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftLowerLeg(double angle_x)
{
    glTranslatef(LeftUpperLeg_LeftLowerLeg_Joint.x,LeftUpperLeg_LeftLowerLeg_Joint.y,LeftUpperLeg_LeftLowerLeg_Joint.z);
    glRotatef(-angle_x,1,0,0);
    glTranslatef(-LeftLowerLeg_Upper_Point.x,-LeftLowerLeg_Upper_Point.y,-LeftLowerLeg_Upper_Point.z);
    //glColor3f(0.8,0.8,0.88);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

    glEnable(GL_TEXTURE_2D);
    glCallList(LeftLowerLeg);
    glDisable(GL_TEXTURE_2D);
}



  
void Robot::makeRightUpperLeg(double angle_x,double angle_y,double angle_z)
{
    glTranslatef(Hip_RightUpperLeg_Joint.x,Hip_RightUpperLeg_Joint.y,Hip_RightUpperLeg_Joint.z);
    glRotatef(angle_x,1,0,0);
    glRotatef(-angle_z,0,0,1);
    glRotatef(angle_y,0,1,0);
    glTranslatef(-RightUpperLeg_Upper_Point.x,-RightUpperLeg_Upper_Point.y,-RightUpperLeg_Upper_Point.z);
    //glColor3f(0.7,0.0,0.98);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightUpperLeg);
    glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightLowerLeg(double angle_x)
{
   glTranslatef(RightUpperLeg_RightLowerLeg_Joint.x,RightUpperLeg_RightLowerLeg_Joint.y,RightUpperLeg_RightLowerLeg_Joint.z);
   glRotatef(-angle_x,1,0,0);
   glTranslatef(-RightLowerLeg_Upper_Point.x,-RightLowerLeg_Upper_Point.y,-RightLowerLeg_Upper_Point.z);
   //glColor3f(0.28,0.18,0.88);
    
    glBindTexture(GL_TEXTURE_2D,texture[RED]);

   glEnable(GL_TEXTURE_2D);
   glCallList(RightLowerLeg);
   glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeLeftFoot(double angle_x)
{
  //Tranformations
   glTranslatef(LeftLowerLeg_LeftFoot_Joint.x,LeftLowerLeg_LeftFoot_Joint.y,LeftLowerLeg_LeftFoot_Joint.z);
   glRotatef(angle_x,1,0,0);
   glTranslatef(-LeftFoot_Behind_Point.x,-LeftFoot_Behind_Point.y,-LeftFoot_Behind_Point.z);
   //glColor3f(0.6,0.4,0.88);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

   glEnable(GL_TEXTURE_2D);
  glCallList(LeftFoot);
  glDisable(GL_TEXTURE_2D);
}
  
void Robot::makeRightFoot(double angle_x)
{
  //Tranformations
    glTranslatef(RightLowerLeg_RightFoot_Joint.x,RightLowerLeg_RightFoot_Joint.y,RightLowerLeg_RightFoot_Joint.z);
    glRotatef(angle_x,1,0,0);
    glTranslatef(-RightFoot_Behind_Point.x,-RightFoot_Behind_Point.y,-RightFoot_Behind_Point.z);
    //glColor3f(0.2,0.1,0.88);
    
    glBindTexture(GL_TEXTURE_2D,texture[BLUE]);

    glEnable(GL_TEXTURE_2D);
    glCallList(RightFoot);
    glDisable(GL_TEXTURE_2D);
}


void Robot::makeRobot(void)
{
    //glLoadIdentity();
    if(keys.frame1==1)
    {
	behindArmAngle=180;
    }
    if(keys.frame4==1)
    {
	RightShoulder_Bust_Joint=point(-0.1,0.25,0);
    	LeftShoulder_Bust_Joint=point(0.1,0.25,0);
    }
    if(keys.frame6==1)
    { 
	Hip_LeftUpperLeg_Joint=point(0.075,0,0);
    	Hip_RightUpperLeg_Joint=point(-0.075,0,0);
	Bust_Hip_Joint=point(0,0,0);
    }
    

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
            makeLeftUpperArmFront(keys.leftUpperArm_X,keys.leftUpperArm_Y,keys.leftUpperArm_Z);
		glPushMatrix();
		    makeLeftUpperArmBehind(behindArmAngle);
		glPopMatrix();
            makeLeftLowerArmFront(keys.leftLowerArm_X);
		glPushMatrix();
		    makeLeftLowerArmBehind(behindArmAngle);
		glPopMatrix();
            makeLeftFrontHand(keys.leftHand_X);
		glPushMatrix();
		    makeLeftBehindHand(behindArmAngle);
		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
	    makeRightShoulder();
            makeRightUpperArmFront(keys.rightUpperArm_X,keys.rightUpperArm_Y,keys.rightUpperArm_Z);
		glPushMatrix();
		    makeRightUpperArmBehind(behindArmAngle);
		glPopMatrix();
            makeRightLowerArmFront(keys.rightLowerArm_X);
		glPushMatrix();
		    makeRightLowerArmBehind(behindArmAngle);
		glPopMatrix();
            makeRightFrontHand(keys.rightHand_X);
		glPushMatrix();
		    makeRightBehindHand(behindArmAngle);
		glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            makeNeck();
            makeHead(keys.head_X,keys.head_Y,keys.head_Z);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}
