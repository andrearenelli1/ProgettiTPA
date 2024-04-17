#include <iostream>
#include <cmath>
#include "classi.h"
using namespace std;

//funzione che date le coordinate del satellite principale calcola le altre e le scrive nell'array attributo pos_calc della classe costellazione
//divide essenzialmente tra 2 casi (y>0, y<0)
void costellazione::allineamento(int x, int y){
    if (y>0){
        this->pos_calc[0] = x;                  //x0
        this->pos_calc[1] = y;                  //y0
        this->pos_calc[2] = -x,                 //x1
        this->pos_calc[3] = -(180-abs(y));      //y1
        this->pos_calc[4] = -(90-x);            //x2
        this->pos_calc[5] = y;                  //y2
        this->pos_calc[6] = (90-x);             //x3
        this->pos_calc[7] = -(180-y);           //y3
    }
    else{
        this->pos_calc[0] = x;
        this->pos_calc[1] = y;
        this->pos_calc[2] = -x, 
        this->pos_calc[3] = (180-abs(y));
        this->pos_calc[4] = (90-x);
        this->pos_calc[5] = (180-abs(y));
        this->pos_calc[6] = -(90-x);
        this->pos_calc[7] = y; 
    }
}

//ritorna 0 se le coordinate inserite sono negli intervalli validi
bool costellazione::controllo(int x,int y){
    if(-90 < x < 90 && -180 < y < 180){
        return 0;
    }
    return 1;
}

void costellazione::lancio(int x, int y){
    if(orb30 == 0){
        
        orb30 = 1;
    }
}

costellazione::costellazione(int x, int y){
    //la verifica di validità avviene subito, in modo tale da evitare qualsiasi calcolo in caso di non validità
    if (controllo(x,y)!=0)
    {
        cerr << "----coordinate non valide, intervalli -90 < x < 90 e -180 < y < 180---- " << endl;
    } 

    allineamento(x, y);
    for(int i=0; i < 4; i++){
        this->sat[i] = satellite(pos_calc[2*i], pos_calc[2*i+1]);
    }
    
    this->idc = ncos;
    ncos++;
}

