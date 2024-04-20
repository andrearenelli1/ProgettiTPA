#include <iostream>
#include "test.h"
#include "classi.h"

using namespace std;

void test1()
{
    costellazione cos(30,60);
    cos.lancio();
    cos.posizionamento();
    cos.get_idc();
    cos.print_sat();
}

void test2()
{
    costellazione cos[3] = {costellazione(40,50),costellazione(10,-50),costellazione(80,-120)};

    for(int i = 0; i < 3; i++)
    {
        cos[i].lancio();
        cos[i].posizionamento();
        cos[i].get_idc();
        cos[i].print_sat();
    }
}

void test3()
{    
    satellite sat;
    cout << "Numero satelliti lanciati: " << sat.numSat() << endl;
}

void test4()
{
    costellazione cos1(30,60);
    cos1.lancio();

    costellazione cos2(30,60);
    cos2.lancio();

    cos1.posizionamento();
    cos1.print_sat();
}

void test12()
{
    test3();
    satellite sat;
    cout << "Numero satelliti allineati: " << sat.numSatAllineati() << endl;
}