#include <iostream> 
#include <string>
#include <vector>
#include <stdlib.h>

#include "calculadora.hpp"


using namespace std; 

int main(void)
{
	int opcion = 9; 
	
	int A; //tamaño lenguaje A
	int B; //tamaño lenguaje B
	
	string aux;
	vector<string> L1;
	vector<string> L2;
	
	

	cout << "Introduzca el numero de cadenas del L1" << endl;
			
				cin >> A;
				
				for( int i=0; i<A; i++)
				{
					cout << "Introduzca la cadena: " << i+1 << endl;
				 	cin >> aux;
				 	L1.push_back(aux);	
				}
				
				cout << endl << "L1= {";
				for( int i=0; i<A; i++)
				{
					cout << L1[i];
					if(i!=(A-1))
					cout <<",";
				 		
				}
				cout << "}" << endl;
				
		cout << endl << "Introduzca el numero de cadenas del L2" << endl;
			
				cin >> B;
				
				for( int i=0; i<B; i++)
				{
					cout << "Introduzca la cadena: " << i+1 << endl;
				 	cin >> aux;
				 	L2.push_back(aux);	
				}
				
				cout << endl << "L2 = {";
				for( int i=0; i<B; i++)
				{
					cout << L2[i];
					if(i!=(B-1))
					cout <<",";
				 		
				}
				cout << "}" << endl;
				cout << endl;
				
				
				calculadora_t S(L1,A,L2,B);
	
	    while(opcion != 0) {    
		
			cout << "---- Calculadora de lenguajes finitos -----	" << endl;
			cout << "1. Calcular la potencia n del lenguaje L1 o L2" << endl; 
			cout << "2· Calcular la inversa del lenguaje L1 o L2" << endl; 
			cout << "3· Calcular la concatenación de L1 y L2" << endl; 
			cout << "4· Calcular la unión de L1 y L2" << endl; 
			cout << "5· Calcular la intersección de L1 y L2" << endl; 
			cout << "6· Calcular la diferencia de L1 y L2" << endl; 
			cout << "7· Calcular los sublenguajes de L1 y L2" << endl;
			cout << "8· Calcular si L1 y L2 son iguales" << endl; 
			cout << "0. Para salir del programa " << endl; 
			cout << "----- Introduce la accion a ejecutar ----- "<<endl;
			cin >> opcion;
			cout << endl; 

			
			switch (opcion) 
			{
				case 0:
					cout << "Saliendo del programa..." << endl;
					exit(0);
				break;
				case 1: 
					int n;
					int m;
					cout << "Elija con que lenguaje desea operar [1 o 2] " << endl;
					cin >> m;
					if(m == 1){
						cout << "Introduzca la potencia a calcular: ";
						cin >> n;
						cout << endl;
						S.potencia(n,1);
					}
					if(m == 2){
						cout << "Introduzca la potencia a calcular: ";
						cin >> n;
						cout << endl;
						S.potencia(n,2);
					}
				break;
				
				case 2:
					int x;
					cout << "Elija con que lenguaje desea operar [1 o 2] " << endl;
					cin >> x;
					if(x == 1){
						cout << endl; 
						S.inversa(1);
					}
					if(x == 2){
						cout << endl;
						S.inversa(2);
					}
				break;	
				
				case 3: 
					S.concatenacion();
				break; 
				
				case 4: 
					S.union_();
				break;
				
				case 5: 
					S.interseccion();
				break;
				case 6: 
					S.diferencia();
				break;
				case 7: 
					if(S.sublenguajes())
					{
						cout << "L2 es sublenguaje de L1" << endl;
					}
					else
					{
						cout << "L2 no es sublenguaje de L1" << endl;
					}
				break;
				case 8: 
					if(S.igualdad_lenguajes())
					{
						cout << "Los Lenguajes L1 y L2 son iguales" << endl;
					}
					else
					{
						cout << "Los Lenguajes L1 y L2  no son iguales" << endl;
					}
				break;
				default: 
				cout << "opción incorrecta" << endl;
				break;

              }
				
			}
			
       }

