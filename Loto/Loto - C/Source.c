#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void startLoto();
void shuffle(int*, int);
void spinNumbers(int *);


int main()
{
	srand((unsigned int)time(0));
	startLoto();
	return 0;
}

void startLoto()
{
	int sviBrojevi[46];
	for (int i = 0; i < 46; i++)
		sviBrojevi[i] = i;
	shuffle(sviBrojevi, 46);
	int korisnikoviBrojevi[7];
	printf("Unesite vase brojeve: ");
	for (int i = 0; i < 7; i++) // ogranicenje unosa samo na brojeve u odgovarajucem opsegu
	{
		do
		{
			if (scanf("%d", &korisnikoviBrojevi[i]) != 1)
			{
				char chr = getchar();
				printf("Pogresan unos, pokusajte ponovo.\n");
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
					printf("Vec ste unijeli dati broj. Pokusajte ponovo.\n");
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

	int pronadjeniBrojevi[20];
	for (int i = 0; i < 20; i++)
	{
		spinNumbers(sviBrojevi); // "animacija"
		pronadjeniBrojevi[i] = sviBrojevi[i];
		printf("%d ", pronadjeniBrojevi[i]);
	}
	int brojPogodjenih = 0;
	int brojBodova = 0;
	for (int i = 0; i < 7; i++) // provjera pogodjenih brojeva
	{
		for (int j = 0; j < 20; j++)
		{
			if (korisnikoviBrojevi[i] == pronadjeniBrojevi[j])
			{
				brojPogodjenih++;
				brojBodova += brojPogodjenih * 10;
			}
				
		}
	}
	printf("\nPogodili ste %d %s i osvojili %d bodova.\n", brojPogodjenih, brojPogodjenih==1 ? "broj" : (brojPogodjenih <5 ? "broja" : "brojeva"), brojBodova);
}

void shuffle(int *niz, int n) { // nasumicno mijesanje elemenata niza
	int i;                           
	for (i = 0; i < n - 1; i++) {
		size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
		int t = niz[j];
		niz[j] = niz[i];
		niz[i] = t;
	}
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

