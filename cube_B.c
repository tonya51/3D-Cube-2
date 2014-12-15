/*
 *Authors:
          Strantzi Antonia, AEM 2090
          Dimitriadou Chaido Maria, AEM 2049
 *
 *Parameters:
             a=8
             b=90
             (vx,vy,vz)=(1,2,6)
*/

#include <Windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int run=0,scalefactor=0; // run=0 -> first time
float a=8.0,b=90.0,angle=0.0,scl=1.0;
 

void myinit(void)
{
	glEnable(GL_BLEND);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, 0.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
    glNewList(1, GL_COMPILE);
		glBegin(GL_POLYGON);
			glVertex3f(1.0, 1.0, 1.0);
			glVertex3f(1.0, -1.0, 1.0);
			glVertex3f(-1.0, -1.0, 1.0);
			glVertex3f(-1.0, 1.0, 1.0);
		glEnd();
	glEndList();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	glColor3f(1.0, 0.0, 0.0);
	glCallList(1);
	
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glCallList(1);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(270.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glCallList(1);
	glPopMatrix();
    
    glutSwapBuffers();
}

void findAngle()
{
     angle+=1.0;
     if(angle>360.0) angle-=360.0;
}

void findScale()
{
     if(scalefactor==0) 
     {
         scl+=0.01;     
         if(scl>2.0) scalefactor=1;          
     }
     else 
     {
         scl-=0.01;     
         if(scl<1.0) scalefactor=0; 
     }
}

void idle(void)
{
    if(run==0)       // first time
    {
        glMatrixMode(GL_MODELVIEW);
     	glLoadIdentity();
        glTranslatef(0.0,0.0,-b);
        glScalef(a,a,a);  
        run=1;       
    }
    else
    {       
      findAngle();
      findScale();
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(0.0,0.0,-8*b/10);
      glRotatef(angle,1.0,2.0,6.0);
      glTranslatef(0.0,0.0,-(b-(8*b/10)));
      glScalef(a*scl,a*scl,a*scl);
    }
    glutPostRedisplay();
}

void main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cube B");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glEnable(GL_DEPTH_TEST); 
	myinit();
	glutMainLoop();
}
