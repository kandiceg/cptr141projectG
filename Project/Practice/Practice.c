#include <cstdlib>
#include <iostream>
#include <graphics.h>   //remember to include the graphics library

using namespace std;

int main(int argc, char *argv[])
{
   initwindow(400,300); //open a 400x300 graphics window
   setcolor(RED);       //choose the red color
   moveto(0,0);         //set the beginning point to (0,0)
   lineto(50,50);       //draw a red line to (50,50)
   while(!kbhit());     //wait for user to press a key
   closegraph();        //close graphics window
   return 0;
}

