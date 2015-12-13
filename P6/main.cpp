#include <iostream>
#include <fstream>
#define MAXCAD 30
#include "nfa.hpp"

using namespace std;

set<estado> prueba;
char* salida;
char* nombre_archivo;
int menu(){
	int res;
	//Si se borra antes no mostrará resultados
	cout << "\x1B[2J\x1B[1;1H";
	cout << "1. Cargar nuevo NFA" << endl;
	cout << "2. Mostrar NFA" << endl;
	cout << "3. Identificar estados de muerte" << endl;
	cout << "4. Analizar cadena" << endl;
	cout << "5. Transformar NFA en DFA" << endl;
	cout << "8. Cerrar" << endl << endl;
	cin >> res;
	return res;
}
set<estado> casos;

int main(int argc, char* argv[]){
	char cad[MAXCAD];
	
	
	nfa ejemplo;
	if(argc == 3){
		salida = argv[2];
		nombre_archivo = argv[1];
		ejemplo.cargar(argv[1]);
	}else{
		cout << "Introduzca el nombre del fichero NFA: ";
		cin >> nombre_archivo;
		getchar();
		getchar();
		cout << "Introduzca el nombre del fichero de salida NFA: ";
		cin >> salida;
		getchar();
		ejemplo.cargar(nombre_archivo);
	}
	int resp = menu();
	while(resp != 8){
		switch(resp){
			case 1:
				cout << "Introduzca el nombre del fichero NFA: ";
				cin >> nombre_archivo;
				getchar();
				ejemplo.cargar(nombre_archivo);
			break;
			case 2:
				ejemplo.print();
				getchar();
				getchar();
			break;
			case 3:
				ejemplo.identify_death();
				getchar();
				getchar();
			break;
			case 4:
				cout << "Introduzca la cadena a analizar: ";
				cin >> cad;
				getchar();
				ejemplo.analize(cad);
				getchar();
			break;
			case 5:
				ejemplo.nfa2dfa(salida);
				getchar();
				getchar();
				menu();
				break;
			break;
			case 6:
				ejemplo.minimizar();
				getchar();
				getchar();
				menu();
			break;
			case 9:
				ejemplo.mostraralfabeto();
				getchar();
				getchar();
				menu();
			break;
			case 10:
				
				casos.insert(ejemplo.estadoinicial());
				prueba = ejemplo.eclausura(casos);
				ejemplo.singlesetprint(prueba);
				prueba = ejemplo.megatransicion(prueba, 'a');
				ejemplo.singlesetprint(prueba);
				getchar();
				getchar();
				menu();
			break;
			case 7:
				ejemplo.nfa2dfa(salida);
				getchar();
				getchar();
				menu();
				break;
			default:
				cout << "Se ha detectado una opción inválida, escriba Y para volver a intentarlo";
				getchar();
				getchar();
				menu();
			break;
		}
	resp = menu();	
	}
	cout << "\x1B[2J\x1B[1;1H";
}