#include "tablero.hpp"
#include <iostream>

int main(void)
{
    tablero_t A(50,90, 7, 7, 5, false, 39, 31);
    A.rellenar();
    A.mostrar();
    
    char opcion;
    
    while (opcion != 's')
    {
        cin >> opcion;
        A.mover(opcion); 
        A.mostrar();
    }
}