#include "Kljucevi.h"

int statusIgre(int i) // provjera da li je igra otkljucana
{
	return status[i];
}
void otkljucaj()
{
	system("cls");
	FILE *dat;
	char* kljuc = (char*)malloc(22);
	printf("Unesite kljuc: (ili unesite 0 za povratak na glavni meni)\n");
LABEL:;
	do
	{
		scanf("%s", kljuc);
		if (!strcmp(kljuc, "0"))
		{
			free(kljuc);
			getchar();
			return;
		}
		if (strlen(kljuc) != 19)
		{
			printf("Greska. Pokusajte ponovo ili unesite 0 za povratak na glavni meni.\n");
		}
	} while (strlen(kljuc) != 19);
	strcat(kljuc, "\n");
	char **kljucevi = (char**)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++)
		kljucevi[i] = (char*)malloc(21);
	char **iskoristeniKljucevi = (char **)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++)
		iskoristeniKljucevi[i] = (char*)malloc(21);
	int i = 0;
	int k = 0;
	if (dat = fopen("Kljucevi.txt", "r")) // citanje kljuceva iz datoteke
	{
		while (fgets(kljucevi[i], 21, dat))
			i++;
		fclose(dat);
	}

	if (dat = fopen("Iskoristeni kljucevi.txt", "r")) // citanje iskoristenih kljuceva
	{
		while (fgets(iskoristeniKljucevi[k], 21, dat))
			k++;
		for (int j = 0; j < 8; j++)  // provjera da li je kljuc unesen ranije
		{
			if (!strcmp(kljuc, iskoristeniKljucevi[j]))
			{
				printf("Vec ste unijeli dati kljuc.\n");
				printOut();
				system("cls");
				fclose(dat);
				return;
			}
		}
		fclose(dat);
	}

	int uslov = 0; // provjera uslova za postojeci kljuc
	if (dat = fopen("Iskoristeni kljucevi.txt", "a")) // otkljucavanje igre, dodavanje kljuca  u
	{                                              // iskoristene kljuceve i pamcenje vremena unosa kljuca
		for (int j = 0; j < 8; j++)
		{
			if (!strcmp(kljuc, kljucevi[j]))
			{
				status[j / 2] = 1;
				fputs(kljuc, dat);
				time_t keytime;
				time(&keytime);
				FILE *dat2;
				char vrijeme[15] = "Vrijeme";
				char brojIgre[2];
				strcat(vrijeme, _itoa(j / 2, brojIgre, 10));
				strcat(vrijeme, ".txt");
				if (dat2 = fopen(vrijeme, "w"))
				{
					fprintf(dat2, "%d", keytime);
					fclose(dat2);
				}
				uslov = 1; // ako pronadje bilo koji kljuc, uslov postavlja na 1
				printf("Uspjesno ste otkljucali %d. igru.\n", j / 2 + 1);
				break;
			}
		}
		if (!uslov) // ako nije pronasao nijedan kljuc u datoteci
		{
			printf("Nevazeci kljuc.\n");
			printOut();
			system("cls");
			return;
		}

		fclose(dat);
	}
	if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
	{
		for (int z = 0; z < 4; z++)
			fprintf(dat, "%d ", status[z]);
		fclose(dat);
	}

	printOut();
	system("cls");
	fclose(dat);
	for (int z = 0; z < 8; z++)
	{
		free(kljucevi[z]);
		free(iskoristeniKljucevi[z]);
	}
	free(iskoristeniKljucevi);
	free(kljucevi);

}
void provjeraKorisnika() // provjera da li je korisnik novi ili postojeci
{
	FILE *dat;
	char ime[20];
	dat = fopen("Korisnik.txt", "r");
	if (dat != NULL)
	{
		fgets(ime, 20, dat);
		printf("Dobrodosli %s.\n", ime);
		Sleep(2000);
		system("cls");
		fclose(dat);
	}
	else
	{
		printf("Dobrodosli!\n"); // ispisujemo uputstva
		printf("Unesite vase ime!\n");
		scanf("%s", ime);
		dat = fopen("Korisnik.txt", "w");
		fputs(ime, dat);
		fclose(dat);
		printf("\nDobili ste kljuc za prvu igru: 4014-5127-1094-6483.\n");
		printf("Ostale kljuceve mozete pogledati u meniju pod opcijom 5.Moji kljucevi.\n");
		printf("Dobijate pocetnih 10 bodova.\n");
		printf("Da biste igrali 3. i 4. igru, potrebno je uloziti 100 bodova.\n");
		printf("Za ostale igre nije potreban ulog.\n");
		printf("Ako zelite otkljucati igru, izaberite opciju 2.Unesi kljuc.\n");
		printOut();
		system("cls");
	}
	uslovKorisnika = 1;
}

void prikaziKljuceve() // prikaz svih kljuceva i njihovog trajanja
{
	system("cls");
	FILE *dat;
	char c;
	if (dat = fopen("Kljucevi2.txt", "r"))
	  while ((c = fgetc(dat)) != EOF)
			printf("%c", c);
	printf("Pritisnite taster Enter za povratak na glavni meni.\n");
	getchar();
}

