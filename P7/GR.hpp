/**
 * @file   .hpp
 * @Author Samuel Ramos Barroso (alu0100815146@ull.edu.es)
 * @date   November, 2015
 * @brief  Gramática asociada a un DFA.
 *
 * GRM.
 */
#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>


#include "estado_t.hpp"
#include "transicion_t.hpp"
#include "dfa_t.hpp"

using namespace std;

class GR_t {

private:

    set<char> terminales_;
    map<int,char> no_terminales_;
    map <pair <char,char>, char> producciones_;
-
public:

    GR_t(dfa_t A);
    ~GR_t(void);
    
    void exportar_GR(char*, dfa_t A);
};