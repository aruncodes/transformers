#include "world.hpp"

using namespace Blocks;
using namespace Texture;

void World::drawScene() {

	glPushMatrix();
		selectCamera();
		shade_obj.initScene();
		
		makeScene();
		//setLights();
		
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
	
	/*GLfloat lightpos[] = {1, 0.5, 1, 01};
	// glPushMatrix();
	// 	glTranslatef(0,0,0);
	// 	defineSphere(0.2,24,24);
	// glPopMatrix();	
	
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);*/
	GLfloat light_position[4]={0.0, 10.0, 10.0, 1.0};
	GLfloat light_diffuse[4]={0.7, 0.7, 0.5, 1.0};
	GLfloat light_specular[4]={1.0, 0.0, 0.0, 1.0};
	shade_obj=Shader(light_position,light_diffuse,light_specular);	
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
		double x = robot.keys.hip_TX;
		double y = robot.keys.hip_TZ;

		double dist = -0.4;
		double angle = robot.keys.hip_Z;
		double delta_x = dist * sin( angle * M_PI / 180);
		double delta_y = dist * cos( angle * M_PI / 180);

		double dist_centre = -1.2;
		double delta_x_centre = dist_centre * sin( angle * M_PI / 180);
		double delta_y_centre = dist_centre * cos( angle * M_PI / 180);

		gluPerspective(10,1,0,1000);
		gluLookAt(x + delta_x,	-1.35 ,	y + delta_y,
					x + delta_x_centre,	-1.4 ,	y + delta_y_centre,
				0.0f,1.0f,0.0f);
	}
	
	//Transformation for Camera3 : Follows car from behind
	if(Camera==3){

			double x = robot.keys.hip_TX;
			double y = robot.keys.hip_TZ;

			double dist = 1.5;
			double angle = robot.keys.hip_Z;
			double delta_x = dist * sin( angle * M_PI / 180);
			double delta_y = dist * cos( angle * M_PI / 180);

		gluPerspective(30,1,-1,1);
		gluLookAt(
			x + delta_x,	-1,		y + delta_y,
			robot.keys.hip_TX,-1.4,robot.keys.hip_TZ,
			0.0f,1.0f,0.0f);
	}
	//Transformation for Camera4 : Always looks at car
	if(Camera==4){
		gluPerspective(30,1,-1,1);		
		gluLookAt(0,0,3,
			robot.keys.hip_TX,0,robot.keys.hip_TZ,
			0.0f,1.0f,0.0f);
	}
}

void World::debugCoord() {
	if(1) return;
	// Coordinate debug code
	// Sphere to know the position of camera in coordinate system

	double x = robot.keys.hip_TX;
	double y = robot.keys.hip_TZ;

	double dist = -0.4;
	double angle = robot.keys.hip_Z;
	double delta_x = dist * sin( angle * M_PI / 180);
	double delta_y = dist * cos( angle * M_PI / 180);

	double dist_centre = -2;
		double delta_x_centre = dist_centre * sin( angle * M_PI / 180);
		double delta_y_centre = dist_centre * cos( angle * M_PI / 180);


	glPushMatrix();
		// glLoadIdentity();
		/*glTranslatef(
				x + delta_x,
				-1.35 ,
				y + delta_y
				);
		defineSphere(0.1,24,24);*/
		// glBegin(GL_LINES);
		// glVertex3f(x + delta_x,	-1.35 ,	y + delta_y);
		// glVertex3f(x + delta_x_centre,	-1.6 ,	y + delta_y_centre);
		// glEnd();
	glPopMatrix();
	//End of debug code

}
