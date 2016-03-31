#include <stdio.h>
#include <ostream>
#include <iostream>

#include "heroe.hpp"
#include "mazmorra.hpp"
#include "amuleto.hpp"
#include "monstruo.hpp"


using namespace std;
class tablero_t
{
    private:
    
    char*	M_;	
    int  	m_;	
	int	    n_;
	heroe_t h_;
    amuleto_t a_;
    monstruo_t m1_;
    monstruo_t m2_;
    monstruo_t m3_;
    monstruo_t m4_;
    monstruo_t m5_;
    monstruo_t m6_;
    monstruo_t m7_;
    monstruo_t m8_;
    monstruo_t m9_;
    mazmorra_t z1_;
    mazmorra_t z2_;
    mazmorra_t z3_;
    
    public:
    
    tablero_t(int m, int n, int x, int y, int vidas, bool amuleto, int c, int v);
    ~tablero_t(void);
    int get_m(void);
    int get_n(void);
    void set_item(int i, int j, char item);
    char get_dato(int i, int j);
    void mostrar(void);
    void rellenar(void);
    void redimensionar(int m, int n);
    void perder_vida(void);
 
    void mover(char op);

    
    
    private:  
    int pos(int i, int j);
    void creartablero();
    void destruirtablero(void);
};