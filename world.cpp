#include <iostream>
#include "world.hpp"

using namespace Blocks;
using namespace Texture;

void World::drawScene() {

	glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();			
		selectCamera();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		setLights();	
		setSceneProperties();		
		makeScene();

		debugCoord();
		
		setRobotProperties();
		robot.makeRobot();
		robot.animate();
	glPopMatrix();
}

void World::initLights() {

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	GLfloat light_position1[4]={1.0,-1.0,1.0,0.0};
	GLfloat light_ambient1[4]={0.7, 0.0, 0.7, 1.0};
	GLfloat light_diffuse1[4]={0.7, 0.0, 0.7, 1.0};
	GLfloat light_specular1[4]={1.0, 1.0, 1.0, 1.0};
	Dir_light1=DirectionalLight(light_position1,light_ambient1,light_diffuse1,light_specular1,GL_LIGHT0);

	GLfloat light_position2[4]={-1.0,1.0,1.0,0.0};
	GLfloat light_ambient2[4]={0.7, 0.7, 0.0, 1.0};
	GLfloat light_diffuse2[4]={0.7, 0.7, 0.0, 1.0};
	GLfloat light_specular2[4]={1.0, 1.0, 1.0, 1.0};
	Dir_light2=DirectionalLight(light_position2,light_ambient2,light_diffuse2,light_specular2,GL_LIGHT1);	

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

void World::setSceneProperties(){
  GLfloat scene_specular[4]={0.1, 0.1, 0.1, 1.0};
  GLfloat scene_diffuse[4]={1.0, 1.0, 0.0, 1.0};
  glMaterialf(GL_FRONT, GL_SHININESS, 0.01f);
  glMaterialfv(GL_FRONT, GL_SPECULAR, scene_specular);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, scene_diffuse);
}

void World::setRobotProperties(){
  GLfloat scene_specular[4]={1.0, 1.0, 1.0, 1.0};
  GLfloat scene_diffuse[4]={1.0, 0.7, 0.7, 1.0};
  glMaterialf(GL_FRONT, GL_SHININESS, 100.0f);
  glMaterialfv(GL_FRONT, GL_SPECULAR, scene_specular);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, scene_diffuse);
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
	double width,length,height;
	half_width=half_length=half_height=1.8;
	length=width=height=3.6;
	double delta_length=length/30;
	double delta_width=width/30;
	double delta_height=height/30;
	double l=-half_length;
	double w=-half_width;
	double h=-half_height;

	glBindTexture(GL_TEXTURE_2D,tf.front);
		for(int i=0;i<30;i++){
		    for(int j=0;j<30;j++){
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
		    		glTexCoord2d((i+1)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i+1)*delta_length,w+(j+1)*delta_width,-half_height);
				glTexCoord2d((i)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i)*delta_length,w+(j+1)*delta_width,-half_height);
				glTexCoord2d((i)/30.0,j/30.0);
		    		glVertex3f(l+(i)*delta_length,w+(j)*delta_length,-half_height);
				glTexCoord2d((i+1)/30.0,j/30.0);
		    		glVertex3f(l+(i+1)*delta_length,w+(j)*delta_length,-half_height);		    		
			glEnd();
		    }
		}

	glBindTexture(GL_TEXTURE_2D,tf.right);
		for(int i=0;i<30;i++){
		    for(int j=0;j<30;j++){
			glBegin(GL_QUADS);
				glNormal3f(1,0,0);
		    		glTexCoord2d((i+1)/30.0,(j+1)/30.0);
		    		glVertex3f(-half_length,w+(i+1)*delta_width,h+(j+1)*delta_height);
				glTexCoord2d((i)/30.0,(j+1)/30.0);
		    		glVertex3f(-half_length,w+i*delta_width,h+(j+1)*delta_height);
				glTexCoord2d((i)/30.0,j/30.0);
		    		glVertex3f(-half_length,w+(i)*delta_width,h+(j)*delta_height);
		    		glTexCoord2d((i+1)/30.0,j/30.0);
		    		glVertex3f(-half_length,w+(i+1)*delta_width,h+(j)*delta_height);
			glEnd();
		    }
		}

	glBindTexture(GL_TEXTURE_2D,tf.left);
		for(int i=0;i<30;i++){
		    for(int j=0;j<30;j++){
			glBegin(GL_QUADS);
				glNormal3f(-1,0,0);
		    		glTexCoord2d((i+1)/30.0,(j+1)/30.0);
		    		glVertex3f(half_length,w+(i+1)*delta_width,h+(j+1)*delta_height);
				glTexCoord2d((i+1)/30.0,j/30.0);
		    		glVertex3f(half_length,w+(i+1)*delta_width,h+(j)*delta_height);	
				glTexCoord2d((i)/30.0,j/30.0);
		    		glVertex3f(half_length,w+(i)*delta_width,h+(j)*delta_height);
				glTexCoord2d((i)/30.0,(j+1)/30.0);
		    		glVertex3f(half_length,w+i*delta_width,h+(j+1)*delta_height);							
			glEnd();
		    }
		}
	glBindTexture(GL_TEXTURE_2D,tf.top);
		for(int i=0;i<30;i++){
		    for(int j=0;j<30;j++){
			glBegin(GL_QUADS);
				glNormal3f(0,-1,0);
		    		glTexCoord2d((i)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i)*delta_length,half_width,h+(j+1)*delta_height);
				glTexCoord2d((i+1)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i+1)*delta_length,half_width,h+(j+1)*delta_height);
				glTexCoord2d((i)/30.0,j/30.0);
		    		glVertex3f(l+(i+1)*delta_length,half_width,h+(j)*delta_height);
				glTexCoord2d((i)/30.0,(j)/30.0);
				glVertex3f(l+(i)*delta_length,half_width,h+(j)*delta_height);
											
			glEnd();
		    }
		}

	glBindTexture(GL_TEXTURE_2D,tf.bottom);
		    for(int i=0;i<30;i++){
		    for(int j=0;j<30;j++){
			glBegin(GL_QUADS);
				glNormal3f(0,1,0);
		    		glTexCoord2d((i)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i)*delta_length,-half_width,h+(j+1)*delta_height);
				glTexCoord2d((i)/30.0,(j)/30.0);
				glVertex3f(l+(i)*delta_length,-half_width,h+(j)*delta_height);
				glTexCoord2d((i)/30.0,j/30.0);
		    		glVertex3f(l+(i+1)*delta_length,-half_width,h+(j)*delta_height);
				glTexCoord2d((i+1)/30.0,(j+1)/30.0);
		    		glVertex3f(l+(i+1)*delta_length,-half_width,h+(j+1)*delta_height);
											
			glEnd();
		    }
		}
		
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void World::setLights() {
	
	Dir_light1.initScene();
	Dir_light2.initScene();
	Head_light1.initScene();
	Head_light2.initScene();

	//Headlight position calculations
	double x = robot.keys.hip_TX;
	double y = robot.keys.hip_TZ;

	double dist = 0.67;
	double angle = robot.keys.hip_Z;
	double delta_x = dist * sin( angle * M_PI / 180);
	double delta_y = dist * cos( angle * M_PI / 180);

	double dist_centre = 1.2;
	double delta_x_centre = dist_centre * sin( angle * M_PI / 180);
	double delta_y_centre = dist_centre * cos( angle * M_PI / 180);

	double dist2=0.13;
	double angle2=robot.keys.hip_Z;
	double delta_x2 = dist2 * cos( angle2 * M_PI / 180);
	double delta_y2 = dist2 * sin( angle2 * M_PI / 180);

//HeadLight1

	Head_light1.updatePosition((x-delta_x-delta_x2),-1.37,(y-delta_y+delta_y2));
	Head_light1.updateDirection(-delta_x_centre,0,-delta_y_centre);

	
	
//HeadLight2

	Head_light2.updatePosition(x-delta_x+delta_x2,-1.37,y-delta_y-delta_y2);
	Head_light2.updateDirection(-delta_x_centre,0,-delta_y_centre);


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
	if (key == GLFW_KEY_L && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT ) 
		Dir_light1.light = !Dir_light1.light; 
	if (key == GLFW_KEY_L && action == GLFW_PRESS && mods == 0) 
		Dir_light2.light = !Dir_light2.light; 

	if (key == GLFW_KEY_O && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT ) 
		Head_light1.light = !Head_light1.light; 
	if (key == GLFW_KEY_O && action == GLFW_PRESS && mods == 0) 
		Head_light2.light = !Head_light2.light; 

	if(key == GLFW_KEY_F5 && action == GLFW_PRESS && mods == 0) {
		glEnable(GL_LIGHTING);
	}
	if(key == GLFW_KEY_F5 && action == GLFW_PRESS && mods == GLFW_MOD_SHIFT) {
		glDisable(GL_LIGHTING);
	}
}

