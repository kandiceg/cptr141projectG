#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstring>
using namespace std;

void *playbutton, *exitbutton, *background, *playbuttonmask, *exitbuttonmask, *exitbutton2, *exitbuttonmask2, *playbutton2, *playbuttonmask2, *playscreen2;
void *playbutton3, *playbutton3mask, *instructions;
void *frogbmp, *frogmask;
void *bloodsplotbmp, *bloodsplotmask;
void *leftmotorcyclebmp, *leftmotorcyclemask,*rightmotorcyclebmp, *rightmotorcyclemask;
void *lefttankbmp, *lefttankmask, *righttankbmp, *righttankmask;
void *leftcarbmp, *leftcarmask, *rightcarbmp, *rightcarmask;
void *leftbikebmp, *rightbikemask; 
void *roadbmp, *blockbmp, *blockmask;
//Declaring pointers.

int charasize (40);//Character size
//int blocksize (50);
//int LevelsizeX (25), LevelsizeY (16);

void memstore(void*&mem, char filepath[],int xr, int yr){//Stores images
unsigned int size = imagesize(1, 1, xr, yr);
         mem = malloc(size);
         readimagefile(filepath,1,1,xr,yr);
         getimage(1, 1, xr, yr, mem);
};
void maskrender(void *pic, void *mask, int x, int y) {//Puts images on screen
   putimage(x, y, mask, OR_PUT);
   putimage(x, y, pic, AND_PUT);
};
/*struct box{
       int posiX;
       int posiY;
       
       }block={200,200};*/
       
struct cars{//Creates structure for array non-player controlable cars.
       int posiX, posiY;
       int veloX, veloY;
       int accel;
       int sizeX, sizeY;
       }bikeright={-300, 400, 0,0,100,50}, bikeleft={900, 400,0,0,100,50}, motorcycleright={-400,165,0,0,-10,100,50}, motorcycleleft={780,165,0,0,-10,100,50}, tankright={-300,275,0,0,-10,155,132},tankleft={850,275,0,0,-10,155,132}, carright={-10,80,0,0,-10,124,81},carleft={800, 80,0,0,-10,124,81};//Initiates variables in cars.
