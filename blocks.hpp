#ifndef _BLOCKS_HPP_
#define _BLOCKS_HPP_

#include <GL/glew.h>
#include <cmath>


class TextureFaces {
public:
	GLuint front,back,top,bottom,left,right;
	TextureFaces() {
		front=back=top=bottom=left=right=-1;
	}
	TextureFaces(GLuint all) {
		front=back=top=bottom=left=right=all;
	}
};


namespace Blocks {

	void defineCuboid(double length,double width,double height, TextureFaces &tf);
	void defineTrapizoid(double top_length,double bottom_length, double width, double height,TextureFaces &tf);
	void defineSphere(double r, int lats, int longs);
	void defineCylinder(double radius,double length,double numsteps);
}

#endif