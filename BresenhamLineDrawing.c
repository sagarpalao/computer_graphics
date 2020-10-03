/**
@Aim: Program to rasterize a line using Bresenham's line drawing algorithm
@Author: Roll No. 73, 77
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){

	int x1,y1,x2,y2;
	int gd=DETECT;
	int gm;
	int x,y;
	int dx,dy,pk,i;


	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	printf("Enter start point (x y): ");
	scanf("%d %d",&x1,&y1);

	printf("Enter end point (x,y): ");
	scanf("%d %d",&x2,&y2);

	dx=x2-x1;
	dy=y2-y1;

	x=x1;
	y=y1;

	pk=2*dy-dx;

	putpixel(x,y,15);

	i=0;
	while(i<=dx){
		if(pk<0){
			x=x+1;
			y=y;
			pk=pk+(2*dy);
		}
		else{
			x=x+1;
			y=y+1;
			pk=pk+(2*dy)-(2*dx);
		}
		putpixel(x,y,15);
		i++;
	}

	getch();
	closegraph();
}
