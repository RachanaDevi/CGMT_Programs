#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>

//FLOOD FILL ALGORITHM

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