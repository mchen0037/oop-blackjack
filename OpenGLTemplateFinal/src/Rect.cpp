#include "Rect.h"

Rect::Rect(float x, float y, float w, float h, float r, float g, float b): x(x), y(y), w(w), h(h), r(r), g(g), b(b){
    
}

float Rect::getX() const {
    return x;
}

float Rect::getY() const {
    return y;
}

float Rect::getW() const {
    return w;
}

float Rect::getH() const {
    return h;
}

float Rect::getR() const {
    return r;
}

float Rect::getG() const {
    return g;
}

float Rect::getB() const {
    return b;
}

void Rect::setX(float x) {
    this->x = x;
}

void Rect::setY(float y) {
    this->y = y;
}

void Rect::setW(float w) {
    this->w = w;
}

void Rect::setH(float h) {
    this->h = h;
}

void Rect::setR(float r) {
    this->r = r;
}

void Rect::setG(float g) {
    this->g = g;
}

void Rect::setB(float b) {
    this->b = b;
}

bool Rect::contains(float px, float py) const {
    return px >= x && px <= x + w && py <= y && py >= y - h;
}

void Rect::draw() const {
    glColor3f(r, g, b);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
    
    glEnd();
}


void Rect::redrawScene(){
    glutPostRedisplay();
}

Rect::~Rect(){
    
}
