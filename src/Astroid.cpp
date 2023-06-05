#include "Astroid.h"

Astroid::Astroid(){
int x = rand()%3 +1;
if (x==1){
this->r=0;
this->g=0;
this->b=1;
}
else if (x==2){
this->r=0;
this->g=1;
this->b=0;
}
else{
this->r=1;
this->g=0;
this->b=0;
}
this->positionX=(rand()%100);
if (this->positionX>100)
    this->positionX=95;
else if (this->positionX<5)
    this->positionX=5;
this->positionY=100.0;
}

Astroid::~Astroid(){
this->positionX=1000;
}

void Astroid::Draw(float cx, float cy){
glColor3f(this->r,this->g,this->b);
glBegin(GL_POLYGON);
for (int i = 0; i < 100; i++){
float theta = 2.0f * 3.1415926f * float(i) / float(100);//get the current angle
float x = 3 * cosf(theta);//calculate the x component
float y = 3 * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
this->positionY --;
glEnd();
}
