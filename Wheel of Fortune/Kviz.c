#include"Kviz.h"

void getPitanje(int i, PITANJA *pitanja) // ispisujemo pitanje na standardni izlaz
{
	printf("%s", pitanja[i].pitanje);
}

void getOdgovori(int i, PITANJA *pitanja) // ispisujemo odgovore na standardni izlaz
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
		int k = 0;
		PITANJA kviz[17];
		int i = 0, j;
		FILE *dat, *dat2;
		int bodovi = 0;
		if ((dat = fopen("pitanja.txt", "r"))) // citamo pitanja i odgovore i datoteke
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
		shuffle(niz, n); // mijesanje niza pitanja
		//getchar();
		for (j = 0; j < 5; j++)
		{
			getPitanje(niz[j], kviz);
			getOdgovori(niz[j], kviz);
			printf("Vas odgovor je:");
			int m = 0;
			do // ogranicenje unosa
			{
			START:;
				int input;
				char buffer[20];
				if (fgets(buffer, 20, stdin) != NULL)
				{
					char *chk;
					input = (int)strtol(buffer, &chk, 10);
					if (!isspace(*chk) && *chk != 0)
					{
						printf("Unesena vrijednost nije validna. Pokusajte ponovo.\n");
						goto START;
					}
				}
				if (input < 1 || input>3)
				{
					printf("Unesena vrijednost nije validna. Pokusajte ponovo.\n");
					goto START;
				}
				m = input;
				break;
			} while (1);

			if (strcmp(kviz[niz[j]].tacanOdgovor, kviz[niz[j]].odgovori[m - 1]) == 0)
			{
				bodovi += 20;
				k++;
			}
			else
				bodovi -= 30;
			printf("\n");
		}
		if (k == 5)
			bodovi += 50;
		printf("Osvojili ste %d bodova\n", bodovi);
		upisiBodoveudat(bodovi, 2);
		brojBodova += bodovi;
		upisiBodove(brojBodova);
		if(bodovi<0)
        {
            izgubljeno+=abs(bodovi);
            upisiIzgubljeno(izgubljeno);
        }

        else
        {
            dobijeno+=bodovi;
            upisiDobijeno(dobijeno);
        }
		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 3; j++)
				free(kviz[i].odgovori[j]);
			free(kviz[i].pitanje);
			free(kviz[i].tacanOdgovor);
			free(kviz[i].odgovori);
		}
		printf("Imate ukupno %d bodova\n", brojBodova);
		printf("Pritisnite taster Enter za povratak na glavni meni.\n");
		getchar();
		system("cls"); // cistimo konzolu
}