#include <iostream>
#include <fstream>
#include <stdio.h>
#include <set>
#include "transicion.hpp"

using namespace std;
class estado{
    
    friend ostream &operator<<(std::ostream &, const estado &);
    
private:
    unsigned int identifier_;
    bool inicial_;
    bool final_;
    unsigned int ntransiciones_;
    set<transicion> posts_;
public:
    //Constructores y destructor
    estado();
    ~estado();
    estado(const estado &copyin);
    
    //Semiconstructores
    void cargar(unsigned int id, bool ini, bool fin, unsigned int nt, set<transicion> trransiciones);
    void charge(unsigned int id, bool ini, bool fin, ifstream &fich);
    
    //Funciones propias
    void print();
    void identify_death();
    
    //Geters
    unsigned int get_identifier(void);
    bool get_final(void);
    bool get_inicial(void);
    unsigned int get_ntransiciones(void);
    set<transicion> get_posts(void);
    int get_siguiente(char c);
    
    //Geters constantes
    unsigned int get_identifier(void) const;
    bool get_final(void) const;
    bool get_inicial(void) const;
    unsigned int get_ntransiciones(void) const;
    set<transicion> get_posts(void) const;
    
    
    //Sobrecarga de operadores
    estado &operator=(const estado &rhs);
    int operator==(const estado &rhs) const;
    int operator<(const estado &rhs) const;
};