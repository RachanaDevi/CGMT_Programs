#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

// LINE CLIPPING ALGORITHM

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
   
   x=(p1.choice[3]==1)?150:x;
   x=(p1.choice[2]==1)?450:x;
   
   if(p1.choice[3] || p1.choice[2])
   {
     m=(float)(p2.y-p1.y)/(p2.x-p1.x);
     k=(float)p1.y+(float)(m*(x-p1.x));
     p1.x=x;
     p1.y=k;
   
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
