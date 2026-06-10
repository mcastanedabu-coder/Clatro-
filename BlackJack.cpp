#include<iostream>
#include<algorithm>
#include<chrono>
#include<thread>
#include<array>
#include<string>
#include<vector>
#include<numeric>   
#include<random>
#include<ctime>
#include<sstream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
using namespace std;

void printMenu(){
	cout<<endl<<endl<<endl;
	
	cout<<"\t\t\t\t\t   "<<".------..------..------..------..------..------..------..------..------."<<endl;
	cout<<"\t\t\t\t\t   "<<"|1.--. ||\033[31m2.--.\033[0m ||3.--. ||\033[31m4.--.\033[0m ||5.--. ||\033[31m6.--.\033[0m ||7.--. ||\033[31m8.--.\033[0m ||9.--. |"<<"   "<<endl;
	cout<<"\t\t\t\t\t   "<<"| :/\\: || \033[31m(\\/)\033[0m || :(): || \033[31m:/\\:\033[0m || :/\\: || \033[31m(\\/)\033[0m || :(): || \033[31m:/\\:\033[0m || :/\\: |"<<"   "<<endl;
	cout<<"\t\t\t\t\t   "<<"| (__) || \033[31m:\\/:\033[0m || ()() || \033[31m:\\/:\033[0m || (__) || \033[31m:\\/:\033[0m || ()() || \033[31m:\\/:\033[0m || (__) |"<<"   "<<endl;
	cout<<"\t\t\t\t\t   "<<"| '--'1|| \033[31m'--'2\033[0m|| '--'3|| \033[31m'--'4\033[0m|| '--'5|| \033[31m'--'6\033[0m|| '--'7|| \033[31m'--'8\033[0m|| '--'9|"<<"   "<<endl;
	cout<<"\t\t\t\t\t   "<<"`------'`------'`------'`------'`------'`------'`------'`------'`------'"<<endl<<endl;
	
	cout<<"\t\t\t\t\t"<<"\033[32m   ______  _____          _     _________  _______      ___                       \033[0m"<<endl;
	cout<<"\t\t\t\t\t"<<"\033[32m .' ___  ||_   _|        / \\   |  _   _  ||_   __ \\   .'   `.     .-.      .-.    \033[0m"<<endl;
	cout<<"\t\t\t\t\t"<<"\033[32m/ .'   \\_|  | |         / _ \\  |_/ | | \\_|  | |__) | /  .-.  \\  __| |__  __| |__  \033[0m"<<endl;
	cout<<"\t\t\t\t\t"<<"\033[32m| |         | |   _    / ___ \\     | |      |  __ /  | |   | | |__   __||__   __| \033[0m"<<endl;
	cout<<"\t\t\t\t\t"<<"\033[32m\\ `.___.'\\ _| |__/ | _/ /   \\ \\_  _| |_    _| |  \\ \\_\\  `-'  /    | |      | |    \033[0m"<<endl;
	cout<<"\t\t\t\t\t"<<"\033[32m `.____ .'|________||____| |____||_____|  |____| |___|`.___.'     '-'      '-'    \033[0m"<<endl<<endl<<endl;

	cout<<"\t\t\t\t\t\t\t       "<<"1. Empezar juego ---------------"<<endl<<endl;
	cout<<"\t\t\t\t\t\t               "<<"2. Cargar juego ----------------"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t       "<<"3. Salir -----------------------"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t       "<<"Digite el numero de su opcion: ";
}

