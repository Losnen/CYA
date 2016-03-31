#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemplo1(const int n)
{ 
    int suma = 0;
    for (int i = 1; i <= n; i++)        // O(n)
      for (int j = 1; j <= n; j *= 2)   // O(log n)
        for (int k = 1; k <= n; k++)    // O(n)
          suma++;
}

int ejemplo2(const int n)
{ 
    int suma = 0;
    for (int i = 1; i <= n - 1; i++)        //O(n - 1)
        for (int j = i + 1; j <= n; j++)    //O(i)
            suma++;
}




int main()
{ // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo 1: " << ejemplo1(n) << endl;
  cout << "Ejemplo 2: " << ejemplo2(n) << endl;
  return 0;
}