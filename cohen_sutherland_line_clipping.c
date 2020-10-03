**
	@AIM: TO IMPLEMENT COHEN-SUTHERLAND LINE CLIPPING ALGORITHM
@AUTHOR: Roll No :73,77.
*/

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

double wxmin,wxmax,wymin,wymax;
double x1,y1,x2,y2;
double m;

void accept_window();
void accept_line();
void bit_code(int code[4],int x,int y);
int AND(int c1[4],int c2[4]);
void clip(int x1,int y1,int x2,int y2);
int is0(int c[4]);

void main(){

	int gd=DETECT,gm;

	clrscr();

	initgraph(&gd,&gm,"C:\\turboc3\\bgi");

	accept_window();
	accept_line();

	clip(x1,y1,x2,y2);

	getch();
}

void accept_window(){
	printf("Enter clipping window:\nwxmin, wxmax, wymin, wymax:\n");
	scanf("%lf%lf%lf%lf",&wxmin,&wymin,&wxmax,&wymax);
	rectangle(wxmin,wymin,wxmax,wymax);
}

void accept_line(){
	printf("\n\nEnter x1 y1, x2 y2: ");
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);

	setlinestyle(1,1,1);
	line(x1,y1,x2,y2);

	m=(y2-y1)/(x2-x1);

}

void bit_code(int code[4],int x,int y){
	if(x<wxmin)
		code[3]=1;
	else
		code[3]=0;

	if(x>wxmax)
		code[2]=1;
	else
		code[2]=0;

	if(y>wymax)
		code[1]=1;
	else
		code[1]=0;

	if(y<wymin)
		code[0]=1;
	else
		code[0]=0;
}

int AND(int c1[4],int c2[4]){

	int i,c3[4];

	for(i=0;i<4;i++){
		c3[i]=c1[i]&c2[i];
	}

	for(i=0;i<4;i++){
		if(c3[i]!=0){
			break;
		}
	}

	if(i==4){
		return 1;
	}
	else{
		return 0;
	}
}

int is0(int c[4]){
	int i;
	for(i=0;i<4;i++){
		if(c[i]!=0){
			break;
		}
	}
	if(i==4){
		return 1;
	}
	else{
		return 0;
	}
}

void clip(int x1,int y1,int x2,int y2){

	int i,x,y;
	int scode[4],ecode[4];

	bit_code(scode,x1,y1);
	bit_code(ecode,x2,y2);

	/*for(i=0;i<4;i++){
		printf("%d",scode[i]);
	}
	printf("\n");
	for(i=0;i<4;i++){
		printf("%d",ecode[i]);
	}
	getch();*/

	if( is0(scode) && is0(ecode) ){
		setlinestyle(0,1,3);
		line(x1,y1,x2,y2);
		getch();
		exit();
	}
	else if(!AND(scode,ecode) ){
		getch();
	}
	else{
		for(i=4-1;i>=0;i--){
			if(scode[i]==1){
				if(i==3){
					x=wxmin;
					y=y1+(x-x1)*m;
				}
				else if(i==2){
					x=wxmax;
					y=y1+(x-x1)*m;
				}
				else if(i==1){
					y=wymax;
					x=x1+(y-y1)/m;
				}
				else if(i==0){
					y=wymin;
					x=x1+(y-y1)/m;
				}
				clip(x,y,x2,y2);
			}
			else if(ecode[i]==1){
				if(i==3){
					x=wxmin;
					y=y2+(x-x2)*m;
				}
				else if(i==2){
					x=wxmax;
					y=y2+(x-x2)*m;
				}
				else if(i==1){
					y=wymax;
					x=x2+(y-y2)/m;
				}
				else if(i==0){
					y=wymin;
					x=x2+(y-y2)/m;
				}
				clip(x1,y1,x,y);
			}
		}
	}
}