//box block;
  
   
struct frog{//Creates structre for array for the frog character that the player controls.
       int posiX;
       int posiY;
       int veloX;
       int veloY;
       int accel;
       bool jumping;

            }player1={400,450,0,0,-10,0};//Intiates variable with appropriate data. 
            
  bool checkmouseover(int x, int y, int xr, int yr){//Checks mouse hovers

    if (mousex() != -1 && mousey() != -1)
        if (mousex() > x && mousex() < xr && mousey() > y && mousey() < yr)
            return 1;
    return 0;

    }
    bool checkmouseclick(int x, int y, int xr, int yr) { //Checks mouse clicks
   if (ismouseclick(WM_LBUTTONUP)) // checks for mouse up
      if (mousex() > x && mousex() < xr && mousey() > y && mousey() < yr) {
          clearmouseclick(WM_LBUTTONUP);
          return 1;
      }
      return 0;
}
       
  bool CheckPointCollisions(int a, int b){//Checks to see if a point is within another object
    //cout<<block.posiX<<" "<<a<<" "<<block.posiX+blocksize<< " "<<b<<"  "<<block.posiY<<" "<<block.posiY+blocksize<<endl;//Debug
    if (a>=motorcycleleft.posiX && a<=motorcycleleft.posiX+motorcycleleft.sizeX && b>=motorcycleleft.posiY && b<=motorcycleleft.posiY+motorcycleleft.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
    if (a>=motorcycleright.posiX && a<=motorcycleright.posiX+motorcycleright.sizeX && b>=motorcycleright.posiY && b<=motorcycleright.posiY+motorcycleright.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
    if (a>=tankleft.posiX && a<=tankleft.posiX+tankleft.sizeX && b>=tankleft.posiY && b<=tankleft.posiY+tankleft.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
    if (a>=tankright.posiX && a<=tankright.posiX+tankright.sizeX && b>=tankright.posiY && b<=tankright.posiY+tankright.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
    if (a>=carleft.posiX && a<=carleft.posiX+carleft.sizeX && b>=carleft.posiY && b<=carleft.posiY+carleft.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
     if (a>=carright.posiX && a<=carright.posiX+carright.sizeX && b>=carright.posiY && b<=carright.posiY+carright.sizeY){
       //cout<<"Collision";//Debug
       return true;
       }
     if (a>=bikeleft.posiX && a<=bikeleft.posiX+bikeleft.sizeX && b>=bikeleft.posiY && b<=bikeleft.posiY+carright.sizeY){
       //cout<<"Collision";//Debug
       return true;
       }
     if (a>=bikeright.posiX && a<=bikeright.posiX+bikeright.sizeX && b>=bikeright.posiY && b<=bikeright.posiY+bikeright.sizeY){
       //cout<<"Collision";//Debug
       return true;
            }
    
       };
  void CheckCollisions(){//Checks to see if the character is colliding with a block
    if (CheckPointCollisions(player1.posiX, player1.posiY)|| CheckPointCollisions(player1.posiX, player1.posiY+charasize)
       || CheckPointCollisions(player1.posiX+charasize, player1.posiY)||CheckPointCollisions(player1.posiX+charasize, player1.posiY+charasize)){
          if (player1.posiY+charasize>motorcycleleft.posiY&&player1.posiY<motorcycleleft.posiY+motorcycleleft.sizeY&&motorcycleleft.posiX<player1.posiX+charasize&&motorcycleleft.posiX+motorcycleleft.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450; 
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);//All bloddsplots failed to remain static      
             }
          else if (player1.posiY+charasize>motorcycleright.posiY&&player1.posiY<motorcycleright.posiY+motorcycleright.sizeY&&motorcycleright.posiX<player1.posiX+charasize&&motorcycleright.posiX+motorcycleright.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);       
             }
          else if (player1.posiY+charasize>tankleft.posiY&&player1.posiY<tankleft.posiY+tankleft.sizeY&&tankleft.posiX<player1.posiX+charasize&&tankleft.posiX+tankleft.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);       
             }
          else if (player1.posiY+charasize>tankright.posiY&&player1.posiY<tankright.posiY+tankright.sizeY&&tankright.posiX<player1.posiX+charasize&&tankright.posiX+tankright.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;  
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);     
             }
          else if (player1.posiY+charasize>carleft.posiY&&player1.posiY<carleft.posiY+carleft.sizeY&&carleft.posiX<player1.posiX+charasize&&carleft.posiX+carleft.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450; 
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);      
             }
          else if (player1.posiY+charasize>carright.posiY&&player1.posiY<carright.posiY+carright.sizeY&&carright.posiX<player1.posiX+charasize&&carright.posiX+carright.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;  
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);     
             }
          else if (player1.posiY+charasize>bikeleft.posiY&&player1.posiY<bikeleft.posiY+bikeleft.sizeY&&bikeleft.posiX<player1.posiX+charasize&&bikeleft.posiX+bikeleft.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);       
             }
          else if (player1.posiY+charasize>bikeright.posiY&&player1.posiY<bikeright.posiY+bikeright.sizeY&&bikeright.posiX<player1.posiX+charasize&&bikeright.posiX+bikeright.sizeX>player1.posiX){
              player1.posiX=400;
              player1.posiY=450;
              //maskrender(bloodsplotbmp, bloodsplotmask, player1.posiX, player1.posiY);       
             }
              }
          };



    

