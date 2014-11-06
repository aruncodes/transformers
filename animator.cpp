#include "animator.hpp"

void Animator::renderFrame() {

	if(mode == NONE) {
		draw();
	} 
	else if(mode == PLAY) {
		play();
	}
}

void Animator::draw() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	// Draw world scene
	WORLD.drawScene();

	// Swap front and back buffers
	glfwSwapBuffers(glfwGetCurrentContext());

	// Poll for and process events
	glfwPollEvents();

}

void Animator::play() {
	
	ifstream keyfile;
	keyfile.open(recordFile.c_str(),ios::in);

	frameNo = 0;
	Frame prev = read(keyfile);
	Frame next,current;
	do {

		//Walk_Spot_light
		next = read(keyfile);
		if(!next.valid) break;

		for( int i = 0; i <= nFrames; i += 1) {
			current = interpolate(next,prev,i);
			
			WORLD.robot.keys.key_frame = current; // update frame
			frameNo++;

			if(capture) { 
				capture_frame(frameNo);
			}

			glfwSetTime(0);
			
			draw();

			while(glfwGetTime() <= 0.05);

		}
		prev = next;
	}while( !keyfile.eof() );

	keyfile.close();
	mode = NONE;
}

void Animator::record() {
	Frame frame = WORLD.robot.keys.key_frame;

	ofstream keyfile;
	keyfile.open(recordFile.c_str(),ios::out | ios::app);
	if(keyfile.is_open()) {
		keyfile << frame.getCurrentVector() << endl;
		keyfile << WORLD.getLightVector() << endl;
		keyfile << WORLD.robot.getHeadLightVector() << endl;
		keyfile << defaultNFrames <<" "<< endl;
		keyfile.close();
	} else {
		cout<<" Error opening keyframe file" << endl;
	}
}

Frame Animator::read(ifstream &keyfile) {
	Frame frame;

	string vector,light,headlight,frameLen;
	if(keyfile.is_open()) {
		getline(keyfile,vector);
		getline(keyfile,light);
		getline(keyfile,headlight);
		getline(keyfile,frameLen);
		nFrames = atoi(frameLen.c_str());
	} else {
		cout<<" Error opening keyframe file" << endl;
		frame.valid = false;
	}
	frame.updateFrameFromVector(vector);
	if(!light.empty())
		WORLD.setLightVector(light);
	if(!headlight.empty())
		WORLD.robot.setHeadLightVector(headlight);
	
	if(vector.empty())
		frame.valid = false;

	return frame;
}

void Animator::resetFile() {
	ofstream keyfile;
	keyfile.open(recordFile.c_str(),ios::out | ios::trunc);
	keyfile.close();
}

