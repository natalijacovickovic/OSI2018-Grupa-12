#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = rand() % 101;
	int i = 0, broj;
	printf("Pogodite zamisljen broj!\n");
	int donja = 0, gornja = 100;
	printf("%d\n",n);
	do
	{
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


		if (i == 4 || broj == n)
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

	} while (broj >= donja && broj <= gornja && i != 5);


	if (i < 5 && broj == n)
	{
		int bodovi = 100 / (i+1);
		if (i == 2)
			bodovi = 35;
		printf("Cestitamo!  Pogodili ste broj!\n");
		printf("Osvojili ste %d bodova", bodovi);
	}
	else
		printf("Niste pogodili");

	return 0;
}