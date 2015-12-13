#pragma once

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

#include "estado.hpp"
using namespace std;
class dfa_t {

private:
    
    unsigned int num_estados_;
    unsigned int estado_inicial_;
    set <estado_t> estados_;
    

public:
    
    dfa_t(char file_name[]);
    ~dfa_t(void);
    
    void leer_dfa(char file_name[]);
    void mostrar_dfa(void);
    void estados_de_muerte(void);
    void analizar_cadena(void);
};