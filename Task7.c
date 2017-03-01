//Tobias Egger, 16-728-016

#include <stdio.h>

double x0, y0, dx, dy;
//bottom line left to right
void l1(){
	x0+dx/2, y0+dy/2;
	x0+3*dx/2, y0+dy/2;
	x0+5*dx/2, y0+dy/2;
}
//bottom line right to left
void l1a(){
	x0+5*dx/2, y0+dy/2;
	x0+3*dx/2, y0+dy/2;
	x0+dx/2, y0+dy/2;
	
}
//middle line right to left
void l2(){
	x0+5*dx/2, y0+3*dy/2;
	x0+3*dx/2, y0+3*dy/2;
	x0+dx/2, y0+3*dy/2;
}
//middle line left to right
void l2a(){
	x0+dx/2, y0+3*dy/2;
	x0+3*dx/2, y0+3*dy/2;
	x0+5*dx/2, y0+3*dy/2;
}
//top line left to right
void l3(){
	x0+dx/2, y0+5*dy/2;
	x0+3*dx/2, y0+5*dy/2;
	x0+5*dx/2, y0+5*dy/2;
}
//top line right to left
void l3a(){
	x0+5*dx/2, y0+5*dy/2;
	x0+3*dx/2, y0+5*dy/2;
	x0+dx/2, y0+5*dy/2;
	
	
}
//S from bottom to top
void A() {	
	l1();
	l2();
	l3();
}
//Z from top to bottom
void B(){
	l3();
	l2();
	l1();
}
void C(){
	l3a();
	l2a();
	l1a();
}
void D(){
	l1a();
	l2a();
	l3a();
}

void drawHilbertCurveII(double x0, double y0, double xm, double ym, int iter){
	double dx, dy;	
	dx = (xm-x0)/3;
	dy = (ym-y0)/3;
	A();
	
//	if (iter > 1){
//		drawHilbertCurveII(x0,y0,x0+dx,y0+dy,iter-1);
//		drawHilbertCurveII(x0+dx,y0+dy,x0+2*dx,y0,iter-1);
//		drawHilbertCurveII(x0+2*dx,y0,x0+3*dx,y0+dy,iter-1);
//		drawHilbertCurveII(x0+3*dx,y0+dy,x0+2*dx,y0+2*dy,iter-1);
//		drawHilbertCurveII(x0+2*dx,y0+2*dy,x0+dx,y0+dy,iter-1);
//		drawHilbertCurveII(x0+dx,y0+dy,x0,y0+2*dy,iter-1);
//		drawHilbertCurveII(x0,y0+2*dy,x0+dx,y0+3*dy,iter-1);
//		drawHilbertCurveII(x0+dx,y0+3*dy,x0+2*dx,y0+2*dy,iter-1);
//		drawHilbertCurveII(x0+2*dx,y0+2*dy,x0+3*dx,y0+3*dy,iter-1);	
//	} else{
//		
//		printf()
//	}
}

int main(){
	drawHilbertCurveII(1,1,7,7,1);
	return 0;
}