int animation(){
     /* mario player1;
      //box block;
      player1.posiX = 0;//Sets positons, velocities, and accelerations
      player1.posiY= 425;
      player1.veloX=0;
      player1.veloY=0;
      player1.accel=-10;*/

      
    while (true){//Game loop
          Sleep(10);//Delay
    putimage(0,0, roadbmp, 0);//Outputs background for game
    //cout<<block.posiX<<" "<<block.posiY<<endl;
    maskrender(frogbmp, frogmask, player1.posiX, player1.posiY);//Uploads character on screen
    //maskrender(blockbmp, blockmask, block.posiX, block.posiY);
    CheckCollisions();//Calls collision checking function to check for collisions.
    
    /*if ((GetAsyncKeyState(VK_UP)||GetAsyncKeyState(87)<10)&&(GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(68)<10)){//Gets the key combination 'W,D' and 'UP,RIGHT'
               for(int i; i <10; i++){//Side jumping
                   player1.veloY = -20;
                   player1.veloX = 20;
                   player1.jumping = true;
                   if (player1.jumping ==true){
                      if (player1.veloY<20){
                      player1.veloY = -player1.veloY+player1.accel;
                      player1.veloX = player1.veloX+player1.accel;
                      player1.posiY = player1.posiY-player1.veloY;
                      player1.posiX = player1.posiX-player1.veloX;
                      }
                      }
               }
               }
    if (GetAsyncKeyState(VK_UP)||GetAsyncKeyState(87)&& GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(65)){//Gets the key combination 'W,A' and 'UP, LEFT'
        for(int i; i <20; i++){//Side jumping
                player1.veloY = -30;
                player1.veloX = 30;
                player1.jumping = true;
                   if (player1.jumping ==true){
                      if (player1.veloY<30){
                      player1.veloY = -player1.veloY+player1.accel;
                      player1.veloX = player1.veloX+player1.accel;
                      player1.posiY = player1.posiY-player1.veloY;
                      player1.posiX = player1.posiX-player1.veloX;
                      }
                      }
               }
       }*/
    if (GetAsyncKeyState(VK_UP)||GetAsyncKeyState(87)){//Gets key combination 'W' or 'UP'
           player1.posiY-=3;
           /*player1.veloY = -15;//Setting up the Jumpkey
           player1.jumping = true;*/
          }
    /*if (player1.jumping == true){         
       if (player1.veloY < 15){
           player1.veloY = -player1.veloY + player1.accel;
           player1.posiY = player1.posiY - player1.veloY;
           }
           }
    if (player1.posiY>=425){
           player1.veloY = 0;
           player1.jumping = false;
           }*/
    if (GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState(83)){//Downwards movement
          player1.posiY+=3;
          }
    if (GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(65)){//Left movement
          player1.posiX-=3;
          }
    if (GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(68)){//Right movement
          player1.posiX+=3;
          }  
     maskrender(rightmotorcyclebmp, rightmotorcyclemask, motorcycleright.posiX,motorcycleright.posiY);//Puts motorcycle going right on screen.
     motorcycleright.posiX+=5; //Moves motorcycle to the right.
    if (motorcycleright.posiX > 1000){//Outputs left-facing motorcycle after right-facing motorcycle has gone off screen.
        maskrender(leftmotorcyclebmp, leftmotorcyclemask, motorcycleleft.posiX,motorcycleleft.posiY);//Puts Left-facing motorcycle on screen.
        motorcycleleft.posiX-=5;//Moves motorcycle to the left.
    if (motorcycleleft.posiX < -400){//Outputs right-facing motorcycle after left-facing motorcycle has gone off screen.
        motorcycleright.posiX=-400;//Re-outputs right-facing motorcycle on screen.
        motorcycleright.posiX+=5;
              //cout<<"HELP!"<<endl;
        }
        } 
    maskrender(righttankbmp, righttankmask, tankright.posiX,tankright.posiY);//Right-facing tank on screen.
    tankright.posiX+=2;//Moves tank to the right.     
    if (tankright.posiX > 1000){//Outputs left-facing tank after right-facing tank has gone off screen.
        maskrender(lefttankbmp, lefttankmask, tankleft.posiX,tankleft.posiY);//Puts left-facing tank on the screen.
        tankleft.posiX-=2;//Moves tank to the left.
    if (tankleft.posiX < -300){//Outputs right-facing tank after left-facing tank has gone off screen.
        tankright.posiX=-300;//Re-Outputs right-facing tank.
        tankright.posiX+=2;
        }
        }
    maskrender(rightcarbmp, rightcarmask, carright.posiX,carright.posiY);//Puts right-facing car on screen.
    carright.posiX+=7;//Moves car the the right. 
    if (carright.posiX > 1000){//Outputs left-facing car after right-facing car has gone off screen.
        maskrender(leftcarbmp, leftcarmask, carleft.posiX,carleft.posiY);//Puts left-facing car on screen.
        carleft.posiX-=7;//Moves car to the left/
    if (carleft.posiX < -200){//Outputs right-facing car after left-facing car has gone off screen.
        carright.posiX = -200;//Re-outputs right-facing car.
        carright.posiX+=7;
        }  
        }
    maskrender(rightmotorcyclebmp, rightmotorcyclemask, bikeright.posiX,bikeright.posiY);//Puts right-facing motorcycle on screen.
    bikeright.posiX+=6;//Moves motorcycle to the right. 
    if (bikeright.posiX > 1000){//Outputs left-facing motorcycle after right-facing motorcycle has gone off screen.
        maskrender(leftmotorcyclebmp, leftmotorcyclemask, bikeleft.posiX,bikeleft.posiY);//Puts left-facing motorcycle on screen.
        bikeleft.posiX-=6;//Moves motorcycle to the left.
    if (bikeleft.posiX < -400){//Outputs right-facing motorcycle left-facing motorcycle has gone off screen.
        bikeright.posiX = -400;//Re-outputs right-facing motorcycle on screen.
        bikeright.posiX+=6;
        }
        }

           
                     if (player1.posiX<0){//Collisions with sides of the screen
                     player1.posiX = 0;
                     };
                     if (player1.posiX>740){
                     player1.posiX=740;
                     };
                     if (player1.posiY<0){
                     player1.posiY = 0;
                     };
                     if (player1.posiY>450){
                     player1.posiY=450;
                     };
                      swapbuffers(); //Double buffering 
                  };
                  
                  
                  }

