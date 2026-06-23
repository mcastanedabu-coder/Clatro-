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
				cout<<"\nHas elegido la mesa larga -------- Saldo de la Mesa: $1000\n\n";
				this_thread::sleep_for(chrono::milliseconds(5000));
				cout<<"\033[2J\033[3J\033[H"<<flush;
				return 3;
			}	
		}	
	}
}

vector<string> aces(vector<string>& arr){
	//se validan los haces evaluandolos de ultimos, pasandolos a las ultimas posiciones de la mano del jugador, 
	//para que se puedan evaluar de manera correcta, ya que los aces pueden valer 1 o 11 dependiendo del puntaje total de la mano
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
	//una vez que se tiene la mano del jugador, se evalua el puntaje de la mano del jugador,
	// teniendo en cuenta que las cartas con valor de 10 (J,Q,K) valen 10, y los Ases pueden valer 1 o 11 dependiendo del puntaje total de la mano

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
                if(val_p + 11 <= 21){
                    val_p += 11;
                }
                else{
                    val_p += 1;
                }
                break;
            default:
                val_p += 10;
                break;
            }
        }
    }
    return val_p;
}

vector<string> tomarCartas(vector<string>& arr, char conf, vector<string>& arr2,double& apuesta,double pres) {
	//se selecciona la acción del jugador, ya sea tomar otra carta, doblar o no tomar mas cartas, y se agregan las cartas a la mano del jugador
	string entrada;
    char comp;
    cout<<endl<<"Desea tomar otra carta? 'Y'\nDesea doblar? 'D'\nDesea no tomar mas cartas? Digite cualquier letra\nDigite su respuesta: ";
	//tambien se define un flag para que el mensaje de la pregunta no se repita en la primera iteración del while
    bool x=false;
    while (true) {
        if(x){
            cout <<endl<<"Desea tomar otra carta? 'Y'\nDesea doblar? 'D'\nDesea no tomar mas cartas? Digite cualquier letra\nDigite su respuesta: ";
        }
        //se hacen las respectivas validaciones de la entrada del usuario, para que no se rompa el programa si el usuario ingresa un valor invalido
        if(!(cin>>entrada)){
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Entrada invalida.\n";
            continue;
        }
        cin.ignore(10000, '\n');
        
        if (entrada.length() > 1) {
            cout << "\nEntrada invalida. Por favor, digite solo UNA letra ('Y' o 'D').\n";
            continue;
        }
        
        comp = toupper(entrada[0]);
        
        if(comp == 'D' && x){
            cout<<"\nNo puedes doblar!";
            continue;
        }
        
        x = true;
        //después de validar la entrada del usuario, se agregan las cartas a la mano del jugador y se eliminan del mazo, y se imprime la mano del jugador y su puntaje
        if (comp == conf) {

            if (arr.empty()) {
                cout << "No quedan cartas.\n";
                break;
            }

            arr2.push_back(arr.front()); // primera carta
            arr.erase(arr.begin());      // eliminarla del mazo
        } else if(comp == 'D'){
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
            cout<<"\nHaz doblado. Tu carta final ha sido agregada.\n";
            break;
        }
        else {
            break;
        }
        cout<<"\nTu mano es: \n";
        for(string s:arr2){
            switch (s[0])
            {
            case 'A':
                if(s[1]=='Z'){
                    cout<<"A"<<" de corazones \n";
                }else{
                    cout<<s.substr(1)<<" de corazones \n";
                }
                break;
            case 'B':
                if(s[1]=='Z'){
                    cout<<"A"<<" de diamantes \n";
                }else{
                    cout<<s.substr(1)<<" de diamantes \n";
                }
                break;
            case 'C':
                if(s[1]=='Z'){
                    cout<<"A"<<" de picas \n";
                }else{
                    cout<<s.substr(1)<<" de picas \n";
                }
                break;
            case 'D':
                if(s[1]=='Z'){
                    cout<<"A"<<" de treboles \n";
                }else{
                    cout<<s.substr(1)<<" de treboles \n";
                }
                break;
            default:
                break;
            }
        }
        cout<<"\nTu puntaje es: "<<evaluar(arr2)<<endl;
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
	//crea un vector que contiene las dos primeras cartas del vector de la baraja, y luego elimina esas dos cartas del vector de la baraja
    vector<string> arr2;
    arr2.push_back(arr[0]);
    arr2.push_back(arr[1]);
    
    arr.erase(arr.begin());
    arr.erase(arr.begin());
    return arr2;
}

array<array<string,13>,4> constructor(vector<string> base){
	//se define una nueva matriz de 4x13 para reconstruir la baraja a partir del vector plano mezclado
    array<array<string,13>,4> valor_c;
	//luego se reconstruye la baraja a partir del vector plano mezclado, llenando la matriz de 4x13 con las cartas en orden
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
	// se crea un generador de numeros aleatorios para mezclar el plano de la baraja, es decir, el vector que contiene todas las cartas de la baraja en un solo arreglo
    random_device rd;
    unsigned t = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 g(rd() ^ t);
	// la funcion shuffle() mezcla el vector plano de manera aleatoria
    shuffle(plano.begin(), plano.end(), g);
    return plano;
}

vector<string> aplanadorRecursivo(array<array<string,13>,4> cartas, int i = 0, int j = 0) {
	// se aplana la baraja de cartas, es decir, se pasa de un arreglo de 4x13 a un vector de 52 cartas
    if (i >= 4){
    	return vector<string>();
	}
	
	if (j >= 13){
		return aplanadorRecursivo(cartas, i + 1, 0);
	}
	
	vector<string> mazo;
	mazo.push_back(cartas[i][j]);
	
	vector<string> restoDelMazo = aplanadorRecursivo(cartas, i, j + 1);
	
	mazo.insert(mazo.end(), restoDelMazo.begin(), restoDelMazo.end());
	
	return mazo;
}

array<array<string,13>,4> aleatorizador(array<array<string,13>,4> orden){
	// se define un vector que sera el plano de la baraja, es decir, un vector que contenga todas las cartas de la baraja en un solo arreglo
    vector<string> plano;
	// se llama a las distintas funciones para aplanar, mezclar y reconstruir la baraja
    plano = aplanadorRecursivo(orden);
    plano = mezclador(plano);
    orden = constructor(plano);
    return orden;
}

//Codigo para la M�sica del Juego
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
	- Se abre la canci�n acutal y se le apoda "musica" para que el MCI la pueda controlar
	- type mpegvideo: le cuenta al sistema que el archivo a abrir es un audio o video comprimido (MP3 � MP4)
	- alias musica: se le asigna el alias de musica a la canci�n actual para no tener que ingresar la ruta de
	nombre todas las veces que nos queramos referir a ese archivo
	*/
	
	string comando = "open \"" + playlist[cancionActual] + "\" type mpegvideo alias musica";
	
	/*
	- .c_str() -> convierte un "objeto moderno" (ej. string) en un arreglo tradicional de caracteres
	- Como windows est� montado sobre C, es necesario hacer esta traducci�n para que el codigo pueda leer
	la ruta del archivo sin problema, ya que C no reconoce strings, solo arreglos de caracteres
	*/
	
	mciSendString(comando.c_str(), NULL, 0, NULL);
	mciSendString("play musica", NULL, 0, NULL);
}

