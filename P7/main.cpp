#include "GR.hpp"
#include "dfa_t.hpp"
using namespace std;

int main (int argc, char* argv[])
{

  char* input_file = argv[1];
  char* output_file = argv[2];
  
  if ((input_file!=NULL) && (output_file!=NULL))
  {
  
    dfa_t DFA;
    dfa_t DFA_MIN;
    DFA.leer_dfa(input_file);
    GR_t GRAMMAR(DFA);
  
    int opcion;
    do
    {
      cout << "PRACTICA #07 -- COMPUTABILIDAD Y ALGORITMIA" << endl;
      cout << "Gramática regular a partir de un DFA" << endl;
      cout << endl;
      cout << "1 - Leer DFA" << endl;
      cout << "2 - Mostrar DFA." << endl;
      cout << "3 - Mostrar estados de muerte." << endl;
      cout << "4 - Analizar cadena." << endl;
      cout << "5 - Minimizar DFA" << endl;
      cout << "6 - Exportar el DFA mínimo" << endl;
      cout << "7 - Obtener gramática regular" << endl;
      cout << "8 - Salir."<< endl;
      cout << "Introduzca una opción >>> ";
      cin >> opcion;

      switch(opcion)
      {
        case 1:
          char fichero[80];
          cout << "Introduzca el nombre del fichero a leer: ";
          cin >> fichero;
          DFA.leer_dfa(fichero);
        case 2:
          DFA.mostrar_dfa();
          break;
        case 3:
          DFA.estados_de_muerte();
          break;
        case 4:
          DFA.analizar_cadena();
          break;
        case 5:
          DFA.minimizar_dfa(DFA_MIN); 
          break;
        case 6:
          DFA_MIN.exportar_dfa();
          break;
        case 7: 
          GRAMMAR.exportar_GR(output_file, DFA);
          break; 
        default:
          cout << "Opción incorrecta." <<endl;
          break;
      }
    }while(opcion!=8);
  }
  else
  {
    cout << "Este programa implementa la función de línea de comandos, por favor vuelva a ejecutar con el siguiente formato: " << endl;
    cout << "./dfa nombre_fichero.dfa nombre_fichero.grm" << endl;
  }
} 