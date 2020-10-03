/**
	@Aim: Flood Fill Algorithm(8 Connected)
	@Author: ROll No: 73,77.
*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood_fill(int x,int y,int init,int fill){
	int current=getpixel(x,y);
	if(current==init && current!=fill){
		putpixel(x,y,fill);
		flood_fill(x+1,y,init,fill);
		flood_fill(x-1,y,init,fill);
		flood_fill(x,y-1,init,fill);
		flood_fill(x,y+1,init,fill);
		flood_fill(x+1,y+1,init,fill);
		flood_fill(x+1,y-1,init,fill);
		flood_fill(x-1,y+1,init,fill);
		flood_fill(x-1,y-1,init,fill);
	}
}
void main(){
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\turboc3\\bgi");
	rectangle(50,50,100,100);
	flood_fill(55,55,BLACK,RED);
	getch();
}
