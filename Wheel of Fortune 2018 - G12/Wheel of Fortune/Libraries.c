#include"Libraries.h"

void shuffle(int *niz, int n) {      // mijesamo niz tako da uvijek
	int i;                           // dobijamo nasumicne brojeve
	for (i = 0; i < n - 1; i++) {
		size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
		int t = niz[j];
		niz[j] = niz[i];
		niz[i] = t;
	}
}


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