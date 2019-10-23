#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

















/*
//OBLIQUE
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
*/


/*
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
//     cout<<"\nymax-->"<<ymax<<endl;
//     cout<<"\nxmax-->"<<getmaxx()<<endl;
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
 //      cout<<"\nLOOP RAN-->"<<i<<endl;
       x1=(int)c[0][i];y1=(int)c[1][i];
       x2=(int)c[0][i+1];y2=(int)c[1][i+1];
      line(x1,ymax-y1,x2,ymax-y2);
//       setcolor(i);
    //   delay(500);
     //  line(123,359,
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
} */

/*FUNCTIONS PRACTICE
void main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  setlinestyle(3,0,1);
  line(10,10,40,40);
  arc(100,100,45,240,50);
  circle(100,100,150);
  ellipse(100,100,30,120,20,60); //x,y,start_angle,end_angle,x_radius,y_radius
  pieslice(100,200,50,130,120);
  fillellipse(100,200,50,50);
  setfillstyle(1,WHITE);
  rectangle(50,50,100,100);
  floodfill(51,51,WHITE);
  getch();
  closegraph();

}
*/


/* LINE CLIPPING ALGORITHM
typedef struct coordinate
{
 int x,y;
 int choice[4];
}PT;

void drawWindow(int coords[2][4])
{
  for(int i=0;i<4;i++)
  {
    line(coords[0][i],coords[1][i],coords[0][(i+1)%4],coords[1][(i+1)%4]);
  }

}
void applyABRL(PT &p)
{
   p.choice[0]=(p.y<100)?1:0; //A
   p.choice[1]=(p.y>350)?1:0; //B
   p.choice[2]=(p.x>450)?1:0; //R
   p.choice[3]=(p.x<150)?1:0; //L

}

int checkcase(PT p1,PT p2)
{
  int flag=0;
  for(int i=0;i<4;i++)
  {
    if(p1.choice[i]==1 || p2.choice[i])
    flag=1;
  }
  if(flag==0)
  return 0;
  for(i=0;i<4;i++)
  {
   if(p1.choice[i]==p2.choice[i] && p1.choice[i]==1)
   return 1;
  }
  return 2;
}
PT newEndPoint(PT p1,PT p2)
{
   int x,y;
   float m,k;
   cout<<"\nORIGINAL VALUES-->"<<p1.x<<","<<p1.y<<endl<<p2.x<<","<<p2.y<<endl;
   cout<<"P1 choices-->"<<p1.choice[0]<<p1.choice[1]<<p1.choice[2]<<p1.choice[3]<<endl;
   x=(p1.choice[3]==1)?150:x;
   x=(p1.choice[2]==1)?450:x;
   cout<<"\nVALUE OF X-->"<<x<<endl;
   if(p1.choice[3] || p1.choice[2])
   {
     m=(float)(p2.y-p1.y)/(p2.x-p1.x);
     k=(float)p1.y+(float)(m*(x-p1.x));
     p1.x=x;
     p1.y=k;
     cout<<"\nValue of y-->"<<k<<endl;
     if(p1.y<=350 && p1.y>=100)
     return p1;

   }

   y=(p1.choice[0]==1)?100:y;
   y=(p1.choice[1]==1)?350:y;
   cout<<"\nValue of y 2nd -->"<<y<<endl;
   if(p1.choice[0] || p1.choice[1])
   {
     m=(float)(p2.y-p1.y)/(p2.x-p1.x);
     k=(float)p1.x+((float)(y-p1.y)/m);
     p1.x=k;
     p1.y=y;
     cout<<"\nValue of x second-->"<<k<<endl;
     return p1;
   }
  else
  return p1;
}
void main()
{
int coords[2][4]={{150,450,450,150},{100,100,350,350}}; //all x then y
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
drawWindow(coords);
PT p1,p2,p3,p4;
cout<<"\nEnter line coordinates\n";
cin>>p1.x>>p1.y>>p2.x>>p2.y;
line(p1.x,p1.y,p2.x,p2.y);
getch();
cleardevice();
applyABRL(p1);
applyABRL(p2);
int v =checkcase(p1,p2);
cout<<v<<endl;

switch(v)
{
 case 0:
 drawWindow(coords);
 line(p1.x,p1.y,p2.x,p2.y);
 break;

 case 1:
 drawWindow(coords);
 break;

 case 2:
 drawWindow(coords);
 p3=newEndPoint(p1,p2);
 p4=newEndPoint(p2,p1);
 line(p3.x,p3.y,p4.x,p4.y);
 break;
}
getch();

}
*/
/*ROTATION OF A POLYGON
void rotate(int xs[],int ys[],int x,int y,float angle)
{
  float t,v;
  for(int i=0;i<4;i++)
  {
    t=xs[i]-x;
    v=ys[i]-y;
    xs[i]=x+floor(t*cos(angle)-v*sin(angle));
    ys[i]=y+floor(v*cos(angle)+t*sin(angle));
  }
}

void drawFn(int xs[],int ys[])
{
  for(int i=0;i<4;i++)
  {
    line(xs[i],ys[i],xs[(i+1)%4],ys[(i+1)%4]);
  }
}
void main()
{
 int gd,gm;
 int xs[4],ys[4],x,y;
 cout<<"\nEnter x and y\n";
 for(int i=0;i<4;i++)
 {
   cin>>xs[i]>>ys[i];
 }
 cout<<"\nEnter rotation angle\n";
 float angle;
 cin>>angle;
 angle=(float)(3.14f*angle/180);
 cout<<"\nEnter starting coordinate\n";
 cin>>x>>y;
 clrscr();
 gd=DETECT;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 drawFn(xs,ys);
 setcolor(RED);
 rotate(xs,ys,x,y,angle);
 drawFn(xs,ys);
 getch();
}
*/
/* SCALING and TRANSLATING
void translateRectangle(int coord[][2],int T[])
{
   for(int i=0;i<2;i++)
   { coord[i][0]+=T[0];
     coord[i][1]+=T[1];
   }
}
void matrixMultiplication(int coord[][2],int S[][2])
{
  int temp[1][2]={0};
  for(int i=0;i<1;i++)
  for(int j=0;j<2;j++)
  for(int k=0;k<2;k++)
  temp[i][j]+=coord[i][k]*S[k][j];

  coord[0][0]=temp[0][0];
  coord[0][1]=temp[0][1];
}
void scaleRectangle(int Coord[][2],int sx,int sy)
{
  int S[2][2]={sx,0,0,sy};
  int temp[1][2]={0};
  for(int i=0;i<2;i++)
  {
    temp[0][0]=Coord[i][0];
    temp[0][1]=Coord[i][1];
    matrixMultiplication(temp,S);
    Coord[i][0]=temp[0][0];
    Coord[i][1]=temp[0][1];
  }
}
void main()
{
//  int Coord[2][2];
  int left,top,right,bottom;
  int gd,gm;
  cout<<"Enter left,top,right,bottom\n";
  cin>>left>>top>>right>>bottom;
  int Coord[2][2]={left,top,right,bottom};
  int T[2]={-left,-top};

  cout<<"\n1.Translate\n2.Scale\n";
  int choice;
  cin>>choice;
  gd=DETECT;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  setcolor(WHITE);
  rectangle(left,top,right,bottom);
  setcolor(RED);
  switch(choice)
  {
  case 1:
  translateRectangle(Coord,T);
  rectangle(Coord[0][0],Coord[0][1],Coord[1][0],Coord[1][1]);
  break;

  case 2:

  scaleRectangle(Coord,2,2);
  rectangle(Coord[0][0],Coord[0][1],Coord[1][0],Coord[1][1]);
  break;

  }
  getch();


}

 */


