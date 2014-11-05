#include "animator.hpp"

void Animator::renderFrame() {

	if(mode == NONE) {
		draw();
	} 
	else if(mode == PLAY) {
		WORLD.Top_Spot_light.light=true;
		play();
		WORLD.Top_Spot_light.light=false;
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
	frame_no=0;
	Frame prev = read(keyfile);
	Frame next,current;
	do {

		//Walk_Spot_light
     	   	
		next = read(keyfile);
		if(!next.valid) break;

		for( int i = 0; i <= 10*no_of_inbetween_frames[frame_no]; i += 10) {
			current = interpolate(next,prev,i);
			
			WORLD.robot.keys.key_frame = current; // update frame

			glfwSetTime(0);
			
			draw();

			while(glfwGetTime() <= 0.05);
		}
		prev = next;
		frame_no++;
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
		keyfile.close();
	} else {
		cout<<" Error opening keyframe file" << endl;
	}
}

Frame Animator::read(ifstream &keyfile) {
	Frame frame;

	string vector,light,headlight;
	if(keyfile.is_open()) {
		getline(keyfile,vector);
		getline(keyfile,light);
		getline(keyfile,headlight);
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

Frame Animator::interpolate(Frame &next,Frame &prev,int progress) {
	//
	//	progress moves from 1 from 100
	//
	Frame delta = prev;

	double prog = double( progress) / (10.0*no_of_inbetween_frames[frame_no]);

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

/*void Animator::interpolateFrames(Frame prev_frame,Frame suc_frame){
	int no_of_inbetween_frames=10;
	double delta_bust_X=(suc_frame.bust_X-prev_frame.bust_X)/no_of_inbetween_frames;
	double delta_bust_Y=(suc_frame.bust_Y-prev_frame.bust_Y)/no_of_inbetween_frames;
	double delta_bust_Z=(suc_frame.bust_Z-prev_frame.bust_Z)/no_of_inbetween_frames;
	double delta_head_X=(suc_frame.head_X-prev_frame.head_X)/no_of_inbetween_frames;
	double delta_head_Y=(suc_frame.head_Y-prev_frame.head_Y)/no_of_inbetween_frames;
	double delta_head_Z=(suc_frame.head_Z-prev_frame.head_Z)/no_of_inbetween_frames;

	double delta_leftUpperArm_X=(suc_frame.leftUpperArm_X-prev_frame.leftUpperArm_X)/no_of_inbetween_frames;
	double delta_leftUpperArm_Y=(suc_frame.leftUpperArm_Y-prev_frame.leftUpperArm_Y)/no_of_inbetween_frames;
	double delta_leftUpperArm_Z=(suc_frame.leftUpperArm_Z-prev_frame.leftUpperArm_Z)/no_of_inbetween_frames;

	double delta_leftLowerArm_X=(suc_frame.leftLowerArm_X-prev_frame.leftLowerArm_X)/no_of_inbetween_frames;
	
	double delta_rightUpperArm_X=(suc_frame.rightUpperArm_X-prev_frame.rightUpperArm_X)/no_of_inbetween_frames;
	double delta_rightUpperArm_Y=(suc_frame.rightUpperArm_Y-prev_frame.rightUpperArm_Y)/no_of_inbetween_frames;
	double delta_rightUpperArm_Z=(suc_frame.rightUpperArm_Z-prev_frame.rightUpperArm_Z)/no_of_inbetween_frames;

	double delta_rightLowerArm_X=(suc_frame.rightLowerArm_X-prev_frame.rightLowerArm_X)/no_of_inbetween_frames;

	double delta_leftHand_X=(suc_frame.leftHand_X-prev_frame.leftHand_X)/no_of_inbetween_frames;
	double delta_rightHand_X=(suc_frame.rightHand_X-prev_frame.rightHand_X)/no_of_inbetween_frames;

	double delta_leftUpperLeg_X=(suc_frame.leftUpperLeg_X-prev_frame.leftUpperLeg_X)/no_of_inbetween_frames;
	double delta_leftUpperLeg_Y=(suc_frame.leftUpperLeg_Y-prev_frame.leftUpperLeg_Y)/no_of_inbetween_frames;
	double delta_leftUpperLeg_Z=(suc_frame.leftUpperLeg_Z-prev_frame.leftUpperLeg_Z)/no_of_inbetween_frames;
	
	double delta_leftLowerLeg_X=(suc_frame.leftLowerLeg_X-prev_frame.leftLowerLeg_X)/no_of_inbetween_frames;

	double delta_rightUpperLeg_X=(suc_frame.rightUpperLeg_X-prev_frame.rightUpperLeg_X)/no_of_inbetween_frames;
	double delta_rightUpperLeg_Y=(suc_frame.rightUpperLeg_Y-prev_frame.rightUpperLeg_Y)/no_of_inbetween_frames;
	double delta_rightUpperLeg_Z=(suc_frame.rightUpperLeg_Z-prev_frame.rightUpperLeg_Z)/no_of_inbetween_frames;
	
	double delta_rightLowerLeg_X=(suc_frame.rightLowerLeg_X-prev_frame.rightLowerLeg_X)/no_of_inbetween_frames;

	double delta_leftFoot_X=(suc_frame.leftFoot_X-prev_frame.leftFoot_X)/no_of_inbetween_frames;
	double delta_rightFoot_X=(suc_frame.rightFoot_X-prev_frame.rightFoot_X)/no_of_inbetween_frames;

	double delta_hip_TX=(suc_frame.hip_TX-prev_frame.hip_TX)/no_of_inbetween_frames;
	double delta_hip_TY=(suc_frame.hip_TY-prev_frame.hip_TY)/no_of_inbetween_frames;
	double delta_hip_TZ=(suc_frame.hip_TZ-prev_frame.hip_TZ)/no_of_inbetween_frames;

	double delta_hip_X=(suc_frame.hip_X-prev_frame.hip_X)/no_of_inbetween_frames;
	double delta_hip_Y=(suc_frame.hip_Y-prev_frame.hip_Y)/no_of_inbetween_frames;
	double delta_hip_Z=(suc_frame.hip_Z-prev_frame.hip_Z)/no_of_inbetween_frames;

	while(no_of_inbetween_frames!=0){
		glfwSetTime(0);
		
		WORLD.robot.keys.key_frame.bust_X+=delta_bust_X;
		WORLD.robot.keys.key_frame.bust_Y+=delta_bust_Y;
		WORLD.robot.keys.key_frame.bust_Z+=delta_bust_Z;

		WORLD.robot.keys.key_frame.head_X+=delta_head_X;
		WORLD.robot.keys.key_frame.head_Y+=delta_head_Y;
		WORLD.robot.keys.key_frame.head_Z+=delta_head_Z;
		
		WORLD.robot.keys.key_frame.leftUpperArm_X+=delta_leftUpperArm_X;
		WORLD.robot.keys.key_frame.leftUpperArm_Y+=delta_leftUpperArm_Y;
		WORLD.robot.keys.key_frame.leftUpperArm_Z+=delta_leftUpperArm_Z;

		WORLD.robot.keys.key_frame.leftLowerArm_X+=delta_leftLowerArm_X;

		WORLD.robot.keys.key_frame.rightUpperArm_X+=delta_rightUpperArm_X;
		WORLD.robot.keys.key_frame.rightUpperArm_Y+=delta_rightUpperArm_Y;
		WORLD.robot.keys.key_frame.rightUpperArm_Z+=delta_rightUpperArm_Z;

		WORLD.robot.keys.key_frame.rightLowerArm_X+=delta_rightLowerArm_X;

		WORLD.robot.keys.key_frame.leftHand_X+=delta_leftHand_X;
		WORLD.robot.keys.key_frame.rightHand_X+=delta_rightHand_X;

		
		WORLD.robot.keys.key_frame.leftUpperLeg_X+=delta_leftUpperLeg_X;
		WORLD.robot.keys.key_frame.leftUpperLeg_Y+=delta_leftUpperLeg_Y;
		WORLD.robot.keys.key_frame.leftUpperLeg_Z+=delta_leftUpperLeg_Z;

		WORLD.robot.keys.key_frame.leftLowerLeg_X+=delta_leftLowerLeg_X;

		WORLD.robot.keys.key_frame.rightUpperLeg_X+=delta_rightUpperLeg_X;
		WORLD.robot.keys.key_frame.rightUpperLeg_Y+=delta_rightUpperLeg_Y;
		WORLD.robot.keys.key_frame.rightUpperLeg_Z+=delta_rightUpperLeg_Z;

		WORLD.robot.keys.key_frame.rightLowerLeg_X+=delta_rightLowerLeg_X;

		WORLD.robot.keys.key_frame.leftFoot_X+=delta_leftFoot_X;
		WORLD.robot.keys.key_frame.rightFoot_X+=delta_rightFoot_X;

		WORLD.robot.keys.key_frame.hip_TX+=delta_hip_TX;
		WORLD.robot.keys.key_frame.hip_TY+=delta_hip_TY;
		WORLD.robot.keys.key_frame.hip_TZ+=delta_hip_TZ;

		WORLD.robot.keys.key_frame.hip_X+=delta_hip_X;
		WORLD.robot.keys.key_frame.hip_Y+=delta_hip_Y;
		WORLD.robot.keys.key_frame.hip_Z+=delta_hip_Z;

		// renderGL();
		glfwSwapBuffers(glfwGetCurrentContext());
		double time;
		while((time=glfwGetTime())<=0.05);
		no_of_inbetween_frames--;
	}
}


void Animator::startAnimation(void){
	FILE *file=fopen("keyframes.txt","r");
	int no_of_frames_left=10;
	while(no_of_frames_left!=0){
		fscanf(file,"%lg",&nextFrame.bust_X);
		fscanf(file,"%lg",&nextFrame.bust_Y);
		fscanf(file,"%lg",&nextFrame.bust_Z);
		fscanf(file,"%lg",&nextFrame.head_X);
		fscanf(file,"%lg",&nextFrame.head_Y);
		fscanf(file,"%lg",&nextFrame.head_Z);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_X);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_Y);
		fscanf(file,"%lg",&nextFrame.leftUpperArm_Z);
		fscanf(file,"%lg",&nextFrame.leftLowerArm_X);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_X);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_Y);
		fscanf(file,"%lg",&nextFrame.rightUpperArm_Z);
		fscanf(file,"%lg",&nextFrame.rightLowerArm_X);
		fscanf(file,"%lg",&nextFrame.leftHand_X);
		fscanf(file,"%lg",&nextFrame.rightHand_X);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_X);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_Y);
		fscanf(file,"%lg",&nextFrame.leftUpperLeg_Z);
		fscanf(file,"%lg",&nextFrame.leftLowerLeg_X);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_X);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_Y);
		fscanf(file,"%lg",&nextFrame.rightUpperLeg_Z);
		fscanf(file,"%lg",&nextFrame.rightLowerLeg_X);
		fscanf(file,"%lg",&nextFrame.leftFoot_X);
		fscanf(file,"%lg",&nextFrame.rightFoot_X);
		fscanf(file,"%lg",&nextFrame.hip_TX);
		fscanf(file,"%lg",&nextFrame.hip_TY);
		fscanf(file,"%lg",&nextFrame.hip_TZ);
		fscanf(file,"%lg",&nextFrame.hip_X);
		fscanf(file,"%lg",&nextFrame.hip_Y);
		fscanf(file,"%lg",&nextFrame.hip_Z);
		fscanf(file,"%d",&WORLD.robot.keys.startTransform);
		interpolateFrames(WORLD.robot.keys.key_frame,nextFrame);
		// WORLD.robot.keys.key_frame.startAnim=nextFrame.startAnim;
		no_of_frames_left--;
	}
	mode=NONE;
	fclose(file);
}*/

void Animator::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
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
