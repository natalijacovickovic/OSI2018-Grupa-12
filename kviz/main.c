#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Pitanja
{
	char *pitanje;
	char **odgovori;
	char *tacanOdgovor;
} PITANJA;

void shuffle(int *niz, int n) {      // mijesamo niz tako da uvijek
	int i;                           // dobijamo nasumicna pitanja
	for (i = 0; i < n - 1; i++) {
		size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
		int t = niz[j];
		niz[j] = niz[i];
		niz[i] = t;
	}
}

void getPitanje(int i, PITANJA *pitanja)
{
	printf("%s", pitanja[i].pitanje);
}
void getOdgovori(int i, PITANJA *pitanja)
{
	printf("1.%s", pitanja[i].odgovori[0]);
	printf("2.%s", pitanja[i].odgovori[1]);
	printf("3.%s", pitanja[i].odgovori[2]);
}

PITANJA set(char *string1, char *string2, char *string3, char *string4, char *tacan)
{
	PITANJA pom;
	pom.pitanje = (char*)calloc(strlen(string1) + 1, sizeof(char));
	pom.odgovori = (char**)calloc(3, sizeof(char*));
	pom.odgovori[0] = (char*)calloc(strlen(string2) + 1, sizeof(char));
	pom.odgovori[1] = (char*)calloc(strlen(string3) + 1, sizeof(char));
	pom.odgovori[2] = (char*)calloc(strlen(string4) + 1, sizeof(char));
	pom.tacanOdgovor = (char*)calloc(strlen(tacan) + 1, sizeof(char));
	strcpy(pom.pitanje, string1);
	strcpy(pom.odgovori[0], string2);
	strcpy(pom.odgovori[1], string3);
	strcpy(pom.odgovori[2], string4);
	strcpy(pom.tacanOdgovor, tacan);
	return pom;
}

void startKviz()
{
	int brBodova = 10;
	int k = 0;
	PITANJA kviz[17];
	int i = 0, j;
	FILE *dat, *dat2;
	if ((dat = fopen("pitanja.txt", "r")))
	{
		if ((dat2 = fopen("odgovori.txt", "r")))
		{
			char pitanje[100], odgovor1[100], odgovor2[100], odgovor3[100], odgovor4[100];
			while ((fgets(pitanje, 100, dat)) != NULL)
			{
				fgets(odgovor1, 100, dat);
				fgets(odgovor2, 100, dat);
				fgets(odgovor3, 100, dat);
				fgets(odgovor4, 100, dat2);
				kviz[i] = set(pitanje, odgovor1, odgovor2, odgovor3, odgovor4);
				i++;
			}
		}

	}
	int *niz = (int*)malloc(16 * sizeof(int));
	for (j = 0; j < 16; j++)
		niz[j] = j;
	int n = 16;
	shuffle(niz, n);

	for (j = 0; j < 5; j++)
	{
		getPitanje(niz[j], kviz);
		getOdgovori(niz[j], kviz);
		printf("Vas odgovor je:");
		int m = 0;
		do
		{
			if (scanf("%d", &m) != 1);
			   char chr = getchar();
			if (m > 3 || m < 1)
				   printf("Pogresan unos, pokusajte ponovo.\n");
		        else
				   break;
			
		} while (m < 1 || m>3);
						
		if (strcmp(kviz[niz[j]].tacanOdgovor, kviz[niz[j]].odgovori[m - 1]) == 0)
			{
				brBodova += 20;
				k++;
			}
			else
				brBodova -= 30;
			printf("\n");
	}
	if (k == 5)
		brBodova += 50;
	printf("Broj osvojenih bodova:%d\n", brBodova);
}


int main()
{
	srand((unsigned int)time(NULL));
	startKviz();
	return 0;
}