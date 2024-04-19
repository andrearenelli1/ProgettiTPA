#include <iostream>
#include "classi.h"

using namespace std;

int satellite::numSatelliti = 0;

int satellite::get_idc()
{
    return idc;
}

int satellite::get_ids()
{
    return ids;
}

bool satellite::get_principale()
{
    if(ids == 0)
    {
        return true;
    }else{
        return false;
    }
}

// AGGIORNARE UNA VARIABILE PRIVATA ALL DA COSTELLAZIONE DOPO ALLINEAMENTO
bool satellite::allineato()
{
    return aligned;
}

satellite::satellite(int x, int y, int ids, int idc):posizione(x, y)
{
    this->ids = ids;
    this->idc = idc;
}

int satellite::numSat()
{
    return numSatelliti;
}