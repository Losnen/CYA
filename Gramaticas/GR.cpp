#include "GR.hpp"


    GR_t::GR_t(dfa_t A)
    {
        //Construccion set de terminales
        set <estado_t> estados = A.get_estados();
        
        for (set <estado_t>::iterator i= estados.begin(); i != estados.end(); i++)
        {
            estado_t estado = (*i);
            set <transicion_t> transiciones = estado.get_transiciones();
            
            for (set<transicion_t>::iterator j= transiciones.begin(); j != transiciones.end(); j++)
            {
                transicion_t trans = (*j);
                terminales_.insert(trans.get_char());
            }
        }
        
        //Construccion de no terminales
        no_terminales_[0] = 'S';
        int k = 1;
        char simb = 'A';
       
        while((simb <= 'Z') && k < (estados.size()))
        { 
            if(simb != 'S')
            { 
                no_terminales_[k] = simb;
            }
             simb++;
             k++;
        }
        
        for (set <estado_t>::iterator j= estados.begin(); j != estados.end(); j++)
        {
            estado_t estado = (*j);
            set <transicion_t> transiciones = estado.get_transiciones();
            for (set<transicion_t>::iterator k= transiciones.begin(); k != transiciones.end(); k++)
            {
                transicion_t trans = (*k);
                producciones_.insert(make_pair(make_pair(no_terminales_[estado.get_identificador()],trans.get_char()),no_terminales_[trans.get_siguiente()]));
                
            }
        }
        
    }
    
    GR_t::~GR_t(void)
    {}
    
    void GR_t::exportar_GR(char* output_file, dfa_t A)
    {
        //char nombre[80];
        //cout << "Introduzca el nombre del fichero .grm a exportar: "; 
        //cin >> nombre;
        ofstream salida(output_file); 
        int aux=0;

        set <estado_t> estados = A.get_estados();
        
        salida << terminales_.size() << endl;
        for (set <char>::iterator i= terminales_.begin(); i != terminales_.end(); i++)
        {
            salida << (*i) << " ";
        }
        salida << endl;
        salida << no_terminales_.size() << endl;
        
        for(int i=0; i<no_terminales_.size(); i++)
        {
            salida << no_terminales_[i] << " "; 
        }
        salida << endl;
        
        for (set <estado_t>::iterator j= estados.begin(); j != estados.end(); j++)
        {
            estado_t estado = (*j);
            salida << no_terminales_[estado.get_identificador()] << "-> ";
            set <transicion_t> transiciones = estado.get_transiciones();
            for (set<transicion_t>::iterator k= transiciones.begin(); k != transiciones.end(); k++)
            {
                transicion_t trans = (*k);
                salida <<trans.get_char() << no_terminales_[trans.get_siguiente()] << " | ";
                aux++;
                if(estado.aceptacion() && aux == transiciones.size())
                {
                    salida << "~ ";
                }
                
            }
            aux=0;
            salida << endl;
        }
        
        
        salida.close();
    }