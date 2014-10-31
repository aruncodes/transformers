#ifndef _FRAME_HPP_
#define _FRAME_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Frame {
public:
    double bust_X,bust_Y,bust_Z;

    double head_X,head_Y,head_Z;

    double leftUpperArm_X,leftUpperArm_Y,leftUpperArm_Z;
    double leftLowerArm_X;
    double rightUpperArm_X,rightUpperArm_Y,rightUpperArm_Z;
    double rightLowerArm_X;

    double leftHand_X;
    double rightHand_X;
    double leftUpperLeg_X,leftUpperLeg_Y,leftUpperLeg_Z;
    double leftLowerLeg_X;
    double rightUpperLeg_X,rightUpperLeg_Y,rightUpperLeg_Z;
    double rightLowerLeg_X;
    double leftFoot_X;
    double rightFoot_X;
    double hip_TX,hip_TY,hip_TZ,hip_X,hip_Y,hip_Z;
    int startAnim;

    Frame() {
		//Arms
		leftUpperArm_X=leftUpperArm_Y=leftUpperArm_Z=10;
		leftLowerArm_X = 10;
		leftHand_X=10;
		
		rightUpperArm_X=rightUpperArm_Y=rightUpperArm_Z=10;
		rightLowerArm_X =10;
		rightHand_X=10;

		//Bust
		bust_X=bust_Y=bust_Z=0;

		//Leg
		leftUpperLeg_X=leftUpperLeg_Y=10;
		leftUpperLeg_Z=10;
		leftLowerLeg_X =0;
		leftFoot_X = 0;

		rightUpperLeg_X=rightUpperLeg_Y=10;
		rightUpperLeg_Z=0;
		rightLowerLeg_X =0;
		rightFoot_X = 0;

		//Head
		head_X=head_Y=head_Z=0;

		//Hip
		hip_TX=hip_TZ=0;
		hip_TY=-0.5;
		hip_X=hip_Y=hip_Z=0;

		//Animation
		startAnim=0;
	}
};


#endif
