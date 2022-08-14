#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

bool Repetido(int num, int i);// Prototype
int Ramdon[4];

int main(){
    srand(time(NULL));
    int num = rand(), i;
    int iteration = 6;
    int attempt [10][4];
    int x;
    int y;
    char Pistas[10][4];


    
    
    for(int i = 0; i < 4; i++){ //llenar arreglo con numeros aleatorios
    
        num = 1 + rand()%(iteration);

        while(Repetido(num,i)){
        
            
            num = 1 + rand()%(iteration);   
        }
        Ramdon[i] = num;
    }

    cout << " *MASTER MIND*" <<endl; //Titulo del juego.

    cout << "   A   B   C   D\n   ";

    for(i = 0; i < 4; i++){ 
        cout << Ramdon[i] << "   ";
    }
    cout << endl;
    
    
    for(x = 0; x < 10; x++){ //Intentos del jugador.
        for(y = 0; y < 4; y++){
            cin >> attempt[x][y];  
        }
        cout << Pistas[x][y] << "   ";
        for(i = 0; i < 4; i++){
            if(attempt[x][i] == Ramdon[i]){
                Pistas[x][i] = 'C';
            }
            else if(attempt[x][i] != Ramdon[0] && attempt[x][i] != Ramdon[1] && attempt[x][i] != Ramdon[2] && attempt[x][i] != Ramdon[3]){
                Pistas[x][i] = 'X';
            }
            else{
                Pistas[x][i] = 'F';
            }
            cout << Pistas[x][i] << "   ";
        }


        /*cout << x + 1 << ". ";
        for(i = 0; i < 4; i++){
                cout << Pistas[x][i] << "   ";
            }
        cout << endl;
        
        system("cls");
        cout << " *MASTER MIND*" <<endl; //Repetir pantalla.
        cout << "   A   B   C   D\n   -------------\n";
        cout << x + 1 << ". ";
        for(i = 0; i < x + 1; i++){
            cout << Pistas[x][y] << "   ";
            for(y = 0; y < 4; y++){
                
            }
            
        }*/

        if(Pistas[x][0] == 'C' && Pistas[x][1] == 'C' && Pistas[x][2] == 'C' && Pistas[x][3] == 'C'){
            cout << "ganaste";
            break;
        }

    }
    
    if(x = 10){
        cout << "Perdiste";
    }
    
    return 0;
}


bool Repetido(int num, int i){ //funcion para no repetir numeros
        
    for(int x = 0; x < i; x++){
        if(num == Ramdon[x]){
            return true;
        }
    
    }
    return false;
}