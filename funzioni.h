#ifndef H_FUNZIONI
#define H_FUNZIONI

#include "Bambini.h"
#include <cctype>
#define SIZE 50

void stampaBambini(const int CURRENT_SIZE, const Bambino b[]) {
  for (int i = 0; i < CURRENT_SIZE; ++i) {
    cout << "[ " << endl;
    cout << "\tNome: " << b[i].getNome() << endl
         << "\tCognome: " << b[i].getCognome() << endl
         << "\tCitta: " << b[i].getCitta() << endl
         << "\tSezione: " << b[i].getSezione() << endl
         << "\tEta: " << b[i].getEta() << endl;
    cout << "[ " << endl;
  }
}

void stampaBambino(const int INDEX, const Bambino b[]) {
  cout << "[ " << endl;
  cout << "\tNome: " << b[INDEX].getNome() << endl
       << "\tCognome: " << b[INDEX].getCognome() << endl
       << "\tCitta: " << b[INDEX].getCitta() << endl
       << "\tSezione: " << b[INDEX].getSezione() << endl
       << "\tEta: " << b[INDEX].getEta() << endl;
  cout << "[ " << endl;
}

string toupperString(string str) {
  for (int i = 0; i < str.length(); ++i) {
    toupper(str[i]);
  }
  return str;
}

int cercaBambino(string name_filter, const Bambino b[]) {
  for (int i = 0; i < SIZE; ++i) {
    if (toupperString(b[i].getNome()) == toupperString(name_filter)) {
      return i;
    } else {
      cerr << "Bambino non trovato" << endl;
      return 0;
    }
  }
}

#endif
