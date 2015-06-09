#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;

void *endscreen;

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
    memstore(endscreen, "C:\\Users\\Kandi Gage\\Desktop\\CPTR141_backup\\Project\\practice2\\images\\EndScreen.bmp", 800, 500);




    system("PAUSE");
    return EXIT_SUCCESS;

}
