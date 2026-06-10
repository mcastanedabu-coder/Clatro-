#include<iostream>
#include<array>
#include<string>
#include<vector>
#include<numeric>   
#include<random>
#include<algorithm>
#include<conio.h>
#include <stdexcept>
#include <chrono>

using namespace std;

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
    arr=aces(arr);
    vector<string> punt_p;
    for(string s:arr){
        punt_p.push_back(s.substr(1));
    }
    int val_p=0;
    for(string s: punt_p){
        try{
            val_p+=stoi(s);
            }
        catch (const invalid_argument& e){
            switch (s[0])
            {
            case 'Z':
                if(21-val_p<=11){
                    val_p+=1;
                }
                else{
                    val_p+=11;
                }
                break;
            default:
                val_p+=10;
                break;
            }
        }
    }
    return val_p;
}

vector<string> tomarCartas(vector<string>& arr, char conf, vector<string>& arr2,double& apuesta,double pres) {
    char comp;
    cout <<endl<<"Desea tomar otra carta? 'y' o desea doblar? 'd' ";
    bool x=false;
    while (true) {
        if(x){
            cout <<endl<<"Desea tomar otra carta? 'y' ";
        }
        
        
        if(!(cin>>comp)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"entrada invalida.\n";
            continue;
        }
        if(comp=='d' && x){
            cout<<"\n no puedes doblar!";
            continue;
        }
        x=true;

        if (comp == conf) {

            if (arr.empty()) {
                cout << "No quedan cartas.\n";
                break;
            }

            arr2.push_back(arr.front()); // primera carta
            arr.erase(arr.begin());      // eliminarla del mazo
        }
        else if(comp == 'd'){
            if(arr.empty()){
                cout << "No quedan cartas.\n";
                break;
            }
            if(pres<apuesta*2){
                cout<<"\nno tienes suficiente dinero para doblar";
                continue;
            }
            arr2.push_back(arr.front()); 
            arr.erase(arr.begin());
            apuesta*=2;
            
        }
        else {
            break;
        }
        cout<<"tu mano es: ";
        for(string s:arr2){
            switch (s[0])
            {
            case 'A':
                if(s[1]=='Z'){
                    cout<<"A"<<" de corazones ";
                }else{
                    cout<<s.substr(1)<<" de corazones ";
                }
                break;
            case 'B':
                if(s[1]=='Z'){
                    cout<<"A"<<" de diamantes ";
                }else{
                    cout<<s.substr(1)<<" de diamantes ";
                }
                break;
            case 'C':
                if(s[1]=='Z'){
                    cout<<"A"<<" de picas ";
                }else{
                    cout<<s.substr(1)<<" de picas ";
                }
                break;
            case 'D':
                if(s[1]=='Z'){
                    cout<<"A"<<" de treboles ";
                }else{
                    cout<<s.substr(1)<<" de treboles ";
                }
                break;
            default:
                break;
            }
        //cout<<s<<" ";
        }
        cout<<" y tu puntaje: "<<evaluar(arr2)<<endl;
        if(evaluar(arr2)>21){
            break;
        }
        if(comp=='d'){
            break;
        }
        
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

array<array<string,13>,4> constructor(vector<string> base){
    array<array<string,13>,4> valor_c;
    int indice = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            valor_c[i][j] = base[indice];
            indice++;
            
        }
    }
    return valor_c;
}

vector<string> mezclador(vector<string> plano){
    random_device rd;

    auto t = chrono::high_resolution_clock::now()
                 .time_since_epoch()
                 .count();

    mt19937 g(rd() ^ t);

    shuffle(plano.begin(), plano.end(), g);

    return plano;
}

vector<string> aplanador(array<array<string,13>,4> cartas) {
    vector<string> cartas_lineal;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cartas_lineal.push_back(cartas[i][j]); 
        }
    }
    return cartas_lineal;

}