int menuOpciones(int opcion){
	switch(opcion){
		case 1:
			cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Iniciando Juego";
			for (int ciclo = 0; ciclo < 2; ciclo++){
				for (int puntos = 0; puntos < 3; puntos++){
					cout<<"."<<flush;
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				cout<<"\r"<<flush;
				cout<<"\r\t\t\t\t\t\t\t\t       Iniciando Juego   \r\t\t\t\t\t\t\t\t       Iniciando Juego"<<flush;
			}
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t       Juego Iniciado\n\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			//ANSI Escape Sequences - Toca buscar que es eso para el informe
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			return opcion;
		case 2:
			cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Cargando Juego";
			for (int ciclo = 0; ciclo < 2; ciclo++){
				for (int puntos = 0; puntos < 3; puntos++){
					cout<<"."<<flush;
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				cout<<"\r"<<flush;
				cout<<"\r\t\t\t\t\t\t\t\t       Cargando Juego   \r\t\t\t\t\t\t\t\t       Cargando Juego"<<flush;
			}
			cout<<endl<<endl<<"\t\t\t\t\t\t\t\t       Carga Completa\n\n";
			this_thread::sleep_for(chrono::milliseconds(1000));
			//ANSI Escape Sequences - Toca buscar que es eso para el informe
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			return opcion;
		case 3:
			cout<<endl<<"\t\t\t\t\t\t\t\t      "<<"Saliendo del Juego";
			this_thread::sleep_for(chrono::milliseconds(3000));
			return 0;
		
		//Return temporal como salva vidas
		return 0;
	}
}

int menuMesa(){
	while(true){
		cout<<"Mesas disponibles para jugar\n";
		cout<<"\t1. Mesa Corta ------ Saldo: $100\n";
		cout<<"\t2. Mesa Mediana ---- Saldo: $300\n";
		cout<<"\t3. Mesa Larga ------ Saldo: $1000\n";
		cout<<"Escoja la mesa para jugar: ";
		int opcionDeMesa;
		cin>>opcionDeMesa;
		if (cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<endl<<"Introduzca un NUMERO, por favor"<<endl<<endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout<<"\033[2J\033[3J\033[H"<<flush;
			opcionDeMesa = 0;
			continue;
		}
		cin.ignore(10000, '\n');
		if (opcionDeMesa != 1 && opcionDeMesa != 2 && opcionDeMesa != 3){
			cout<<endl<<"Opcion no valida"<<endl<<endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			//ANSI Escape Sequences
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
		}
		
		switch(opcionDeMesa){
			case 1:{
				cout<<"\nHas elegido la mesa corta ------ Saldo de la Mesa: $100\n\n";
				this_thread::sleep_for(chrono::milliseconds(5000));
				cout<<"\033[2J\033[3J\033[H"<<flush;
				return 1;
			}
				
			case 2:{
				cout<<"\nHas elegido la mesa mediana ------ Saldo de la Mesa: $300\n\n";
				this_thread::sleep_for(chrono::milliseconds(5000));
				cout<<"\033[2J\033[3J\033[H"<<flush;
				return 2;
			}
				
			case 3:{
				cout<<"\nHas elegido la mesa larga -------- Saldo de la Mesa: $500\n\n";
				this_thread::sleep_for(chrono::milliseconds(5000));
				cout<<"\033[2J\033[3J\033[H"<<flush;
				return 3;
			}	
		}	
	}
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
    cout <<endl<<"Desea tomar otra carta? 'y'\nO desea doblar? 'd' \nDigite su respuesta: ";
    bool x=false;
    while (true) {
        if(x){
            cout <<endl<<"Desea tomar otra carta? 'y' \nDigite su respuesta: ";
        }
        
        
        if(!(cin>>comp)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Entrada invalida.\n";
            continue;
        }
        if(comp=='d' && x){
            cout<<"\nNo puedes doblar!";
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
                cout<<"\nNo tienes suficiente dinero para doblar";
                continue;
            }
            arr2.push_back(arr.front()); 
            arr.erase(arr.begin());
            apuesta*=2;
            
        }
        else {
            break;
        }
        cout<<"\nTu mano es: ";
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
        cout<<"y tu puntaje: "<<evaluar(arr2)<<endl;
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

//Codigo para la Música del Juego
string playlist[] = {"music/cancion2.mp3", "music/cancion1.mp3", "music/cancion3.mp3"};
int totalCanciones = 3;
int cancionActual = 0;

void detenerMusica(){
	mciSendString("stop musica", NULL, 0, NULL);
	mciSendString("close musica", NULL, 0, NULL);
}

void reproducirMusica(){
	//Primero se tiene que parar cualquier musica que haya estado sonando
	detenerMusica();
	
	/*
	- Se abre la canción acutal y se le apoda "musica" para que el MCI la pueda controlar
	- type mpegvideo: le cuenta al sistema que el archivo a abrir es un audio o video comprimido (MP3 ó MP4)
	- alias musica: se le asigna el alias de musica a la canción actual para no tener que ingresar la ruta de
	nombre todas las veces que nos queramos referir a ese archivo
	*/
	
	string comando = "open \"" + playlist[cancionActual] + "\" type mpegvideo alias musica";
	
	/*
	- .c_str() -> convierte un "objeto moderno" (ej. string) en un arreglo tradicional de caracteres
	- Como windows está montado sobre C, es necesario hacer esta traducción para que el codigo pueda leer
	la ruta del archivo sin problema, ya que C no reconoce strings, solo arreglos de caracteres
	*/
	
	mciSendString(comando.c_str(), NULL, 0, NULL);
	mciSendString("play musica", NULL, 0, NULL);
}

//Esta función permite que el juego use la playlist para reproducir la música
void revisarLoopMusica(){
	
	/*
	- Este buffer permite recibir el dato que windows nos de con respecto al estado del archivo
	si está detenido manda un "stopped", reproduciendo un "playing", etc. Con el fin de guardar
	el estado del archivo, se crea un buffer de 128 bytes que sea lo suficientemente grande para guardar
	las palabras clave que mande el MCI de windows, ya que por letra es un byte y por palabras entre 7 y 8 bytes
	*/
	
	char buffer[128];
	
	mciSendString("status musica mode", buffer, sizeof(buffer), NULL);
	string estado(buffer);
	
	if (estado.find("stopped") != string::npos){
		cancionActual += 1;
		
		if (cancionActual >= totalCanciones){
			cancionActual = 0;
		}
		
		//Reproduce la canción con el nuevo indice (la siguiente canción o el bucle)
		reproducirMusica();
	}
}

int main(){
	reproducirMusica();
	int saldo = 0;
	int opcionGeneral = 0;
	while (opcionGeneral != 3 && opcionGeneral != 4){
		int opcion = 0;
		do{
			printMenu();
			cin>>opcion;
			if (cin.fail()){
				cin.clear();
				cin.ignore(10000, '\n');
				cout<<endl<<"\t\t\t\t\t\t\t       Introduzca un NUMERO, por favor"<<endl<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
				cout<<"\033[2J\033[3J\033[H"<<flush;
				opcion = 0;
				continue;
			}
			
			cin.ignore(10000, '\n');
			
			if (opcion != 1 && opcion != 2 && opcion != 3){
				cout<<endl<<"\t\t\t\t\t\t\t\t       "<<"Opcion no valida"<<endl<<endl;
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
			
			//ANSI Escape Sequences
			//"\033[2J" Limpia la pantalla visible
			//"\033[3J" Limpia lo que se imprimio (el buffer)
			//"\033[H" te lleva hasta el orgien de la impresion por consola (Esquina superior izq.)
			cout<<"\033[2J\033[3J\033[H"<<flush;
			
		} while (opcion != 1 && opcion != 2 && opcion != 3);
		
		if (menuOpciones(opcion) == 0){
			return 0;
		}
		
		//Saldo Inicial
		vector<string> barajaPlana;
	    vector<string> mano;
	    vector<string> mano_dealer;
	
	    //Ajustar monto inicial
	    invalidModeInput:
	    int input = menuMesa();
	    double presupuesto; 
	    switch (input){
		    case 1:
		        presupuesto=100;
		        break;
		    case 2:
		        presupuesto=300;
		        break;
		    case 3:
		        presupuesto=1000;
		        break;
		}
		
	    cout<<"La apuesta minima es el 5%"<<" de tu bankroll ($"<<presupuesto<<") ---> $"<<presupuesto*0.05<<"\n\n";
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
	    	revisarLoopMusica();
	        if(flag){
	            x:
	            cout<<"Cuanto apuestas a esta ronda? \nDigite su apuesta: $";
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
	        
	        cout<<endl;
	        revisarLoopMusica();
	
	        /*for(int i=0;i<barajaPlana.size();i++){
	            cout<<barajaPlana[i]<<" ";
	        }
	        cout<<endl;*/
	
	    
	        mano=pasarMano(barajaPlana);
	        mano_dealer=pasarMano(barajaPlana);
	
	        cout<<"Tu mano: ";
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
	        
	        revisarLoopMusica();
	        
	        switch (mano_dealer[1][0])
	            {
	            case 'A':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: "<<"A"<<" de corazones \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de corazones \n";
	                }
	                break;
	            case 'B':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: "<<"A"<<" de diamantes \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de diamantes \n";
	                }
	                break;
	            case 'C':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: "<<"A"<<" de picas \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de picas \n";
	                }
	                break;
	            case 'D':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: "<<"A"<<" de treboles \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: "<<mano_dealer[1].substr(1)<<" de treboles \n";
	                }
	                break;
	            default:
	                break;
	            }
	        //cout<<endl<<"Carta visible del crupier: "<<mano_dealer[1]<<endl;
	        //imprime la mano del crupier
	        /*cout<<"mano del crupier: ";
	        for(int i=0;i<mano_dealer.size();i++){
	            cout<<mano_dealer[i]<<" ";
	        
	        }*/
	    
	        // tomar mas cartas
	        revisarLoopMusica();
	        int puntaje_p=evaluar(mano);
	        cout<<"Tu puntaje: "<<puntaje_p<<endl;
	
	        mano=tomarCartas(barajaPlana,'y',mano, apuesta,presupuesto);
	        
	        //evaluar puntajes
	
	        puntaje_p=evaluar(mano);
	        if(puntaje_p>21){
	            cout<<"La casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
	            cout<<"Balance: $"<<presupuesto-apuesta<<endl;
	            presupuesto-=apuesta;
	            if(presupuesto<ap_minima){
	            cout<<"\nYa no tienes dinero :O,   q mal :c\n";
	            string a;
	            cout<<"\nQuieres volver a empezar? 'y'";cin>>a;
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
	        
	        revisarLoopMusica();
	        
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
	        
	        revisarLoopMusica();
	        
	        cout<<endl<<"Crupier puntaje: "<<puntaje_c<<endl;
	        if(21-puntaje_p<0 && 21-puntaje_c<0){
	            cout<<"Empate, no cambia tu balance."<<endl;
	            cout<<"Balance: $"<<presupuesto<<endl;
	        }else if(puntaje_c==puntaje_p){
	            cout<<"Empate, no cambia tu balance."<<endl;
	            cout<<"Balance: $"<<presupuesto<<endl;
	        }else if(21-puntaje_p<0){
	            cout<<"La casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
	            cout<<"Balance: $"<<presupuesto-apuesta<<endl;
	            presupuesto-=apuesta;
	        }else if(21-puntaje_c<0){
	            cout<<"Tu ganas, te llevas la apuesta de la casa!!, que es de: "<<apuesta<<endl;
	            cout<<"Balance: $"<<presupuesto+apuesta<<endl;
	            presupuesto+=apuesta;
	        }else if(21-puntaje_c<21-puntaje_p){
	            cout<<"La casa gana, pierdes tu apuesta, que es de: "<<apuesta<<endl;
	            cout<<"Balance: $"<<presupuesto-apuesta<<endl;
	            presupuesto-=apuesta;
	        }else{
	            cout<<"Tu ganas, te llevas la apuesta de la casa!!, que es de: "<<apuesta<<endl;
	            cout<<"Balance: $"<<presupuesto+apuesta<<endl;
	            presupuesto+=apuesta;
	        }
	        
	        revisarLoopMusica();
	        
	        if(presupuesto<ap_minima){
	            cout<<"\nYa no tienes dinero :O,   q mal :c\n";
	            string a;
	            cout<<"\nQuieres volver a empezar? 'y'";
	            entradaInvalida:
	            if(!(cin>>a)){
	                cin.clear();
	                cin.ignore(10000, '\n');
	                cout<<"Entrada invalida.\n";
	                goto entradaInvalida;
	            }
	            if(a=="y"){
	                goto invalidModeInput;
	            }else{
	                cout<<"Juego terminado.";
	                goto game_over;
	            }            
	        }
	        
	        revisarLoopMusica();
	        
	        getch();
	        mano.clear();
	        mano_dealer.clear();
	    }
	    
	    if(barajaPlana.size()<4){
	        cout<<"\nNo quedan sufucientes cartas.\n";
	        goto remezcleo;
	    }
		    
	}
	
    cout<<"Juego terminado.";
    game_over:
    getch();
    return 0;
}
