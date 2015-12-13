#include "heroe.hpp" 

    heroe_t::heroe_t(int x, int y, int vidas, bool amuleto):
    x_(x),
    y_(y),
    vidas_(vidas),
    amuleto_(false)
    {}
    
    heroe_t::~heroe_t(void)
    {
        x_=0;
        y_=0;
        vidas_=0;
        amuleto_=false;
    }
   
    
    
    int heroe_t::get_x(void)
    {
        return x_;
    }
    
    int heroe_t::get_y(void)
    {
        return y_;
    }
    
    int heroe_t::get_vidas(void)
    {
        return vidas_;
    }
    
    bool heroe_t::get_amuleto(void)
    {
        return amuleto_;
    }
     
    void heroe_t::set_x(int a)
    {
        x_=a;
    }

    void heroe_t::set_y(int a)
    {
        y_=a;
    }
   