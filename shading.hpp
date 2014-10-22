#ifndef _SHADING_HPP_
#define _SHADING_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Light {
	public:
	GLfloat light_position[4];
	GLfloat light_diffuse[4];
	GLfloat light_specular[4];
	GLenum light_enum;
	bool light;

	void updatePosition(double x,double y,double z);
};


class DirectionalLight: public Light {
	public:
	GLfloat light_ambient[4];

	DirectionalLight(){
	}

	DirectionalLight(GLfloat* l_pos,GLfloat* l_ambient,GLfloat* l_diffuse,GLfloat* l_specular,GLenum light_num) {
		for(int i=0;i<4;i++){
			light_position[i]=l_pos[i];
			light_diffuse[i]=l_diffuse[i];
			light_specular[i]=l_specular[i];
			light_ambient[i]=l_ambient[i];
		}
		light_enum=light_num;
		light=true;
	}

	void initScene();

};


class SpotLight: public Light {
	public:
	GLfloat spot_direction[3];

	SpotLight(){
	}

	SpotLight(GLfloat* l_pos,GLfloat* l_diffuse,GLfloat* l_specular,GLfloat* spot_dir,GLenum light_num) {
		for(int i=0;i<4;i++){
			light_position[i]=l_pos[i];
			light_diffuse[i]=l_diffuse[i];
			light_specular[i]=l_specular[i];
			if (i!=3)
				spot_direction[i]=spot_dir[i];
		}
		light=true;
		light_enum=light_num;
	}
	void initScene();
	void updateDirection(double x,double y,double z);
};


#endif
