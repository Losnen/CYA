#include "amuleto.hpp"

    amuleto_t::amuleto_t(int q, int w):
    q_(q),
    w_(w)
    {}
    
    amuleto_t::~amuleto_t(void)
    {
      q_=0;
      w_=0;
    }
    
    int amuleto_t::get_q(void)
    {
         return q_;
    }
    
    int amuleto_t::get_w(void)
    {
        return w_;
    }
   