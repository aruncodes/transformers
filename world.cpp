#include "world.hpp"

using namespace Blocks;
using namespace Texture;

void World::drawScene() {
	
	makeScene();

	robot.makeRobot();
	robot.animate();
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
		    //glColor3f(0,0,1.0);
		    glTexCoord2d(0.0,0.0);
		    glVertex3f(half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,0.0);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glTexCoord2d(1.0,1.0);
		    glVertex3f(-half_length,-half_width,half_height);
		    glTexCoord2d(0.0,1.0);
		    glVertex3f(half_length,-half_width,half_height);
		glEnd();
		
// defineCuboid(1,1,1,tf);
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