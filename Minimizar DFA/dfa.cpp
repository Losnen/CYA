#include "dfa.hpp"
#include <cstring>

#define NAME_SIZE 50

dfa_t::dfa_t(void):
    estados_(),
    estado_inicial_()
{}

dfa_t::dfa_t(const dfa_t &cp):
    estados_(cp.get_estados()), 
    estado_inicial_(cp.get_estado_inicial())
{}

estado_t dfa_t::get_estado_inicial(void) const
{
    return estado_inicial_; 
}


set<estado_t> dfa_t::get_estados(void) const
{
    return estados_;
}
 
void dfa_t::leer_dfa(void)
{
    char fichero[80];
    cout << "Introduzca el nombre del fichero a leer: ";
    cin >> fichero;
    ifstream file;
    file.open(fichero);
    if (file.is_open())
    {
        if(!estados_.empty())
		  estados_.erase(estados_.begin(),estados_.end());
    int n_estados_;
    int auxa;
    bool auxb;
    char auxc;
    int auxd;
    file >> (int &) auxa;
    n_estados = auxa; 
    n_estados_ = auxa;
    file >> (int &) auxa;
    int estado_inicial = auxa;
    for(int i=0; i<n_estados_; i++)
    {
      int sz;
      file >> (int &) auxd;
      file >> (bool &) auxb >> (int &) auxa;
      sz=auxa;
      set<transicion_t> transiciones;
      for(int j=0; j<sz; j++)
      {
        file>>(char &) auxc>>(int &) auxa;
        if(auxc != '~')
        {
            alfabeto_.insert(auxc);
        }
        transicion_t aux(auxc,auxa); 
        transiciones.insert(aux);
      }
      estado_t tmp(auxb,auxd,transiciones);
      estados_.insert(tmp);
      if(auxd==estado_inicial)
      {
        estado_inicial_=get_estado(auxd);
      }
    }
    file.close();
  }
  else
  {
    cout<<"Error en la apertura del fichero."<<endl;
    
  }
 
  
}

dfa_t::~dfa_t(void)
{}

