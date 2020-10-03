/**
@AIM: PROGRAM TO IMPLEMENT BEZIER CURVE
@AUTHOR: ROLL NO.: 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int n;
double p[20];
void bezier_curve();
int nCr(int,int);
void main(){
int i;
int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"C:\\tc\\bgi");
printf("Enter order of beizer curve: ");
scanf("%d",&n);
printf("Enter control points: ");
for(i=0;i<(n+1)*2;i+=2){
printf("\nP: ");
scanf("%lf%lf",&p[i],&p[i+1]);
}
clearviewport();
for(i=0;i<(n+1)*2;i+=2){
putpixel(p[i],p[i+1],14);
}
bezier_curve();
getch();
}
void bezier_curve(){
double u,x,y,sum_x,sum_y;
double i;
int j;
sum_x=0.0;
sum_y=0.0;
for(u=0.001;u<=0.999;u+=0.001){
j=0;
for(i=0;i<=n;i++){
x=nCr(n,i)*pow(u,i)*pow(1-u,n-i)*p[j];
y=nCr(n,i)*pow(u,i)*pow(1-u,n-i)*p[j+1];
sum_x=sum_x+x;
sum_y=sum_y+y;
j+=2;
}
putpixel(sum_x,sum_y,15);
sum_x=0.0;
sum_y=0.0;
}
}
int nCr(int n,int r){
if(n==r||r==0){
return 1;
}
else{
return nCr(n-1,r-1)+nCr(n-1,r);
}
}