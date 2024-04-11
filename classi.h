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
    posizione(int x, int y, int orbita = 0);

    //conferma posizione:
    bool conferma(int x, int y);
};

class satellite: public posizione
{
    private:
    int idc;
    int ids;

    public:
    //costruttore di defaul:
    satellite() : posizione(0, 0, 0), idc(0), ids(0) {};
    // Costruttore
    satellite(int x, int y, int orbita)
    :posizione(x, y,orbita){};

    //Funzioni
    //stampa identificativo costellazione
    int stp_idc();
    //stampa identificativo satellite
    int stp_ids();
    //satellite principale
    bool prnpl();
    //allinamento
    bool allmto();
};

class costellazione
{
    private:
    int id;
    satellite sat[4];
    bool controllo(int x, int y);
    void lancio(int x, int y);


    public:
    //costruttore:
    costellazione(int x, int y);
    //stampa id;
    int stp_id();
    //stampa posizioni 4 satelliti:
    void pos_sat();
    //orbita:
    int orbita();
    //allineamento:
    bool allineamento(int orbita);
    //distruttore:
    ~costellazione(){};
    

};

#endif