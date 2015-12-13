#include <stdio.h>
#include <iostream>

using namespace std;
class estado_t {
    
    friend std::ostream &operator<<(std::ostream &, const estado_t &);
    
    
    
public:
    
    unsigned int id_;           // atributos privados añadir get/set?
    bool aceptado_;               
    unsigned int transiciones_;  
    char *simbolo_;              
    int *destino_;              
    
    estado_t();
    estado_t(int, bool, int, char*, int*);
    estado_t(const estado_t &);
    
    virtual ~estado_t(void);

    estado_t &operator=(const estado_t &rhs);
    int operator==(const estado_t &rhs) const;
    int operator<(const estado_t &rhs) const;

};


