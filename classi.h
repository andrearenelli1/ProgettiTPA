#ifndef CLASSI
#define CLASSI

class posizione
{
    protected:
    int x;                                      // coordinata x
    int y;                                      // coordinata y
    int orbita;                                 //variabile orbita
    void set_orbita(int orbita);                //set variabile orbita, non accessibile dall'utente

    public:
    int get_x();                                // ritorna coordinata x
    int get_y();                                // ritorna coordinata y
    int get_orbita();                           // ritorna variabile orbita
    bool set_x(int x);                          //set coordinata x
    bool set_y(int y);                          //set coordinata y

    posizione(int x, int y, int orbita = -1);   // costruttore con orbita di default -1 (sulla terra)
};

class satellite: public posizione
{
    private:
    int idc;                                    // identificativo costellazione
    int ids;                                    // identificativo satellite
    bool aligned;                               // booleano allineamento
    bool principal;                             // booleano, true se satellite principale
    static int NLaunchSat;                      // attrito statico numero satelliti lanciati
    static int NAlignedSat;                     // attributo statico numero satelliti allineati

    public:
    satellite() : posizione(0, 0, -1), ids(0) {}; // costruttore di default
    satellite(int x, int y);  // costruttore
    int get_ids();                              // ritorna identificativo satellite
    int get_idc();                              // ritorna identificativo costellazione
    bool get_principal();                       // ritorna se è il satellite principale
    bool get_aligned();                         // ritorna se il satellite è allineato
    int get_launchSat();                        // ritorna il numero di satelliti lanciati
    int get_alignedSat();                       // ritorna il numero di satelliti allineati

    friend class costellazione;                 // dichiaro costellazione e satellite friend per lasciare a costellazione l'accesso ai miei attributi privati
};

class costellazione
{
    private:
    static int ncos;                            //attributo statico della classe costellazione, viene incrementata dal costruttore, equivale quindi al numero totale di costellazioni create, solo progressivo
    static int nactive;                         //numero di costellazioni attive (lanciate in orbite geostazionarie)
    static bool map[181][361][4];               //matrice tridimensionale di bool avente come base tutte le posizioni possibili sul piano considerando solo coordinate intere (181x361), moltiplicate per 4 orbite. La posizione è rappresentata come un bool, 1=occupata, 0=libera. Le orbite sono codificate così 0=30k, 1=35k, 2=36k, 3=37k.
    int idc;                                    //identificatore costellazione (univoco)
    satellite sat[4];                           //array contenente i 4 satelliti della costellazione     
    void allineamento(int x, int y);            //allinea i 4 satelliti sugli stessi piani longitudinali e latitudinali con le formule date dal testo del problema, inoltre comunica al satellite di essere posizionate correttamente settando aligned = 1.
    void move_n_flag(int orb);                  //serve a spostare i satelliti aggiornando la mappa
    void occ_pos(int x, int y, int orb);        //serve ad occupare una posizione nella mappa     
    void free_pos(int x, int y, int orb);       //serve a liberare una posizione nella mappa


    public:
    costellazione(int x, int y);                //costruttore
    costellazione();                            //costruttore di default
    int get_idc();                              //ritorna identificatore costellazione
    void print_sat();                           //stampa posizioni 4 satelliti
    bool pos_available(int x, int y, int orb);  //ritorna il valore della mappa per una data posizione, quindi 0 = libera, 1 = occupata.
    bool check(int orb);                        //controlla per una data orbita se le coordinate di ogni satellite di sat[4] sono disponibili, ritorna 1 solo se sono disponibili tutte e quattro.
    void lancio();                              //controlla la disponibilità in orbita 0 per le posizioni di sat[4], in caso positivo cambia l'orbita a 0, altrimenti fallisce con un messaggio di errore.
    void posizionamento();                      //controlla la disponibilità nelle orbite per il posizionamento e nel caso agisce come descritto dal testo del problema, comunicando a terminale l'esito ed eventuali errori di posizionamento
    void erase();                               //porta l'orbita a 4, nel caso i satelliti fossero posizionati in orbita, ne aggiorna il numero
    int get_nactive();                          //ritorna il numero di costellazioni attive
    
};

#endif