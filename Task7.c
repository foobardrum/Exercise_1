//Tobias Egger, 16-728-016

#include <stdio.h>

//bottom line left to right
void l1(double x0, double y0, double dx, double dy){
	printf("(%lf,%lf)\n",x0+1*dx/2, y0+dy/2);
	printf("(%lf,%lf)\n",x0+3*dx/2, y0+dy/2);
	printf("(%lf,%lf)\n",x0+5*dx/2, y0+dy/2);
}
//middle line right to left
void l2(double x0, double y0, double dx, double dy){
	printf("(%lf,%lf)\n",x0+5*dx/2, y0+3*dy/2);
	printf("(%lf,%lf)\n",x0+3*dx/2, y0+3*dy/2);
	printf("(%lf,%lf)\n",x0+1*dx/2, y0+3*dy/2);
}
//top line left to right
void l3(double x0, double y0, double dx, double dy){
	printf("(%lf,%lf)\n",x0+1*dx/2, y0+5*dy/2);
	printf("(%lf,%lf)\n",x0+3*dx/2, y0+5*dy/2);
	printf("(%lf,%lf)\n",x0+5*dx/2, y0+5*dy/2);
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


int main(){
	drawHilbertCurveII(1,1,7,7,1);
	return 0;
}
