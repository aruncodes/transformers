#ifndef _ANIMATOR_HPP_
#define _ANIMATOR_HPP_

#include <iostream>
#include <fstream>
#include <string>

#include "world.hpp"
#include "frame.hpp"

#define	RECORDFILE 	"keyframes.txt"

enum {NONE,RECORD,PLAY};

class Animator {

	std::string recordFile;
public:
	int screenWidth,screenHeight;
	int mode;
	World WORLD;
	Frame nextFrame;
	int frameNo;
	int nFrames;
	int defaultNFrames;
	unsigned char *pRGB;
	bool capture;

	Animator(int w,int h) {

		screenWidth = w;
		screenHeight = h;

  		recordFile = RECORDFILE;
  		WORLD=World();
  		nextFrame=Frame();
  		mode = NONE;
  		nFrames = 0;
  		defaultNFrames = 5;
		frameNo = 0;
		capture = false;
	}

	void renderFrame();
	
	void resetFile();
	void record();
	Frame read(ifstream &file);
	void play();
	void draw();

	Frame interpolate(Frame &next,Frame &prev,int progress);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void capture_frame(unsigned int framenum);
};

#endif
