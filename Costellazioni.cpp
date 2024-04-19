#include <iostream>
#include <cmath>
#include "classi.h"
using namespace std;

int costellazione::ncos = 0;
int costellazione::nactive = 0;
bool costellazione::map[181][361][4] = {};

//funzione che date le coordinate del satellite principale calcola le altre e imposta le coordinate di ogni satellite con set_x e set_y, che al loro interno hanno il controllo intervallo di validità
//divide essenzialmente tra 2 casi (y>0, y<0)
void costellazione::allineamento(int x, int y){ //modo di aggiornare all dopo questa funzione
    if (y>0){
        if(sat[0].set_x(x) && sat[0].set_y(y)) {sat[0].aligned = 1;}  //imposta e controlla le coordinate del satellite principale e in caso entrambe le coordinate siano valide imposta aligned a 1                 
        if(sat[1].set_x(-x) && sat[1].set_y(-(180-abs(y)))) {sat[1].aligned = 1;}
        if(sat[2].set_x(-(90-x)) && sat[2].set_y(y)) {sat[2].aligned = 1;}
        if(sat[3].set_x(90-x) && sat[3].set_y(-(180-y))) {sat[3].aligned = 1;}
    }
    else{
        if(sat[0].set_x(x) && sat[0].set_y(y)) {sat[0].aligned = 1;}  //imposta e controlla le coordinate del satellite principale e in caso entrambe le coordinate siano valide imposta aligned a 1                 
        if(sat[1].set_x(-x) && sat[1].set_y(180-abs(y))) {sat[1].aligned = 1;}
        if(sat[2].set_x(90-x) && sat[2].set_y(180-abs(y))) {sat[2].aligned = 1;}
        if(sat[3].set_x(-(90-x)) && sat[3].set_y(y)) {sat[3].aligned = 1;}          
    }
}

int costellazione::get_idc(){
    return idc;
}

//stampa le posizioni dei 4 satelliti della costellazione
void costellazione::print_sat(){
    cout << "Posizioni satelliti costellazione id." << idc << endl;
    cout << "sat nr." << "\n" << "x" << "\n" << "y" << "\n" << "orbita" << endl;
    for(int i = 0; i < 4; i++){
        cout << sat[i].ids << "\n" << sat[i].get_x() << "\n" << sat[i].get_y()  << "\n" << sat[i].get_orbita() << endl;
    }
}

//ritorna 1 se le coordinate di ogni satellite sono disponibili nell'orbita data e quindi non occupate da altri satelliti
bool costellazione::pos_available(satellite sat[4],int orb){
    
    //serve questo doppio controllo perché quando nel posizionamento vado a incrementare X per 3 volte nessuno assicura che, nel caso X sia 90 non si vada a leggere al di fuori della mappa di posizioni
    for(int i = 0; i < 4; i++){
        bool doublecheck = (-90 <= sat[i].get_x() <= 90 && -180 <= sat[i].get_x() <= 180);
        if(!doublecheck){
            return 0;
        };
    }

    bool res=0;

    for(int i = 0; i < 4; i++){
        res = res || map[sat[i].get_x()][sat[i].get_y()][orb];
    }
    return !res;
};

bool costellazione::posizionamento(){
    //controlla orbita 35k
    if(pos_available(sat, 1)){
        for(int i=0; i < 4; i++){
            sat[i].set_orbita(1);
            map[sat[i].get_x()][sat[i].get_y()][1] = 1;
        }
        cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 35k----";
        return 1;
    }
    //se fallisce sopra controlla orbita 36k, se vero setta orbita del satellite e flagga posizione come occupata
    else if(pos_available(sat, 2)){
        for(int i=0; i < 4; i++){
            sat[i].set_orbita(2);
            map[sat[i].get_x()][sat[i].get_y()][2] = 1;
        }
        cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 36k----";
        return 1;
    }
    //se fallisce sopra controlla orbita 37k, se vero setta orbita del satellite e flagga posizione come occupata
    else if(pos_available(sat, 3)){
        for(int i=0; i < 4; i++){
            sat[i].set_orbita(3);
            map[sat[i].get_x()][sat[i].get_y()][3] = 1;
        }
        cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 37k----";
        return 1;
    }
    //se fallisce sopra fa per tre volte X+1, ogni volta controlla disponibilità
    else {
        satellite find[4]; //array locale usato solo per usare la funzione di ricerca posizione senza cambiare le coordinate del satellite
        for(int j = 1; j < 4; j++){
            for(int i = 0; i < 4; i++){
                find[i] = satellite(sat[i].get_x()+j, sat[i].get_y(), -1, -1); //in questo caso orbita e identificatore non servono e sono inizializzati a valori privi di senso
            }
            if(pos_available(find,3)){
                for(int i = 0; i < 4; i++){
                    sat[i].set_x(find[i].get_x());
                    sat[i].set_orbita(3);
                    map[sat[i].get_x()][sat[i].get_y()][3] = 1;
                }
            }
            else{
                for(int i = 0; i < 4; i++){
                    sat[i].set_orbita(4);
                }
                cout << "----Posizionamento in orbita geo-stazionara fallito per la costellazione id: " << idc << "----" << endl;
                cout << "----Posizionamento in orbita non stazionaria 40k----" << endl;

            }
        }
    }

}

bool costellazione::lancio(){
    if(pos_available(sat, 0)){

        for(int i=0; i < 4; i++){
            sat[i].set_orbita(0);
            map[sat[i].get_x()][sat[i].get_y()][0] = 1;
            sat[i].numSatelliti++;
        }
        cout << "----Lancio in orbita di sicurezza effettuato con successo per la costellazione id: " << idc << "----";
        nactive++;
        return  1;
    }
    else{
        cerr << "----Lancio fallito, posizione non disponibile in orbita di sicurezza----";
        return 0;
    }
}

void costellazione::erase(){
    for(int i = 0; i < 4; i++){
        sat[i].set_orbita(4);
        sat[i].numSatelliti--;
    }
    nactive--;
    cout << "----Costellazione id. " << idc << " correttamente posizionata in orbita non stazionaria e disattivata";
}

costellazione::costellazione(int x, int y){

    idc = ncos; //aggiornamento dell'id costellazione mediante valore attuale della variabile statica
    
    for(int i=0; i < 4; i++){
        this->sat[i] = satellite(0, 0, i, idc);
    }

    allineamento(x, y);
    ncos++; //aggiornamento variabile statica
}

