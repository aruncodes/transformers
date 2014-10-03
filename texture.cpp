#include <cstdlib>
#include <stdio.h>

#include "robot.hpp"

void Robot::initTexture() {

    int nTex = 45;
    texture = new GLuint[nTex];
    glGenTextures(nTex,texture);

    makeTexture("tex/bust.bmp",texture[LOGO]);
    makeTexture("tex/bustback.bmp",texture[43]);
    // makeTexture("tex/fire.bmp",texture[BLUE]);
    makeTexture("parts/side/lower_leg_left.bmp",texture[BLUE]);
    makeTexture("parts/side/shoulder_back.bmp",texture[RED]);
    // makeTexture("tex/blue_fire.bmp",texture[RED]);
    makeTexture("tex/head.bmp",texture[HEAD]);
    makeTexture("tex/wheel.bmp",texture[WHEEL]);
    makeTexture("tex/hip.bmp",texture[HIP]);

//-----Side----
    makeTexture("parts/side/bust_left.bmp",texture[BUST_LEFT]);
    makeTexture("parts/side/foot_left.bmp",texture[RIGHT_FOOT_RIGHT]);
    makeTexture("parts/side/lower_arm_front_left.bmp",texture[9]);
    makeTexture("parts/side/lower_leg_left.bmp",texture[10]);
    makeTexture("parts/side/shoulder_back.bmp",texture[11]);
    makeTexture("parts/side/upper_arm_front_left.bmp",texture[12]);
    makeTexture("parts/side/upper_leg_left.bmp",texture[13]);
    makeTexture("parts/side/hand_behind_left.bmp",texture[14]);
    makeTexture("parts/side/arm_left_tira.bmp",texture[15]);

//----Front---
    makeTexture("parts/front/head_top.bmp",texture[16]);
    makeTexture("parts/front/left_hand_behind.bmp",texture[17]);
    makeTexture("parts/front/left_hand_front.bmp",texture[18]);
    makeTexture("parts/front/left_upper_arm_behind_top.bmp",texture[19]);
    makeTexture("parts/front/left_upper_arm_front_top.bmp",texture[20]);
    makeTexture("parts/front/right_hand_behind.bmp",texture[21]);
    makeTexture("parts/front/right_hand_front.bmp",texture[22]);
    makeTexture("parts/front/right_upper_arm_behind_top.bmp",texture[23]);
    makeTexture("parts/front/right_upper_arm_front_top.bmp",texture[24]);
    makeTexture("parts/front/shoulder_top.bmp",texture[25]);
    makeTexture("parts/front/shoulder_top_right.bmp",texture[26]);

//-----BACK--------
    makeTexture("parts/back/left_lower_leg_top.bmp",texture[27]);
    makeTexture("parts/back/left_upper_leg_bottom.bmp",texture[28]);
    makeTexture("parts/back/right_lower_leg_top.bmp",texture[29]);
    makeTexture("parts/back/right_upper_leg_bottom.bmp",texture[30]);
//-----Top---------
    makeTexture("parts/top/left_lower_leg_back.bmp",texture[31]);
    makeTexture("parts/top/right_lower_leg_back.bmp",texture[32]);
    makeTexture("parts/top/left_foot_front.bmp",texture[33]);
    makeTexture("parts/top/right_foot_front.bmp",texture[34]);
    makeTexture("parts/top/left_hand_front_front.bmp",texture[35]);
    makeTexture("parts/top/left_hand_behind_back.bmp",texture[36]);
    makeTexture("parts/top/right_larm_behind_lower_back.bmp",texture[37]);
    makeTexture("parts/top/right_larm_front_lower_back.bmp",texture[38]);
    makeTexture("parts/top/left_uarm_behind_back.bmp",texture[39]);
    makeTexture("parts/top/left_uarm_front_back.bmp",texture[40]);
    makeTexture("parts/top/right_uarm_behind_back.bmp",texture[41]);
    makeTexture("parts/top/right_uarm_front_back.bmp",texture[42]);

}

void Robot::makeTexture(const char* FilePath,GLuint gltexture)
{
    TextureImage=fopen(FilePath,"rb");

    unsigned char header[54];
    fread(header,1,54,TextureImage); //read header

    int width      = *(int*)&(header[0x12]);
    int height     = *(int*)&(header[0x16]);

    fseek ( TextureImage , 128 , SEEK_SET );
    
    TextureData=(unsigned char *)malloc(width*height*3);
    fread(TextureData,width*height,3,TextureImage);
    fclose(TextureImage);

    glBindTexture(GL_TEXTURE_2D,gltexture);
    glPixelStorei(GL_UNPACK_ALIGNMENT,2);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR,GL_REPLACE);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_BGR,GL_UNSIGNED_BYTE,TextureData);
    
    delete TextureData;
}

