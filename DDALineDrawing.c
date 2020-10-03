/**
@Aim: Program to rasterize a line using DDA line drawing algorithm
@Author: Roll No. 73, 77
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int round(double x){
	return (int)(x+0.5);
}

void main(){

	int gd=DETECT;
	int gm;
	int x,y,i;
	int step;
	double x_incr,y_incr;
	int x1,y1,x2,y2;
	double dx,dy;

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("Enter start point (x,y): ");
	scanf("%d %d",&x1,&y1);

	printf("Enter end point (x,y): ");
	scanf("%d %d",&x2,&y2);

	dx=x2-x1;
	dy=y2-y1;

	if(abs(dx)>abs(dy)){
		step=abs(dx);
	}
	else{
		step=abs(dy);
	}

	x=x1;
	y=y1;
	x_incr=dx/step;
	y_incr=dy/step;

	putpixel(round(x),round(y),15);

	for(i=0;i<=step;i++){
		x=x+x_incr;
		y=y+y_incr;
		putpixel(round(x),round(y),15);
	}

	getch();
	closegraph();
}
