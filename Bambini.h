#include "funzioni.h"

enum class Sezioni{
    A, B, C, D, E
};

class Bambino{

    private:

    string nome;
    string cognome;
    string citta;
    Sezioni sezione;
    int eta;

    public:

    string getNome()const {return nome;}
    string getCognome()const {return cognome;}
    string getCitta()const {return citta;}
    Sezioni getSezione()const {return sezione;}
    int getEta()const {return eta;}

    Bambino(){}
    Bambino(string n, string c, string ct, Sezioni s, int e): nome{n}, cognome{c}, citta{ct}, sezione{s}, eta{e}{
        
        if(eta>5 || eta<2){
            throw runtime_error("Questa eta' non e' valida");
        }

    };

};