//Tobias Egger, 16-728-016

#include <stdio.h>
#include <math.h>

#ifdef __MINGW32__
#include <windows.h>
#endif
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//bottom line left to right
void l1(double x0, double y0, double dx, double dy){
	glVertex2f(x0+1*dx/2, y0+dy/2);
	glVertex2f(x0+3*dx/2, y0+dy/2);
	glVertex2f(x0+5*dx/2, y0+dy/2);
}
//middle line right to left
void l2(double x0, double y0, double dx, double dy){
	glVertex2f(x0+5*dx/2, y0+3*dy/2);
	glVertex2f(x0+3*dx/2, y0+3*dy/2);
	glVertex2f(x0+1*dx/2, y0+3*dy/2);
}
//top line left to right
void l3(double x0, double y0, double dx, double dy){
	glVertex2f(x0+1*dx/2, y0+5*dy/2);
	glVertex2f(x0+3*dx/2, y0+5*dy/2);
	glVertex2f(x0+5*dx/2, y0+5*dy/2);
}
//S from bottom to top
void A(double x0, double y0, double dx, double dy) {	
	l1(x0,y0,dx,dy);
	l2(x0,y0,dx,dy);
	l3(x0,y0,dx,dy);
}

void drawHilbertCurveII(double x0, double y0, double xm, double ym, int iter){
	double dx, dy;	
	dx = (xm-x0)/3;
	dy = (ym-y0)/3;
	
	if (iter > 1){
		drawHilbertCurveII(x0,y0,x0+dx,y0+dy,iter-1);
		drawHilbertCurveII(x0+dx,y0+dy,x0+2*dx,y0,iter-1);
		drawHilbertCurveII(x0+2*dx,y0,x0+3*dx,y0+dy,iter-1);
		drawHilbertCurveII(x0+3*dx,y0+dy,x0+2*dx,y0+2*dy,iter-1);
		drawHilbertCurveII(x0+2*dx,y0+2*dy,x0+dx,y0+dy,iter-1);
		drawHilbertCurveII(x0+dx,y0+dy,x0,y0+2*dy,iter-1);
		drawHilbertCurveII(x0,y0+2*dy,x0+dx,y0+3*dy,iter-1);
		drawHilbertCurveII(x0+dx,y0+3*dy,x0+2*dx,y0+2*dy,iter-1);
		drawHilbertCurveII(x0+2*dx,y0+2*dy,x0+3*dx,y0+3*dy,iter-1);	
	} else{
		A(x0,y0,dx,dy);
	}
}

// is called by Glut to draw the window
void DrawGLScene() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0);
  glViewport(0, 0, 600, 600);	
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 600, 600, 0);
  glBegin(GL_LINE_STRIP);

  // Call recursive function here.
  drawHilbertCurveII(0,600,600,0,4);

  glEnd();
  glFlush();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv); // Declare initial window
  glutInitWindowSize(600,600);
  glutCreateWindow("Hilbert Curve II"); // Open window with the title "Tree".
  glutDisplayFunc(DrawGLScene); /* use the function "DrawGLScene" to determine what
                                   will be shown in the window you created */
  glutMainLoop(); // Enter main loop and process events.
}

// Linux: gcc task7b.c -o task7b -lm -lglut -lGL; ./task7b
// Mac-OS: gcc task7b.c -o task7b -lm -framework OpenGL -framework GLUT; ./task7b
// Windows: gcc task7b.c -o  task7b -lm -lfreeglut -lopengl32; task7b

