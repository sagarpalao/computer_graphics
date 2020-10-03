#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

float e[10][5];
inted[10];
intpt[10];
void main(){

	intgd=DETECT,gm,n,i,j,k,tmp,y,m;
	floatp,q,r,yk,xk;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	printf("Enter no. of edges: ");
	scanf("%d",&n);
	printf("\nEnterxmin, ymin, xmax, ymax: ");
	for(i=0;i<n;i++){
		flushall();
		printf("\nE%d: ",(i+1));
		scanf("%f%f%f%f",&e[i][0],&e[i][1],&e[i][2],&e[i][3]);
	}
	for(i=0;i<n;i++){
		if(e[i][3]-e[i][1]==0){
			for(j=i;j<n-1;j++){
				for(k=0;k<5;k++){
					e[j][k]=e[j+1][k];
				}
			}
			n--;
		}
	}
	for(i=0;i<n;i++){
		if(e[i][2]-e[i][0]==0){
			e[i][4]=0;
		}
		else{
			p=e[i][3]-e[i][1];
			q=e[i][2]-e[i][0];
			r=p/q;
			e[i][4]=1.0f/r;
		}
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(e[j][3]<e[j+1][3]){
				for(k=0;k<5;k++){
					tmp=e[j][k];
					e[j][k]=e[j+1][k];
					e[j+1][k]=tmp;
				}
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<5;j++){
			printf("%f\t",e[i][j]);
		}
	}
	getch();

	clearviewport();

	for(y=e[0][3];y>=e[n-1][1];y--){

		k=0;
		for(i=0;i<n;i++){
			if(y>=e[i][1] && y<=e[i][3]){
				for(m=0;m<k;m++){
					if(e[i][1]==e[ed[m]][3]||e[i][3]==e[ed[m]][1]){
					break;
					}
				}
				if(m==k){
					ed[k]=i;
					k++;
				}
			}
		}

		j=0;
		for(i=0;i<k;i++){
			yk=y;
			xk=e[ed[i]][0]+(y-e[ed[i]][1])*(e[ed[i]][4]);
			pt[j]=xk;
			pt[j+1]=y;
			j+=2;
		}

		for(i=0;i<j;i+=4){
			line(pt[i],pt[i+1],pt[i+2],pt[i+3]);
			delay(10);
		}

	}
	getch();
}
