#include "funzioni.h"
#define SIZE 50

/*
Questa applicazione deve poter permettere l'inserimento dei nuovi bambini, la stampa di tutti i bambini,
la ricerca di un bambino,
il salvataggio su file dei dati, lettura dei file da dati, ordinamento dei bambini in base ad un criterio.
*/


int main(){
    Bambino bambini[SIZE];
    int nBambini = 0;
    char choice;
    try{
    do{
        cout << "Benvenuto alla scuola Marchesi" << endl
             << "1. Iscrivi nuovo bambino" << endl
             << "2. Stampa tutti i bambini" << endl
             << "3. Filtra bambini" << endl
             << "4. Esporta lista bambini" << endl
             << "5. Importa lista bambini" << endl
             << "6. Oridna bambini" << endl;
        cout << "-> ";
        cin >> choice;
        switch(choice){
            case '1':{
                string nome, cognome, citta;
                Sezioni sezione;
                int eta;
  
                cout << "Inserire i dati del nuovo bambino: " << endl
                     << "Nome: ";
                cin >> nome;
                cout << "Cognome: ";
                cin >> cognome;
                cout << "Citta: ";
                cin >> citta;
                cout << "Sezione(A,B,C,D,E,F): ";
                cin >> sezione;
                cout << "Eta: ";
                cin >> eta;
  
                bambini[nBambini](nome, cognome, citta, sezione, eta);
                ++nBambini;
                break;
            }
            case '2':{
                stampaBambini(nBambini, bambini);
                break;
            }
            case 'q':{
                cout << "Arrivederci!" << endl;
                break;
            }
            default:{
                cout << "Scelta non valida" << endl;
            }
        }

    }while(choice != 'q');
    }catch(BambinoNonValido err){
        cerr << err.msg << endl;
    }

    return 0;
}