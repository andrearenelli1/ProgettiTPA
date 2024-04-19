#include <iostream>
#include <cmath>
#include "classi.h"
using namespace std;

//funzione che date le coordinate del satellite principale calcola le altre e le scrive nell'array attributo pos_calc della classe costellazione
//divide essenzialmente tra 2 casi (y>0, y<0)
bool costellazione::allineamento(int x, int y){ //modo di aggiornare all dopo questa funzione
    if (y>0){
        this->pos_calc[0] = x;                  //x0
        this->pos_calc[1] = y;                  //y0
        this->pos_calc[2] = -x,                 //x1
        this->pos_calc[3] = -(180-abs(y));      //y1
        this->pos_calc[4] = -(90-x);            //x2
        this->pos_calc[5] = y;                  //y2
        this->pos_calc[6] = (90-x);             //x3
        this->pos_calc[7] = -(180-y);           //y3
        return 0;
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
        return 0;
    }
    return 1;
}

int costellazione::get_idc(){
    return this
}

//ritorna 0 se le coordinate inserite sono negli intervalli validi
bool costellazione::controllo(int x,int y){
    if(-90 <= x <= 90 && -180 <= y <= 180){
        return 0;
    }
    return 1;    
}

bool costellazione::pos_available(satellite sat[4],int orb){

    bool res=0;

    for(int i = 0; i < 4; i++){
        res += map[sat[i].get_x()][sat[i].get_y()][orb];
    }
    return res;
};

bool costellazione::lancio(satellite sat[4]){
    if(pos_available(sat, 0)){

        for(int i=0; i < 4; i++){
            this->sat[i] = satellite(pos_calc[2*i], pos_calc[2*i+1], i, this->idc, sat[i].allineato(), 0);
            map[sat[i].get_x()][sat[i].get_y()][0] = 1;
        }
        return 1;
    }
    else{
        cerr << "----Lancio fallito, posizione non disponibile in orbita di sicurezza----";
        return 1;
    }

}

costellazione::costellazione(int x, int y){
    //la verifica di validità avviene subito, in modo tale da evitare qualsiasi calcolo in caso di non validità
    if (controllo(x,y)!=0)
    {
        cerr << "----coordinate non valide, intervalli -90 < x < 90 e -180 < y < 180---- " << endl;
    } 

    this->idc = ncos; //aggiornamento dell'id costellazione mediante valore attuale della variabile statica
    
    bool all = allineamento(x, y);
    for(int i=0; i < 4; i++){
        this->sat[i] = satellite(pos_calc[2*i], pos_calc[2*i+1], i, this->idc, all);
    }
    
    ncos++; 
}

