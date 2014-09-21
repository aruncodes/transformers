
#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

class point
{
 public:
    double x;
    double y;
    double z;
    point()
    {
    	x=0;  	y=0;   	z=0;
    }
    point(double a,double b,double c)
    {
    	x=a;   	y=b;   	z=c;
    }
};


class Robot
{
private:
    point HeadNeckJoint;
    point NeckBustJoint;
    point Bust_LeftUpperArm_Joint;
    point Bust_RightUpperArm_Joint;
    point Bust_Hip_Joint;
    point Hip_LeftUpperLeg_Joint;
    point Hip_RightUpperLeg_Joint;

    point LeftUpperArm_LeftLowerArm_Joint;
    point RightUpperArm_RightLowerArm_Joint;
    point LeftLowerArm_LeftHand_Joint;
    point RightLowerArm_RightHand_Joint;

    point LeftUpperLeg_LeftLowerLeg_Joint;
    point RightUpperLeg_RightLowerLeg_Joint;
    point LeftLowerLeg_LeftFoot_Joint;
    point RightLowerLeg_RightFoot_Joint;

//Some more structural constraints and structural parameters.
    GLuint Hip;
    GLuint Bust;
    GLuint Neck;
    GLuint Head;

    GLuint LeftUpperArm;
    GLuint LeftLowerArm;
    GLuint RightUpperArm;
    GLuint RightLowerArm;
    GLuint LeftHand;
    GLuint RightHand;

    GLuint LeftUpperLeg;
    GLuint RightUpperLeg;
    GLuint LeftLowerLeg;
    GLuint RightLowerLeg;
    GLuint LeftFoot;
    GLuint RightFoot;

    

public:
    Robot()
    {
    Hip_LeftUpperLeg_Joint=point(0.1,-0.1,0);
    LeftUpperLeg_LeftLowerLeg_Joint=point(0,-0.125,0.05);
    Hip_RightUpperLeg_Joint=point(-0.1,-0.1,0);
    RightUpperLeg_RightLowerLeg_Joint=point(0,-0.125,0.05);

    //std::cout<<"Robot";
    initHip();
    initBust();
    initNeck();
    initHead();

    initLeftUpperArm();
    initLeftLowerArm();
    initRightUpperArm();
    initRightLowerArm();
    initLeftHand();
    initRightHand();


    initLeftUpperLeg();
    initLeftLowerLeg();
    initRightUpperLeg();
    initRightLowerLeg();
    initLeftFoot();
    initRightFoot();    
  }

  //initilize Hip structure
  void initHip();

  //initilize Bust structure
  void initBust();

  void initNeck();
  void initHead();

  void initLeftUpperArm();
  void initLeftLowerArm();
  void initRightUpperArm();
  void initRightLowerArm();
  void initLeftHand();
  void initRightHand();


  void initLeftUpperLeg();
  void initLeftLowerLeg();
  void initRightUpperLeg();
  void initRightLowerLeg();
  void initLeftFoot();
  void initRightFoot();


  void makeHip(double tx,double ty,double tz,double angle_y);
  void makeBust(double angle_x,double angle_y,double angle_z);

  void makeNeck(void);
  void makeHead(double angle_x,double angle_y,double angle_z);

  void makeLeftUpperArm(double angle_x,double angle_y,double angle_z);
  void makeLeftLowerArm(double angle_x);
  void makeRightUpperArm(double angle_x,double angle_y,double angle_z);
  void makeRightLowerArm(double angle_x);
  void makeLeftHand(double angle_x);
  void makeRightHand(double angle_x);


  void makeLeftUpperLeg(double angle_x,double angle_y,double angle_z);
  void makeLeftLowerLeg(double angle_x);
  void makeRightUpperLeg(double angle_x,double angle_y,double angle_z);
  void makeRightLowerLeg(double angle_x);
  void makeLeftFoot(double angle_x);
  void makeRightFoot(double angle_x);

  void makeRobot(void);
}; 

#endif
