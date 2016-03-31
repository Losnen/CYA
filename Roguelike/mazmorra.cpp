#include "mazmorra.hpp"

    mazmorra_t::mazmorra_t(int o, int p):
    o_(o),
    p_(p)
    {}
    
     mazmorra_t::~mazmorra_t(void)
    {
      o_=0;
      p_=0;
    }
    
    int mazmorra_t::get_o(void)
    {
         return o_;
    }
    
    int mazmorra_t::get_p(void)
    {
        return p_;
    }
   