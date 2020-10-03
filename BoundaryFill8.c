/**
	@AIM: Boundary Fill Algorithm(8 COnnected Region)
@AUTHOR: Roll No :73,77.
*/


#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundaryfill(int,int,int,int);

void main(){
	int gdriver=DETECT,gmode;
	int x,y;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	rectangle(50,50,100,100);
	boundaryfill(55,55,15,4);
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
		boundaryfill(x+1,y-1,boundary,fill);
		boundaryfill(x+1,y+1,boundary,fill);
		boundaryfill(x-1,y-1,boundary,fill);
		boundaryfill(x-1,y+1,boundary,fill);
	}
}
