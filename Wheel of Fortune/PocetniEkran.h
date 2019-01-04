#ifndef POCETNIEKRAN_H_INCLUDED
#define POCETNIEKRAN_H_INCLUDED

#include "Libraries.h"
void name1();
void countdown1();
void name2();
void countdown2();
void name3();
void countdown3();
void name4();
void countdown4();
void printPocetni();

int meni() // pocetni meni gdje korisnik bira opcije
{
	if (!uslovKorisnika)
		provjeraKorisnika();
	printPocetni();
        printf("Bodovi: %d\n", brojBodova); 
	printf("1.Igraj igru\n");
	printf("2.Unesi kljuc\n");
	printf("3.Prikaz rezultata\n");
	printf("4.Sacuvaj rezultate\n");
	printf("5.Moji kljucevi\n");
	printf("6.Uputstvo\n");
	printf("7.Otkazi igru\n");
	printf("8.Izlaz\n");
	int n = 0;
	do
	{
	START:;
		if (scanf("%d", &n) != 1)
		{
			char pom[20];
			fgets(pom, 20, stdin);
			printf("Pogresan unos. Pokusajte ponovo.\n");
			goto START;
		}
		else if (n > 8 || n<1)
			printf("Nepoznata komanda.\n");
	} while (n < 1 || n>8);
	return n;
}

void prva() // provjera i pokretanje 1. igre
{
	int n = statusIgre(0);
	if (n)
	{
		if (checkDate(0, 1))
		{
			int z;
			FILE *dat;
			printf("Kljuc je istekao.\n");
			printOut();
			status[0] = 0;
			if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
			{
				for (z = 0; z < 4; z++)
					fprintf(dat, "%d ", status[z]);
				fclose(dat);
			}
			return;
		}
		else
		{
			name1();
			countdown1();
			system("cls");
			startBroj();
		}
	}
	else
	{
		printf("Niste otkljucali igru.\n");
		printOut();
		system("cls");
		return;
	}

}
void druga() // // provjera i pokretanje 2. igre
{
	int n = statusIgre(1);
	if (n)
	{
		if (checkDate(1, 1))
		{
			printf("Kljuc je istekao.\n");
			status[1] = 0;
			FILE *dat;
			printOut();
			if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
			{
				int z;
				for (z = 0; z < 4; z++)
					fprintf(dat, "%d ", status[z]);
				fclose(dat);
			}
			return;
		}
		else
		{
			name2();
			countdown2();
			system("cls");
			startKviz();
		}
	}
	else
	{
		printf("Niste otkljucali igru.\n");
		printOut();
		system("cls");
		return;
	}
}
void treca() // // provjera i pokretanje 3. igre
{
	int n = statusIgre(2);
	if (n)
	{
		if (checkDate(2, 24))
		{
			printf("Kljuc je istekao.\n");
			status[2] = 0;
			printOut();
			FILE *dat;
			if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
			{
				int z;
				for (z = 0; z < 4; z++)
					fprintf(dat, "%d ", status[z]);
				fclose(dat);
			}
			return;
		}
		else
		{
			if (brojBodova < 100)
			{
				printf("Nemate dovoljno bodova da igrate ovu igru.\n");
				printOut();
				return;
			}
			izgubljeno += 100;
			upisiIzgubljeno(izgubljeno);
			brojBodova -= 100;
			name3();
			countdown3();
			system("cls");
			startLoto();
		}
	}
	else
	{
		printf("Niste otkljucali igru.\n");
		printOut();
		system("cls");
		return;
	}
}
void cetvrta() // provjera i pokretanje 4. igre
{
	int n = statusIgre(3);
	if (n)
	{
		if (brojBodova < 100)
		{
			printf("Nemate dovoljno bodova da igrate ovu igru.\n");
			printOut();
			return;
		}
		izgubljeno += 100;
		upisiIzgubljeno(izgubljeno);
		brojBodova -= 100;
		name4();
		countdown4();
		system("cls");
		startBlackJack();
	}
	else
	{
		printf("Niste otkljucali igru.\n");
		printOut();
		system("cls");
		return;
	}
}

