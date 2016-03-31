#include "estado_t.hpp"

estado_t::estado_t(void):
    aceptacion_(0),
    identificador_(0),
    ntransiciones_(0),
    transiciones_()
  {}

estado_t::estado_t(const estado_t &cp):                     
  aceptacion_(cp.aceptacion()),
  identificador_(cp.get_identificador()),
  transiciones_(cp.get_transiciones())
  {}


estado_t::estado_t(bool aceptacion, int identificador, set<transicion_t> transiciones):
  aceptacion_(aceptacion),
  identificador_(identificador),
  transiciones_(transiciones)
  {}


estado_t::~estado_t(void)
{}

set<transicion_t> estado_t::get_transiciones(void) const
{
  return(transiciones_);
}


bool estado_t::aceptacion(void)
{
  return(aceptacion_);
}


bool estado_t::aceptacion(void) const
{
  return(aceptacion_);
}



bool estado_t::estado_muerte(void)
{
  if(aceptacion_)
    return(0);
  for(set <transicion_t>::iterator i=transiciones_.begin(); i!=transiciones_.end(); i++)
    if((*i).get_siguiente()!=get_identificador())
      return(0);
  return(1);
}

 
bool estado_t::estado_muerte(void) const
{
  if(aceptacion_)
    return(0);
  for(set <transicion_t>::iterator i=transiciones_.begin(); i!=transiciones_.end(); i++)
    if((*i).get_siguiente()!=get_identificador())
      return(0);
  return(1);
}

void estado_t::mostrar(void)
{
  cout<< get_identificador() << " " << aceptacion_ << " " << transiciones_.size();
  for(set <transicion_t>::iterator i=transiciones_.begin(); i!=transiciones_.end(); i++)
    (*i).mostrar();
}


void estado_t::mostrar(void) const
{
  cout<< get_identificador() << " " << aceptacion_ << " " << transiciones_.size();
  for(set <transicion_t>::iterator i=transiciones_.begin(); i!=transiciones_.end(); i++)
    (*i).mostrar();
}

int estado_t::get_identificador(void)
{
  return(identificador_);
}


int estado_t::get_identificador(void) const
{
  return(identificador_);
} 


ostream& operator<<(ostream &output, const estado_t &x)
{
  output<< x.get_identificador() << " " << x.aceptacion() << " "<< x.get_transiciones().size();
  for(set <transicion_t>::iterator i=x.get_transiciones().begin(); i!=x.get_transiciones().end(); i++)
    output << (*i);
  return(output);
}


int estado_t::operator<(const estado_t &x) const
{
  if(this->get_identificador() < x.get_identificador())
    return(1);
    
  return(0);
}


int estado_t::operator=(const estado_t& state)
{
	identificador_ = state.identificador_;
	aceptacion_ = state.aceptacion_;


	set <transicion_t> t = state.transiciones_;
		for (set<transicion_t> ::iterator j= t.begin(); j != t.end(); j++){
			transicion_t tran = *j;
			
		
		transiciones_.insert(tran);
		
		}

	return 1;
}



int estado_t:: get_siguiente(char c)
{
  
 for (set<transicion_t> ::iterator i= transiciones_.begin(); i != transiciones_.end(); i++)
 {
  transicion_t tran = *i;
  if(tran.get_char() == c) 
    return tran.get_siguiente();
  
 
  }
}

int estado_t::operator==(const estado_t& state) const 
{
 if(identificador_ == state.get_identificador()) return 1;
 return 0;

}

void estado_t::set_identificador(int n)
{
  
 identificador_ = n;

}

int estado_t:: get_transicion(void)
{
 return transiciones_.size();
}

void  estado_t:: set_transicion(int t)
{
 ntransiciones_ = t;

}

bool estado_t:: get_tipo_estado(void)
{

 return aceptacion_;
}

void estado_t:: set_tipo_estado(bool acep)
{
 aceptacion_ = acep;

}

set<transicion_t> estado_t:: get_cjtotransicion(void)
{

 return transiciones_;

}

void estado_t:: insert_transicion(transicion_t transit)
{

 transiciones_.insert(transit);
 
}