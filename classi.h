#ifndef CLASSI
#define CLASSI

class posizione
{
    private:
    bool set_x(int x);
    bool set_y(int y);
    void set_orbita(int orbita);

    protected:
    int x;
    int y;
    int orbita;

    public:
    //i 3 ritorni delle coordinate:
    int get_x();
    int get_y();
    int get_orbita();

    //funzione per stampare le coordinate:
    void stampa_pos();

    //funzione per settare le coordinate:
    posizione(int x, int y);

    //conferma posizione:
    bool conferma(int x, int y);
};

class satellite: public posizione
{
    private:
    int idc;
    int ids;
    int aligned;

    public:
    //costruttore di defaul:
    satellite() : posizione(0, 0), ids(0) {};
    // Costruttore
    satellite(int x, int y, int ids,int idc,int orbita=0)
    :posizione(x, y){};

    //Funzioni
    //stampa identificativo satellite
    int stp_ids();
    //satellite principale, sarebbe meglio secondo me metterlo come attributo (che viene messo a 1 dal costruttore solo sul primo satellite)
    bool prnpl();
    //allinamento
    bool allmto();
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