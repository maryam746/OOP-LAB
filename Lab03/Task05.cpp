#include<iostream>
using namespace std;

class MusicPlayer{

string playlist[50];
string currentsong;
int count;

public:

MusicPlayer(){
    count = 0;
    currentsong = "";
    for(int i=0; i<50; i++){
        playlist[i]="";
    }
}

void addsong(string song){
    if(count >= 50){
        cout << "Playlist is full" << endl;
        return;
    }
    playlist[count] = song;
    count++;
    cout << "Added: " << song << " to the playlist." << endl;
}

void removesong(string song){
    for(int i=0; i<count; i++){
        if(playlist[i] == song){
            cout << "Removed: " << song << " from the playlist." << endl;
            for(int j=i; j<count-1; j++){
                playlist[j] = playlist[j+1];
            }
            count--;
            return;
        }
    }
    cout << "Song not found in the playlist" << endl;
}

void playsong(string song){
    for(int i=0; i<count; i++){
        if(playlist[i] == song){
            currentsong = song;
            cout << "Playing: " << currentsong << endl;
            return;
        }
    }
    cout << "Song not found in the playlist" << endl;
}

void displayplaylist(){
    if(count == 0){
        cout << "Playlist is empty" << endl;
        return;
    }
    cout << "Playlist:" << endl;
    for(int i=0; i<count; i++){
        cout << i+1 << ") " << playlist[i] << endl;
    }
}  
};

int main(){
    MusicPlayer music;
    music.addsong("Bleachers");
    music.addsong("Sea shanty");
    music.displayplaylist();
    music.removesong("Bleachers");
    music.displayplaylist();
    return 0;
}

