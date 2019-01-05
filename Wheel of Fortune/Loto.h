#ifndef LOTO_H_INCLUDED
#define LOTO_H_INCLUDED

#include "Libraries.h"
#include "Namjestanje.h"
void startLoto();
void spinNumbers(int *);
void animation1();

void startLoto()
{
	int dozvoljeno = provjera();
	int sviBrojevi[46], i;
	for (i = 0; i < 46; i++)
		sviBrojevi[i] = i;
	shuffle(sviBrojevi, 46);
	int korisnikoviBrojevi[7] = { 0 };
	printf("Unesite 7 brojeva (od 0 do 45): ");
	//getchar();
	int k = 0;
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
		if (input < 0 || input>45)
		{
			printf("Broj je van opsega. Pokusajte ponovo.\n");
			goto START;
		}
		for (int j = 0; j < k; j++)
		{
			if (korisnikoviBrojevi[j] == input)
			{
				printf("Vec ste unijeli dati broj. Pokusajte ponovo.\n");
				goto START;
			}
		}
		korisnikoviBrojevi[k] = input;
		k++;
	} while (k < 7);

	printf("\n");
	system("cls");
	printf("Vasi brojevi su: ");
	int z;
	for (z = 0; z < 7; z++)
		printf("%d ", korisnikoviBrojevi[z]);
	int pronadjeniBroj;
	animation1(); // "animacija"
	int bodovi = 0;
	int p = 0;
	int brojPogodjenih = 0;
	int brojac = 0;
	do
	{
		spinNumbers(sviBrojevi);// "animacija"
	LABEL:;
		pronadjeniBroj = sviBrojevi[p];
		for (z = 0; z < 7; z++)
			if (pronadjeniBroj == korisnikoviBrojevi[z])
			{
				brojPogodjenih++;
				bodovi += brojPogodjenih * 10;
			}
		if (bodovi > dozvoljeno)
		{
			bodovi -= brojPogodjenih * 10;
			brojPogodjenih--;
			p++;
			goto LABEL;
		}
		else
		{
			printf("%d ", pronadjeniBroj);
			brojac++;
			p++;
		}

	} while (brojac < 20);
	if (brojPogodjenih == 0)
	{
		printf("\nPogodili ste 0 brojeva i osvojili 0 bodova.\n ");
		goto END;
	}
	printf("\nPogodili ste %d %s i osvojili %d bodova.\n", brojPogodjenih, brojPogodjenih == 1 ? "broj" : (brojPogodjenih < 5 ? "broja" : "brojeva"), bodovi);
END:;
	upisiBodoveudat(bodovi, 3);
	brojBodova += bodovi;
	printf("Imate ukupno %d bodova.\n", brojBodova);
	upisiBodove(brojBodova);
	printf("Pritisnite taster Enter za povratak na glavni meni.\n");
	getchar();
	system("cls");
}

void spinNumbers(int *sviBrojevi) // "animacija" promjene brojeva
{
	int j;
	for (j = 0; j < 46; j++)
	{
		if (sviBrojevi[j] < 10)
		{
			printf("%d\b", sviBrojevi[j]);
			Sleep(55);
		}
		else
		{
			printf("%d\b\b", sviBrojevi[j]);
			Sleep(55);
		}
	}
}


void animation1()
{
	printf("\nIzvlacenje pocinje za "); // "animacija"
	printf("3");
	Sleep(1000);
	printf("\b");
	printf("2");
	Sleep(1000);
	printf("\b");
	printf("1");
	Sleep(1000);
	int i;
	for (i = 0; i < 50; i++) // ciscenje posljednjeg reda u konzoli
		printf("\b");
	for (i = 0; i < 50; i++)
		printf(" ");
	//for (int i = 0; i < 51; i++)
	//printf("\b");
	printf("\n");
}

#endif // LOTO_H_INCLUDED

