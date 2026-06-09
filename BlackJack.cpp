#include<iostream>
#include<array>
#include<string>
#include<vector>
#include<numeric>   
#include<random>
#include<algorithm>
#include<conio.h>
#include <stdexcept>

using namespace std;

int apuestaEfectiva(int apuesta){
    return 0;
}

vector<string> aces(vector<string>& arr){
    vector<string> arr2,arr3;
    for(int i=0;i<arr.size();i++){
        string s=arr[i];
        if(s[1]=='Z'){
            arr3.push_back(s);
        }else{
            arr2.push_back(s);
        }
    }
    for(string s:arr3){
        arr2.push_back(s);
    }
    return arr2;
}

int evaluar(vector<string> arr){
    aces(arr);
    vector<string> punt_p;
    for(string s:arr){
        punt_p.push_back(s.substr(1));
    }
    int val_p=0;
    for(string s: punt_p){
        try{
            switch (stoi(s))
            {
            case 1:
                val_p+=stoi(s);
                break;
            case 2:
                val_p+=stoi(s);
                break;
            case 3:
                val_p+=stoi(s);
                break;
            case 4:
                val_p+=stoi(s);
                break;
            case 5:
                val_p+=stoi(s);
                break;
            case 6:
                val_p+=stoi(s);
                break;
            case 7:
                val_p+=stoi(s);
                break;
            case 8:
                val_p+=stoi(s);
                break;
            case 9:
                val_p+=stoi(s);
                break;
            case 10:
                val_p+=stoi(s);
                break;
            default:
                break;
            }
        }
        catch (const invalid_argument& e){
            switch (s[0])
            {
            case 'J':
                val_p+=10;
                break;
            case 'Q':
                val_p+=10;
                break;
            case 'K':
                val_p+=10;
                break;
            case 'Z':
                if(21-val_p<=11){
                    val_p+=1;
                }
                else{
                    val_p+=11;
                }
                break;
            default:
                break;
            }
        }
    }
    return val_p;
}

vector<string> tomarCartas(vector<string>& arr, char conf, vector<string>& arr2) {
    char comp;

    while (true) {
        cout <<endl<<"Desea tomar otra carta? 'y': ";
        cin>>comp;

        if (comp == conf) {

            if (arr.empty()) {
                cout << "No quedan cartas.\n";
                break;
            }

            arr2.push_back(arr.front()); // primera carta
            arr.erase(arr.begin());      // eliminarla del mazo
        }
        else {
            break;
        }
        cout<<"tu mano es: ";
        for(string s:arr2){
        cout<<s<<" ";
        }
        cout<<" y tu puntaje: "<<evaluar(arr2)<<endl;
        
    }

    return arr2;
}

vector<string> pasarMano(vector<string>& arr){
    vector<string> arr2;
    for(int i=0;i<2;i++){
        arr2.push_back(arr[i]);
        
    }
    arr.erase(arr.begin());
    arr.erase(arr.begin());
    return arr2;
}

array<array<string,14>,4> constructor(vector<string> base){
    array<array<string,14>,4> valor_c;
    int indice = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 14; j++) {
            valor_c[i][j] = base[indice];
            indice++;
            
        }
    }
    return valor_c;
}

vector<string> mezclador(vector<string> plano){
    random_device rd;
    mt19937 g(rd());
    shuffle(plano.begin(), plano.end(), g);
    return plano;
} 

vector<string> aplanador(array<array<string,14>,4> cartas) {
    vector<string> cartas_lineal;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 14; j++) {
            cartas_lineal.push_back(cartas[i][j]); 
        }
    }
    return cartas_lineal;

}

array<array<string,14>,4> aleatorizador(array<array<string,14>,4> orden){
    vector<string> plano;
    plano = aplanador(orden);
    plano = mezclador(plano);
    orden = constructor(plano);
    return orden;
}

