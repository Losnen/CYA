#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
#include "transicion.hpp" 
#include "estado.hpp"

using namespace std;

class dfa_t {

private:
    
    estado_t estado_inicial_;
    set <estado_t> estados_;
    set <char> alfabeto_;
    int n_estados;
    
public:
    
    dfa_t(void);
    dfa_t(const dfa_t &cp);
    ~dfa_t(void); 
    
    estado_t get_estado(int x);
    estado_t get_estado_inicial(void) const;
    void leer_dfa(void);
    void mostrar_dfa(void);
    void estados_de_muerte(void);
    void analizar_cadena(void);
    void minimizar_dfa(dfa_t& dfa_minimizado);
    void exportar_dfa(void);
    void imprimirconjunto(set<set<estado_t> > C,int& contador,char caracter,set<estado_t> conjunto, set< set<estado_t> > Piantiguo);
    void construir_dfa(set< set<estado_t> > Pi, estado_t estado_arranque, int cont);
    set< set<estado_t> > crear_nueva_particion(set< set<estado_t> > Piviejo, int& contador);
    set< set<estado_t> > descomp(set<estado_t> conjunto, set< set<estado_t> > Piantiguo, int& contador);
    set<set<estado_t> > part(set<estado_t> G, char simbolo, set<set<estado_t> > viejo);  

    set<estado_t> get_estados(void) const;
};