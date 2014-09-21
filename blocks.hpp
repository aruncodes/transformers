#ifndef _BLOCKS_HPP_
#define _BLOCKS_HPP_

#include <GL/glew.h>

namespace Blocks {

	void defineCuboid(double length,double width,double height);
	void defineTrapizoid(double top_length,double bottom_length, double width, double height);
}

#endif