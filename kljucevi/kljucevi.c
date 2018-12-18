int statusIgre(int i)
{
	return status[i];
}
void otkljucaj()
{
	system("cls");
	FILE *dat;
	printf("Unesite kljuc!\n");
	char* kljuc = (char*)malloc(22);
	scanf("%s", kljuc);
	strcat(kljuc, "\n");
	char **kljucevi = (char**)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++)
		kljucevi[i] = (char*)malloc(20);
	char **iskoristeniKljucevi = (char **)malloc(8 * sizeof(char*));
	for (int i = 0; i < 8; i++)
		iskoristeniKljucevi[i] = (char*)malloc(20);
	int i = 0;
	int k = 0;
	if (dat = fopen("Kljucevi.txt", "r")) // citanje kljuceva iz datoteke
	{
		while (fgets(kljucevi[i], 21, dat))
			i++;
	}
	fclose(dat);
	if (dat = fopen("Iskoristeni kljucevi.txt", "r")) // citanje iskoristenihj kljuceva
	{
		while (fgets(iskoristeniKljucevi[k], 21, dat))
			k++;
		fclose(dat);
	}
	
	for (int j = 0; j < 7; j++)  // provjera da li je kljuc unesen ranije
	{
		if (!strcmp(kljuc, iskoristeniKljucevi[j]))
		{
			printf("Vec ste unijeli dati kljuc.\n");
			getchar();
			getchar();
			system("cls");
			return;
		}
	}
	dat = fopen("Iskoristeni kljucevi.txt", "a");

	for (int j = 0; j < 7; j++)
		if (!strcmp(kljuc, kljucevi[j]))
		{
			status[j / 2] = 1;
			fputs(kljuc, dat);
			printf("Uspjesno ste otkljucali %d. igru.\n", j/2 + 1);
		}

	getchar();
	getchar();
	system("cls");
	fclose(dat);
	for (int z = 0; z < 20; z++)
		free(kljucevi[i]);
	free(kljucevi);

}
void provjeraKorisnika()
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
		printf("Dobrodosli!\n");
		printf("Unesite vase ime!\n");
		scanf("%s", ime);
		dat = fopen("Korisnik.txt", "w");
		fputs(ime, dat);
		fclose(dat);
		printf("\nDobili ste kljuc za prvu igru: 4014-5127-1094-6483.\n");
		printf("Ostale kljuceve mozete pogledati u meniju pod opcijom 7.Moji kljucevi.\n");
		printf("Dobijate pocetnih 10 bodova.\n");
		printf("Da biste igrali 3. i 4. igru, potrebno je uloziti 100 bodova.\n");
		printf("Za ostale igre nije potreban ulog.\n");
		printf ("Ako zelite otkljucati igru, izaberite opciju 2.Unesi kljuc.\n");
		getchar();
		getchar();
		system("cls");
	}
	uslovKorisnika = 1;
}

void prikaziKljuceve()
{
	FILE *dat;
	char c;
	if (dat = fopen("Kljucevi2.txt", "r"))
		while ((c = fgetc(dat)) != EOF)
			printf("%c", c);

}