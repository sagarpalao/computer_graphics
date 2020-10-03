/**
@Aim: Program to plot a pixel in screen
@Author: Roll No. 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
int gdriver=DETECT;
int gmode;
int x,y,c;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
printf("\nEnter x & y coordinate of pixel to plot on screen (x y): ");
scanf("%d %d",&x,&y);
printf("\nEnter color of pixel to plot: ");
scanf("%d",&c);
//Plotting pixel at specified location and color
putpixel(x,y,c);
getch();
closegraph();
}