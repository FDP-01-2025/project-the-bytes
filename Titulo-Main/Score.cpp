#include <iostream>
#include <fstream>
using namespace std;

struct Player
{
    char nombre[50]; 
    int partidasGanadas;
};

int main(){
string usuario;
    cout<<"Insert your username: ";
    cin>>usuario;
    
    cout<<"Partidas jugadas: "<<partidas<<endl;
    cout<<"Partidas perdidas: "<<Ganadas<<endl;
    cout<<"Partidas ganadas: "<<perdidas<<endl;

    ofstream archivo("player.txt", ios::app);

    return 0;
}