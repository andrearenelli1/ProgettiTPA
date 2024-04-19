#include <iostream>
#include "classi.h"
#include "test.h"

using namespace std;

int main()
{
    costellazione cos0(30, 60);
    cos0.read_map(30, 60, 1);
    satellite sat[4];
    cout << "pos_available= " << cos0.pos_available(sat,1) << endl;
    cos0.lancio();
    
    
    
    return 0;
}