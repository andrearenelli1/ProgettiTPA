#include <iostream>
#include "classi.h"

using namespace std;

int satellite::NLaunchSat = 0;              // inizializzazione attributo statico
int satellite::NAlignedSat = 0;             // inizializzazione attributo statico

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

satellite::satellite(int x, int y, int ids, int idc):posizione(x, y)
{
    this->ids = ids;
    this->idc = idc;
}

int satellite::get_launchSat()
{
    return NLaunchSat;
}

int satellite::get_alignedSat()
{
    return NAlignedSat;
}