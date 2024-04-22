#include <iostream>
#include "classi.h"

//Tutto il file Andrea Corradini

using namespace std;

int satellite::NLaunchSat = 0;              // inizializzazione attributo statico
int satellite::NPositionedSat = 0;             // inizializzazione attributo statico

int satellite::get_idc()
{
    return idc;
}

int satellite::get_ids()
{
    return ids;
}

bool satellite::get_principal()
{
    if(ids == 0)
    {
        return true;
    }else{
        return false;
    }
}

bool satellite::get_aligned()
{
    return aligned;
}

satellite::satellite(int x, int y):posizione(x, y)
{}

int satellite::get_launchSat()
{
    return NLaunchSat;
}

int satellite::get_positionedSat()
{
    return NPositionedSat;
}

void satellite::print_pos(){
    cout << "sat nr."<< ids << "\t" << "x: " << get_x() << "\t" << "y: " << get_y()  << "\t" << "orb: " << get_orbita() << endl;
}