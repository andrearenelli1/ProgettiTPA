#include <iostream>
#include "classi.h"

using namespace std;

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