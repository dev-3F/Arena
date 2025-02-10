#ifndef H_BAMBINI
#define H_BAMBINI

#include <iostream>

using namespace std;

class BambinoNonValido {
public:
  string msg;
  BambinoNonValido(string n_msg) : msg{n_msg} {}
};

enum class Sezioni { A, B, C, D, E };

class Bambino {

private:
  string nome;
  string cognome;
  string citta;
  Sezioni sezione;
  int eta;

public:
  string getNome() const { return nome; }
  string getCognome() const { return cognome; }
  string getCitta() const { return citta; }
  Sezioni getSezione() const { return sezione; }
  int getEta() const { return eta; }

  void operator()(string n, string c, string ct, Sezioni s, int e) {
    if (e > 5 || e < 2) {
      throw BambinoNonValido("Questa eta' non e' valida");
    }

    nome = n;
    cognome = c;
    citta = ct;
    sezione = s;
    eta = e;
  }

  Bambino() {}
};

istream &operator>>(istream &in, Sezioni s) {
  char input;
  in >> input;
  switch (input) {
  case 'a':
  case 'A': {
    s = Sezioni::A;
    break;
  }
  case 'b':
  case 'B': {
    s = Sezioni::B;
    break;
  }
  case 'c':
  case 'C': {
    s = Sezioni::C;
    break;
  }
  case 'd':
  case 'D': {
    s = Sezioni::D;
    break;
  }
  case 'e':
  case 'E': {
    s = Sezioni::E;
    break;
  }
  default: {
    cout << "Input non valido" << endl;
  }
  }
  return in;
}

ostream &operator<<(ostream &out, Sezioni s) {
  switch (s) {
  case Sezioni::A: {
    out << 'A';
    break;
  }
  case Sezioni::B: {
    out << 'B';
    break;
  }
  case Sezioni::C: {
    out << 'C';
    break;
  }
  case Sezioni::D: {
    out << 'D';
    break;
  }
  case Sezioni::E: {
    out << 'E';
    break;
  }
  }
  return out;
}

#endif
