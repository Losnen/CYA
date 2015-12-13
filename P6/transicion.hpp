
#include <iostream>
using  namespace std;


class transicion{
    
    private:
        char caracter_;
        int next_;
        
        
    public:
    
    transicion();
    ~transicion();
     transicion(const transicion &copyin);
    
    void cargar(char c, unsigned int sig);
    bool puedo_navegar(char c);
    unsigned int navegar();
    void print();
    
    char get_caracter();
    int get_siguiente();
     
    char get_caracter() const;
    int get_siguiente() const;
    
   
    
    transicion& operator=(const transicion &x);
    int operator<(const transicion &x) const;
    private:
    friend ostream &operator<<(ostream &, const transicion &);
};
