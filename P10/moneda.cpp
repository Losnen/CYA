//
//  moneda.cpp
//  P10
//
//  Created by Samuel Ramos barroso on 30/11/15.
//  Copyright © 2015 Samuel Ramos barroso. All rights reserved.
//
//  Compile: g++ -std=c++11 -o Greedy  moneda.cpp
//

#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int mayor(int sum, int n, const vector<int> &monedas,int pos)
{
    int v = -1;
    for(int i = pos; i < monedas.size();i++)
    {
        if((sum + monedas[i]) <= n)
        {
            v=i;
            break;
        }
    }
    return v;
}

vector<int> devolver_cambio(int n, bool &nosol, const vector <int> &monedero)
{
    int suma = 0;
    int pos = 0;
    vector<int> solucion(monedero.size());
    
    while(suma < n)
    {
        pos = mayor(suma,n,monedero,pos);
        
        
        if(pos == -1)
        {
            cout << "No existe solución" << endl;
            nosol = false;
            break;
        }
        else
        {
            solucion[pos]++;
        }
        
        suma += monedero[pos];
    }
    
    
    return solucion;
}

void imprimir_solucion (vector<int> solucion,const vector <int> monedero)
{
    int aux = 0;
    for(int i = 0; i < solucion.size(); i++)
    {
        if (solucion[i] > 0)
        {
            aux = i;
        }
    }
    
    for(int i = 0; i < solucion.size(); i++)
    {
        if (solucion[i] > 0)
        {
            int pos = solucion[i];
            if (pos == 1)
            {
                if(monedero[i] <= 50)
                {
                    cout << monedero[i] << "¢";
                }
                else
                {
                    cout << monedero[i] / 100 <<"€";
                }
            }
            else
            {
                if(monedero[i] <= 50)
                {
                    cout << solucion[i] << "x"<< monedero[i] << "¢";
                }
                else
                {
                    cout << solucion[i] << "x" << monedero[i] / 100 <<"€";
                }
            }
            
            if(i !=  aux)
                cout << ",";
        }
        
    }
}

/*

vector<int> devolver_cambio(int n)
{
    int valores [] = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};
    vector <int> monedero (valores, valores + sizeof(valores) / sizeof(int) );
    int suma = 0;
    int v = 0;
    vector<int> solucion;
    
    while(suma < n)
    {
        v = mayor(suma,n,monedero);
        
        if(v == 0)
        {
            cout << "No existe solución" << endl;
        }
        else
        {
            solucion.push_back(v);
        }
        
        suma += v;
    }
    
    
    return solucion;
}

void imprimir_solucion (vector<int> solucion)
{
    for(int i = 0; i < solucion.size(); i++)
    {
        if(solucion[i] <= 50)
        {
            cout << solucion[i] << "¢";
        }
        else
        {
            cout << solucion[i] / 100 <<"€";
        }
        
        if(i != (solucion.size()-1))
            cout << ",";
    }
}
*/

int main(void)
{
    int n = -1;
    bool existe = true;
    float cantidad;
    const vector <int> monedero = {50000,20000,10000,5000,1000,500,200,100,50,20,10,5,2,1};
    
    while (n != 0)
    {
      
        cout << "Práctica 10 Computabilidad y Algoritmia: Algoritmos Voraces (Greedy)" << endl;
        cout << "Algoritmo de la moneda (Pulse 0 para salir)" << endl;
        cout << "Introduzca la cantidad n: ";
        cin >> cantidad;
        n = (int) ceil(cantidad * 100);
        
        vector<int> solucion = devolver_cambio(n,existe,monedero);
        
        if(existe == true)
        {
            cout << "S={";
            imprimir_solucion(solucion,monedero);
            cout << "}" << endl;
        }
        existe = true;
    }
}