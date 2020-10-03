/**
@Aim: Program to implement Midpoint Circle Generation Algorithm
@Author: Roll No.: 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void plot8(int,int,int,int);
void main(){
int gdriver=DETECT,gmode;
int x0,y0,r;
int x,y,pk;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
cleardevice();
printf("Enter center (x y): ");
scanf("%d %d",&x0,&y0);
printf("Enter radius: ");
scanf("%d",&r);
x=0;
y=r;
pk=1-r;
plot8(x,y,x0,y0);
while(x<=y){
if(pk<0){
x++;
pk=pk+(2*x)+1;
}
else{
x++;
y--;
pk=pk+(2*x)+1-(2*y);
}
plot8(x,y,x0,y0);
}
getch();
closegraph();
}
void plot8(int x,int y,int x0,int y0){
putpixel(x0+x,y0+y,15);
putpixel(x0-x,y0+y,15);
putpixel(x0+x,y0-y,15);
putpixel(x0-x,y0-y,15);
putpixel(x0+y,y0+x,15);
putpixel(x0-y,y0+x,15);
putpixel(x0+y,y0-x,15);
putpixel(x0-y,y0-x,15);
}