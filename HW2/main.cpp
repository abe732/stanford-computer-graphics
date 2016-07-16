/*******************************************************
 * Homework 2: OpenGL                                  *
 * CS 148 (Summer 2016), Stanford University           *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 1000, windowHeight = 640;
double yRot = 0;
int curProblem = 4; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
    int x = 0;
    int y = 0;
    int angleRot = 0;
    
    glPushMatrix();
    for (int i=0; i<10; i++) {
        float translateAngleA = cos(x * 3.14 / 180.0);
        float translateAngleB = sin(y * 3.14 / 180.0);
        
        glPushMatrix();
        glTranslatef(translateAngleA, translateAngleB, 0);
        glRotatef(180, 0, 1, 0);
        glRotatef(angleRot, 0, 0, 1);
        glutSolidTeapot(.2);
        glPopMatrix();
        
        x += 36;
        y += 36;
        angleRot += sin(x * 3.14 / 180.0) - 36 ;
    }
    glPopMatrix();
    glFlush();

}

void problem2() {
    float xShift = 1;
    float yScale = 1;
    float yShift = 0;
    
    glPushMatrix();
    glTranslatef(-2.1, 0, 0);
    
    for (int i = 0; i < 15; i++) {
        glPushMatrix();
        glTranslatef(xShift, yShift, 0);
        glScalef(1, yScale, 1);
        glutSolidCube(.15);
        glPopMatrix();
        
        xShift += .15;
        yScale += .15;
        yShift += .01;
    }
    glPopMatrix();
    glFlush();
}

void problem3() {
    float xShift = 0;
    float yShift = 0;
    float teapotSize = .2;
    glPushMatrix();
    glTranslatef(.25, 1.25, 0);
    
    for (int i = 1; i < 7; i ++) { //new level below
        float xCenter = -(xShift) - (i * (teapotSize * 1.5));
        glPushMatrix();
        glTranslatef(xCenter, yShift, 0);
    
        for (int j = i; j > 0; j-- ){ //move sidewaya
            glPushMatrix();
            glTranslatef(xShift, 0, 0);
            glutSolidTeapot(teapotSize);
            glPopMatrix();
            
            xShift += .7;
        }
        
        yShift -= .4;
        glPopMatrix();
        
    }
    glPopMatrix();
    glFlush();
    
}

//helper functions for problem 4:

void beak () { //tried to make yellow
    glBegin( GL_TRIANGLES );
    
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, 1.f, 0.0f );
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f );
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
    
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    
    glEnd();
}

void head () {
    glPushMatrix();
    glTranslatef(0, .6, .6);
    glScalef(.9, 1, 1.2);
    glutSolidSphere(.3, 10, 10);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(.18, .7, .8);
    glutSolidSphere(.05, 5, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-.18, .7, .8);
    glutSolidSphere(.05, 5, 5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, .5, .98);
    glScalef(.18f, .15f, .3f);
    glRotatef(130, 1, 0, 0);
    beak();
    glEnd();
    
    glPopMatrix();
}

void tail () {
    glPushMatrix();
    glTranslatef(0, -.4, -.4);
    glScalef(.25, .5, .5);
    glRotatef(-15, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    
    glBegin( GL_TRIANGLES );
    
    glColor3f(1.0, 1.0, 0.0); glVertex3f(0.0f, 1.f, 0.0f );
    glColor3f(1, 1, 0); glVertex3f(-1.0f, -1.0f, 1.0f );
    glColor3f(1, 1, 0); glVertex3f(1.0f, -1.0f, 1.0f);
    
    glEnd();
    
    glPopMatrix();
}

void torso () {
    glPushMatrix();
    glRotatef(-45, 1, 0 ,0);
    glScalef(.4, .5, .9);
    glutSolidSphere(1, 10, 10);
    glPopMatrix();
}

void legs () {
    glPushMatrix();
    
    glPushMatrix();
    glTranslatef(-.15, -.5, .2);
    glRotatef(-15, 1, 0 ,0);
    glScalef(.15, 2, .15);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-.15, -.78, .28);
    glutSolidSphere(.04, 5, 5);
    
    glPushMatrix();
    glTranslatef(0, -.10, .16);
    glRotatef(-60, 1, 0 ,0);
    glScalef(.15, 1.25, .15);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -.18, .25);
    glRotatef(-30, 0, 1, 0);
    glPushMatrix();
    glutSolidCone(.04, .3, 5, 5);
    glRotatef(25, 0, 1, 0);
    glutSolidCone(.04, .3, 5, 5);
    glRotatef(25, 0, 1, 0);
    glutSolidCone(.04, .3, 5, 5);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(.15, -.5, .2);
    glRotatef(-15, 1, 0 ,0);
    glScalef(.15, 2, .15);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(.15, -.78, .28);
    glutSolidSphere(.05, 5, 5);
    
    glPushMatrix();
    glTranslatef(0, -.10, .16);
    glRotatef(-60, 1, 0 ,0);
    glScalef(.15, 1.25, .15);
    glutSolidCube(.3);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, -.18, .25);
    glRotatef(-30, 0, 1, 0);
    glPushMatrix();
    glutSolidCone(.04, .3, 5, 5);
    glRotatef(25, 0, 1, 0);
    glutSolidCone(.04, .3, 5, 5);
    glRotatef(25, 0, 1, 0);
    glutSolidCone(.04, .3, 5, 5);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
}

void feather () {
    glPushMatrix();
    glScalef(.5, 4, .3);
    glutSolidCube(.2);
    glPopMatrix();
}

void wing() {
    float zScale = 1;
    float xScale = .5;
    float yScale = 3;
    float tipShift = 1;
    
    for (int i=0; i<15; i++) {
        float xShift = (i*.13);
        glPushMatrix();
        glTranslatef(xShift, 0, 0);
        glPopMatrix();
    }
    
    for (int i=0; i<20; i++) {
        float xShift = i * .12;
        float featherRot = -i * 3;
        glPushMatrix();
        glTranslatef(xShift, .8, 0);
        glScalef(1, 2, .1);
        
        glPushMatrix();
        glRotatef(featherRot, 0, 0, 1);
        glScalef(xScale, yScale, zScale);
        glutSolidCube(.2);
        glPopMatrix();
       
        glPopMatrix();
        
        yScale += .35;
        zScale -= .05;
    }
}

void problem4() {
    glPushMatrix();
    glTranslatef(0, .5, -.5);
    glScalef(.75, .75, .75);
    
    torso();
    head();
    tail();
    
    glPushMatrix();
    glRotatef(15, 1, 0, 0);
    legs();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-.25, .4, 0);
    glRotatef(-30, 0, 1, 0);
    glRotatef(-180, 1, 0, 1);
    wing();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.25, .4, 0);
    glRotatef(30, 0, 1, 0);
    glRotatef(-180, 1, 0, 1);
    wing();
    glPopMatrix();
    
    glPopMatrix();
    
    glFlush();
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
