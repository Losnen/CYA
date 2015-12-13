#include "calculadora.hpp"



    calculadora_t::calculadora_t(vector<string> A, int a, vector<string> B, int b)
    {
        for (int i=0; i<a; i++)
        {
		    L1_.insert(A[i]);
	    }
	
	    for (int i=0; i<b; i++)
	    {
		    L2_.insert(B[i]);
	    }
	
    }
    
    calculadora_t::~calculadora_t(void)
    {}
    
    void calculadora_t::potencia(int n, int a)
    {
        if(n == 0)
        {
            cout << "{&}" << endl; 
        }
        else
        {
            if(a==1)
            {
                set<string> C;
                
                for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
                {
                C.insert(*i);
                }
            
                int numero = L1_.size();
                for(int i = 1; i < n; i++)
                {
                    numero *= L1_.size(); 
                }
            
                while(C.size() < numero)
                {
                    C = potencia_(C, L1_);
                }
                print(C);
            }
            
            if(a==2)
            {
                set<string> C;
                
                for (set<string>::iterator i = L2_.begin(); i != L2_.end(); i++)
                {
                C.insert(*i);
                }
            
                int numero = L2_.size();
                for(int i = 1; i < n; i++)
                {
                    numero *= L2_.size(); 
                }
            
                while(C.size() < numero)
                {
                    C = potencia_(C, L2_);
                }
                print(C);
            }
        }
    }
    
    set<string> calculadora_t::potencia_(set<string> C1, set<string> C2)
    {
        string aux; 
        string aux2;
        set<string> resultado;
            for (set<string>::iterator i = C1.begin(); i != C1.end(); i++){
                for (set<string>::iterator j = C2.begin(); j != C2.end(); j++){
                    aux = (*i);
                    aux2 = (*j);
                    aux.insert(aux.size(), aux2);
                    resultado.insert(aux);
                }
            }
        return resultado;
    }
    
    void calculadora_t::inversa(int a)
    {
        if(a == 1)
        {
            string aux;
            int iaux=0;
            
            cout << "L^-1 = {"; 
            for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
            {
                 aux = (*i);
                 
                 for (string::reverse_iterator rit= aux.rbegin(); rit!= aux.rend(); rit++)
                 cout << *rit;
                 
                 if (iaux != L1_.size()-1)
                 {
                        cout << "," ;
                 }
                 iaux++;
            }
            cout << "}" << endl << endl;
        }
        if(a ==2 )
        {
            string aux;
            int iaux=0;
            
            cout << "L^-1 = {"; 
            for (set<string>::iterator i = L2_.begin(); i != L2_.end(); i++)
            {
                 aux = (*i);
                 
                 for (string::reverse_iterator rit= aux.rbegin(); rit!= aux.rend(); rit++)
                 cout << *rit;
                 
                 if (iaux != L2_.size()-1)
                 {
                        cout << "," ;
                 }
                 iaux++;
            }
            cout << "}" << endl << endl;    
        }
    }
    
    void calculadora_t::concatenacion(void)
    {
        cout << "L1 * L2 = {"; 
        int iaux=0;
        string cvacio="&";
        for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
        {
             for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
             {
                    if (*i == cvacio)
                    {
                            cout << *j;
                    }
                    else if ( *j == cvacio)
                    {
                            cout << *i;
                    }
                    else
                    {
                            cout << *i << *j;
                    }
                 
                   if (iaux < L1_.size()*L2_.size())  
                    {    
                        cout << "," ;
                    }
                    
                    iaux++;
             }
            iaux++;
        }
               
                   
        cout << "}" << endl << endl;
    }
    
    void calculadora_t::union_(void)
    {
    	cout << "Unión: ";
	    ostream_iterator <string> iter( cout, " " );
	    set_union(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), iter );
        cout << endl;
 
    }
    
    void calculadora_t::interseccion(void)
    {
        cout << "Intersección: ";
        ostream_iterator <string> iter( cout, " " );
	    set_intersection(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), iter);    
	    cout << endl;
    }
    
    void calculadora_t::diferencia(void)
    {
        ostream_iterator <string> iter( cout, " " );
        set <string> C; 
        
	    set_difference(L1_.begin(), L1_.end(), L2_.begin(), L2_.end(), inserter(C, C.begin())); 

	    cout << "Diferencia de A y B: ";
	    copy(C.begin(), C.end(), iter);
	    cout << endl;
    }
    
    bool calculadora_t::sublenguajes(void) 
    {
        int aux=0;
        
        for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
        {
                for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
                {
                    if((*i) == (*j))
                    {
                        aux++;
                        
                    }
                }    
                
                if (aux == L2_.size()-1)
                {
                    return true;   
                }
                else
                {
                    return false;
                }
        }
        cout << "}" << endl;
    }
    
  bool calculadora_t::igualdad_lenguajes(void)
    {
       int aux= 0;
       
        
        if(L1_.size() != L2_.size())
        {   
            return false;
        }
            
        else{
        
            for (set<string>::iterator i = L1_.begin(); i != L1_.end(); i++)
                for (set<string>::iterator j = L2_.begin(); j != L2_.end(); j++)
                    if((*i) == (*j))
                        aux ++;
                        
            
            if(aux == L1_.size())
             {
                
                return true;
             }
            else
            {
                
                return false;
            }
         
         
        }
        
	   
    }
    
    
    
    
    
    void calculadora_t::print(set <string> C)
    {
        cout << "Potencia L^" <<": {";
        int iaux=0;
	    for (set<string>::iterator i = C.begin(); i != C.end(); i++)
	    {
	        cout << (*i);
	        
	        if (iaux != C.size()-1)
            {
                    cout << "," ; 
            }
            iaux++;
	    }
	    
	   cout << "}" << endl << endl; 
	    
    }