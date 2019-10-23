#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>


//ROTATION OF A POLYGON
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