void dfa_t::mostrar_dfa(void)
{
    cout<< estados_.size() <<endl;
    cout<< estado_inicial_.get_identificador() <<endl;
    for(set<estado_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
    {
        (*i).mostrar();
        cout << endl;
    }

}

void dfa_t::estados_de_muerte(void)
{
    for(set<estado_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
        if((*i).estado_muerte())
            cout<<"q"<<(*i).get_identificador()<<" es un estado de muerte."<<endl;
  
  cout<<"q"<<estados_.size()<<" es un estado de muerte."<<endl;
}

estado_t dfa_t::get_estado(int x)
{
    for(set<estado_t>::iterator i=estados_.begin(); i!=estados_.end(); i++)
        if((*i).get_identificador()==x)
            return(*i);
  cout<<x<<endl;
  cout<<"Estado no encontrado."<<endl;
}

void dfa_t::analizar_cadena(void)
{
    
      char analyze_chain[80];
    
    cout << "Cadena de entrada: ";
    cin >> analyze_chain;
    cin.ignore();
    
    int current_state = estado_inicial_.get_identificador(); 
    int next_state = estado_inicial_.get_identificador();
    bool aceptado;
    
    cout << "Estado Actual\tEntrada\t\tSiguiente estado" << endl;
    
    for (int j = 0; j < strlen(analyze_chain); j++)
    {
        current_state = next_state;
        
        for (set<estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
        {
            estado_t aux;
            aux=(*i);
            
            if (aux.get_identificador() == current_state)
            {
                for (set<transicion_t>::iterator k = aux.get_transiciones().begin(); k != aux.get_transiciones().end(); k++)
                {
                    transicion_t trans;
                    trans = (*k);
                    if(analyze_chain[j] == trans.get_char())
                    {   
                        next_state = trans.get_siguiente();
                    }
                }
            }
        }
        cout << current_state << "\t\t" << analyze_chain[j] << "\t\t" << next_state << endl;
    }
    
    for (set<estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
    {
        estado_t aux;
        aux = (*i);
        
        if (aux.get_identificador() == next_state)
        {
            aceptado = aux.aceptacion();
        }
    }
    
    if(aceptado == true)
    {
        cout << "Cadena ACEPTADA." << endl;
    }
	else
	{
		cout << "Cadena NO ACEPTADA." << endl;
	}
}






void dfa_t::minimizar_dfa(dfa_t& dfa_minimizado)
{
set< set<estado_t> > Pi;
set< set<estado_t> > Piantiguo;
set<estado_t> conjunto1;
set<estado_t> conjunto2;
int contador = 1;
 for (set<estado_t> ::iterator i= estados_.begin(); i != estados_.end(); i++)
 {
    estado_t state = *i;
    if(state.aceptacion()) 
    conjunto1.insert(state);
    else conjunto2.insert(state);
 }


Pi.insert(conjunto1);
Pi.insert(conjunto2);
    
    cout<<"P0:{";
    for (set< set<estado_t> > ::iterator i= Pi.begin(); i != Pi.end(); i++)
    {
        set<estado_t> conjunto = *i;
        cout<<"{";
        for (set<estado_t> ::iterator j = conjunto.begin(); j != conjunto.end(); j++)
        {
         estado_t st = *j;
        set<estado_t> ::iterator l = j;
        cout<< st.get_identificador()<<",";
    }
    cout<<"} ";
 

}
    cout<<"}"<<endl;
        while(!(Pi==Piantiguo)) 
    {

        Piantiguo = Pi;
        Pi = crear_nueva_particion(Piantiguo,contador);
    }
  
  int cont = 0;
    for (set< set<estado_t> > ::iterator i= Pi.begin(); i != Pi.end(); i++) cont++;
    cout<<endl;
    cout<<"El DFA mínimo tiene "<< cont << " estados"<<endl;
    dfa_minimizado.construir_dfa(Pi, estado_inicial_,cont);
	
}



set< set<estado_t> > dfa_t:: crear_nueva_particion(set< set<estado_t> > Piviejo, int& contador){

    set< set<estado_t> > Pi ;
    set< set <estado_t> > Estado;
    for(set<set<estado_t> >:: iterator i = Piviejo.begin(); i!=Piviejo.end(); i++)
    {
    set<estado_t> state = (*i);
         Estado = descomp(state,Piviejo,contador);
         Pi.insert(Estado.begin(), Estado.end());
    }  
    
    return Pi;
    

}


set< set<estado_t> > dfa_t:: descomp(set<estado_t> conjunto, set< set<estado_t> > Piantiguo, int& contador )
{
    set< set<estado_t> > T ;
    T.insert(conjunto);


     set< set<estado_t> >  aux2;
    for(set<char> :: iterator i =alfabeto_.begin(); i!=alfabeto_.end(); i++)
    {
         set< set<estado_t> > estado_aux;
         char caracter = *i;
        for(set< set<estado_t> >:: iterator j = T.begin(); j!=T.end(); j++)
        {
             aux2 = part((*j), caracter, Piantiguo);
            estado_aux.insert(aux2.begin(), aux2.end());
        }
   T = estado_aux;

  imprimirconjunto(T, contador,caracter, conjunto, Piantiguo);
    }
    return T;
}


set <set<estado_t> >dfa_t::part(set<estado_t> G, char simbolo, set <set<estado_t> > Piantiguo)
{    set< set<estado_t> >  T ;

    for (set<set<estado_t> >::iterator h = Piantiguo.begin(); h != Piantiguo.end(); h++)
    {
        set <estado_t> H = *h;
        set<estado_t> state;

   for( set <estado_t>::iterator g = G.begin(); g!=G.end(); g++)
   {
        estado_t aux1 = (*g);
        for(set<estado_t>::iterator l = H.begin();  l!= H.end(); l++)
        {
             estado_t aux2 = (*l);
            if(aux1.get_siguiente(simbolo) == aux2.get_identificador())
            state.insert(aux1);

        }

   }
 
    if(state.empty() == false) 
        T.insert(state);

    }


    return T;
}



void dfa_t:: imprimirconjunto(set< set<estado_t> > particion, int& contador, char caracter, set<estado_t> G, set< set<estado_t> > Pi)
{
    cout<<"Con el símbolo '"<<caracter<<"':"<<endl;
    cout<<"P"<<contador<<":{";
    for (set< set<estado_t> > ::iterator i= particion.begin(); i != particion.end(); i++)
    {
        set<estado_t> conjunto = *i;
        cout<<"{";
        for (set<estado_t> ::iterator j = conjunto.begin(); j != conjunto.end(); j++)
        {
            estado_t st = *j;
            cout<< st.get_identificador()<<",";
        }
        cout<<"} ";
    }

    for (set< set<estado_t> > ::iterator i= Pi.begin(); i != Pi.end(); i++)
    {
        set<estado_t> conjunto = *i;
        if(conjunto !=G)
        {
            cout<<"{";
            for (set<estado_t> ::iterator j = conjunto.begin(); j != conjunto.end(); j++)
            {
                estado_t st = *j;
                cout<< st.get_identificador()<<",";
            }
            cout<<"} ";
        }
        
    }
    cout<<"}"<<endl;
 
    contador++;
}


void dfa_t::exportar_dfa(void)
{
    char nombre[80];
    cout << "Introduzca el nombre del fichero .dfa a exportar: "; 
    cin >> nombre;
    ofstream salida(nombre); 

   salida << estados_.size() << endl;
   salida << estado_inicial_.get_identificador() << endl;
   for(set <estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++){
	    estado_t aux;
	    aux = (*i);
	    salida << aux.get_identificador() << " " << aux.aceptacion() << " " << aux.get_transiciones().size();
	   	set<transicion_t>::iterator j = aux.get_transiciones().begin();
	   	for(int k = 0; k < aux.get_transiciones().size(); k++){
        	transicion_t auxt;
	    	auxt = (*j);
	    	salida << " " << auxt.get_char() << " " << auxt.get_siguiente();
	    	j++;
    	}
    	salida << endl;
      
    }
   salida.close();
}

    

void dfa_t:: construir_dfa(set< set<estado_t> > Pi, estado_t estado_arranque, int cont )
{
int contador = estado_arranque.get_identificador(); 

estado_inicial_.set_identificador(estado_inicial_.get_identificador());
n_estados = cont;
	
for (set< set<estado_t> > ::iterator i= Pi.begin(); i != Pi.end(); i++)
{
	set<estado_t> conjunto = *i;
	set<estado_t> :: iterator j = conjunto.begin();
	estado_t auxiliar = (*j);
	estado_t state;
	state.set_identificador(contador);
	state.set_transicion(auxiliar.get_transicion());
	bool booleano = false;
	for ( set<estado_t>  ::iterator j= conjunto.begin(); j != conjunto.end(); j++)
	{
		estado_t e = *j;
		if(e.get_tipo_estado())
		booleano = true;
		
	}
	
	state.set_tipo_estado(booleano);
	
	set<transicion_t> cjto = auxiliar.get_cjtotransicion();
	for (set< transicion_t> ::iterator k= cjto.begin(); k!= cjto.end(); k++)
	{
			transicion_t tran = *k;
			transicion_t aux;
			int  count = estado_arranque.get_identificador();
		for (set< set<estado_t> > ::iterator l= Pi.begin(); l != Pi.end(); l++)
		{
			set<estado_t> state2 = *l;
	
			for ( set<estado_t> ::iterator m= state2.begin(); m!= state2.end(); m++)
			{
				estado_t est = *m;
				if(est.get_identificador() == tran.get_siguiente()) 
				{ aux.set_transicion(tran.get_char(), count);
				break;
				    
				}
		
		
	        }   
		 count++;
	
	
	    }
    	state.insert_transicion(aux);
	}
	estados_.insert(state);
	contador++;
    }
}   