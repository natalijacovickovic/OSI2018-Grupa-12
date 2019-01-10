#ifndef KVIZ_H
#define KVIZ_H
#include "Libraries.h"
#include "Rezultati.h"
#include "Namjestanje.h"
typedef struct Pitanja
{
	char *pitanje;
	char **odgovori;
	char *tacanOdgovor;
} PITANJA;
void getPitanje(int i, PITANJA *pitanja); // ispisujemo pitanje na standardni izlaz
void getOdgovori(int i, PITANJA *pitanja); // ispisujemo odgovore na standardni izlaz
PITANJA set(char *string1, char *string2, char *string3, char *string4, char *tacan);
void startKviz();

#endif