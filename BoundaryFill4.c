/**
	@AIM: Boundary Fill Algorithm(4 COnnected Region)
@AUTHOR: Roll No :73,77.
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundaryfill(int,int,int,int);

void main(){
	int gdriver=DETECT,gmode;
int points[22] = {130,100,120,120,100,120,120,140,108,160,130,150,152,160,140,140,160,120,140,120,130,100};
	int x,y;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	drawpoly(11,points);
	boundaryfill(130,120,15,4);
	getch();
}

void boundaryfill(int x,int y,int boundary,int fill){
int current=getpixel(x,y);
	if(current!=boundary && current!=fill){
		putpixel(x,y,fill);
		delay(5);
		boundaryfill(x+1,y,boundary,fill);
		boundaryfill(x-1,y,boundary,fill);
		boundaryfill(x,y+1,boundary,fill);
		boundaryfill(x,y-1,boundary,fill);
	}
}
