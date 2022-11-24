/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <gl/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <windows.h>
#include <math.h>

void reshape(int w,int h);
//void timer(int);
void display();
void init(){
    glClearColor(0.0,0.0,0.25,0.0);

}
float rotationAngle=0;
float step=0;//boat translate
float stepx=0;//rotation
float stept=0;// moon translate
int state = 1;//boat translate
int state1 = 1;// moon translate
void timer(int);//boat timer
void timerx(int);//rotation timer
void timert(int);//moon timer
int main(int argc,char**argv)
{
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowPosition(200,0);
        glutInitWindowSize(1200,800);
        glutCreateWindow("20102372, 20102364");
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutTimerFunc(0,timer,0);
        glutTimerFunc(0,timerx,0);
        glutTimerFunc(0,timert,0);
        init();
        glutMainLoop();

}

float angle=0.0;

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glLineWidth(5);

    glPushMatrix();
    glRotated(rotationAngle,0,0,1);
    glBegin(GL_QUADS);//boat
    glColor3ub(116, 52, 32);//brown
    glPopMatrix();
    glVertex2f(-5+step,-2);
    glVertex2f(5+step,-2);
    glVertex2f(2+step,-4);
    glVertex2f(-2+step,-4);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

    glPushMatrix();
    glBegin(GL_QUADS);//line
    glColor3f(0,0,0);//black
    glVertex2f(-0.5+step,2);
    glVertex2f(0+step,2);
    glVertex2f(0+step,-2);
    glVertex2f(-0.5+step,-2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);//flag
    glColor3f(0.7,0.5,1.2);//light purple
    glVertex2f(-3+step,0);
    glVertex2f(-0.5+step,0);
    glVertex2f(-0.5+step,1.5);
    //glVertex2f(0+step,-3);
    glEnd();
    glPopMatrix();


     glPushMatrix();
     glBegin(GL_POLYGON);//mountains
     glLineWidth(10.0);
     glBegin(GL_LINE_LOOP);

     glColor3f(1, 0, 0 );//red mountain
     glVertex2d(-14,-1.5);
     glVertex2d(-10,5);
     glVertex2d(-4,-1.5);

     glColor3f(1, 0, 1);//pink mountain
     glVertex2d(-9,-1.5);
     glVertex2d(-5,3);
     glVertex2d(-1,-1.5);

     glColor3f(0, 0, 1 );//blue mountain
     glVertex2d(-6,-1.5);
     glVertex2d(-1,2);
     glVertex2d(3,-1.5);

     glEnd();
     glPopMatrix();

     glPushMatrix();//moon
     glTranslated(10,7,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(220, 255, 255 );


     for(int i=0;i<360;i++){ //circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-2*cos(angle)+stept,2*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glPushMatrix();//waves1
     glTranslated(10.5,-10,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(0,100,255);


     for(int i=0;i<180;i++){ //half circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-6*cos(angle),6*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glPushMatrix();//waves2
     glTranslated(3,-10,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(0,100,255);


     for(int i=0;i<180;i++){ //half circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-6*cos(angle),6*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glPushMatrix();//waves3
     glTranslated(-5,-10,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(0,100,255);


     for(int i=0;i<180;i++){ //half circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-6*cos(angle),6*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glPushMatrix();//waves4
     glTranslated(-13,-10,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(0,100,255);


     for(int i=0;i<180;i++){ //half circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-6*cos(angle),6*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glPushMatrix();//waves5
     glTranslated(-17,-10,0);
     glBegin(GL_POLYGON);
     glColor3f(255,255,255);
     glColor3ub(0,100,255);


     for(int i=0;i<180;i++){ //half circle
        int radius = 2 ;
        double angle= i * 3.14/180;
        glVertex2d(-6*cos(angle),6*sin(angle));

     }
     glEnd();
     glPopMatrix();

     glFlush();

}

void reshape(int w,int h)
{
  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-15,15,-10,10);
  glMatrixMode(GL_MODELVIEW);

}

void timer(int) //for boat
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

        if(stepx > 4)
                stepx -= 0.1;


	switch(state)
	{
	case 1:
	    if(step<10)
            step+=0.10;
        else
            state =-1;
        break;
     case -1:
         if(step > 4)
            step-=0.1;
         else
            state=1;
         break;
        }
	}
void timerx(int) //for rotation
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

            if (rotationAngle<30)
            rotationAngle += 5;

}
void timert(int)   //for moon
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timert,0);

        if(stept < 4)
                stept -= 0.1;


	switch(state)
	{
	case 1:
	    if(stept<=10)
            stept+=0.15;
        else
            state1 =-1;
        break;\
     case -1:
         if(stept > 0)
            stept-=0.15;
         else
            state1=1;
         break;

	}
}

