#include "monstruo.hpp"    
    monstruo_t::monstruo_t(int g, int f):
    g_(g),
    f_(f)
    {}
    
    monstruo_t::~monstruo_t(void)
    {
        g_=0;
        f_=0;
    }
    
    int monstruo_t::get_g(void)
    {
        return g_;
    }
    int monstruo_t::get_f(void)
    {
        return f_;
    }