#include "DFA.hpp"
#include <cstring>

#define NAME_SIZE 50

dfa_t::dfa_t(char file_name[])
{
    fstream in;
    
    int identificador, transiciones;
    bool aceptacion;
    int *destino;
    char *simbolo;
    
    
    in.open(file_name);
    
    if (in.is_open())
    {
        in >> (int &) num_estados_ >> (int &) estado_inicial_;

        for (int i = 0; i < num_estados_; i++)
        {
            in >> identificador >> aceptacion >> transiciones;
            
            simbolo = new char[transiciones];
            destino = new int[transiciones];
            
            for (int j = 0; j < transiciones; j++)
            {
                in >> simbolo[j] >> destino[j];
            }
            
            estado_t tmp(identificador, aceptacion, transiciones, simbolo, destino);
            estados_.insert(tmp);
        }
    
    if (estados_.size() == num_estados_)
    {
        cout << " DFA correctamente cargado " << endl;
    }
    in.close();
}
}
 
void dfa_t::leer_dfa(char file_name[])
{
    fstream in;
    
    int identificador, transiciones;
    bool aceptacion;
    int *destino;
    char *simbolo;
    
    
    in.open(file_name);
    
    if (in.is_open())
    {
        in >> (int &) num_estados_ >> (int &) estado_inicial_;

        for (int i = 0; i < num_estados_; i++)
        {
            in >> identificador >> aceptacion >> transiciones;
            
            simbolo = new char[transiciones];
            destino = new int[transiciones];
            
            for (int j = 0; j < transiciones; j++)
            {
                in >> simbolo[j] >> destino[j];
            }
            
            estado_t tmp(identificador, aceptacion, transiciones, simbolo, destino);
            estados_.insert(tmp);
        }
    
    if (estados_.size() == num_estados_)
    {
        cout << "Correcto" << endl;
    }
    in.close();
}
}

dfa_t::~dfa_t(void)
{}

void dfa_t::mostrar_dfa(void)
{
    cout << endl;
    cout << "DFA definido:" << endl;
    
    cout << num_estados_ << endl;
    cout << estado_inicial_ << endl;
    
    for (set<estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
    {
        cout << (*i);
    }
}

void dfa_t::estados_de_muerte(void)
{
    bool existe = false;
    
    for (set<estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
    {
        int cont = 0;
        estado_t aux;
        aux = (*i);
       
        for (int j = 0; j < aux.transiciones_; j++ )
        {
            if (aux.destino_[j] == aux.id_)
            {
                cont++;
            }
            
        }
        
        if (cont == aux.transiciones_)
        {
            cout << "El estado " << aux.id_ << " es de muerte" << endl;
            existe = true;
        }
        
    }
    if(!existe)
    {
        cout << "No existen estados de muerte" << endl; 
    }

}

void dfa_t::analizar_cadena(void)
{
    char analyze_chain[80];
    
    cout << "Cadena de entrada: ";
    cin >> analyze_chain;
    cin.ignore();
    
    int current_state = estado_inicial_;
    int next_state = estado_inicial_;
    bool aceptado;
    
    cout << "Estado Actual\tEntrada\t\tSiguiente estado" << endl;
    
    for (int j = 0; j < strlen(analyze_chain); j++)
    {
        current_state = next_state;
        
        for (set<estado_t>::iterator i = estados_.begin(); i != estados_.end(); i++)
        {
            estado_t aux;
            aux=(*i);
            
            if (aux.id_ == current_state)
            {
                for(int k=0; k<aux.transiciones_; k++)
                {
                    if(analyze_chain[j] == aux.simbolo_[k])
                    {   
                        next_state = aux.destino_[k];
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
        
        if (aux.id_ == next_state)
        {
            aceptado = aux.aceptado_;
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