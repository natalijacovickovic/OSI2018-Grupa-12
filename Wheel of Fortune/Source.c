#include "Libraries.h"
#include "Broj.h"
#include "Loto.h"
#include "Kviz.h"
#include "Kljucevi.h"
#include "PocetniEkran.h"
#include "Libraries.h"

int brojBodova = 0;
int status[4] = { 0, 0, 0, 0 };
int brojIgranja = 0;
int uslovKorisnika = 0;

int main()
{
	int i = 0;
	FILE *dat;
	if (dat = fopen("Broj igranja.txt", "r"))
		fscanf(dat, "%d", &brojIgranja);
	fclose(dat);
	if (dat = fopen("Status.txt", "r"))
	{
		while (fscanf(dat, "%d", &status[i]) != EOF)
			i++;
		fclose(dat);
	}
	if (dat = fopen("Bodovi.txt", "r"))
	{
		fscanf(dat, "%d", &brojBodova);
		fclose(dat);
	}
	
	int n;
	srand((unsigned int)time(0));
	do {
		n = meni();

		if (n == 1)
		{
			igrajIgru();
		}
		else if (n == 2)
		{
			otkljucaj();
		}
		else if (n == 3)
		{
			tabela();
		}
		else if (n == 4)
		{
			//sacuvaj();
		}
		else if (n == 5)
		{
			prikaziKljuceve();
		}
		else if (n == 6)
		{
			uputstva();
		}
	} while (n != 8);
	return 0;
}