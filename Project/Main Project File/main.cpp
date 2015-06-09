#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <graphics.h>   //remember to include the graphics library

using namespace std;

void *playbutton, *exitbutton, *background, *playbuttonmask, *exitbuttonmask, *playbutton2, *playbuttonmask2;

void memstore(void*&mem, char filepath[], int xr, int yr){
unsigned int size = imagesize(1, 1, xr, yr);
        mem = malloc(size);
        readimagefile(filepath, 1, 1, xr, yr);
        getimage(1, 1, xr, yr, mem);
}

void maskrender(void *pic, void *mask, int x, int y){
    putimage(x, y, mask, OR_PUT);
    putimage(x, y, pic, AND_PUT);
}

bool checkmouseover(int x, int y, int xr, int yr){

    if (mousex() != -1 && mousey() != -1)
        if (mousex() > x && mousex() < xr && mousey() > y && mousey() < yr)
            return 1;
    return 0;

}

bool checkmouseclick(int x, int y, int xr, int yr){

    if (ismouseclick(WM_LBUTTONUP))
        if (mousex() > x && mousex() < xr && mousey() > y && mousey() < yr){
            clearmouseclick(WM_LBUTTONUP);
            return 1;
    }
    return 0;

}

/*void animation(){
    while(true){
    if(checkmouseover(150, 400, 300, 500) == 1)
    {
        maskrender(playbutton2,NULL, 150,300);
    }
        else{
          maskrender(playbutton, NULL, 150, 300);
        }
    swapbuffers();
    };


}*/

/*void mousefunction(){
    int x, y;
    getmouseclick(WM_LBUTTONUP, x, y);
    if(x > 150 && x < 300 && y > 300 && y < 400)
    {
        memstore(playbutton, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_gageka\\Project\\practice2\\images\\PlayButton3.bmp", 500,300);
        memstore(playbuttonmask, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_gageka\\Project\\practice2\\images\\PlayButton4.bmp", 500,300);
        maskrender(playbutton, playbuttonmask, 150, 200);
    }
}*/

int main()
{
    //int oldvisual =getvisualpage();
    //int oldactive = getactivepage();
    initwindow(800,500,"Play Screen");
    memstore(background, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayScreenBackground2.bmp", 800, 500);
    memstore(playbutton, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayButton3.bmp", 500,300);
    memstore(playbuttonmask, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayButton4.bmp", 500,300);
    memstore(exitbutton, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\ExitButton3.bmp", 500, 300);
    memstore(exitbuttonmask, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayButton4.bmp", 500, 300);
    memstore(playbutton2, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayButton5.bmp", 500,300);
    memstore(playbuttonmask2, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\PlayButton4.bmp", 500,300);

    putimage(0,0,background,0);
    maskrender(playbutton, playbuttonmask, 150, 300);
    maskrender(exitbutton, exitbuttonmask, 400, 300);
    int x,y;
    if(true){
    getmouseclick( WM_LBUTTONDOWN,x, y);
    cout << "The mouse was clicked at: ";
    cout << "x= " << x;
    cout << "y= " << y;
    }
    /*if(checkmouseclick(150,300,300,400)){
        cout << "IT WORKS" << endl;
    }*/

    /*checkmouseover()
    animation();
    setactivepage(oldvisual);
    setvisualpage(oldactive);*/
    system("PAUSE");
    return EXIT_SUCCESS;

}

