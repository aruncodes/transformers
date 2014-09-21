#include "blocks.hpp"

namespace Blocks {

	void defineCuboid(double length,double width,double height)
	{
		//std::cout<<"Cuboid";
		double half_length,half_width,half_height;
		half_length=length/2;
		half_width=width/2;
		half_height=height/2;
		glBegin(GL_QUADS);	    
		    glVertex3f(-half_length,-half_width,-half_height);
		    glVertex3f(half_length,-half_width,-half_height);
		    glVertex3f(half_length,half_width,-half_height);
		    glVertex3f(-half_length,half_width,-half_height);
		    
		    glColor3f(0,1.0,0);
		    glVertex3f(half_length,half_width,-half_height);
		    glVertex3f(-half_length,half_width,-half_height);
		    glVertex3f(-half_length,half_width,half_height);
		    glVertex3f(half_length,half_width,half_height);

		    glColor3f(1.0,0.0,0.0);
		    glVertex3f(half_length,half_width,half_height);
		    glVertex3f(-half_length,half_width,half_height);
		    glVertex3f(-half_length,-half_width,half_height);
		    glVertex3f(half_length,-half_width,half_height);

		    glColor3f(0,0,1.0);
		    glVertex3f(half_length,-half_width,half_height);
		    glVertex3f(-half_length,-half_width,half_height);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glVertex3f(half_length,-half_width,-half_height);

		
		    glVertex3f(half_length,half_width,half_height);
		    glVertex3f(half_length,-half_width,half_height);
		    glVertex3f(half_length,-half_width,-half_height);
		    glVertex3f(half_length,half_width,-half_height);
		  
		    glVertex3f(-half_length,half_width,half_height);
		    glVertex3f(-half_length,-half_width,half_height);
		    glVertex3f(-half_length,-half_width,-half_height);
		    glVertex3f(-half_length,half_width,-half_height);
		glEnd();
	}

}