Frame Animator::interpolate(Frame &next,Frame &prev,int frameNo) {

	Frame delta = prev;

	double prog = double( frameNo) / double(nFrames);

	delta.bust_X += prog * ( next.bust_X - prev.bust_X );
	delta.bust_Y += prog * ( next.bust_Y - prev.bust_Y );
	delta.bust_Z += prog * ( next.bust_Z - prev.bust_Z );
	delta.head_X += prog * ( next.head_X - prev.head_X );
	delta.head_Y += prog * ( next.head_Y - prev.head_Y );
	delta.head_Z += prog * ( next.head_Z - prev.head_Z );

	delta.leftUpperArm_X += prog * ( next.leftUpperArm_X - prev.leftUpperArm_X );
	delta.leftUpperArm_Y += prog * ( next.leftUpperArm_Y - prev.leftUpperArm_Y );
	delta.leftUpperArm_Z += prog * ( next.leftUpperArm_Z - prev.leftUpperArm_Z );

	delta.leftLowerArm_X += prog * ( next.leftLowerArm_X - prev.leftLowerArm_X );
	
	delta.rightUpperArm_X += prog * ( next.rightUpperArm_X - prev.rightUpperArm_X );
	delta.rightUpperArm_Y += prog * ( next.rightUpperArm_Y - prev.rightUpperArm_Y );
	delta.rightUpperArm_Z += prog * ( next.rightUpperArm_Z - prev.rightUpperArm_Z );

	delta.rightLowerArm_X += prog * ( next.rightLowerArm_X - prev.rightLowerArm_X );

	delta.leftHand_X += prog * ( next.leftHand_X - prev.leftHand_X );
	delta.rightHand_X += prog * ( next.rightHand_X - prev.rightHand_X );

	delta.leftUpperLeg_X += prog * ( next.leftUpperLeg_X - prev.leftUpperLeg_X );
	delta.leftUpperLeg_Y += prog * ( next.leftUpperLeg_Y - prev.leftUpperLeg_Y );
	delta.leftUpperLeg_Z += prog * ( next.leftUpperLeg_Z - prev.leftUpperLeg_Z );
	
	delta.leftLowerLeg_X += prog * ( next.leftLowerLeg_X - prev.leftLowerLeg_X );

	delta.rightUpperLeg_X += prog * ( next.rightUpperLeg_X - prev.rightUpperLeg_X );
	delta.rightUpperLeg_Y += prog * ( next.rightUpperLeg_Y - prev.rightUpperLeg_Y );
	delta.rightUpperLeg_Z += prog * ( next.rightUpperLeg_Z - prev.rightUpperLeg_Z );
	
	delta.rightLowerLeg_X += prog * ( next.rightLowerLeg_X - prev.rightLowerLeg_X );

	delta.leftFoot_X += prog * ( next.leftFoot_X - prev.leftFoot_X );
	delta.rightFoot_X += prog * ( next.rightFoot_X - prev.rightFoot_X );

	delta.hip_TX += prog * ( next.hip_TX -prev.hip_TX );
	delta.hip_TY += prog * ( next.hip_TY -prev.hip_TY );
	delta.hip_TZ += prog * ( next.hip_TZ -prev.hip_TZ );

	delta.hip_X += prog * ( next.hip_X - prev.hip_X );
	delta.hip_Y += prog * ( next.hip_Y - prev.hip_Y );
	delta.hip_Z += prog * ( next.hip_Z - prev.hip_Z );

	//cout<<prog << " : " <<delta.getCurrentVector() <<endl;
	return delta;
}

void Animator::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	/* Toggle start capturing frames when playing*/	
	if(key == GLFW_KEY_F7 && action == GLFW_PRESS) {
		capture = !capture;
	}

	/* Empty keyframe file */	
	if(key == GLFW_KEY_F8 && action == GLFW_PRESS) {
		resetFile();
	}

	/* Record a frame to file*/	
	if(key == GLFW_KEY_F9 && action == GLFW_PRESS) {
		record();
	}

	/* Start playback*/	
	if(key == GLFW_KEY_F10 && action == GLFW_PRESS) {
		mode = PLAY;
	}

}

void Animator::capture_frame(unsigned int framenum)
{
  //global pointer float *pRGB
  pRGB = new unsigned char [3 * (screenWidth+1) * (screenHeight + 1) ];

  // set the framebuffer to read
  //default for double buffered
  glReadBuffer(GL_BACK);

  glPixelStoref(GL_PACK_ALIGNMENT,1);//for word allignment
  
  glReadPixels(0, 0, screenWidth, screenHeight, GL_RGB, GL_UNSIGNED_BYTE, pRGB);
  char filename[200];
  sprintf(filename,"/media/arun/DriveD/IITB-Assignment/cg/frames/frame_%04d.ppm",framenum);
  std::ofstream out(filename, std::ios::out);
  out<<"P6"<<std::endl;
  out<<screenWidth<<" "<<screenHeight<<" 255"<<std::endl;
  out.write(reinterpret_cast<char const *>(pRGB), (3 * (screenWidth+1) * (screenHeight + 1)) * sizeof(int));
  out.close();

  //function to store pRGB in a file named count
  delete pRGB;
}