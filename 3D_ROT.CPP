#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

//3D ROTATION
void main()
{
  clrscr();
  int a[4][8]={1};
  int m,n,p,i,j,k,gd,gm;
  float par[4][4];
  float c[4][8],b[4][8],r[4][4];
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  memset(r,0,sizeof(r));
  double phi,angle;
  float F;
  cout<<"\nEnter angle:\n";
  cin>>angle;
  phi=(double)(angle*0.0175);
  cout<<"\nEnter value of F\n";
  cin>>F;

  a[0][0]= 100;a[1][0]=100;a[2][0]=100;
  a[0][1]= 200;a[1][1]=100;a[2][1]=100;
  a[0][2]= 200;a[1][2]=200;a[2][2]=100;
  a[0][3]= 100;a[1][3]=200;a[2][3]=100;


  a[0][4]=100;a[1][4]=100;a[2][4]=200;
  a[0][5]=200;a[1][5]=100;a[2][5]=200;
  a[0][6]=200;a[1][6]=200;a[2][6]=200;
  a[0][7]=100;a[1][7]=200;a[2][7]=200;

  //now par
    par[0][0]=1;par[0][1]=0;par[0][2]=F*cos(phi);par[0][3]=0;
    par[1][0]=0;par[1][1]=1;par[1][2]=F*sin(phi);par[1][3]=0;
    par[2][0]=par[2][1]=par[2][2]=par[2][3]=0;
    par[3][0]=par[3][1]=par[3][2]=0; par[3][3]=1;

    //now rotation towards Z clockwise

    //  cosQ -sinQ 0   0
    //  sinQ cosQ  0   0
    //  0     0    1   0
    //  0     0    0   1




     r[0][0]=cos(phi);r[0][1]=-sin(phi);r[0][2]=r[0][3]=0;
     r[1][0]=sin(phi);r[1][1]=cos(phi); r[1][2]=r[1][3]=0;
     r[2][0]=r[2][1]=0;r[2][2]=1;r[2][3]=0;
     r[3][0]=r[3][1]=r[3][2]=0; r[3][3]=1;

     m=4;n=4;p=8;

     for(i=0;i<m;i++)
     {
       for(j=0;j<p;j++)
       {
	for(k=0;k<n;k++)
	{
	 b[i][j]+=(float)par[i][k]*a[k][j];
	}
       }
     }
      for(i=0;i<m;i++)
     {
       for(j=0;j<p;j++)
       {
	 for(k=0;k<n;k++)
	 {
	  c[i][j]+=(float)r[i][k]*b[k][j];
	 }
       }
     }

     detectgraph(&gd,&gm);
     initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     int ymax=getmaxy();
     int x1,y1,x2,y2;

      //front display
      for(i=0;i<3;i++)
      {
	 x1=(int)c[0][i];y1=(int)c[1][i];
	 x2=(int)c[0][i+1];y2=(int)c[1][i+1];
	 line(x1,ymax-y1,x2, ymax-y2);
      }
      x1=(int)c[0][3];y1=(int)c[1][3];
      x2=(int)c[0][0];y2=(int)c[1][0];
      line(x1,ymax-y1,x2,ymax-y2);

      //back display
      setcolor(RED);
     for(i=4;i<7;i++)
      {

       x1=(int)c[0][i];y1=(int)c[1][i];
       x2=(int)c[0][i+1];y2=(int)c[1][i+1];
       line(x1,ymax-y1,x2,ymax-y2);

     }
     x1=(int)c[0][4];y1=(int)c[1][4];
     x2=(int)c[0][7];y2=(int)c[1][7];
     line(x1,ymax-y1,x2,ymax-y2);

     setcolor(GREEN);
     for(i=0;i<4;i++)
     {
      x1=(int)c[0][i];y1=(int)c[1][i];
      x2=(int)c[0][i+4];y2=(int)c[1][i+4];
      line(x1,ymax-y1,x2,ymax-y2);
     }

     //
  getch();
} 
