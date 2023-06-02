#include<GL/glut.h>
#include <stdio.h>
#include "Astroid.h"

int mouseX= 50, mouseY = 10;
int time=0;
int score=0;
Astroid astroids[25];
int beamR=0,beamG=1,beamB=0;
bool restart=true;
void passiveMouse(int x,int y){
    mouseX = x;
    mouseX=0.5+1.0*mouseX*100/700;
    mouseY = 700 - y;
    mouseY=0.5+1.0*mouseY*100/700;
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
            exit(0);
    } else if (key == ' ') {
        int x = rand()%3 +1;
    if (x==1){
            beamR=0;
            beamG=0;
            beamB=1;
    }else if (x==2){
            beamR=0;
            beamG=1;
            beamB=0;
    }else{
            beamR=1;
            beamG=0;
            beamB=0;
    }
  }
}

void init2D(){
    glClearColor( 0.0, 0.0, 0.0, 0.0);
    glMatrixMode( GL_PROJECTION);
    gluOrtho2D( 0.0, 100, 0.0, 100);
}

void printSome(char *str,int x,int y) {
    glColor3f (1, 1.0, 1.0);
    glRasterPos2d(x,y);
    for (int i=0;i<strlen(str);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
        glFlush();
}

void Display2(){
    glClear( GL_COLOR_BUFFER_BIT);
    glClearColor( 0.09,0.4,0.06, 0.0);
    printSome("TIME'S UP",45,55);
    printSome("Your score: ",42,50);
    char buffer[33];
    itoa(score, buffer, 10);
    printSome(buffer,57,50);
    printSome("Press F1 to play again!",40,45);
    glutSwapBuffers();
    glFlush();
}
void Display(){
    glClear( GL_COLOR_BUFFER_BIT);
    if(restart){
        for (int i = 0; i < 25; i++)
            astroids[i] = Astroid();
        restart=false;
        }
    if (time==20000)
        glutDisplayFunc(Display2);
    time+=10;
    glColor3f(1.0, 0.8, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(mouseX,mouseY);
    glVertex2i(mouseX+6,mouseY);
    glVertex2i(mouseX+6,mouseY+9);
    glVertex2i(mouseX,mouseY+9);
    glEnd();

    glColor3f(beamR,beamG,beamB);
    glBegin(GL_QUADS);
    glVertex2i(mouseX,mouseY+9);
    glVertex2i(mouseX+6,mouseY+9);
    glVertex2i(mouseX+6,mouseY+100);
    glVertex2i(mouseX,mouseY+100);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(mouseX,mouseY+9);
    glVertex2i(mouseX+6,mouseY+9);
    glVertex2i(mouseX+3,mouseY+13);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(mouseX-3,mouseY+1);
    glVertex2i(mouseX,mouseY+1);
    glVertex2i(mouseX,mouseY+6);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(mouseX+6,mouseY+1);
    glVertex2i(mouseX+9,mouseY+1);
    glVertex2i(mouseX+6,mouseY+6);
    glEnd();

    printSome("Score: ",5,95);
    printSome("Time: ",85,95);
    int i = 20-time/1000;
    char buffer[33];
    itoa(i, buffer, 10);
    printSome(buffer,93,95);
    itoa(score, buffer, 10);
    printSome(buffer,15,95);
    int currentNum=1;
    for (int i=0;i<currentNum;i++){
        astroids[i].Draw(astroids[i].positionX,astroids[i].positionY);
        if(astroids[i].positionY<20)
            currentNum++;
        if(mouseX<= astroids[i].positionX && astroids[i].positionX <= mouseX+6 &&astroids[i].positionY>=0 &&astroids[i].positionY<=100){
            beamR=astroids[i].r;
            beamG=astroids[i].g;
            beamB=astroids[i].b;
            delete &astroids[i];
            score++;
        }
    }
    glColor3f (1, 1.0, 1.0);
    for(int i=0;i<500;i++){
            glBegin(GL_POINTS);
    glVertex2i(rand()%100,rand()%100);
    glEnd();
    }
    glutSwapBuffers();
    glFlush();
}

void Timer(int value) {
    glutTimerFunc(10, Timer, value);
    glutPostRedisplay();
}

void special(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        score =0;
        time =0;
        restart=true;
        glClearColor( 0.0, 0.0, 0.0, 0.0);
        glutDisplayFunc(Display);
        glutPassiveMotionFunc(passiveMouse);
        glutKeyboardFunc(keyboard);
        glutSpecialFunc(special);
        Timer(0);
    }
}

int main( int argc, char ** argv){
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition( 300, 100);
    glutInitWindowSize(700,700);
    glutCreateWindow("El Space Rocket bta3 Ra7ma w Eman");
    init2D();
    glutDisplayFunc(Display);
    glutPassiveMotionFunc(passiveMouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    Timer(0);
    glutMainLoop();
}
