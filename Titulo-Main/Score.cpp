#include <iostream>
#include <fstream>
using namespace std;

struct Player
{
    // The following variables will be changed in the future to call them in another file
    char name[50]; 
    int victories;
    int loses;
    int gamesPlayed;
};

int main(){
string username;
    cout<<"Insert your username: ";
    cin>>username;
    
    cout<<"Games played: "<<gamesPlayed<<endl;
    cout<<"Games lost: "<<victories<<endl;
    cout<<"Games victories: "<<loses<<endl;

    ofstream file("player.txt", ios::app);

    // Hola
    if (file.is_open()) {
        file << username <<endl;
        file << "Wins: "<<victories<<endl;
        file << "Loses: "<<loses<<endl;

    }

    return 0;
}