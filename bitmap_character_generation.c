/**
@Aim: Program to implement Bitmap Character Generation Method
@Author: Roll No. 73, 77
*/
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void plot(char *);
void main(){
char *str;
int gd=DETECT;
int gm;
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
printf("Enter string: ");
gets(str);
plot(str);
getch();
closegraph();
}
void plot(char *s){
int p[7][5];
int i,k,j,x,y;
y=100;
x=10;
for(i=0;i<7;i++){
for(j=0;j<5;j++){
p[i][j]=0;
}
}
for(k=0;k<strlen(s);k++){
switch(s[k]){
case 'A':
p[0][2]=p[1][1]=p[1][3]=p[2][0]=p[2][4]=p[3][0]=p[3][4]=p[4][0]=p
[4][1]=p[4][2]=p[4][3]=p[4][4]=p[5][0]=p[5][4]=p[6][0]=p[6][4]=1;
break;
case 'B':
p[0][0]=p[0][1]=p[0][2]=p[1][0]=p[1][3]=p[2][0]=p[2][3]=p[3][0]=p
[3][1]=p[3][2]=p[3][3]=p[4][3]=p[4][0]=p[5][0]=p[5][3]=p[6][0]=p[6][1]
=p[6][2]=1;
break;
case 'C':
p[0][0]=p[0][1]=p[0][2]=p[1][0]=p[1][3]=p[2][0]=p[3][0]=p[4][0]=p
[5][0]=p[5][3]=p[6][0]=p[6][1]=p[6][2]=1;
break;
case 'D':
p[0][0]=p[0][1]=p[0][2]=p[1][0]=p[1][3]=p[2][0]=p[3][0]=p[4][0]=p
[5][0]=p[5][3]=p[6][0]=p[6][1]=p[6][2]=p[2][3]=p[3][3]=p[4][3]=1;
break;
}
for(i=0;i<7;i++){
for(j=0;j<5;j++){
if(p[i][j]==1){
putpixel(x+j,y+i,15);
}
}
}
for(i=0;i<7;i++){
for(j=0;j<5;j++){
p[i][j]=0;
}
}
x=x+8;
}
}