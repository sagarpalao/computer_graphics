/**
	@Aim: Flood Fill Algorithm(4 Connected)
	@Author: ROll No: 73,77.
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood_fill(int x,int y,int init,int fill){
	int current=getpixel(x,y);
	if(current==init && current!=fill){
		putpixel(x,y,fill);
		delay(1);
		flood_fill(x+1,y,init,fill);
		flood_fill(x-1,y,init,fill);
		flood_fill(x,y-1,init,fill);
		flood_fill(x,y+1,init,fill);
	}
}

void main(){

	int gdriver=DETECT,gmode;
	int b1[10]={100,100,100,122,122,122,122,87,100,100};
	int b2[10]={100,125,100,150,122,162,122,125,100,125};
	int b3[10]={125,87,125,122,150,122,150,73,125,87};
	int b4[10]={125,125,125,165,150,180,150,125,125,125};
	initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");

	drawpoly(5,b1);
	drawpoly(5,b2);
	drawpoly(5,b3);
	drawpoly(5,b4);

	outtextxy(90,190,"WINDOWS 10");

	flood_fill(105,105,BLACK,CYAN);
	flood_fill(105,130,BLACK,CYAN);
	flood_fill(127,127,BLACK,CYAN);
	flood_fill(127,100,BLACK,CYAN);

	getch();
}
