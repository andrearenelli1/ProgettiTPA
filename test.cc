#include <iostream>
#include "test.h"
#include "classi.h"

using namespace std;

void test1()
{
    costellazione cos0(30,60);
    cout << "Identificativo costellazione: " << cos0.get_idc() << endl;
    cout << "Posizione satelliti: " << cos0.print_sat() << endl;
}

void test2()
{
    costellazione cos[3];
    cos[0] = costellazione(40,50);
    cos[1] = costellazione(10,-50);
    cos[2] = costellazione(80,-120);

    for(int i = 0; i < 3; i++)
    {
        cout << "Identificativo costellazione: " << cos[i].get_idc() << endl;
        cout << "Posizione satelliti: " << cos[i].print_sat() << endl << endl;
    }

}

void test3()
{

}

void test4()
{
    
}