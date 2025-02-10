#ifndef H_FUNZIONI
#define H_FUNZIONI

#include "Bambini.h"
#include <cctype>
#include <fstream>
#define SIZE 50

Sezioni stoe(const string str);

void stampaBambini(const Bambino b[]);

void stampaBambino(const int INDEX, const Bambino b[]);

string toupperString(string str);

int cercaBambino(string query, const Bambino b[]);

void cercaBambino(string query, const Bambino b[], int result[]);

int cercaBambino(Sezioni query, const Bambino b[]);

int cercaBambino(int query, const Bambino b[], int result[]);

string splitString(string str, const char DELIMITER, const int OFFSET);

int importaBambini(ifstream &in, Bambino b[]);

int esportaBambini(ofstream &out, Bambino b[]);

#endif