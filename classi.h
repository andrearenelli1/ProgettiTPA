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

    posizione(int x, int y, int orbita); // costruttore

    //bool conferma(int x, int y); l'ho eliminato perche' il codice potrebbe dare problemi utilizza quello che utilizzavi prima
};

class satellite: public posizione
{
    private:
    int idc; // identificativo costellazione
    int ids; // identificativo satellite
    bool aligned; // variabile allineamento
    bool principale; // variabile satellite principale = 1; per verifica -> get_principale

    public:
    satellite() : posizione(0, 0), ids(0) {}; // costruttore di default che serve in costellazione

    satellite(int x, int y, int ids, int idc, int orbita = 0)
    :posizione(x, y); // costruttore per passarmi le variabili

    int get_ids(); // ritorna identificativo satellite

    int get_idc(); // ritorna identificativo satellite
    
    bool get_principale(); // ritorna se è il satellite principale

    bool allineato(); // ritorna se è allineato
};

class costellazione
{
    private:
    static int ncos; //attributo statico della classe costellazione, di default a zero, viene incrementata dal costruttore, equivale quindi al numero totale di costellazioni create
    static int t, orb30, orb35, orb36; //attributi statici che conteggiano il numero attuale di costellazioni a terra e nelle varie orbite
    int idc;
    satellite sat[4];
    bool controllo(int x, int y);
    void lancio(int x, int y);
    int pos_calc[8];
    
    //porca troia

    public:
    //costruttore:
    costellazione(int x, int y);
    //ritorna idc, usare per passarla al costruttore;
    int get_idc();
    //stampa posizioni 4 satelliti:
    void print_sat();
    //allineamento:
    void allineamento(int x, int y);
    //distruttore:
    ~costellazione(){};
    

};

#endif