void exitbuttonscreen(){
    if(checkmouseover(400, 350, 600, 450) == 1)//Checks to see if mouse if hovering over exit button
       {
        maskrender(exitbutton2, exitbuttonmask2, 400, 300);//Replaces exit button with another exit button if the player hovers over it.
        }
        else{
          maskrender(exitbutton, exitbuttonmask, 400, 300);
        } 
if (checkmouseclick(400, 350, 600, 450)==1){//Checks mouse click and exits program
       exit(1);
      }
      }


int playscreen(){//Play screen
    while (true){
    putimage(0,0,playscreen2,0);//Uploads playscreen on screen
    if (checkmouseclick(150, 350, 300, 450)==1){//Checks mouse click and calls animation
       animation();
      }
      if(checkmouseover(150, 350, 300, 450) == 1)//Checks to see if mouse is hovering over the play button
      {
        maskrender(playbutton2,playbuttonmask2, 150,300);//Replaces play button with another play button with different colors if the player hovers over the play button.
        }
        else{
          maskrender(playbutton, playbuttonmask, 150, 300);
        } 
        exitbuttonscreen();  
        
      swapbuffers();
      };
      }




int main()
{   
    initwindow (800,500,"Hop to It");//Starts Window
     int oldvisual = getvisualpage();//Double buffering part 2
     int oldactive = getactivepage();
     

    system("color 5B");
    
    memstore(frogmask,"Images/frogmask.bmp",charasize,charasize );//Stores images
    memstore(frogbmp,"Images/frog.bmp",charasize,charasize);
    memstore(roadbmp, "Images/road.bmp",800,500);
    memstore(leftmotorcyclemask, "Images/leftmotorcyclemask.bmp",motorcycleleft.sizeX, motorcycleleft.sizeY);
    memstore(leftmotorcyclebmp, "Images/leftmotorcycle.bmp",motorcycleleft.sizeX, motorcycleleft.sizeY);
    memstore(rightmotorcyclebmp, "Images/rightmotorcycle.bmp",motorcycleright.sizeX, motorcycleright.sizeY);
    memstore(rightmotorcyclemask, "Images/rightmotorcyclemask.bmp",motorcycleright.sizeX, motorcycleright.sizeY);
    memstore(lefttankbmp, "Images/lefttank.bmp",tankleft.sizeX,tankleft.sizeY);
    memstore(lefttankmask, "Images/lefttankmask.bmp",tankleft.sizeX,tankleft.sizeY);
    memstore(righttankbmp, "Images/righttank.bmp",tankright.sizeX,tankright.sizeY);
    memstore(righttankmask, "Images/righttankmask.bmp",tankright.sizeX,tankright.sizeY);
    memstore(leftcarbmp, "Images/leftcar.bmp",carleft.sizeX,carleft.sizeY);
    memstore(leftcarmask, "Images/leftcarmask.bmp",carleft.sizeX,carleft.sizeY);
    memstore(rightcarbmp, "Images/rightcar.bmp",carright.sizeX,carright.sizeY);
    memstore(rightcarmask, "Images/rightcarmask.bmp",carright.sizeX,carright.sizeY);
    memstore(playscreen2, "Images/PlayScreenBackground2.bmp", 800, 500);
    memstore(playbutton, "Images/PlayButton3.bmp", 500,300);
    memstore(playbuttonmask, "Images/PlayButton4.bmp", 500,300);
    memstore(exitbutton, "Images/ExitButton3.bmp", 500, 300);
    memstore(exitbuttonmask, "Images/PlayButton4.bmp", 500, 300);
    memstore(exitbutton2, "Images/ExitButton5.bmp", 500, 300);
    memstore(exitbuttonmask2, "Images/PlayButton4.bmp", 500, 300);
    memstore(playbutton2, "Images/PlayButton5.bmp", 500,300);
    memstore(playbuttonmask2, "Images/PlayButton4.bmp", 500,300);
    memstore(instructions, "Images/Instructions.bmp", 800, 500);
    memstore(playbutton3, "Images/ContinueButton.bmp", 500,300);
    memstore(playbutton3mask, "Images/ContinueButtonMask.bmp", 500,300);
    memstore(bloodsplotbmp, "Images/bloodsplot.bmp", charasize, charasize);
    memstore(bloodsplotmask, "Images/bloodsplotmask.bmp", charasize, charasize);
    
    //memstore(blockbmp, "Images/Block.bmp", blocksize, blocksize);
    //memstore(blockmask,"Images/Blockmask.bmp", blocksize , blocksize);
    //animation(); 
    playscreen();
    
    setactivepage(oldvisual);//Double buffering part 3
    setvisualpage(oldactive);
        

    
    system("PAUSE");
    return EXIT_SUCCESS;

    
}

