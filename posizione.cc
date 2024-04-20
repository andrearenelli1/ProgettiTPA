#include <iostream>
#include "classi.h"

using namespace std;

int posizione::get_x()
{
    return x;
}

int posizione::get_y()
{
    return y;
}

int posizione::get_orbita()
{
    return orbita;
}

bool posizione::set_x(int x)
{
    // controllo validità coordinata x:
    if(-90 <= x && x <= 90)
    {
        this->x = x;
        return true;
    }else{
        this->x = 0;
        cerr << "----coordinata x non valida, intervallo valido -90 <= x <= 90----" << endl;
        return false;
    }
}

bool posizione::set_y(int y)
{
    // controllo validità coordinata y:
    if(-180 <= y && y <= 180)
    {
        this->y = y;
        return true;
    }else
    {
        this->y = 0;
        cerr << "----coordinata y non valida, intervallo valido -180 <= x <= 180----" << endl;
        return false;
    }
}

void posizione::set_orbita(int orbita)
{
    this->orbita = orbita;
}

posizione::posizione(int x, int y, int orbita)
{
    set_x(x);
    set_y(y);
    set_orbita(orbita);
}