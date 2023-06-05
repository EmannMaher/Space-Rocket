#ifndef ASTROID_H
#define ASTROID_H
#include <math.h>
#include<GL/glut.h>
class Astroid
{
    public:
        Astroid();
        virtual ~Astroid();
        float positionX;
        float positionY;
        int r;
        int g;
        int b;
        void Draw(float cx, float cy);
};

#endif // ASTROID_H
