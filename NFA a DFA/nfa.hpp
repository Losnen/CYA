
#include <set>
#include <fstream>
#include <vector>
#include <stack>
#include "estado.hpp"
using namespace std;

class nfa{
    private:
    unsigned int n_est_;
    unsigned int ini_est_;
    set<estado> estados_;
    vector<char> abecedario;
    int nchar_;
    
    public:
    
    //Constructor y destructor
    nfa();
    nfa(char nombre[]);
    ~nfa();
    
    //Semiconstructor
    void cargar(char cadena[]);
    
    //Geters
    estado estadoinicial();
    estado estadon(unsigned int x);
    
    //Métodos propios
    void descargar(char* output);
    void print();
    void identify_death();
    void analize(char cadena[]);
    set<estado> eclausura(set<estado> C);
    set<estado> epsclausura(set<estado> conjunto);
    
    //Métodos de minimización de DFAs
    void minimizar();
    set<set<estado> > crear_nueva_particion(set<set<estado> > conjunto_viejo);
    set<set<estado> > descomp(set<estado> G, set<set<estado> > conjunto);
    set<set<estado> > part(set<estado> G, char a, set<set<estado> > conjunto);
    void construir_DFA(set<set<estado> > conjunto);
    
    
    
    //void construir_DFA(set<set<estado> > conjunto);
    set<estado> megatransicion(set<estado> C, char a);
    void singlesetprint(set<estado> C);
    void setprint(set<set<estado> > C);
    bool marcado(set<set<estado> > marcas, set<estado> prob);
    set<estado> buscarT(set<set<estado> > conju, set<set<estado> > marcados);
    unsigned int get_n_estadodfa(set<set<estado> > dfaest, set<estado> ab);
    unsigned int get_n_estvect(vector<set<estado> > vect, set<estado> ab);
    bool alreadyin(vector<set<estado> > vect, set<estado> ab);
    void nfa2dfa(char* output);
    bool hasfin(set<estado> C);
    bool hasbegin(set<estado> C);
    
    void comprobarabc(char c);
    void rellenaabecedario();
    
    //Métodos auxiliares
    void mostraralfabeto();
};