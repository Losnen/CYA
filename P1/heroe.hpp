#include <iostream>

class heroe_t
{
    private:
    
    int x_;
    int y_;
    int vidas_;
    bool amuleto_;
    
    public:
    
    heroe_t(int x, int y,int vidas, bool amuleto);
    ~heroe_t(void);
    int get_x(void);
    int get_y(void); 
    int get_vidas(void);
    bool get_amuleto(void);
    void set_x(int a);
    void set_y(int a);
};