array<array<string,13>,4> aleatorizador(array<array<string,13>,4> orden){
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
    int input;
    double presupuesto;
    cout<<"decide el modo de juego: \n"<<"1.Corto ($100) 2.largo ($300) 3.Muy largo($1000)\n";   
    if(!(cin>>input)){
        cin.clear();
        cin.ignore(10000, '\n');
        cout<<"entrada invalida.\n";
        goto invalidModeInput;
    }
    switch (input)
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
    double apuesta=presupuesto*0.05;
    double ap_minima=presupuesto*0.05;
    remezcleo:
    array<array<string,13>,4> cartas_val={{
        {"A2","A3","A4","A5","A6","A7","A8","A9","A10","AJ","AQ","AK","AZ"},
        {"B2","B3","B4","B5","B6","B7","B8","B9","B10","BJ","BQ","BK","BZ"},
        {"C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","CZ"},
        {"D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","DZ"}
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
    
    bool flag = false;
    while(barajaPlana.size()>=4){
        if(flag){
            x:
            cout<<"cuanto apuestas a esta ronda? \n";
            if(!(cin>>apuesta)){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"entrada invalida.\n";
                goto x;
            }
            if(apuesta>presupuesto || apuesta<ap_minima){
                cout<<"monto invalido!!\n";
                goto x;
            }
        }
        flag=true;


        /*for(int i=0;i<barajaPlana.size();i++){
            cout<<barajaPlana[i]<<" ";
        }
        cout<<endl;*/

    
        mano=pasarMano(barajaPlana);
        mano_dealer=pasarMano(barajaPlana);

        cout<<"tu mano: ";
        for(int i=0;i<mano.size();i++){
            switch (mano[i][0])
            {
            case 'A':
                if(mano[i][1]=='Z'){
                    cout<<"A"<<" de corazones ";
                }else{
                    cout<<mano[i].substr(1)<<" de corazones ";
                }
                break;
            case 'B':
                if(mano[i][1]=='Z'){
                    cout<<"A"<<" de diamantes ";
                }else{
                    cout<<mano[i].substr(1)<<" de diamantes ";
                }
                break;
            case 'C':
                if(mano[i][1]=='Z'){
                    cout<<"A"<<" de picas ";
                }else{
                    cout<<mano[i].substr(1)<<" de picas ";
                }
                break;
            case 'D':
                if(mano[i][1]=='Z'){
                    cout<<"A"<<" de treboles ";
                }else{
                    cout<<mano[i].substr(1)<<" de treboles ";
                }
                break;
            default:
                break;
            }
            //cout<<mano[i]<<" ";
        
        }
        
        switch (mano_dealer[1][0])
            {
            case 'A':
                if(mano_dealer[1][1]=='Z'){
                    cout<<endl<<"carta visible del crupier: "<<"A"<<" de corazones \n";
                }else{
                    cout<<endl<<"carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de corazones \n";
                }
                break;
            case 'B':
                if(mano_dealer[1][1]=='Z'){
                    cout<<endl<<"carta visible del crupier: "<<"A"<<" de diamantes \n";
                }else{
                    cout<<endl<<"carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de diamantes \n";
                }
                break;
            case 'C':
                if(mano_dealer[1][1]=='Z'){
                    cout<<endl<<"carta visible del crupier: "<<"A"<<" de picas \n";
                }else{
                    cout<<endl<<"carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de picas \n";
                }
                break;
            case 'D':
                if(mano_dealer[1][1]=='Z'){
                    cout<<endl<<"carta visible del crupier: "<<"A"<<" de treboles \n";
                }else{
                    cout<<endl<<"carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de treboles \n";
                }
                break;
            default:
                break;
            }
        //cout<<endl<<"carta visible del crupier: "<<mano_dealer[1]<<endl;
        //imprime la mano del crupier
        /*cout<<"mano del crupier: ";
        for(int i=0;i<mano_dealer.size();i++){
            cout<<mano_dealer[i]<<" ";
        
        }*/
    
        // tomar mas cartas
        int puntaje_p=evaluar(mano);
        cout<<"tu puntaje: "<<puntaje_p<<endl;

        mano=tomarCartas(barajaPlana,'y',mano, apuesta,presupuesto);
        
        //evaluar puntajes

        puntaje_p=evaluar(mano);
        if(puntaje_p>21){
            cout<<"la casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
            cout<<"balance: "<<presupuesto-apuesta<<endl;
            presupuesto-=apuesta;
            if(presupuesto<ap_minima){
            cout<<"\nya no tienes dinero :O,   q mal :c\n";
            string a;
            cout<<"\nquieres volver a empezar? 'y'";cin>>a;
            if(a=="y"){
                goto invalidModeInput;
            }else{
                cout<<"Juego terminado.";
                goto game_over;
            }            
        }
            mano.clear();
            mano_dealer.clear();
            continue;
        }
        
        
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
            cout<<"la casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
            cout<<"balance: "<<presupuesto-apuesta<<endl;
            presupuesto-=apuesta;
        }else if(21-puntaje_c<0){
            cout<<"tu ganas, te llevas la apuesta de la casa!!, que es de: "<<apuesta<<endl;
            cout<<"balance: "<<presupuesto+apuesta<<endl;
            presupuesto+=apuesta;
        }else if(21-puntaje_c<21-puntaje_p){
            cout<<"la casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
            cout<<"balance: "<<presupuesto-apuesta<<endl;
            presupuesto-=apuesta;
        }else{
            cout<<"tu ganas, te llevas la apuesta de la casa!!, que es de: "<<apuesta<<endl;
            cout<<"balance: "<<presupuesto+apuesta<<endl;
            presupuesto+=apuesta;
        }
        
        if(presupuesto<ap_minima){
            cout<<"\nya no tienes dinero :O,   q mal :c\n";
            string a;
            cout<<"\nquieres volver a empezar? 'y'";
            entradaInvalida:
            if(!(cin>>a)){
                cin.clear();
                cin.ignore(10000, '\n');
                cout<<"entrada invalida.\n";
                goto entradaInvalida;
            }
            if(a=="y"){
                goto invalidModeInput;
            }else{
                cout<<"Juego terminado.";
                goto game_over;
            }            
        }
        getch();
        mano.clear();
        mano_dealer.clear();
        
    }
    if(barajaPlana.size()<4){
        cout<<"\nno quedan sufucientes cartas.\n";
        goto remezcleo;
    }
    cout<<"Juego terminado.";
    game_over:
    getch();
    return 0;
}
