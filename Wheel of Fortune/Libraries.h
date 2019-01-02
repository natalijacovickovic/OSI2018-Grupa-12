#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <math.h>


void shuffle(int *niz, int n) {      // mijesamo niz tako da uvijek
	int i;                           // dobijamo nasumicne brojeve
	for (i = 0; i < n - 1; i++) {
		size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
		int t = niz[j];
		niz[j] = niz[i];
		niz[i] = t;
	}
}

extern int dobijeno;
extern int izgubljeno;
extern int brojBodova;
extern int status[4]; // status igara (zakljucane/otkljucane)
extern int brojIgranja; // broj igranja prve igre
extern int uslovKorisnika; // pri povratku na pocetni ekran, provjera da li
						   // je korisnik tek usao u igru ili je samo zavrio sa trenutnom igrom

void upisiBodove(int bodovi) // cuvanje bodova u datoteci
{
	FILE *dat;
	if (dat = fopen("Bodovi.txt", "w"))
	{
		fprintf(dat, "%d", bodovi);
		fclose(dat);
	}
}

void printOut() // pomocna funkcija za ispis
{
	printf("Pritisnite taster Enter za povratak na glavni meni.\n");
	getchar();
	getchar();
}