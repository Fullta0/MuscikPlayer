#include <QCoreApplication>
#include "musicplayer.h"
#include <iostream>
#include <conio.h>

int choisee(int shoise){
    MusicPlayer player;
    switch (shoise) {
    case 0:
         player.Play();
        break;
    case 1:
        player.Selecting();
        break;
    case 2:
        player.Pause();
        break;
    case 3:
        player.Stop();
        break;
    case 4:
        cout<<"0. Play track."<<endl;
        cout<<"1. Select track."<<endl;
        cout<<"2. Pause track."<<endl;
        cout<<"3. Stop player."<<endl;
        cout<<"4. Help."<<endl;
    default:
        break;
    }
    return 0;
}
int main(){
    cout<<"Welcome!!!"<<endl;
    int shoise = 0;
    choisee(4);
    while(1){
        cin >> shoise;
        choisee(shoise);
    }

    return 0;
}
