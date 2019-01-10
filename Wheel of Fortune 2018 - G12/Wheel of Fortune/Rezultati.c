#include "Rezultati.h"


void header(FILE *dat, int n) // upis headera u fajl za sve igrice
{
	if (n == 1)
	{
		fprintf(dat, "================   ==========\n");
		fprintf(dat, "Pogadjanje broja   Rezultat\n");
		fprintf(dat, "================   ==========\n");
	}
	else if (n == 2)
	{
		fprintf(dat, "====   ==========\n");
		fprintf(dat, "Kviz   Rezultat\n");
		fprintf(dat, "====   ==========\n");
	}
	else if (n == 3)
	{
		fprintf(dat, "====   ==========\n");
		fprintf(dat, "Loto   Rezultati\n");
		fprintf(dat, "====   ==========\n");
	}
	else if (n == 4)
	{
		fprintf(dat, "=========   ==========\n");
		fprintf(dat, "BlackJack   Rezultat\n");
		fprintf(dat, "=========   ==========\n");
	}
}

void upis(FILE *dat, PODATAK *novi, int n) // cuvanje rezultata u datotekama i njihov
{                                          // formatiran upis
	int i;
	if (n == 1)
	{
		for (i = 0; i < 10; i++)
		{
			fprintf(dat, "%22d\n", novi[i].broj);
			fprintf(dat, "%21d.%d.%d\n\n", novi[i].vrijeme.tm_mday, novi[i].vrijeme.tm_mon, novi[i].vrijeme.tm_year);
		}
	}
	else if (n == 2)
	{
		for (i = 0; i < 10; i++)
		{
			fprintf(dat, "%10d\n", novi[i].broj);
			fprintf(dat, "%9d.%d.%d\n\n", novi[i].vrijeme.tm_mday, novi[i].vrijeme.tm_mon, novi[i].vrijeme.tm_year);
		}
	}
	else if (n == 3)
	{
		for (i = 0; i < 10; i++)
		{
			fprintf(dat, "%10d\n", novi[i].broj);
			fprintf(dat, "%9d.%d.%d\n\n", novi[i].vrijeme.tm_mday, novi[i].vrijeme.tm_mon, novi[i].vrijeme.tm_year);
		}
	}
	else if (n == 4)
	{
		for (i = 0; i < 10; i++)
		{
			fprintf(dat, "%15d\n", novi[i].broj);
			fprintf(dat, "%14d.%d.%d\n\n", novi[i].vrijeme.tm_mday, novi[i].vrijeme.tm_mon, novi[i].vrijeme.tm_year);
		}
	}
}


void upisiBodoveudat(int broj, int redniBroj) // upisivanje bodova u datoteke
 {
	char r[9] = "Rezultat";
	int i, j = 0;
	PODATAK niz[10] = { 0 };
	PODATAK novi[10] = { 0 };
	FILE *dat;
	char pom[150];
	char naziv[20] = "Rezultati";
	char b[2];
	_itoa(redniBroj, b, 10);
	strcat(naziv, b);
	strcat(naziv, ".txt");
	if (dat = fopen(naziv, "r"))
	{
		fgets(pom, 150, dat);
		fgets(pom, 150, dat);
		fgets(pom, 150, dat);
		for (i = 0; i < 10; i++)
		{
			fscanf(dat, "%d\n", &niz[i].broj);
			fscanf(dat, "%d.%d.%d\n", &niz[i].vrijeme.tm_mday, &niz[i].vrijeme.tm_mon, &niz[i].vrijeme.tm_year);

		}
		fclose(dat);
	}
	i = 0;
	while (niz[i].broj > broj && niz[i].broj != 0)
	{
		novi[i] = niz[i];
		j++;
		i++;
	}
	while (niz[i].broj == 0 && niz[i].vrijeme.tm_mday != 0 && broj < 0)
	{
		novi[i] = niz[i];
		j++;
		i++;
	}
	if (i != 10)
	{
		PODATAK p;
		p.broj = broj;
		time_t rawtime;
		struct tm* timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		p.vrijeme = *timeinfo;
		p.vrijeme.tm_mon = p.vrijeme.tm_mon + 1;
		p.vrijeme.tm_year = p.vrijeme.tm_year + 1900;
		novi[i] = p;
		for (i += 1; i < 10; j++, i++)
			novi[i] = niz[j];
	}
	if (dat = fopen(naziv, "w"))
	{
		header(dat, redniBroj);
		fclose(dat);
	}
	if (dat = fopen(naziv, "a"))
	{
		upis(dat, novi, redniBroj);
		fclose(dat);
	}

}

