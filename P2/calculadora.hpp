#include <set>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <string.h>
#include <iterator>  



using namespace std; 

class calculadora_t
{
    private:
    
    set<string> L1_;
    set<string> L2_;
    
    public:
    
    calculadora_t(vector<string> A, int a, vector<string> B, int b);
    ~calculadora_t(void);
    void potencia(int n, int a);
    set<string> potencia_(set<string> Set1, set<string> Set2);
    void inversa(int a);
    void concatenacion(void);
    void union_(void);
    void interseccion(void);
    void diferencia(void);
    bool sublenguajes(void);
    bool igualdad_lenguajes(void);
    
    void print(set <string> C);
    
};