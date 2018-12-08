#include "TexRect.h"

TexRect::TexRect(const char* filename, float x=0, float y=0, float w=0.5, float h=0.5): Rect(x, y, w, h, 1.0f, 1.0f, 1.0f){
    
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    texture_id = SOIL_load_OGL_texture (
                                        filename,
                                        SOIL_LOAD_AUTO,
                                        SOIL_CREATE_NEW_ID,
                                        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                                        );
    
    if(0 == texture_id){
        std::cout <<"SOIL loading error: " << SOIL_last_result() << std::endl;
    }
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}


void TexRect::draw(float z) const {
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glEnable(GL_TEXTURE_2D);
    
    glBegin(GL_QUADS);
    glColor4f(1, 1, 1, 1);
    glTexCoord2f(0, 0);
    glVertex3f(x, y - h, z);
    
    glTexCoord2f(0, 1);
    glVertex3f(x, y, z);
    
    glTexCoord2f(1, 1);
    glVertex3f(x+w, y, z);
    
    glTexCoord2f(1, 0);
    glVertex3f(x+w, y - h, z);
    
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}
