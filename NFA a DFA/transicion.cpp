#include "transicion.hpp"    
    
    
    transicion::transicion():
        caracter_(0),
        next_(-1)
    {}
    transicion::~transicion(){
    }
    
    void transicion::cargar(char c, unsigned int sig){
        caracter_ = c;
        next_ = sig;
    }
    
    bool transicion::puedo_navegar(char c){
        if(caracter_ == c || caracter_ == '~'){
            return true;
        }else{
            return false;
        }
    }
 
    void transicion::print(){
      cout << " " << caracter_ << " " << next_;
      
    }
    
    int transicion::get_siguiente(){
        
        return next_;
    }
    
    char transicion::get_caracter(){
        
        return caracter_;
    }
    
    int transicion::get_siguiente() const
     {
        
        return next_;
    }
    
    char transicion::get_caracter() const
    {
        
        return caracter_;
    }
    ostream& operator<<(ostream &output, const transicion &x)
    {
        output<<" "<<x.get_caracter()<<" "<<x.get_siguiente();
        return(output);
    }
    
    transicion& transicion::operator=(const transicion &x){
        this->caracter_ = x.get_caracter();
        this->next_ = x.get_siguiente();
        return(*this);
    }
    
    int transicion::operator<(const transicion &x) const
    {
        if(this->get_caracter()==x.get_caracter() && this->get_siguiente() < x.get_siguiente())
            return 1;
        if(this->get_caracter() < x.get_caracter()) 
            return 1;
        return 0;
    }
    
    transicion::transicion(const transicion &copyin):
    
    caracter_(copyin.caracter_),
    next_(copyin.next_)

{}
