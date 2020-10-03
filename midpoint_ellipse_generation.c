/**
@Aim: Program to implement Midpoint Ellipse Generation Algorithm
@Author: Roll No.: 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void plot4(float,float,float,float);
void main(){
int gd=DETECT,gm;
float x0,y0,x,y,rx,ry;
float p1,p2;
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
printf("Enter center point: ");
scanf("%f%f",&x0,&y0);
printf("Enter radius along x-axis: ");
scanf("%f",&rx);
printf("Enter radius along y-axis: ");
scanf("%f",&ry);
x=0;
y=ry;
p1=(ry*ry)-(rx*rx*ry)+(rx*rx)/4 ;
plot4(x,y,x0,y0);
while( (2*ry*ry*x) <= (2*rx*rx*y) ){
if(p1<0){
x=x+1;
y=y;
p1=p1+(2.0*ry*ry*x)+(ry*ry);
}
else{
x=x+1;
y=y-1;
p1= p1+(2.0*ry*ry*x)+(ry*ry)-(2.0*rx*rx*y);
}
plot4(x,y,x0,y0);
}
p2 = (rx*rx)*((y-1)*(y-1))+(ry*ry)*((x+0.5)*(x+0.5))-(rx*rx*ry*ry);
while(y!=0){
if(p2>0){
y=y-1;
x=x;
p2=p2+(rx*rx)-(2.0*rx*rx*y);
}
else{
y=y-1;
x=x+1;
p2=p2+(2.0*ry*ry*x)-(2.0*rx*rx*y)+(rx*rx);
}
plot4(x,y,x0,y0);
}
getch();
}
void plot4(float x,float y,float x0,float y0){
putpixel(x0+x,y0+y,15);
putpixel(x0+x,y0-y,15);
putpixel(x0-x,y0+y,15);
putpixel(x0-x,y0-y,15);
delay(100);
}