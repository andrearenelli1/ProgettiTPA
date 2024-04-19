#ifndef CLASSI
#define CLASSI

class posizione
{
    private:
    bool set_x(int x); //set variabile x
    bool set_y(int y); //set variabile y
    void set_orbita(int orbita); //set variabile orbita

    protected:
    int x;
    int y;
    int orbita;

    public:
    int get_x(); // ritorna x
    int get_y(); // ritorna y
    int get_orbita(); // ritorna orbita

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

    public:
    satellite() : posizione(0, 0,0), ids(0) {}; // costruttore di default che serve in costellazione

    satellite(int x, int y, int ids, int idc, bool aligned, int orbita = -1); // costruttore per passarmi le variabili

    int get_ids(); // ritorna identificativo satellite

    int get_idc(); // ritorna identificativo satellite
    
    bool get_principale(); // ritorna se è il satellite principale

    bool allineato(); // ritorna se è allineato
};

class costellazione
{
    private:
    static int ncos;                    //attributo statico della classe costellazione, di default a zero, viene incrementata dal costruttore, equivale quindi al numero totale di costellazioni create
    static bool map[181][361][4];       //matrice tridimensionale avente come base tutte le posizioni possibili sul piano considerando solo coordinate intere (181x361), moltiplicate per 4 orbite. La posizione è un bool, 1=occupata, 0=libera. Le orbite sono codificate così 0=30k, 1=35k, 2=36k, 3=37k.
    int idc;                            //identificatore costellazione (univoco)
    satellite sat[4];                   //array contenente i 4 satelliti della costellazione
    bool controllo(int x, int y);       
    bool lancio(satellite sat[4]);
    bool allineamento(int x, int y);    
    int pos_calc[8];                    //contiene il risultato del calcolo coordinate

    public:
    costellazione(int x, int y);        //costruttore:
    int get_idc();                      //ritorna idc
    void print_sat();                   //stampa posizioni 4 satelliti
    bool pos_available(satellite sat[4], int orb);
    ~costellazione(){};                 //distruttore
    

};

#endif