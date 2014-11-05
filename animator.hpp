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
	int mode;
	World WORLD;
	Frame nextFrame;
	int frame_no;
	double no_of_inbetween_frames[88];
	

	Animator() {
  		recordFile = RECORDFILE;
  		WORLD=World();
  		nextFrame=Frame();
  		mode = NONE;
		frame_no=0;
		double copy_of_inbetween_frames[88]={3,5,3,3,5,3,3,5,3,3,
						     5,3,3,5,3,3,5,3,3,5,
						     3,3,5,3,3,5,3,3,5,3,
						     3,5,3,3,5,3,3,5,3,3,
						     40,3,5,5,3,3,5,3,3,5,
						     3,3,5,3,3,5,3,3,5,3,
						     3,5,3,3,5,3,3,5,3,3,5,
						     3,3,5,3,3,5,3,3,5,3,
						     20,20,20,20,20,20,20};
		for(int i=0;i<88;i++){
		    no_of_inbetween_frames[i]=copy_of_inbetween_frames[i];
		}

		
	}

	void renderFrame();
	
	void resetFile();
	void record();
	Frame read(ifstream &file);
	void play();
	void draw();

	Frame interpolate(Frame &next,Frame &prev,int progress);

	void startAnimation(void);
	void interpolateFrames(Frame prev_frame,Frame suc_frame);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif
