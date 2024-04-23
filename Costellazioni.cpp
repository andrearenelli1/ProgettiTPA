#include <iostream>
#include <cmath>
#include "classi.h"
using namespace std;

//Tutto il file Andrea Renelli

int costellazione::ncos = 0;
int costellazione::nCostPositioned = 0;
bool costellazione::map[181][361][4] = {};

costellazione::costellazione(int x, int y){

    idc = ncos; //aggiornamento dell'id costellazione mediante valore attuale della variabile statica
    
    for(int i = 0; i < 4; i++){
        sat[i]=satellite(x, y);
        sat[i].idc = idc;
        sat[i].ids = i;
    }
    ncos++; //aggiornamento variabile statica
}

costellazione::costellazione(){
    idc = ncos; //aggiornamento dell'id costellazione mediante valore attuale della variabile statica
    
    for(int i = 0; i < 4; i++){
        sat[i]=satellite(0, 0);
        sat[i].idc = idc;
        sat[i].ids = i;
    }
    
    ncos++; //aggiornamento variabile statica
}

int costellazione::get_idc(){
    return idc;
}

//stampa le posizioni dei 4 satelliti della costellazione
void costellazione::print_sat(){
    cout << "Posizioni satelliti costellazione id: " << idc << endl;
    for(int i = 0; i < 4; i++){
        sat[i].print_pos();
    }
}

//ritorna 1 se le coordinate del satellite sono disponibili nell'orbita data e quindi non occupate da altri satelliti
bool costellazione::pos_available(int x, int y, int orb){
    
    //serve un doppio controllo perché quando nel posizionamento vado a incrementare X per 3 volte nessuno assicura che, nel caso X sia 90 non si vada a leggere al di fuori della mappa di posizioni
    if(-90 <= x <= 90 && -180 <= y <= 180){
        return map[x+90][y+180][orb]; //coordinate negative vengono riportate alla numerazione dell'array
    }
    else{
        cerr << "----Coordinate non valide----" << endl;
        return 1;
    }
};

void costellazione::occ_pos(int x, int y, int orb){
    map[x+90][y+180][orb] = true;
}

void costellazione::free_pos(int x, int y, int orb){
    map[x+90][y+180][orb] = false;
}

bool costellazione::check(int orb, int increment){
    bool res = false;
    for(int i = 0; i < 4; i++){
        res = res || pos_available(sat[i].get_x()+increment, sat[i].get_y(), orb);
    }
    return !res;
}

void costellazione::lancio(){
    if(!pos_available(sat[0].get_x(), sat[0].get_y(), 0) && !sat[0].launched && sat[0].get_x() > 0){
        for(int i=0; i < 4; i++){
            sat[i].set_orbita(0);
            occ_pos(sat[i].get_x(), sat[i].get_y(), 0);
            sat[i].NLaunchSat++;
            sat[i].launched = true;
        }
        cout << "----Lancio in orbita di sicurezza effettuato con successo per la costellazione id: " << idc << "----" << endl;
        nCostPositioned++; 
    }
    else{
        if(pos_available(sat[0].get_x(), sat[0].get_y(), 0)){
            cerr << "\033[31m" << "----Lancio fallito per costellazione id: " << idc <<", posizione non disponibile in orbita di sicurezza----" <<"\033[0m"<< endl;
        }
        if(sat[0].launched){
            cerr << "\033[31m" << "----Lancio fallito per costellazione id: " << idc <<", la costellazione e' già stata lanciata----" <<"\033[0m"<< endl;
        }
        if(sat[0].get_x() <= 0){
            cerr << "\033[31m" << "----Lancio fallito per costellazione id: " << idc <<", il lancio puo' avvenire solo per X>0----" <<"\033[0m"<< endl;
        }
    } 
}

//funzione che date le coordinate del satellite principale calcola le altre e imposta le coordinate di ogni satellite con set_x e set_y, che al loro interno hanno il controllo intervallo di validità
//divide essenzialmente tra 2 casi (y>0, y<0)
void costellazione::allineamento(int x, int y){
    if (y>0){
        if(sat[0].set_x(x) && sat[0].set_y(y)) {sat[0].aligned = 1;}  //imposta e controlla le coordinate del satellite principale e in caso entrambe le coordinate siano valide imposta aligned a 1                 
        if(sat[1].set_x(-x) && sat[1].set_y(-(180-abs(y)))) {sat[1].aligned = 1;}
        if(sat[2].set_x(-(90-x)) && sat[2].set_y(y)) {sat[2].aligned = 1;}
        if(sat[3].set_x(90-x) && sat[3].set_y(-(180-y))) {sat[3].aligned = 1;}
    }
    else{
        if(sat[0].set_x(x) && sat[0].set_y(y)) {sat[0].aligned = 1;}  //stessa funzionalità ma nel caso y<=0                 
        if(sat[1].set_x(-x) && sat[1].set_y(180-abs(y))) {sat[1].aligned = 1;}
        if(sat[2].set_x(90-x) && sat[2].set_y(180-abs(y))) {sat[2].aligned = 1;}
        if(sat[3].set_x(-(90-x)) && sat[3].set_y(y)) {sat[3].aligned = 1;}          
    }
}

