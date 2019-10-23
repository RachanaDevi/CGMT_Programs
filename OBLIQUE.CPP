#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

//OBLIQUE CODE

void main(){
clrscr();
int x1,y1,x2,y2,gd,gm;
int ymax,a[4][8]={0};
float par[4][4],b[4][8];
memset(b,0,sizeof(b));
int i,j,k,m,n,p;
double L1,phi;

a[0][0]=100; a[1][0]=100;a[2][0]=100;
a[0][1]=200;a[1][1]=100;a[2][1]=100;
a[0][2]=200;a[1][2]=200;a[2][2]=100;
a[0][3]=100;a[1][3]=200;a[2][3]=100;

a[0][4]=100;a[1][4]=100;a[2][4]=200;
a[0][5]=200;a[1][5]=100;a[2][5]=200;
a[0][6]=200;a[1][6]=200;a[2][6]=200;
a[0][7]=100;a[1][7]=200;a[2][7]=200;

//oblique angle 45
phi=(double)(3.14*45.0)/180;
L1=0.5;

par[0][0]=1;par[0][1]=0;par[0][2]=L1*cos(phi);par[0][3]=0;

par[1][0]=0;par[1][1]=1;par[1][2]=L1*sin(phi);par[1][3]=0;

par[2][0]=par[2][1]=par[2][2]=par[2][3]=0;

par[3][0]=par[3][1]=par[3][2]=0; par[3][3]=1;

m=4;n=4;p=8;
for(i=0;i<m;i++)
 { for(j=0;j<p;j++)
   {
     for(k=0;k<n;k++)
     {
     b[i][j]+=(float)par[i][k]*a[k][j];
     }

   }
 }
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 ymax=getmaxy();

 //front plane display
 for(i=0;i<3;i++)
 {
   x1=(int)b[0][i];y1=(int)b[1][i];
   x2=(int)b[0][i+1];y2=(int)b[1][i+1];
   line(x1,ymax-y1,x2,ymax-y2);
 }

 //first and last
 x1=(int)b[0][0];y1=(int)b[1][0];
 x2=(int)b[0][3];y2=(int) b[1][3];
 line(x2,ymax-y2,x1,ymax-y1);

 //for back display
 setcolor(GREEN);
 for(i=4;i<7;i++)
 {
   x1=(int)b[0][i];y1=(int)b[1][i];
   x2=(int)b[0][i+1];y2=(int)b[1][i+1];
   line(x1,ymax-y1,x2,ymax-y2);

 }
 x1=(int)b[0][7];y1=(int)b[1][7];
 x2=(int)b[0][4];y2=(int)b[1][4];
 line(x1,ymax-y1,x2,ymax-y2);

 //joining the ends
 setcolor(RED);
 for(i=0;i<4;i++)
 {
   x1=(int)b[0][i];y1=(int)b[1][i];
   x2=(int)b[0][i+4];y2=(int)b[1][i+4];
   line(x1,ymax-y1,x2,ymax-y2);
 }
getch();

}


