#include "funzioni.h"

/*

Questa applicazione deve poter permettere l'inserimento dei nuovi bambini, la stampa di tutti i bambini,
la ricerca di un bambino,
il salvataggio su file dei dati, lettura dei file da dati, ordinamento dei bambini in base ad un criterio.

*/

int main(){

    constexpr int SIZE = 50;
    string nome[SIZE];
    string cognome[SIZE];
    string citta[SIZE];
    char sezione[SIZE];
    int eta[SIZE];

    char scelta;

    cout<<"Benvenuto! Cosa vuole fare?"<<endl;
    cout<<endl;
    cout<<"A. Inserisci i dati di un bambino"<<endl;
    cout<<"B. Stampa di tutti i bambini"<<endl;
    cout<<"C. Ricerca di un bambino"<<endl;
    cout<<"D. Salvataggio su file dei dati"<<endl;
    cout<<"E. Lettura dei file da dati"<<endl;
    cout<<"F. Ordinamento dei bambini"<<endl;
    cout<<endl;
    cin>>scelta;
    switch(scelta){
        case 'A':{
            cout<<"Inserisci il nome"
                <<"\nInserisci il cognome"
                <<"\nInserisci la citta'"
                <<"\nInserisci la sezione"
                <<"\nInserisci l'eta'"<<endl;
                cout<<endl;
                
            break;
        }
        case 'B':{

            break;
        }
        case 'C':{

            break;
        }
        case 'D':{

            break;
        }
        case 'E':{

            break;
        }
        case 'F':{

            break;
        }
        default:{
            cout<<"Carattere non valido"<<endl;
            break;
        }
    }


    


    return 0;
}