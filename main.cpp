#include "funzioni.h"

/*
Questa applicazione deve poter permettere l'inserimento dei nuovi bambini, la
stampa di tutti i bambini, la ricerca di un bambino, il salvataggio su file dei
dati, lettura dei file da dati, ordinamento dei bambini in base ad un criterio.
*/

int Bambino::nBambini = 0;

int main() {
  Bambino bambini[SIZE];
  char choice;
  try {
    do {
      cout << "Benvenuto alla scuola Marchesi" << endl
           << "1. Iscrivi nuovo bambino" << endl
           << "2. Stampa tutti i bambini" << endl
           << "3. Filtra bambini" << endl
           << "4. Importa lista bambini" << endl
           << "5. Esporta lista bambini" << endl
           << "6. Oridna bambini" << endl
           << "q. Esci" << endl;
      cout << "-> ";
      cin >> choice;
      switch (choice) {
        case '1': {
          if (Bambino::nBambini > SIZE) {
            cerr << "Spazio non disponibile per altri bambini" << endl;
            break;
          }
          string nome, cognome, citta;
          Sezioni sezione;
          int eta;

          cout << "Inserire i dati del nuovo bambino: " << endl << "Nome: ";
          cin >> nome;
          cout << "Cognome: ";
          cin >> cognome;
          cout << "Citta: ";
          cin >> citta;
          cout << "Sezione(A,B,C,D,E,F): ";
          cin >> sezione;
          cout << "Eta: ";
          cin >> eta;

          bambini[Bambino::nBambini](nome, cognome, citta, sezione, eta);
          ++Bambino::nBambini;
          break;
        }
        case '2': {
          stampaBambini(bambini);
          break;
        }
        case '3': {
          cout << "Filtra per... : " << endl
               << "1. Nome o Cognome" << endl
               << "2. Citta" << endl
               << "3. Sezione" << endl
               << "4. Eta" << endl;
          cin >> choice;
          switch (choice) {
            case '1': {
              string query;
              cout << "Nome o Cognome da cercare: ";
              cin >> query;

              int filterIndex = cercaBambino(query, bambini);
              if (filterIndex > -1) {
                stampaBambino(filterIndex, bambini);
              } else {
                cerr << "Bambino non trovato" << endl;
              }
              break;
            }
            case '2': {
              string query;
              cout << "Citta da cercare: ";
              cin >> query;

              int filterIndexes[Bambino::nBambini];
              cercaBambino(query, bambini, filterIndexes);
              for (int i = 0; i < Bambino::nBambini; ++i) {
                if (filterIndexes[i] > -1) {
                  stampaBambino(filterIndexes[i], bambini);
                } else {
                  cerr << "Bambino non trovato" << endl;
                }
              }
              break;
            }
            case '3': {
              Sezioni query;
              cout << "Sezione da cercare: ";
              cin >> query;

              int filterIndex = cercaBambino(query, bambini);
              if (filterIndex > -1) {
                stampaBambino(filterIndex, bambini);
              } else {
                cerr << "Bambino non trovato" << endl;
              }
              break;
            }
            case '4': {
              unsigned int query;
              cout << "Eta da cercare: ";
              cin >> query;

              int filterIndexes[Bambino::nBambini];
              cercaBambino(query, bambini, filterIndexes);
              for (int i = 0; i < Bambino::nBambini; ++i) {
                if (filterIndexes[i] > -1) {
                  stampaBambino(filterIndexes[i], bambini);
                } else {
                  cerr << "Bambino non trovato" << endl;
                }
              }
              break;
            }
          }
          break;
        }
        case '4': {
          string file;
          cout << "Nome file: ";
          cin >> file;

          ifstream in(file.c_str());
          cout << "dichiarazione superata" << endl;
          if (importaBambini(in, bambini) != 0) {
            cerr << "Errore nella lettura del file" << endl;
          }
          break;
        }
        case '5': {
          string file;
          cout << "Nome file: ";
          cin >> file;

          ofstream out(file.c_str());
          if (esportaBambini(out, bambini) != 0) {
            cerr << "Errore nella esportazione dei dati" << endl;
          }
          break;
        }
        case 'q': {
          cout << "Arrivederci!" << endl;
          break;
        }
        default: {
          cout << "Scelta non valida" << endl;
        }
      }

    } while (choice != 'q');
  } catch (BambinoNonValido err) {
    cerr << err.msg << endl;
  }

  return 0;
}
