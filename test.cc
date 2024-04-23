// CORRADINI ANDREA
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
    cout << endl;
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
        cout << endl;
    }
}

void test3()
{    
    satellite sat;
    cout << "Numero satelliti lanciati: " << "\033[32m" << sat.get_launchSat() << "\033[0m" << endl << endl;
}

void test4()                        // test 4, 5, 6. Scritti in un unico test
{
    costellazione cos[2] = {costellazione(30,60),costellazione(30,60)};

    for(int i = 0; i < 2; i++)
    {
        cos[i].lancio();
        cout << endl;
        cos[i].print_sat();
        cout << endl;
    }

    cos[0].posizionamento();
    cos[0].print_sat();
    cout << endl;
}

void test7()                        // test 7,8,9,10,11. Scritti in un unico test perché erano uguali
{
    for(int i = 0; i < 5; i++)
    {
        costellazione cos(30,60);
        cos.lancio();
        cos.posizionamento();
        cout << endl;
        cos.print_sat();
        cout << endl;
    }
}

void test12()
{
    satellite sat;
    cout << "Numero satelliti lanciati: " << "\033[32m" << sat.get_launchSat() << "\033[0m" << endl << endl;
    cout << "Numero satelliti allineati: " << "\033[32m" << sat.get_positionedSat() << "\033[0m" << endl<< endl;
}