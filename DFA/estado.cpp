#include "estado.hpp"

/*
    Constructor por defecto
*/
estado_t::estado_t(void):
    id_(0),
    aceptado_(false),
    transiciones_(0),
    simbolo_(NULL),
    destino_(NULL)
    {}

 estado_t::estado_t(int id, bool aceptado, int transitions, char* simbolo, int* destino):
    id_(id),
    aceptado_(aceptado),
    transiciones_(transitions),
    simbolo_(NULL),
    destino_(NULL)
    {
        simbolo_ = new char[transiciones_];
        destino_ = new int[transiciones_];
        
        for(int i = 0; i< transiciones_; i++)
        {
            simbolo_[i] = simbolo[i];
            destino_[i] = destino[i];
        }
        
        if ((simbolo_ == NULL) || (destino_ == NULL))
        {
            std::cout << "Error reservando memoria" << std::endl;
        }
    }
    
estado_t::estado_t(const estado_t &copyin)
{
    
    id_ = copyin.id_;
    aceptado_ = copyin.aceptado_;
    transiciones_ = copyin.transiciones_;
    simbolo_ = copyin.simbolo_;
    destino_ = copyin.destino_;

}

estado_t::~estado_t(void)
{}

int estado_t::operator==(const estado_t &rhs) const
{
    if (this->id_ != rhs.id_) return 0;
    if (this->aceptado_ != rhs.aceptado_) return 0;
    if (this->transiciones_ != rhs.transiciones_) return 0;
    for (int i = 0; i < transiciones_; i++)
    {
        if (simbolo_[i] != rhs.simbolo_[i]) return 0;
        if (destino_[i] != rhs.destino_[i]) return 0;
    }
    
    return 1;
}

int estado_t::operator<(const estado_t &rhs) const
{
    if (this->id_ < rhs.id_) return 1;
    return 0;
}

estado_t& estado_t::operator=(const estado_t &rhs)
{
    this->id_ = rhs.id_;
    this->aceptado_ = rhs.aceptado_;
    this->transiciones_ = rhs.transiciones_;

    simbolo_ = new char[transiciones_];
    destino_ = new int[transiciones_];

    for (int i = 0; i < transiciones_; i++)
    {

        simbolo_[i] = rhs.simbolo_[i];
        destino_[i] = rhs.destino_[i];
    }
    

    return *this;
}

std::ostream &operator<<(std::ostream &output, const estado_t &bbb)
{
    output << bbb.id_ << " " <<  bbb.aceptado_ << " " << bbb.transiciones_ << " ";
    
    for (int i = 0; i < bbb.transiciones_; i++)
    {
        output << bbb.simbolo_[i] << " " << bbb.destino_[i] << " ";
    }
    
    std::cout << std::endl;
    
    return output;
}

