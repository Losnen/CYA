/**
 * @file   MT.hpp
 * @Author Samuel Ramos Barroso (alu0100815146@ull.edu.es)
 * @date   November, 2015
 * @brief  Clase que simula una máquina de Turing
 */
#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class MT
{
  private:
  
    int num_estados; //Numero de estados
    int arranque; //estado de inicio
    string prim_final; //conjunto de estados finales
    int num_uplas; //numero de uplas
    string* M_uplas; //vector de uplas
    void camb_vec(std::vector<string>& cad); //Función que hace que el vector sea infinito.
    
  public:
  
    MT(char* nombre); 
    ~MT(void);
    void leer_MT(char nombre[]);
    void mostrar(void);
    void simular(string tape);
};