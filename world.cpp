#include "world.hpp"

using namespace Blocks;
using namespace Texture;

void World::drawScene() {

	glPushMatrix();
		selectCamera();	
		makeScene();
		setLights();

		debugCoord();

		robot.makeRobot();
		robot.animate();
	glPopMatrix();
}

void World::initLights() {
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}

void World::setLights() {
	
	GLfloat lightpos[] = {1, 0.5, 1, 01};
	// glPushMatrix();
	// 	glTranslatef(0,0,0);
	// 	defineSphere(0.2,24,24);
	// glPopMatrix();	
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);	
}

void World::makeScene() {

	TextureFaces tf;
	tf.back = texture[0];
	tf.front = texture[0];
	tf.left = texture[2];
	tf.right = texture[3];
	tf.bottom = texture[4];
	tf.top = texture[5];
	
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	// glRotatef(45,1,1,0);
	double half_width,half_length,half_height;
	half_width=half_length=half_height=1.8;

	glBindTexture(GL_TEXTURE_2D,tf.front);
		glBegin(GL_QUADS);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		glEnd();

	glBindTexture(GL_TEXTURE_2D,tf.right);
		glBegin(GL_QUADS);    
		    glTexCoord2d(0.0f,1.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,half_width,half_height);
		glEnd();
	glBindTexture(GL_TEXTURE_2D,tf.left);
		glBegin(GL_QUADS);    
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(half_length,half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,-half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,half_width,half_height);
		glEnd();
	glBindTexture(GL_TEXTURE_2D,tf.top);
		glBegin(GL_QUADS);    
		    glTexCoord2d(0.0,0.0);	
		    glVertex3f(half_length,half_width,half_height);
	        glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,half_width,half_height);
            glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,half_width,-half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,half_width,-half_height);
		glEnd();
	glBindTexture(GL_TEXTURE_2D,tf.bottom);
		glBegin(GL_QUADS);    
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,-half_width,half_height);
		glEnd();
		
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void World::initTexture() {

    int nTex = 4;
    texture = new GLuint[nTex];
    glGenTextures(nTex,texture);

    makeTexture("tex/world/back.bmp",texture[0]);
    makeTexture("tex/world/front.bmp",texture[1]);
    makeTexture("tex/world/left.bmp",texture[2]);
    makeTexture("tex/world/right.bmp",texture[3]);
    makeTexture("tex/world/bottom.bmp",texture[4]);
    makeTexture("tex/world/top.bmp",texture[5]);

}

//!GLFW keyboard callback
void World::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_F1 && action == GLFW_PRESS) {
		Camera=1;
	}

	if(key == GLFW_KEY_F2 && action == GLFW_PRESS) {
		Camera=2;
	}		

	if(key == GLFW_KEY_F3 && action == GLFW_PRESS) {
		Camera=3;
	}
	if(key == GLFW_KEY_F4 && action == GLFW_PRESS) {
		Camera=4;
	}
}

void World::selectCamera()
{
	//Transformation for Camera1 : global camera
	if(Camera==1){
		gluPerspective(30,1,-1,1000);
		gluLookAt(0,0,3,0,-0.1,0,0.0f,1.0f,0.0f);
	}
	
	//Transformation for Camera2 : inside car
	if(Camera==2){
		
		gluPerspective(10,1,0,1000);
		gluLookAt(robot.keys.camera2[0],robot.keys.camera2[1],robot.keys.camera2[2],
				robot.keys.camera2[0]+robot.keys.camera2_l[0],
				robot.keys.camera2[1]+robot.keys.camera2_l[1],
				robot.keys.camera2[2]+robot.keys.camera2_l[2],
				0.0f,1.0f,0.0f);
	}
	
	//Transformation for Camera3 : Follows car from behind
	if(Camera==3){

			double x = robot.keys.camera2[0];
			double y = robot.keys.camera2[2];

			double dist = 1.5;
			double angle = robot.keys.hip_Z;
			double delta_x = dist * sin( angle * M_PI / 180);
			double delta_y = dist * cos( angle * M_PI / 180);

		gluPerspective(30,1,-1,1);
		gluLookAt(
			x + delta_x,	-1,		y + delta_y,
			robot.keys.camera2[0],-1.4,robot.keys.camera2[2],
			0.0f,1.0f,0.0f);
	}
	//Transformation for Camera4 : Always looks at car
	if(Camera==4){
		gluPerspective(30,1,-1,1);		
		gluLookAt(0,0,3,
			robot.keys.camera2[0],0,robot.keys.camera2[2],
			0.0f,1.0f,0.0f);
	}
}

void World::debugCoord() {
	if(1) return;
	// Coordinate debug code
	// Sphere to know the position of camera in coordinate system

	double x = robot.keys.camera2[0];
	double y = robot.keys.camera2[2];

	double dist = 1;
	double angle = robot.keys.hip_Z;
	double delta_x = dist * sin( angle * M_PI / 180);
	double delta_y = dist * cos( angle * M_PI / 180);

	glPushMatrix();
		// glLoadIdentity();
		glTranslatef(
				x + delta_x,
				-1 ,
				y + delta_y
				);
		defineSphere(0.1,24,24);
	glPopMatrix();
	//End of debug code

}