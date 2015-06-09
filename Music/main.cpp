#include <iostream>
#include <Windows.h>
#include <MMSystem.h>

using namespace std;

int main()
{
    //PlaySound("chicken6.wav",NULL, SND_LOOP,SND_ASYNC);

    //PlaySound(TEXT("chicken6.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    PlaySound(TEXT("8-bit-music.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    PlaySound(TEXT("frogs.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

   // PlaySound(TEXT("frogs.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

    cout<<endl;
    cout<<" "<<"WELCOME TO OUR GAME"<<" "<<endl;


    system("pause");
    return 0;
}
