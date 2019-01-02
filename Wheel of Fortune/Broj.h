#ifndef BROJ_H_INCLUDED
#define BROJ_H_INCLUDED

#include "Libraries.h"
#include "Rezultati.h"
#include "Namjestanje.h"

void startBroj()
{
	int dozvoljeno = provjera(); //maksimalan broj bodova koje moze dobiti
	int manji = 0, veci = 0;
	int niz[5] = { 0 };
	int n = rand() % 101;
	int i = 0, broj;
	//printf("%d\n", n);
	printf("Pogodite zamisljen broj!\n");
	niz[0] = n;
	int donja = 0, gornja = 100;

	do  // ogranicavamo unos tako da korisnik ne moze unijeti broj koji je
	{   // van opsega ili slovo
	LABEL:;
		printf("%d.pokusaj: ", i + 1);
		do
		{
			if (scanf("%d", &broj) != 1)
			{
				char pom[20];
				fgets(pom, 20, stdin);
				printf("Pogresan unos, pokusajte ponovo.\n");
				goto LABEL;
			}
			else if (broj < 0 || broj>101)
			{
				printf("Pogresan unos, pokusajte ponovo.\n");
				goto LABEL;
			}
			else
				break;

		} while (broj < 0 || broj>101);
		niz[i + 1] = broj;
		if (i == 4 || broj == n)
			break;
		else if (brojIgranja == 0 && i >= 2)
			break;
		else if (brojIgranja == 1 && i >= 1)
			break;
		else if (brojIgranja == 2 && i >= 3)
			break;
		else if (broj > n)
		{
			printf("Zamisljeni broj je manji od unesenog.\n");
			if (gornja == 100)
				gornja = broj;
			i++;
			if (n == broj - 1)
				manji++;
		}
		else
		{
			printf("Zamisljeni broj je veci od unesenog.\n");
			if (donja == 0)
				donja = broj;
			i++;
			if (n == broj + 1)
				veci++;
		}

	} while (i != 5);

	int bodovi = 0;

	if (i == 4 && brojIgranja > 2 && dozvoljeno == 0 && (veci == 0 || manji == 0))
	{
		printf("Niste pogodili.\n");
	}

	else if (i >= 2 && brojIgranja == 0 && broj<gornja && broj>donja) // omogucavanje pobjede prva tri puta
	{
		printf("Cestitamo! Pogodili ste broj!\n");
		bodovi = 100 / (i + 1);
		if (i == 2)
			bodovi = 35;
		printf("Osvojili ste %d bodova\n", bodovi);

	}
	else if (i >= 1 && brojIgranja == 1 && broj<gornja && broj>donja)
	{
		printf("Cestitamo! Pogodili ste broj!\n");
		bodovi = 100 / (i + 1);
		if (i == 2)
			bodovi = 35;
		printf("Osvojili ste %d bodova\n", bodovi);

	}
	else if (i >= 3 && brojIgranja == 2 && broj<gornja && broj>donja)
	{
		printf("Cestitamo! Pogodili ste broj!\n");
		bodovi = 100 / (i + 1);
		if (i == 2)
			bodovi = 35;
		printf("Osvojili ste %d bodova\n", bodovi);

	}

	else if (brojIgranja < 3 && broj == n) //ako sam pogodi broj u prva tri igranja
	{
		bodovi = 100 / (i + 1);
		if (i == 2)
			bodovi = 35;
		printf("Cestitamo! Pogodili ste broj!\n");
		printf("Osvojili ste %d bodova\n", bodovi);
	}

	else if (i < 5 && (broj > gornja || broj < donja))  //ako izadje iz opsega
	{
		if (broj > n)
			printf("Zamisljeni broj je manji od unesenog.\n");
		else
			printf("Zamisljeni broj je veci od unesenog.\n");
		i++;
		goto LABEL;
	}

	else if (i <= 4 && broj == n) // ako pogodi broj
	{
		bodovi = 100 / (i + 1);
		if (i == 2)
			bodovi = 35;
		if (manji != 0 && veci != 0)
		{
			printf("Cestitamo! Pogodili ste broj!\n");
			printf("Osvojili ste %d bodova\n", bodovi);
		}
		else if (bodovi > dozvoljeno)
		{
			if (manji != 1)
			{
				n = broj + 1;
				printf("Zamisljeni broj je veci od unesenog.\n");

			}
			else if (veci != 1)
			{
				n = broj - 1;
				printf("Zamisljeni broj je manji od unesenog.\n");
			}
			int k = 0;
			while (k!= 5 && niz[k] != 0 && niz[k] + 1 != n)
				k++;
			if (niz[k] != 0 && k != 5)
				veci++;
			else if (k == 5 && niz[k - 1] != 0)
				veci++;
			k = 0;
			while (k!=5 && niz[k] != 0 && niz[k] - 1 != n)
				k++;
			if (niz[k] != 0 && k != 5)
				manji++;
			else if (k == 5 && niz[k - 1] != 0)
				manji++;
			if (i < 5)
			{
				i++;
				goto LABEL;
			}
		}
		else
		{
			printf("Cestitamo!  Pogodili ste broj!\n");
			printf("Osvojili ste %d bodova\n", bodovi);
		}
	}
	else
		printf("Niste pogodili\n");
	upisiBodoveudat(bodovi, 1);
	brojBodova += bodovi;
	brojIgranja++;
	FILE *dat;
	if (dat = fopen("Broj igranja.txt", "w")) // cuvanje koliko je puta odigrao prvu igru
	{
		fprintf(dat, "%d", brojIgranja);
		fclose(dat);
	}
	printf("Imate ukupno %d bodova.\n", brojBodova);
	upisiBodove(brojBodova);
	dobijeno += bodovi;
	upisiDobijeno(dobijeno);
	printOut();
	system("cls");
	return;

}

#endif // BROJ_H_INCLUDED
