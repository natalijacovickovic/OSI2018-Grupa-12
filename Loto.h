#pragma once
#include "Libraries.h"
void startLoto();
void spinNumbers(int *);
void animation1();

void startLoto()
{
		int sviBrojevi[46];
		for (int i = 0; i < 46; i++)
			sviBrojevi[i] = i;
		shuffle(sviBrojevi, 46);
		int korisnikoviBrojevi[7];
		printf("Unesite 7 brojeva (od 0 do 45): ");
		for (int i = 0; i < 7; i++) // ogranicenje unosa samo na brojeve u odgovarajucem opsegu
		{
			do
			{
				if (scanf("%d", &korisnikoviBrojevi[i]) != 1)
				{
					char chr = getchar();
					printf("Pogresan unos, pokusajte ponovo.\n");
					int uslov = 0;
					for (int j = 0; j < i; j++)
						if (korisnikoviBrojevi[j] == korisnikoviBrojevi[i])
							uslov = 1;
					if (uslov)
						i--;
				}
				else if (korisnikoviBrojevi[i] > 45 || korisnikoviBrojevi[i] < 0)
					printf("Pogresan unos, pokusajte ponovo.\n");
				else if (korisnikoviBrojevi[i] < 46 || korisnikoviBrojevi[i] > -1)
				{
					int uslov = 0;
					for (int j = 0; j < i; j++)
						if (korisnikoviBrojevi[j] == korisnikoviBrojevi[i])
							uslov = 1;
					if (uslov)
					{
						printf("Vec ste unijeli dati broj.\n");
						i--;
					}
				}
				else
					break;

			} while (korisnikoviBrojevi[i] < 0 || korisnikoviBrojevi[i]>45);
		}
		printf("\n");
		printf("Vasi brojevi su: ");
		for (int i = 0; i < 7; i++)
			printf("%d ", korisnikoviBrojevi[i]);
		int pronadjeniBrojevi[20];
		animation1(); // "animacija"
		int bodovi = 0;
		for (int i = 0; i < 20; i++)
		{
			spinNumbers(sviBrojevi); // "animacija"
			pronadjeniBrojevi[i] = sviBrojevi[i];
			printf("%d ", pronadjeniBrojevi[i]);
		}
		int brojPogodjenih = 0;
		for (int i = 0; i < 7; i++) // provjera pogodjenih brojeva
		{
			for (int j = 0; j < 20; j++)
			{
				if (korisnikoviBrojevi[i] == pronadjeniBrojevi[j])
				{
					brojPogodjenih++;
					bodovi += brojPogodjenih * 10;
				}

			}
		}
		brojBodova += bodovi;
		printf("\nPogodili ste %d %s i osvojili %d bodova.\n", brojPogodjenih, brojPogodjenih == 1 ? "broj" : (brojPogodjenih < 5 ? "broja" : "brojeva"), bodovi);
		upisiBodoveudat(bodovi, 3);
		printf("Imate ukupno %d bodova.\n", brojBodova);
		upisiBodove(brojBodova);
		printOut();
		system("cls");
}

void spinNumbers(int *sviBrojevi) // "animacija" promjene brojeva
{
	for (int j = 0; j < 46; j++)
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
	for (int i = 0; i < 50; i++) // ciscenje posljednjeg reda u konzoli
		printf("\b");
	for (int i = 0; i < 50; i++)
		printf(" ");
	for (int i = 0; i < 51; i++)
		printf("\b");
}