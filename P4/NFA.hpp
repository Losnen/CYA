#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#include "state.hpp"
class NFA_t
{
  private:
    set <state_t> estados_;
    state_t estado_inicial_;
  public:
    NFA_t(void);
    ~NFA_t(void);
    
    void analizar_cadena_recursivo(int &n, char cadena [], int i, const stringbuf &buffer, const ostream &os, state_t estado, bool &baux);
    
    int get_n_estados(void);
    int get_n_estados(void) const;
    
    state_t get_inicial(void);
    state_t get_inicial(void) const;
    
    set<state_t> get_estados(void) const;

    void mostrar_estados_muerte(void);
    bool leer_fichero(void);
    void mostrar(void);
    void analizar_cadena(void);
    state_t get_state(const int x);
  private:
    friend ostream &operator<<(ostream &, const NFA_t &);
};