//Esta funci�n permite que el juego use la playlist para reproducir la m�sica
void revisarLoopMusica(){
	
	/*
	- Este buffer permite recibir el dato que windows nos de con respecto al estado del archivo
	si est� detenido manda un "stopped", reproduciendo un "playing", etc. Con el fin de guardar
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
		
		//Reproduce la canci�n con el nuevo indice (la siguiente canci�n o el bucle)
		reproducirMusica();
	}
}

//Funci�n que guarda historial, punto de guardado y muestra men� de opciones
//Devuelve: 0=continuar, 1=reset, 2=guardar y continuar, 3=guardar y salir, 4=salir
int guardarHistorialYOpciones(int mesaNum, int numeroPartida, double apuesta, 
                               int puntajeJug, int puntajeCrup, 
                               double saldoAntes, double saldoDespues){
	
	//PARTE 1: Guardar historial en txt
	fstream historialFile;
	historialFile.open("historial.txt", ios::out | ios::app);
	if(historialFile.is_open()){
		time_t now = time(nullptr);
		tm* local_time = localtime(&now);
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
		
		string nombreMesa = "";
		if(mesaNum == 1) nombreMesa = "Mesa Corta ($100)";
		else if(mesaNum == 2) nombreMesa = "Mesa Mediana ($300)";
		else if(mesaNum == 3) nombreMesa = "Mesa Larga ($1000)";
		
		historialFile<<"Fecha/Hora : "<<buffer<<endl;
		historialFile<<"Mesa       : "<<nombreMesa<<endl;
		historialFile<<"Apuesta    : $"<<apuesta<<endl;
		historialFile<<"Puntaje Jug.: "<<puntajeJug<<endl;
		historialFile<<"Puntaje Cru.: "<<puntajeCrup<<endl;
		historialFile<<"Balance ant.: $"<<saldoAntes<<endl;
		historialFile<<"Balance des.: $"<<saldoDespues<<endl;
		historialFile<<"--------------------------------------------"<<endl;
		historialFile.close();
	}
	
	//PARTE 2: Mostrar menú de opciones (misma lógica que opcionesGenerales)
	int opcion = 0;
	while(true){
		cout<<"Que desea hacer?\n";
		cout<<"\t1. Continuar la partida\n";
		cout<<"\t2. Resetear Juego \n";
		cout<<"\t3. Guardar la partida y Continuar\n";
		cout<<"\t4. Guardar y salir\n";
		cout<<"\t5. Salir\n";
		cout<<endl<<"Digite su opcion: ";
		cin>>opcion;
		
		if(cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			cout<<endl<<"Entrada invalida. Ingrese un NUMERO o una opcion VALIDA"<<endl<<endl;
			continue;
		}
		cin.ignore(10000, '\n');
		
		if(opcion < 1 || opcion > 5){
			cout<<endl<<"Entrada invalida. Ingrese un NUMERO o una opcion VALIDA"<<endl<<endl;
			continue;
		}
		
		//PARTE 3: Guardar punto de guardado si es necesario
		if(opcion == 3 || opcion == 4){
			ofstream saveFile("saveFile.txt");
			fstream recordFile;
			recordFile.open("gameRecords.txt", ios::out | ios::app);
			if(recordFile.is_open()){
				time_t now2 = time(nullptr);
				tm* local_time2 = localtime(&now2);
				char buffer2[11];
				strftime(buffer2, sizeof(buffer2), "%Y/%m/%d", local_time2);
				
				recordFile<<"Saldo: "<<(int)saldoDespues<<" - Fecha: "<<buffer2;
				saveFile<<"Saldo: "<<(int)saldoDespues<<" - Fecha: "<<buffer2;
				
				char time_string[9];
				strftime(time_string, sizeof(time_string), "%X", local_time2);
				
				recordFile<<" - Hora: "<<time_string<<endl;
				saveFile<<" - Hora: "<<time_string<<endl;
				recordFile.close();
			}
			cout<<"El juego se ha guardado con exito\n\n";
			
			if(opcion == 4){
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
		}
		
		//PARTE 4: Devolver opción según acción
		if(opcion == 1) return 0;      //Continuar
		else if(opcion == 2) return 1; //Reset
		else if(opcion == 3) return 2; //Guardar y continuar
		else if(opcion == 4) return 3; //Guardar y salir
		else if(opcion == 5) return 4; //Salir
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
		
		
		
		if (opcion == 3){
			menuOpciones(opcion);
			return 0;
		}
		
		menuOpciones(opcion);
		double presupuesto = 0;
		int puntaje_c = 0;
			
		if (opcion == 2){
			presupuesto = 0;
    		ifstream loadFile("saveFile.txt");
    
		    if(!loadFile) {
		        cout << "Error: No se encontro un archivo de guardado (saveFile.txt).\n";
		        cout << "Iniciando con mesa peque�a por defecto...\n";
		        opcion = 1; 
		    } else {
		        string line, etiqueta;
		        int saveSaldo;
		        getline(loadFile, line);
		        stringstream data(line);
		        data >> etiqueta >> saveSaldo;
		        presupuesto = saveSaldo;
		        loadFile.close();
		        if (presupuesto < 5){ // 5 es el m�nimo para poder apostar el 5% de 100
					cout << "El archivo de guardado registra un saldo insuficiente ($" << presupuesto << ").\n";
					cout << "Redireccionando a la seleccion de mesa...\n";
					this_thread::sleep_for(chrono::milliseconds(2500));
					opcion = 1; // Lo forzamos a elegir mesa nueva
		    	}
			}
		}
		
		double apuesta = presupuesto*0.05;
	    double ap_minima = presupuesto*0.05;
		
		invalidModeInput:
			
		if (opcion == 1 || presupuesto < ap_minima){
		    int input = menuMesa();
		    presupuesto = 0;
		    switch (input){
			    case 1:
			        presupuesto = 100;
			        break;
			    case 2:
			        presupuesto = 300;
			        break;
			    case 3:
			        presupuesto = 1000;
			        break;
			}
			
			apuesta = presupuesto * 0.05;
			ap_minima = presupuesto * 0.05;
		}
		
		//Saldo Inicial
		vector<string> barajaPlana;
	    vector<string> mano;
	    vector<string> mano_dealer;
	
	    //Ajustar monto inicial
		
	    cout<<"La apuesta minima es el 5%"<<" de tu bankroll ($"<<presupuesto<<") ---> $"<<ap_minima<<"\n\n";
	    remezcleo:
	    array<array<string,13>,4> cartas_val={{
	        {"A2","A3","A4","A5","A6","A7","A8","A9","A10","AJ","AQ","AK","AZ"},
	        {"B2","B3","B4","B5","B6","B7","B8","B9","B10","BJ","BQ","BK","BZ"},
	        {"C2","C3","C4","C5","C6","C7","C8","C9","C10","CJ","CQ","CK","CZ"},
	        {"D2","D3","D4","D5","D6","D7","D8","D9","D10","DJ","DQ","DK","DZ"}
	    }};
		
	    cartas_val = aleatorizador(cartas_val);
	    barajaPlana = aplanadorRecursivo(cartas_val);
	    
	    bool flag = false;
	    while(barajaPlana.size()>=4){
	    	revisarLoopMusica();
	    	
	        pedir_apuesta:
			cout<<"Cuanto apuestas a esta ronda? \nDigite su apuesta: $";
	        if(!(cin>>apuesta)){
	            cin.clear();
	            cin.ignore(10000, '\n');
	            cout<<"Entrada invalida.\n";
	            goto pedir_apuesta;
	        }
	    	if(apuesta > presupuesto || apuesta < ap_minima){
	            cout<<"Monto invalido (no tienes suficiente dinero o es menor al minimo)!!\n";
	            cin.ignore(10000, '\n');
	            goto pedir_apuesta;
	        }
	        cin.ignore(10000, '\n');
	        
	        flag = true;
	        
	        cout<<endl;
	        revisarLoopMusica();
			
			mano=pasarMano(barajaPlana);
	        mano_dealer=pasarMano(barajaPlana);
	
	        cout<<"Tu mano: \n";
	        for(int i=0;i<mano.size();i++){
	            switch (mano[i][0])
	            {
	            case 'A':
	                if(mano[i][1]=='Z'){
	                    cout<<"A"<<" de corazones \n";
	                }else{
	                    cout<<mano[i].substr(1)<<" de corazones \n";
	                }
	                break;
	            case 'B':
	                if(mano[i][1]=='Z'){
	                    cout<<"A"<<" de diamantes \n";
	                }else{
	                    cout<<mano[i].substr(1)<<" de diamantes \n";
	                }
	                break;
	            case 'C':
	                if(mano[i][1]=='Z'){
	                    cout<<"A"<<" de picas \n";
	                }else{
	                    cout<<mano[i].substr(1)<<" de picas \n";
	                }
	                break;
	            case 'D':
	                if(mano[i][1]=='Z'){
	                    cout<<"A"<<" de treboles \n";
	                }else{
	                    cout<<mano[i].substr(1)<<" de treboles \n";
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
	                    cout<<endl<<"Carta visible del crupier: \n"<<"A"<<" de corazones \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: \n"<<mano_dealer[1].substr(1)<<" de corazones \n";
	                }
	                break;
	            case 'B':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: \n"<<"A"<<" de diamantes \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: \n"<<mano_dealer[1].substr(1)<<" de diamantes \n";
	                }
	                break;
	            case 'C':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: \n"<<"A"<<" de picas \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: \n"<<mano_dealer[1].substr(1)<<" de picas \n";
	                }
	                break;
	            case 'D':
	                if(mano_dealer[1][1]=='Z'){
	                    cout<<endl<<"Carta visible del crupier: \n"<<"A"<<" de treboles \n";
	                }else{
	                    cout<<endl<<"Carta visible del crupier: \n"<<mano_dealer[1].substr(1)<<" de treboles \n";
	                }
	                break;
	            default:
	                break;
	            }
	    
	        // tomar mas cartas
	        revisarLoopMusica();
	        int puntaje_p=evaluar(mano);
	        cout<<"\nTu puntaje: "<<puntaje_p<<endl;
	
	        mano=tomarCartas(barajaPlana,'Y',mano, apuesta,presupuesto);
	        
	        //evaluar puntajes
	
	        puntaje_p = evaluar(mano);
	        
	        puntaje_c = evaluar(mano_dealer);
	        
	        if(puntaje_p>21){
	            if((presupuesto - apuesta) < ap_minima){
	            	cout<<"La casa gana, pierdes tu apuesta, que es de: $"<<apuesta<<endl;
	            	double saldoFinal = presupuesto - apuesta;
	            	cout<<"Balance: $"<<saldoFinal<<endl;
	            	cout<<"\nYa no tienes dinero :O, q mal :c\n";
	            	guardarHistorialYOpciones(1, 1, apuesta, puntaje_p, puntaje_c, presupuesto, saldoFinal);
	            	string a;
	            	cout<<"\nQuieres volver a empezar? 'Y'";
					cin>>a;
	            	if(a == "Y" || a == "y"){
	                	goto invalidModeInput;
	            	} else{
	                	cout<<"Juego terminado.";
	                	goto game_over;
	            	}            
	        	}
	        } else {
	        	revisarLoopMusica();
	        	while(puntaje_c<17){
		            if(barajaPlana.empty()){
		                break;
		            }
		            mano_dealer.push_back(*barajaPlana.begin());
		            barajaPlana.erase(barajaPlana.begin());
		            puntaje_c=evaluar(mano_dealer);
		        }	
			}
			
	        revisarLoopMusica();
	        
	        cout << endl << "Puntaje del Crupier: " << puntaje_c << endl;
	        
		    double saldoAnterior = presupuesto; 
	
	        if (puntaje_p > 21) {
	            cout << "Te pasaste de 21. La casa gana, pierdes tu apuesta de: $" << apuesta << endl;
	            presupuesto -= apuesta;
	        } 
	        else if (puntaje_c > 21) {
	            cout << "El crupier se paso de 21! Tu ganas la apuesta de la casa: $" << apuesta << endl;
	            presupuesto += apuesta;
	        }
		    else if (puntaje_p == puntaje_c) {
		        cout << "Empate, ambos tienen el mismo puntaje. No cambia tu balance." << endl;
		    } 
		    else if (puntaje_p > puntaje_c) {
		        cout << "Tu ganas!! Te llevas la apuesta de la casa: $" << apuesta << endl;
		        presupuesto += apuesta;
		    } 
		    else {
		        cout << "La casa gana, pierdes tu apuesta de: $" << apuesta << endl;
		        presupuesto -= apuesta;
		    }
		
		    cout << "Balance actual: $" << presupuesto << endl << endl;
	        
	        revisarLoopMusica();
	        
	        if(presupuesto<ap_minima){
	            cout<<"\nYa no tienes dinero :O,   q mal :c\n";
	            string a;
	            cout<<"\nQuieres volver a empezar? 'Y'";
	            entradaInvalida:
	            if(!(cin>>a)){
	                cin.clear();
	                cin.ignore(10000, '\n');
	                cout<<"Entrada invalida.\n";
	                goto entradaInvalida;
	            }
	            if(a == "y" || a == "Y"){
	                goto invalidModeInput;
	            }else{
	                cout<<"Juego terminado.";
	                goto game_over;
	            }            
	        }
	        
	        revisarLoopMusica();
	        
			int accionPartida = guardarHistorialYOpciones(1, 1, apuesta, puntaje_p, puntaje_c, saldoAnterior, presupuesto);        
			
	        if (accionPartida == 1) { // Opci�n 2 del men�: Resetear Juego
	        	cout<<"\033[2J\033[3J\033[H"<<flush;
	            goto invalidModeInput;
	        } 
	        else if (accionPartida == 3 || accionPartida == 4) { // Guardar y salir, o Salir directamente
	            cout << "Regresando al menu principal...\n";
	            this_thread::sleep_for(chrono::milliseconds(1500));
	            cout<<"\033[2J\033[3J\033[H"<<flush;
	            break; // Rompe el bucle de la partida y vuelve al men� de inicio del juego
	        }
	        
	        mano.clear();
	        mano_dealer.clear();
	    }
	    
	    if (barajaPlana.size() < 4){
	        cout<<"\nNo quedan sufucientes cartas.\n";
	        mano.clear();
		    mano_dealer.clear();
		    barajaPlana.clear();
		    this_thread::sleep_for(chrono::milliseconds(1500));
	        goto remezcleo;
	    }
		    
	}
    cout<<"Juego terminado.";
    game_over:
    getch();
    return 0;
}
