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

	void defineTrapizoid(double top_length,double bottom_length, double width, double height) {

		double half_top_length, half_bottom_length,half_width,half_height;

		half_top_length = top_length / 2;
		half_bottom_length = bottom_length / 2;
		half_width = width/2;
		half_height = height/2;

#define 	POINT_A		glVertex3f(-half_top_length,half_height,half_width)
#define 	POINT_B		glVertex3f(half_top_length,half_height,half_width)
#define 	POINT_C		glVertex3f(half_bottom_length,-half_height,half_width)
#define 	POINT_D		glVertex3f(-half_bottom_length,-half_height,half_width)
#define 	POINT_E		glVertex3f(-half_bottom_length,-half_height,-half_width)
#define 	POINT_F		glVertex3f(half_bottom_length,-half_height,-half_width)
#define 	POINT_G		glVertex3f(half_top_length,half_height,-half_width)
#define 	POINT_H		glVertex3f(-half_top_length,half_height,-half_width)

		glBegin(GL_QUADS);
			/* Top face*/
			POINT_A;
			POINT_B;
			POINT_G;
			POINT_H;
	
		    glColor3f(1,1,0);

			/* Bottom face*/
			POINT_D;
			POINT_C;
			POINT_F;
			POINT_E;

		    glColor3f(0,1.0,0);

			/* Front face */
			POINT_A;
			POINT_B;
			POINT_C;
			POINT_D;

		    glColor3f(0,0,1);

			/*Left face*/
			POINT_A;
			POINT_H;
			POINT_E;
			POINT_D;

		    glColor3f(1,1.0,0);

			/*Right face*/
			POINT_B;
			POINT_G;
			POINT_F;
			POINT_C;

		    glColor3f(0,1.0,1);

			/*Back face*/
			POINT_H;
			POINT_G;
			POINT_F;
			POINT_E;
		glEnd();

	}

}