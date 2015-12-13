#include <cstdio>
#include <iostream>
#include <stdlib.h>

#include "DFA.hpp"
 
using namespace std;
int main(void)
{
    int opcion=9; 
    char fichero[100];
	int error=0;
	char cadena[100];
	
	
	cout << "Escriba el nombre del fichero .dfa que desea cargar: ";
	cin >> fichero;
    
    dfa_t A(fichero);
   	
   	if(error != 1)
   	{
	    while(opcion != 0) 
	    {   
			cout << "---- Simulación de un DFA -----	" << endl;
			cout << "[1]. Leer DFA" << endl; 
			cout << "[2]· Mostrar DFA" << endl; 
			cout << "[3]· Identificar estados de muerte" << endl; 
			cout << "[4]· Analizar una cadena" << endl; 
			cout << "[0]. Para salir del programa " << endl; 
			cout << "----- Introduce la accion a ejecutar ----- "<<endl;
			cin >> opcion;
			cout << endl; 
	
	    
	    
	        switch (opcion) 
			{
			    case 0:
				    cout << "Ha salido del programa." << endl;
					exit(0);
				break;
				case 1:
					cout << "Escriba el nombre del fichero .dfa que desea cargar:  ";
					cin >> fichero;
					A.leer_dfa(fichero);
				break;
				case 2:	
					A.mostrar_dfa();
				break;	
				case 3:	
					A.estados_de_muerte();
				break; 
				case 4: 
					A.analizar_cadena(); 
				break;
				default: 
		    		cout << "Opción incorrecta" << endl;
			    break;
				
				
			}
	         
	        if(error == 1)
	        {
	        	opcion = 0;
	        }
		 }
    }
}