/* FLOOD FILL ALGORITHM
void floodFill(int x,int y,int old_color,int new_color)
{
  if(getpixel(x,y)==old_color)
  {
    putpixel(x,y,new_color);
    delay(5);

    floodFill(x+1,y,old_color,new_color);
    floodFill(x-1,y,old_color,new_color);
    floodFill(x,y+1,old_color,new_color);
    floodFill(x,y-1,old_color,new_color);

    floodFill(x-1,y+1,old_color,new_color);
    floodFill(x+1,y+1,old_color,new_color);
    floodFill(x+1,y-1,old_color,new_color);
    floodFill(x-1,y-1,old_color,new_color);
    //		floodFill(x+1,y,old_color,new_color);
  }

}

void main()
{
  int gd,gm;
  gd=DETECT;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  int left,top,right,bottom;
  left=top=50;
  right=bottom=100;
  rectangle(left,top,right,bottom);
  int old_color=0;
  int new_color=RED;
  floodFill(left+1,top+1,old_color,new_color);
  getch();
}
*/



/* BRESENHAM CIRCLE FORMULA
void drawCircle(int X,int Y,int x,int y)
{
  putpixel(X+x,Y-y,RED);
  putpixel(X+x,Y+y,RED);
  putpixel(X-x,Y-y,RED);
  putpixel(X-x,Y+y,RED);
  putpixel(X+y,Y-x,RED);
  putpixel(X+y,Y+x,RED);
  putpixel(X-y,Y-x,RED);
  putpixel(X-y,Y+x,RED);
}
void main()
{
  int X,Y;
  int x,y,r;
  int gd,gm;
  int s;
  clrscr();
  cout<<"\nEnter x and y coordinates\n";
  cin>>X>>Y;
  cout<<"\nEnter radius of circle\n";
  cin>>r;
  x=0;y=r; // initialization
  detectgraph(&gd,&gm);
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  setcolor(RED);
  s=3-2*r;
  drawCircle(X,Y,x,y);
  while(y>=x)
  {
     x++;
     if(s<=0)
     {
       s=s+(4*x)+6;
     }
     else
     {
       y--;
       s=s+4*(x-y)+10;
     }
     drawCircle(X,Y,x,y);
     delay(50);
  }
  getch();
}
*/