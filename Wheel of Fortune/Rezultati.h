#pragma once
#include "Libraries.h"

typedef struct podatak
{
	int broj;
	struct tm vrijeme;
}
PODATAK;

void header(FILE *dat, int n); // upis headera u fajl za sve igrice
void upis(FILE *dat, PODATAK *novi, int n); // cuvanje rezultata u datotekama i njihov
void upisiBodoveudat(int broj, int redniBroj); // upisivanje bodova u datoteke
void ispisRezultata(int brojIgrice); // ispis rezultata na standardni izlaz
void cvs(); // cuvanje rezultata u .csv fajlu
void meniRezultata();
