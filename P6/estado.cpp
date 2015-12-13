#include "estado.hpp"

estado::estado(): 
    identifier_(0),
    inicial_(false),
    final_(false),
    ntransiciones_(0),
    posts_()
{}

estado::estado(const estado &copyin):
    
    identifier_(copyin.identifier_),
    final_(copyin.final_),
    ntransiciones_(copyin.get_ntransiciones()),
    posts_(copyin.get_posts())

{}

estado::~estado(){}

//-----------------------Semiconstructores
void estado::cargar(unsigned int id, bool ini, bool fin, unsigned int nt, set<transicion> trransiciones){
    identifier_ = id;
    inicial_ = ini;
    final_ = fin;
    ntransiciones_ = nt;
    posts_ = trransiciones;
}
    
void estado::charge(unsigned int id, bool ini, bool fin, ifstream &fich){
    identifier_ = id; 
    inicial_ = ini;
    final_ = fin;
    char c;
    unsigned int sig;
    transicion aux;
    fich >> ntransiciones_;
    posts_.clear();
    for (int i = 0; i < ntransiciones_; i++){
        fich >> (char &) c >> (unsigned int &) sig;
	    aux.cargar(c, sig);
        posts_.insert(aux);
    }
}
    
//-----------------------Funciones propias    
void estado::print(){
    cout << identifier_ << " " << final_ << " " << ntransiciones_;
    for(set <transicion>::iterator i = posts_.begin(); i != posts_.end(); i++){
        transicion tmp;
	    tmp = (*i);
	    tmp.print();
    }
    cout << endl;
}
    
void estado::identify_death(){
    bool dead = true;
    for(set <transicion>::iterator i = posts_.begin(); i != posts_.end(); i++){
        if(identifier_ != (*i).get_siguiente())
        dead = false;
    }
    cout << "El estado Q" << identifier_;
    if(!dead)
    cout << " no";
    cout << " es un estado de muerte." << endl;
}

//-----------------------Sobrecarga de operadores
int estado::operator==(const estado &rhs) const{
    if (this->get_identifier() != rhs.get_identifier()) return 0;
    return 1;
}

int estado::operator<(const estado &rhs) const{
    if (this->get_identifier() < rhs.get_identifier()) return 1;
    return 0;
}

estado& estado::operator=(const estado &rhs){
    this->identifier_ = rhs.get_identifier();
    this->ntransiciones_ = rhs.get_ntransiciones();
    this->final_ = rhs.get_final();
    this->posts_= rhs.get_posts();
    return (*this);
}

std::ostream &operator<<(ostream &output, const estado &bbb){
    output << bbb.get_identifier() << " " <<  bbb.get_final() << " " << bbb.get_posts().size() << " ";
    
    for(set <transicion>::iterator i=bbb.get_posts().begin(); i!=bbb.get_posts().end(); i++){
        output << (*i);
    }
    
    return output;
}

//------------------------Geters constantes
set<transicion> estado::get_posts() const{
    return posts_;
}

unsigned int estado::get_identifier(void) const{
    return identifier_;
}
    
bool estado::get_final(void) const{
    return final_;
    
}
    
bool estado::get_inicial(void) const{
    return inicial_;
}
    
unsigned int estado::get_ntransiciones(void) const{
    return ntransiciones_;
}

//-------------------------Geters    
unsigned int estado::get_identifier(void) {
    return identifier_;
}
    
bool estado::get_final(void) {
    return final_;
}
    
bool estado::get_inicial(void) {
    return inicial_;
}
    
unsigned int estado::get_ntransiciones(void) {
    return ntransiciones_;
}
    
set<transicion> estado::get_posts() {
    return posts_;
}

int estado::get_siguiente(char c){
    for(set<transicion>::iterator i = posts_.begin(); i != posts_.end(); i++){
        transicion tmp = (*i);
        if(tmp.get_caracter() == c)
        return tmp.get_siguiente();
    }
}