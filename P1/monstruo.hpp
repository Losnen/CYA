#include <iostream>

class monstruo_t
{
    private:
    
    int g_;
    int f_;
    
    public:
    
    monstruo_t(int g, int f);
    ~monstruo_t(void);
    int get_g(void);
    int get_f(void);
};