void World::selectCamera()
{
	//Transformation for Camera1 : global camera
	if(Camera==1){
		gluPerspective(60,1,1,-1000);
		gluLookAt(0,0,4,0,-0.1,0,0.0f,1.0f,0.0f);
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

		gluPerspective(30,1,1,-1);
		gluLookAt(x + delta_x,	-1.35 ,	y + delta_y,
					x + delta_x_centre,	-1.5 ,	y + delta_y_centre,
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

		gluPerspective(30,1,1,-1);
		gluLookAt(
			x + delta_x,	-1,		y + delta_y,
			robot.keys.hip_TX,-1.4,robot.keys.hip_TZ,
			0.0f,1.0f,0.0f);
	}
	//Transformation for Camera4 : Always looks at car
	if(Camera==4){
		gluPerspective(60,1,1,-1);		
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

	double dist = 0.67;
	double angle = robot.keys.hip_Z;
	double delta_x = dist * sin( angle * M_PI / 180);
	double delta_y = dist * cos( angle * M_PI / 180);

	double dist_centre = 1.2;
	double delta_x_centre = dist_centre * sin( angle * M_PI / 180);
	double delta_y_centre = dist_centre * cos( angle * M_PI / 180);

	double dist2=0.13;
	double angle2=robot.keys.hip_Z;
	double delta_x2 = dist2 * cos( angle2 * M_PI / 180);
	double delta_y2 = dist2 * sin( angle2 * M_PI / 180);

	glPushMatrix();
		 glLoadIdentity();

		 /*glTranslatef(
		 		(x - delta_x - delta_x2)/(y - delta_y + delta_y2),
		 		-1.37 /(y - delta_y + delta_y2),
		 		y - delta_y + delta_y2
		 		);
		  defineSphere(0.05,24,24);*/
		 glTranslatef(
		 		-0.15,0.15,0
		 		);
		 defineSphere(0.2,24,24);
		 glBegin(GL_LINES);
		 glVertex3f(0,0,1);
		 glVertex3f(0,0,-1);
		 glEnd();
		 /*glBegin(GL_LINES)
		 glVertex3f(x-delta_x-delta_x2,-1.37,y-delta_y+delta_y2);
		 glVertex3f( x-delta_x_centre-delta_x2,-1.5,y-delta_y_centre+delta_y2);
		 glEnd();*/
	// glTranslatef(
	// 			x-delta_x_centre-delta_x2,
	// 			 	-1.5,
	// 			 	y-delta_y_centre+delta_y2
	// 			);
	// 	 defineSphere(0.05,24,24);
	glPopMatrix();
	//End of debug code

}