void ispisRezultata(int brojIgrice) // ispis rezultata na standardni izlaz
{
	system("cls");
	FILE *dat;
	int i;
	char naziv[20] = "Rezultati";
	char b[2];
	_itoa(brojIgrice, b, 10);
	strcat(naziv, b);
	strcat(naziv, ".txt");
	if (dat = fopen(naziv, "r"))
	{
		while ((i = fgetc(dat)) != EOF)
		{
			printf("%c", i);
		}
		fclose(dat);
	}
}

void cvs() // cuvanje rezultata u .csv fajlu
{
	char ime[4][17];
	strcpy(ime[0], "Pogadjanje broja");
	strcpy(ime[1], "Kviz");
	strcpy(ime[2], "Loto");
	strcpy(ime[3], "BlackJack");
	int i, j = 0;
	PODATAK niz[40] = { 0 };
	FILE *dat;
	char *pom = (char*)malloc(500);

	for (j = 0; j < 4; j++)
	{
		char naziv[20] = "Rezultati";
		char b[2];
		_itoa(j + 1, b, 10);
		strcat(naziv, b);
		strcat(naziv, ".txt");
		if (dat = fopen(naziv, "r"))
		{
			fgets(pom, 150, dat);
			fgets(pom, 150, dat);
			fgets(pom, 150, dat);
			for (i = j * 10; i < (j * 10) + 10; i++)
			{
				fscanf(dat, "%d\n", &niz[i].broj);
				fscanf(dat, "%d.%d.%d\n", &niz[i].vrijeme.tm_mday, &niz[i].vrijeme.tm_mon, &niz[i].vrijeme.tm_year);

			}
			fclose(dat);
			strcpy(naziv, "Rezultati");
		}
	}
	if (dat = fopen("Rezultati.csv", "w"))
	{
		fprintf(dat, "igra, bodovi, datum\n");
		for (j = 0; j < 4; j++)
		{

			for (i = j * 10; (i < (j * 10) + 10) && niz[i].vrijeme.tm_mday!=0; i++)
			{
				fprintf(dat, "%s,", ime[j]);
				fprintf(dat, "%d,", niz[i].broj);
				fprintf(dat, "%d.%d.%d\n", niz[i].vrijeme.tm_mday, niz[i].vrijeme.tm_mon, niz[i].vrijeme.tm_year);
			}
		}
		fclose(dat);
	}
	free(pom);
	system("cls");
	printf("Uspjesno ste sacuvali rezultate.\n");
	//printOut();
	printf("Pritisnite taster Enter za povratak u glavni meni.\n");
	getchar();

}


 void meniRezultata()
{
	 system("cls");
	 printf("Izaberite za koju igru zelite vidjeti rezultate.\n");
	 printf("1. Pogadjanje broja\n");
	 printf("2. Kviz\n");
	 printf("3. Loto\n");
	 printf("4. BlackJack\n");
	 printf("0. Povratak na glavni meni\n");
	 int n;
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
		 if (input < 0 || input>4)
		 {
			 printf("Unesena vrijednost nije validna. Pokusajte ponovo.\n");
			 goto START;
		 }
		 n = input;
		 break;
	 } while (1);
	 if (n == 0)
		 return;
	 ispisRezultata(n);
	 printf("Pritisnite taster Enter za povratak na glavni meni.\n");
	 getchar();
}

