#pragma once
#include "Libraries.h"
void startBroj()
{
	int n = rand() % 101;
	int i = 0, broj;
	printf("Pogodite zamisljen broj!\n");
	int donja = 0, gornja = 100;
		
		do  // ogranicavamo unos tako da korisnik ne moze unijeti broj koji je
		{   // van opsega ili slovo
		LABEL:;
			printf("%d.pokusaj: ", i + 1);
			do
			{
				if (scanf("%d", &broj) != 1)
				{
					getchar();
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


			if (i == 4 || broj==n)
				break;
			else if (broj > n)
			{
				printf("Zamisljeni broj je manji od unesenog.\n");
				gornja = broj;
				i++;
			}
			else
			{
				printf("Zamisljeni broj je veci od unesenog.\n");
				donja = broj;
				i++;
			}

		} while (broj >= donja && broj <= gornja && i!=5);

	int bodovi = 0;
	if (i < 5 && broj==n) // ako pogodi broj
	{
		bodovi = 100 / (i+1);
		if (i == 3)
			bodovi = 35;
		printf("Cestitamo!  Pogodili ste broj!\n");
		printf("Osvojili ste %d bodova\n", bodovi);
	}
	else if (i == 4 && brojIgranja < 3 && broj<gornja && broj>donja) // omogucavanje pobjede
	{
		printf("Cestitamo! Pogodili ste broj!\n");
		printf("Osvojili ste %d bodova\n", 20);
		bodovi = 20;
	}
	else
		printf("Niste pogodili\n");
	brojBodova += bodovi;
	brojIgranja++;
	FILE *dat;
	if(dat=fopen("Broj igranja.txt", "w"))
		fprintf(dat, "%d", brojIgranja);
	printf("Imate ukupno %d bodova.\n", brojBodova);
	upisiBodove(brojBodova);
	printf("Pritisnite bilo koji taster za povratak.\n");
	getchar();
	getchar();
	system("cls");
	return;
}