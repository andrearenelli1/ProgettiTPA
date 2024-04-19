#ifndef CLASSI
#define CLASSI

class posizione
{
    protected:
    int x;
    int y;
    int orbita;

    public:
    int get_x(); // ritorna x
    int get_y(); // ritorna y
    int get_orbita(); // ritorna orbita
    bool set_x(int x); //set variabile x
    bool set_y(int y); //set variabile y
    void set_orbita(int orbita); //set variabile orbita

    void print_pos(); // stampa coordinate elegante

    posizione(int x, int y, int orbita = -1); // costruttore

    //bool conferma(int x, int y); l'ho eliminato perche' il codice potrebbe dare problemi utilizza quello che utilizzavi prima
};

class satellite: public posizione
{
    private:
    int idc; // identificativo costellazione
    int ids; // identificativo satellite
    bool aligned; // variabile allineamento = 0 se allineato
    bool principale; // variabile satellite principale = 1; per verifica -> get_principale
    int static numSatelliti; // numero satelliti

    public:
    satellite() : posizione(0, 0,0), ids(0) {}; // costruttore di default che serve in costellazione

    satellite(int x, int y, int ids, int idc); // costruttore

    int get_ids(); // ritorna identificativo satellite

    int get_idc(); // ritorna identificativo satellite
    
    bool get_principale(); // ritorna se è il satellite principale

    bool allineato(); // ritorna se è allineato

    int numSat(); // ritorna il numero di satelliti


    friend class costellazione;
};

class costellazione
{
    private:
    static int ncos;                    //attributo statico della classe costellazione, viene incrementata dal costruttore, equivale quindi al numero totale di costellazioni create, solo progressivo
    static int nactive;                 //numero di costellazioni attive (lanciate in orbite geostazionarie)
    static bool map[181][361][4];       //matrice tridimensionale avente come base tutte le posizioni possibili sul piano considerando solo coordinate intere (181x361), moltiplicate per 4 orbite. La posizione è un bool, 1=occupata, 0=libera. Le orbite sono codificate così 0=30k, 1=35k, 2=36k, 3=37k.
    int idc;                            //identificatore costellazione (univoco)
    satellite sat[4];                   //array contenente i 4 satelliti della costellazione     
    void allineamento(int x, int y);    

    public:
    costellazione(int x, int y);        //costruttore:
    void lancio();
    int get_idc();                      //ritorna idc
    void print_sat();                   //stampa posizioni 4 satelliti
    bool pos_available(int x, int y, int orb);  
    satellite* get_sat();
    void read_map(int x, int y, int orb);  
    void posizionamento();
    void erase();
    void move_n_flag(int orb);
    bool check(int orb);

};

#endif