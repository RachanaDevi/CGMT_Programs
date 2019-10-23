#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>


// BRESENHAM CIRCLE FORMULA

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
