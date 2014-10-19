#include "world.hpp"

using namespace Blocks;
using namespace Texture;

void World::drawScene() {

	glPushMatrix();
		selectCamera();	
		makeScene();

		robot.makeRobot();
		robot.animate();
	glPopMatrix();
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
}

void World::selectCamera()
{
	if(Camera==1){
		//gluPerspective(90,1,-2,2);
		//glFrustum(-1,1,0,2,0.1,2);
		gluPerspective(30,1,-1,1000);
		gluLookAt(0,0,3,0,-0.1,0,0.0f,1.0f,0.0f);
	}
	
	//Transformation for Camera1
	if(Camera==2){
		//Transformation for Camera2
		
		//glFrustum(-15,15,0,15,0.1,2);
		gluPerspective(10,1,0,1000);
		gluLookAt(robot.keys.camera2[0],robot.keys.camera2[1],robot.keys.camera2[2],robot.keys.camera2[0]+robot.keys.camera2_l[0],robot.keys.camera2[1]+robot.keys.camera2_l[1],robot.keys.camera2[2]+robot.keys.camera2_l[2],0.0f,1.0f,0.0f);
	}
	
	//Transformation for Camera3
	if(Camera==3);
}