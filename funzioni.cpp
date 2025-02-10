#include "funzioni.h"

Sezioni stoe(const string str) {
  switch (str[0]) {
    case 'a':
    case 'A': {
      return Sezioni::A;
      break;
    }
    case 'b':
    case 'B': {
      return Sezioni::B;
      break;
    }
    case 'c':
    case 'C': {
      return Sezioni::C;
      break;
    }
    case 'd':
    case 'D': {
      return Sezioni::D;
      break;
    }
    case 'e':
    case 'E': {
      return Sezioni::E;
      break;
    }
    default: {
      cout << "Input non valido" << endl;
      throw BambinoNonValido("Sezione errata");
    }
  }
}

void stampaBambini(const Bambino b[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
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

int cercaBambino(string query, const Bambino b[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
    if (toupperString(b[i].getCognome()) == toupperString(query) ||
        toupperString(b[i].getNome()) == toupperString(query)) {
      return i;
    } else {
      return -1;
    }
  }
  return -1;
}

void cercaBambino(string query, const Bambino b[], int result[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
    if (toupperString(b[i].getCitta()) == toupperString(query)) {
      result[i] = i;
    }
  }
  return;
}

int cercaBambino(Sezioni query, const Bambino b[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
    if (b[i].getSezione() == query) {
      return i;
    } else {
      return -1;
    }
  }
  return -1;
}

int cercaBambino(int query, const Bambino b[], int result[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
    if (b[i].getEta() == query) {
      result[i] = i;
    }
  }
  return -1;
}

string splitString(string str, const char DELIMITER, const int OFFSET) {
  int pos = -1, posPre = 0;
  for (int i = 0; i < OFFSET; ++i) {
    posPre = pos;
    pos = str.find(DELIMITER, pos + 1);
    cout << "pos: " << pos << endl << "posPre: " << posPre << endl;
  }
  return str.substr(posPre + 1, pos - posPre - 1);
}

int importaBambini(ifstream &in, Bambino b[]) {
  in.clear();
  string line;
  while (getline(in, line)) {
    if (in.bad()) {
      return -1;
    } else if (in.fail()) {
      return -2;
    } else if (in.eof()) {
      return 0;
    }

    string dati[3];
    Sezioni s;
    int e;
    for (int i = 0; i < 5; ++i) {
      dati[0] = splitString(line, ';', 0);
      dati[1] = splitString(line, ';', 1);
      dati[2] = splitString(line, ';', 2);
      s = stoe(splitString(line, ';', 3));
      e = stoi(splitString(line, ';', 4));
    }
    b[Bambino::nBambini](dati[0], dati[1], dati[2], s, e);
    ++Bambino::nBambini;
  }
  return 0;
}

int esportaBambini(ofstream &out, Bambino b[]) {
  for (int i = 0; i < Bambino::nBambini; ++i) {
    if (out.bad()) {
      return -1;
    } else if (out.fail()) {
      return -2;
    } else {
      out << b[i].getNome() << ';' << b[i].getCognome() << ';'
          << b[i].getCitta() << ';' << b[i].getSezione() << ';' << b[i].getEta()
          << ';' << endl;
    }
  }

  out.close();
  return 0;
}