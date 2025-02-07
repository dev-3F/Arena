#ifndef H_FUNZIONI
#define H_FUNZIONI

#include "Bambini.h"

void stampaBambini(const int CURRENT_SIZE, Bambino b[]){
    for(int i = 0; i < CURRENT_SIZE; ++i){
        cout << "[ " << endl;
        cout << "\tNome: " << b[i].getNome() << endl
            << "\tCognome: " << b[i].getCognome() << endl
            << "\tCitta: " << b[i].getCitta() << endl
            << "\tSezione: " << b[i].getSezione() << endl
            << "\tEta: " << b[i].getEta() << endl;
        cout << "[ " << endl;
    }
}


#endif