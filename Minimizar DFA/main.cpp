#include "dfa.hpp"
using namespace std;

int main (void)
{
  dfa_t DFA;
  dfa_t DFA_B;
  DFA.leer_dfa();
  bool minimo = false;
  int opcion;
  do
  {
    cout << "MENU:" << endl;
    cout << "1 Leer DFA" << endl;
    cout << "2 Mostrar DFA." << endl;
    cout << "3 Mostrar estados de muerte." << endl;
    cout << "4 Analizar cadena." << endl;
    cout << "5 Minimizar DFA" << endl;
    cout << "6 Exportar el DFA mínimo" << endl;
    cout << "7 Salir."<< endl;
    cout << "Introduzca una opción: ";
    cin >> opcion;

    switch(opcion)
    {
      case 1:
        DFA.leer_dfa();
      break;
      case 2:
        
        if(minimo)
        {
          DFA_B.mostrar_dfa();
        }
        else
        {
          DFA.mostrar_dfa();
        }
        break;
      case 3:
        if(minimo)
        {
          DFA_B.estados_de_muerte();
        }
        else
        {
          DFA.estados_de_muerte();
        }
        break;
      case 4:
        DFA.analizar_cadena();
        break;;
      case 5: 
        DFA.minimizar_dfa(DFA_B);
        minimo = true;
      break;
      case 6:
        if(minimo)
        {
          DFA_B.exportar_dfa();
        }
        else
        {
          cout << "Primero debe minimizar el DFA" << endl;
        }
      break;
      case 7: 
      return 0;
      break; 
      default:
        cout << "Opción incorrecta." <<endl;
        break;
    }
  }while(opcion!=7);
} 