int main(){
    vector<string> barajaPlana;
    vector<string> mano;
    vector<string> mano_dealer;

    //Ajustar monto inicial
    invalidModeInput:
    int presupuesto;
    cout<<"decide el modo de juego: \n"<<"1.Corto ($100) 2.largo ($300) 3.Muy largo($1000)\n";cin>>presupuesto;   
    
    switch (presupuesto)
    {
    case 1:
        presupuesto=100;
        break;
    case 2:
        presupuesto=300;
        break;
    case 3:
        presupuesto=1000;
        break;
    default:
        cout<<"modo invalido, porfavor elegir un numero entre 1, 2 y 3\n";
        goto invalidModeInput;
        break;
    }

    cout<<"La apuesta minima es el 5%"<<" de tu bankroll\n\n"<<"---> $"<<presupuesto*0.05<<"\n";
    int apuesta=presupuesto*0.05;

    remezcleo:
    array<array<string,14>,4> cartas_val={{
        {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","AJ","AQ","AK","AZ"},
        {"B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","BJ","BQ","BK","BZ"},
        {"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","CZ"},
        {"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","DZ"}
    }};
// aleatorizar mazo
    /*for(int i=0;i<4;i++){
        for(int j=0;j<14;j++){
            cout<<cartas_val[i][j]<<',';
        }
        cout<<endl;
    }
    cout<<"\n"<<"\n"<<"\n";*/
    cartas_val = aleatorizador(cartas_val);

    /*for(int i=0;i<4;i++){
        for(int j=0;j<14;j++){
            cout<<cartas_val[i][j]<<',';
        }
        cout<<endl;
    }
    cout<<"\n"<<"\n"<<"\n";*/
    //getch();
    barajaPlana=aplanador(cartas_val);
    

    while(barajaPlana.size()>=4){
        

        /*for(int i=0;i<barajaPlana.size();i++){
            cout<<barajaPlana[i]<<" ";
        }
        cout<<endl;*/

    
        mano=pasarMano(barajaPlana);
        mano_dealer=pasarMano(barajaPlana);

        cout<<"tu mano: ";
        for(int i=0;i<mano.size();i++){
            cout<<mano[i]<<" ";
        
        }
        cout<<endl;
        /*cout<<"mano del crupier: ";
        for(int i=0;i<mano_dealer.size();i++){
            cout<<mano_dealer[i]<<" ";
        
        }*/
    
        // tomar mas cartas
        int puntaje_p=evaluar(mano);
        cout<<"tu puntaje: "<<puntaje_p<<endl;

        mano=tomarCartas(barajaPlana,'y',mano);
        
        //evaluar puntajes

        puntaje_p=evaluar(mano);
        

        int puntaje_c=evaluar(mano_dealer);
        while(puntaje_c<17){
            if(barajaPlana.empty()){
                break;
            }
            mano_dealer.push_back(*barajaPlana.begin());
            barajaPlana.erase(barajaPlana.begin());
            puntaje_c=evaluar(mano_dealer);
        }
        /*for(string s:mano_dealer){
            cout<<s<<" ";
        }*/
        cout<<endl<<"crupier puntaje: "<<puntaje_c<<endl;
        if(21-puntaje_p<0 && 21-puntaje_c<0){
            cout<<"empate, no cambia tu balance."<<endl;
            cout<<"balance: "<<presupuesto<<endl;    
        }else if(puntaje_c==puntaje_p){
            cout<<"empate, no cambia tu balance."<<endl;
            cout<<"balance: "<<presupuesto<<endl;
        }else if(21-puntaje_p<0){
            cout<<"la casa gana, pierdes tu apuesta"<<endl;
            cout<<"balance: "<<presupuesto-apuesta<<endl;
        }else if(21-puntaje_c<0){
            cout<<"tu ganas, te llevas la apuesta de la casa!!"<<endl;
            cout<<"balance: "<<presupuesto+apuesta<<endl;
        }else if(21-puntaje_c<21-puntaje_p){
            cout<<"la casa gana, pierdes tu apuesta"<<endl;
            cout<<"balance: "<<presupuesto-apuesta<<endl;
        }else{
            cout<<"tu ganas, te llevas la apuesta de la casa!!"<<endl;
            cout<<"balance: "<<presupuesto+apuesta<<endl;
        }

        getch();
        mano.clear();
        mano_dealer.clear();
        
    }
    if(barajaPlana.size()<4){
        cout<<"\nno quedan sufucientes cartas.\n";
        goto remezcleo;
    }
    getch();
    return 0;
}
