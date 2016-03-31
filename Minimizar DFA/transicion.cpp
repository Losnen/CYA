#include "transicion.hpp"   
   
    transicion_t::transicion_t(void):
        caracter_(0),
        siguiente_(-1)
    {}
    
    transicion_t::transicion_t(const transicion_t &cp)
    {
        this->caracter_ = cp.get_char();
        this->siguiente_ = cp.get_siguiente();
    }
    
    transicion_t::transicion_t(char caracter, int siguiente):
        caracter_(caracter),
        siguiente_(siguiente)
    {}
    
    transicion_t::~transicion_t(void)
    {}
    
    char transicion_t::get_char(void)
    {
        return caracter_;
    }
    
    int transicion_t::get_siguiente(void)
    {
        return siguiente_;
    }
    
    char transicion_t::get_char(void) const
    {
        return caracter_;
    }
    
    int transicion_t::get_siguiente(void) const
    {
        return siguiente_;
    }
    
    void transicion_t::mostrar(void)
    {
        cout<<" "<<caracter_<<" "<<siguiente_;
    }
    
    void transicion_t::mostrar(void) const
    {
        cout<<" "<<caracter_<<" "<<siguiente_;
    }
    
    transicion_t& transicion_t:: operator=(const transicion_t &x)
    {
        this->caracter_= x.get_char();
        this->siguiente_=x.get_siguiente();
         return(*this);
    }
    
    int transicion_t::operator<(const transicion_t &x) const
    {
        if(this->get_char()==x.get_char()&&this->get_siguiente()<x.get_siguiente())
            return(1);
        if(this->get_char()<x.get_char())
            return(1);
        return 0;
    }
    
    ostream &operator<<(ostream &output, const transicion_t &x)
    {
        output << " " << x.get_char() << " " << x.get_siguiente();
        
        return output;
    }

    void transicion_t:: set_transicion( char simb,  int siguiente)
    {

     caracter_= simb;
     siguiente_= siguiente;
    }