void costellazione::posizionamento(){
    if(!sat[0].positioned && sat[0].launched){
        allineamento(sat[0].get_x(), sat[0].get_y());
        //controlla orbita 35k
        if(check(1)){
            move_n_flag(1);
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 35k----" << endl;
        }
        //se fallisce sopra controlla orbita 36k, se vero setta orbita del satellite e flagga posizione come occupata
        else
        if(check(2)){
            move_n_flag(2);
            cerr << "\033[31m" << "----Posizioni non disponibili in orbita 35k----" <<"\033[0m"<< endl;
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 36k----" << endl;
        }
        //se fallisce sopra controlla orbita 37k, se vero setta orbita del satellite e flagga posizione come occupata
        else 
        if(check(3)){
            move_n_flag(3);
            cerr << "\033[31m" << "----Posizioni non disponibili in orbite 35k e 36k----" <<"\033[0m"<< endl;
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 37k----" << endl;
        }
        //se fallisce sopra fa per tre volte X+1, ogni volta controlla disponibilità
        else
        if(check(3,1)){
            move_n_flag(3,1);
            cerr << "\033[31m" << "----Posizioni non disponibili in orbite 35k, 36k, 37k----" <<"\033[0m"<< endl;
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 37k, " << "\033[32m" << "con X incrementata di 1" << "\033[0m" << "----" << endl;
        }
        else
        if(check(3,2)){
            move_n_flag(3,2);
            cerr << "\033[31m" << "----Posizioni non disponibili in orbite 35k, 36k, 37k----" <<"\033[0m"<< endl;
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 37k, "<< "\033[32m" << "con X incrementata di 2" << "\033[0m" << "----" << endl;
        }
        else
        if(check(3,3)){
            move_n_flag(3,3);
            cerr << "\033[31m" << "----Posizioni non disponibili in orbite 35k, 36k, 37k----" <<"\033[0m"<< endl;
            cout << "----Costellazione id: " << idc << " correttamente posizionata in orbita 37k, "<< "\033[32m" << "con X incrementata di 3" << "\033[0m" << "----" << endl;
        }
        else{
            cout << "----tutti i tentativi di posizionamento sono falliti----" << endl;
            erase();
        }
    }
    else{
        if(sat[0].positioned){
            cerr << "\033[31m" << "----Posizionamento fallito per costellazione id: " << idc <<", costellazione già posizionata----" <<"\033[0m"<< endl;
        }
        if(sat[0].launched){
            cerr << "\033[31m" << "----Posizionamento fallito per costellazione id: " << idc <<", la costellazione non è stata lanciata----" <<"\033[0m"<< endl;
        }
    }
}

void costellazione::erase(){
    if(sat[0].active){
        for(int i = 0; i < 4; i++){
            if (-1 < sat[i].orbita < 4){
            free_pos(sat[i].get_x(), sat[i].get_y(), sat[i].get_orbita());
            sat[i].NPositionedSat--;
            }
            sat[i].set_orbita(4);
            sat[i].NLaunchSat--;
            sat[i].active = false;
        }
        nCostPositioned--;
        cout << "----Costellazione id. " << idc << " posizionata in orbita non stazionaria 40k e "<< "\033[31m" << "disattivata" <<"\033[0m"<< endl;
    }
    else{
        cerr << "\033[31m" << "----Cancellazione fallita per costellazione id: " << idc <<", la costellazione è già stata cancellata----" <<"\033[0m"<< endl;
    }
}

void costellazione::move_n_flag(int orb, int increment){
    for(int i=0; i < 4; i++){
            free_pos(sat[i].get_x(),sat[i].get_y(),0);
            sat[i].set_orbita(orb);
            sat[i].set_x(sat[i].get_x()+increment);
            occ_pos(sat[i].get_x(),sat[i].get_y(),orb);
            sat[i].NPositionedSat++;
            sat[i].positioned = true;
        }
}

int costellazione::get_nCostPositioned(){
    return nCostPositioned;
}