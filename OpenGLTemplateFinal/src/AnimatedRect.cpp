#include "AnimatedRect.h"
#include <iostream>



AnimatedRect::AnimatedRect (const char* map_filename, int rows, int cols, int rate, float x=0, float y=0, float w=0.5, float h=0.5): TexRect(map_filename, x, y, w, h){
    
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture
    (
     map_filename,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
     );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    this->rows = rows;
    this->cols = cols;
    
    
    curr_row = 1;
    curr_col = 1;
    
    complete = false;
    animating = false;
    loop = false;
    
    setRate(rate);
    start();
}

bool AnimatedRect::done() {
    return complete;
}


void AnimatedRect::draw(float z){
    if (animating){
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
        
        float xinc = 1.0/cols;
        float yinc = 1.0/rows;
        
        
        float top = 1 - yinc * (curr_row - 1);
        float bottom = 1 - yinc * curr_row;
        
        float left = xinc * (curr_col - 1);
        float right = xinc * curr_col;
        
        
        glBegin(GL_QUADS);
        
        glTexCoord2f(left, bottom);
        glVertex3f(x, y - h, z);
        
        glTexCoord2f(left, top);
        glVertex3f(x, y, z);
        
        glTexCoord2f(right, top);
        glVertex3f(x+w, y, z);
        
        glTexCoord2f(right, bottom);
        glVertex3f(x+w, y - h, z);
        
        glEnd();
        
        glDisable(GL_TEXTURE_2D);
    }
}

void AnimatedRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}

void AnimatedRect::reset(){
    complete = false;
    curr_row = 1;
    curr_col = 1;
}

void AnimatedRect::playLoop(){
    reset();
    animating = true;
    loop = true;
}

void AnimatedRect::playOnce(){
    reset();
    animating = true;
    loop = false;
}

void AnimatedRect::pause(){
    animating = false;
}

void AnimatedRect::resume(){
    animating = true;
}

void AnimatedRect::play(){
    start();
}

void AnimatedRect::action(){
    if (animating){
        if (loop){
            advance();
            redrawScene();
        }
        else {
            if (!done()){
                advance();
                redrawScene();
            }
        }
    }
}