void igrajIgru() // meni gdje igrac bira igru
{
	system("cls");
	printf("1. Pogadjanje broja\n");
	printf("2. Kviz\n");
	printf("3. Loto\n");
	printf("4. BlackJack\n");
	printf("0. Povratak na glavni meni\n");
START:;
	int n = 0;
	if (scanf("%d", &n) != 1)
	{
		char pom[20];
		fgets(pom, 20, stdin);
		printf("Pogresan unos. Pokusajte ponovo.\n");
		goto START;
	}
	if (n == 1)
		prva();
	else if (n == 2)
		druga();
	else if (n == 3)
		treca();
	else if (n == 4)
		cetvrta();
	else if (n == 0)
		return;
	else
	{
		printf("Nepoznata komanda. Pokusajte ponovo.\n");
		goto START;
	}
}

void countdown1() // odbrojavanje za 1. igru
{
	FILE *dat;
	int i;
	if ((dat = fopen("tri1.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("dva1.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("jedan1.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");
	system("color 07");
}

void name1() // // ispis naziva (ASCII art) 1. igre
{
	system("cls");
	system("color 57");
	FILE *dat;
	int i;
	if ((dat = fopen("prva.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
		{
			printf("%c", i);
		}
		fclose(dat);
	}
	Sleep(1700);
	system("cls");
}

void countdown2() // odbrojavanje za 2. igru
{
	FILE *dat;
	int i;
	if ((dat = fopen("tri2.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("dva2.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("jedan2.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");
	system("color 07");
}

void name2() // // ispis naziva (ASCII art) 2. igre
{
	system("cls");
	system("color 0F");
	FILE *dat;
	int i;
	if ((dat = fopen("druga.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
		{
			printf("%c", i);
		}
		fclose(dat);
	}
	Sleep(1500);
	system("cls");
}

void countdown3() // odbrojavanje za 3. igru
{
	FILE *dat;
	int i;
	if ((dat = fopen("tri3.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("dva3.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("jedan3.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");
	system("color 07");
}

void name3() // ispis naziva (ASCII art) 3. igre
{
	system("cls");
	system("color E1");
	FILE *dat;
	int i;
	if ((dat = fopen("treca.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
		{
			printf("%c", i);
		}
		fclose(dat);
	}
	Sleep(1500);
	system("cls");
}

void countdown4() // odbrojavanje za 4. igru
{
	FILE *dat;
	int i;
	if ((dat = fopen("tri4.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("dva4.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");

	if ((dat = fopen("jedan4.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
			printf("%c", i);
		fclose(dat);
	}
	Sleep(1000);
	system("cls");
	system("color 07");
}

void name4() // ispis naziva (ASCII art) 4. igre
{
	system("cls");
	system("color C0");
	FILE *dat;
	int i;
	if ((dat = fopen("cetvrta.txt", "r")) != NULL)
	{
		while ((i = fgetc(dat)) != EOF)
		{
			printf("%c", i);
		}
		fclose(dat);
	}
	Sleep(1700);
	system("cls");
}

void printPocetni() // animacija pocetnog ekrana i promjene boje
{

	system("cls");
	system("color 09");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
	Sleep(400);
	system("cls");
	system("color 0D");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
	Sleep(400);
	system("cls");
	system("color 0E");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
	Sleep(400);
	system("cls");
	system("color 0A");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
	Sleep(400);
	system("cls");
	system("color 0C");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
	Sleep(400);
	system("cls");
	system("color 07");
	printf("---------------------------------------------------------------\n");
	printf("                      Wheel of Fortune                         \n");
	printf("---------------------------------------------------------------\n");
}

void uputstva()
{
	system("cls");
	printf("Ako zelite igrati igru, izaberite opciju 1.Igraj igru.\n");
	printf("Ako zelite otkljucati igru, izaberite opciju 2.Unesi kljuc.\n");
	printf("Kljuceve mozete pogledati u meniju pod opcijom 5.Moji kljucevi.\n");
	printf("Dobijate pocetnih 10 bodova.\n");
	printf("Da biste igrali 3. i 4. igru, potrebno je uloziti 100 bodova.\n");
	printf("Za ostale igre nije potreban ulog.\n");
	printf("Ako zelite otkljucati igru, izaberite opciju 2.Unesi kljuc.\n");
	printOut();
	system("cls");
	return;
}

#endif // POCETNIEKRAN_H_INCLUDED

