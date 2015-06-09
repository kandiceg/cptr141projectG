#include <iostream>
#include <Windows.h>
#include <MMSystem.h>//This is the library which allows the wav audio file to play.

using namespace std;

int main()
{

   // PlaySound(TEXT("chicken6.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    PlaySound(TEXT("8-bit-music.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);  //Here I am calling a function that will allow me to play ".wav" audio files from a set library.

   // PlaySound(TEXT("frogs.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);



    cout<<endl;
    cout<<" "<<"WELCOME TO OUR GAME"<<" "<<endl;

    int count = 1;

    system("pause");
    return 0;
}
