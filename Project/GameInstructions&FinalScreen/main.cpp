#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;

void *playbutton2, *playbutton2mask, *instructions;

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
int main()
{

    initwindow(800,500,"Play Screen");
    memstore(instructions, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\GameInstructions\\Instructions.bmp", 800, 500);
    memstore(playbutton2, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\ContinueButton.bmp", 500,300);
    memstore(playbutton2mask, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\ContinueButtonMask.bmp", 500,300);
    putimage(0,0,instructions,0);
    maskrender(playbutton2, playbutton2mask, 575, 350);


    system("PAUSE");
    return EXIT_SUCCESS;

}




