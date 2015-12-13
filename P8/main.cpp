#include "MT.hpp"


int main (int argc, char* argv[])
{
	
	char* input_file = argv[1];
	
	string tape;
	ifstream f_tape;
	f_tape.open(argv[2]);
	
	if(f_tape.is_open()) 
	{
		
		f_tape >> tape;
	}

	if (input_file!=NULL)
  	{
		MT A(input_file);
		int opcion;
	    do
	    {
	      cout << "PRACTICA #08 -- COMPUTABILIDAD Y ALGORITMIA" << endl;
	      cout << "Máquina de Turing" << endl;
	      cout << endl;
	      cout << "1 - Leer una máquina nueva." << endl;
	      cout << "2 - Mostrar máquina." << endl;
	      cout << "3 - Simular máquina de Turing." << endl;
	      cout << "4 - Salir."<< endl;
	      cout << "Cadena extraida del fichero .tape: " << tape << endl;
	      cout << "Fichero actual: " << input_file << endl;
	      cout << "Introduzca una opción >>> ";
	      cin >> opcion;
	
	      switch(opcion)
	      {
	        case 1:
	          char fichero[80];
	          cout << "Introduzca el nombre del fichero a leer: ";
	          cin >> fichero;
	          A.leer_MT(fichero);
	        case 2:
	          	A.mostrar();
	        break;
	        case 3:
	        	A.simular(tape);  
	        break;
	        default:
	          cout << "Opción incorrecta." <<endl;
	          break;
	      }
    }while(opcion!=4);
  }
  else
  {
    cout << "Este programa implementa la función de línea de comandos, por favor vuelva a ejecutar con el siguiente formato: " << endl;
    cout << "./MT nombre_fichero.dfa nombre_fichero.tape" << endl;
  }


}