#include "tablero.hpp"




using namespace std; 

    int tablero_t::pos(int i, int j)
    {
       if ((i<1)||(i>m_)||(j<1)||(j>n_)){
    		cerr << "ERROR: acceso al tablero incorrecto"<< endl;
    		return 0;
        }
    	return (i-1)*n_+j-1;
    }
    
    void tablero_t::creartablero(void)
    {
	M_= new char [m_*n_];                                

	if (M_==NULL)                                      
		cout << "Error creando el tablero." << endl;
    }
    
    void tablero_t::destruirtablero(void)
    {
	if (M_!=NULL){
		delete [] M_;                                        
		M_=NULL;                                            
	}

	m_=0;
	n_=0;
    }

    tablero_t::tablero_t(int m, int n, int x, int y, int vidas, bool amuleto, int c, int v):
        m_(m),
        n_(n),
        h_(x,y,vidas,amuleto),
        a_(c,v),
        m1_(10,20),
        m2_(14,17),
        m3_(6,21),
        m4_(14,63),
        m5_(6,50),
        m6_(10,60),
        m7_(40,49),
        m8_(36,39),
        m9_(48,41),
        z1_(15,25),
        z2_(15,25),
        z3_(15,25)
    {
        creartablero();
    }
    
    
    tablero_t::~tablero_t(void)
    {
        destruirtablero(); // destructor algoritmico
       
    }
    
    void tablero_t::redimensionar(int m,int n)
    {
        destruirtablero();
        m_=m;
        n_=n;
        creartablero();
    }
    
    int tablero_t::get_m(void)
    {
        return m_;
    }
    
    int tablero_t::get_n(void)
    {
        return n_;
    }
    
    void tablero_t::set_item(int i, int j, char item)
    {
        M_[pos(i,j)]=item;
    }
    
    void tablero_t::rellenar(void)
    {
        char a = ' ';
        char b = '-';
        char c = '|';
        char d = '@';
        char e = '&';
        char f = 'O';
        char g = '*';
        
        for(int i=1; i<=get_m(); i++)
        {
            for(int j=1; j<=get_n(); j++)
            {
                set_item(i,j,a);  
                
            }
        }
        
        for(int j=1; j<=n_; j++)
        {
            set_item(1,j,b);
            set_item(m_,j,b);
        }
        
        for(int i=1; i<=m_; i++)
        {
            set_item(i,1,c);
            set_item(i,n_,c);
        }
        
        for(int j=5; j<= z1_.get_p(); j++) //Mazmorra 1
        {
            set_item(5,j,g); 
            set_item(z1_.get_o(),j,g);   
        }
        
        for(int i=5; i<= z1_.get_o(); i++) 
        {
            set_item(i,5,g);
            set_item(i,z1_.get_p(),g);
        }
        
        for(int j=40; j<= 40 + z2_.get_p(); j++) //Mazmorra 2
        {
            set_item(5,j,g); 
            set_item(z2_.get_o(),j,g);   
        }
        
        for(int i=5; i<= z2_.get_o(); i++) 
        {
            set_item(i,40,g);
            set_item(i,40 + z2_.get_p(),g);
        }
        
        for(int j=30; j<=30+ z3_.get_p(); j++) //Mazmorra 3
        {
            set_item(35,j,g); 
            set_item(35 +z3_.get_o(),j,g);
        }
        
        for(int i=35; i<=35+ z3_.get_o(); i++)
        {
            set_item(i,30,g);
            set_item(i,40+z3_.get_o(),g);
        }
        
        
        set_item(h_.get_x(), h_.get_y(),d);  
        set_item(a_.get_q(), a_.get_w(),e);
        set_item(m1_.get_g(), m1_.get_f(),f);
        set_item(m2_.get_g(), m2_.get_f(),f);
        set_item(m3_.get_g(), m3_.get_f(),f);
        set_item(m4_.get_g(), m4_.get_f(),f);
        set_item(m5_.get_g(), m5_.get_f(),f);
        set_item(m6_.get_g(), m6_.get_f(),f);
        set_item(m7_.get_g(), m7_.get_f(),f);
        set_item(m8_.get_g(), m8_.get_f(),f);
        set_item(m9_.get_g(), m9_.get_f(),f);
        
    }
    
    char tablero_t::get_dato(int i, int j)
    {
        return M_[pos(i,j)];
    }
    
    void tablero_t::mostrar(void)
    {
       for(int i=1; i<=m_; i++)
        {
            for(int j=1; j<=n_;j++)
            {
               cout << get_dato(i,j); 
            }
            cout << endl;
        }
        cout << endl; 
    }
    void tablero_t::mover(char option)
    {
         switch(option)
        {
            int aux;
            
            case 'i': aux = h_.get_x(); 
            set_item(h_.get_x(),h_.get_y(),' ');
            h_.set_x(aux-1);
            set_item(h_.get_x(),h_.get_y(),'@');
            break;
            case 'k': aux = h_.get_x(); 
            set_item(h_.get_x(),h_.get_y(),' ');
            h_.set_x(aux+1); 
            set_item(h_.get_x(),h_.get_y(),'@');
            break;
            case 'j': aux = h_.get_y(); 
            set_item(h_.get_x(),h_.get_y(),' ');
            h_.set_y(aux-1);
            set_item(h_.get_x(),h_.get_y(),'@');
            break;
            case 'l': aux = h_.get_y(); 
            set_item(h_.get_x(),h_.get_y(),' ');    
            h_.set_y(aux+1); 
            set_item(h_.get_x(),h_.get_y(),'@');
            break;
        }  
    } 
        
    /* 
    void tablero_t::perder_vida(void)
    {
        if(h_.get_x() == m1_.get_g() && h_.get_y() == m1_.get_f())
        {
            h_.et_vidas()--;
        }
        else if(h_.get_x() == m2_.get_g() && h_.get_y() == m2_.get_f())
        {
            h_.get_vidas()--;
        }
        else if(h_.get_x() == m3_.get_g() && h_.get_y() == m3_.get_f())
        {
            h_.get_vidas()--;
        }
    }
    void tablero_t::fin_partida(void)
    {
        if(h_.get_x() == a_.get_q() && h_.get_y() == a_.get_w())
        {
            h_.get_amuleto() = true;
        }
    }
    */