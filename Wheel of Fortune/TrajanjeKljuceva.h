#pragma once
#include "Libraries.h"



int checkDate(int i, int duration)
{
	FILE *dat;
	time_t keytime;
	time_t currtime;
	time(&currtime);
	char vrijeme[15] = "Vrijeme";
	char game[2];
	strcat(vrijeme, _itoa(i, game, 10));
	strcat(vrijeme, ".txt");
	if (dat = fopen(vrijeme, "r"))
	{
		fscanf(dat, "%d", &keytime);
		fclose(dat);
	}
	int razlika = currtime - keytime;
	if (razlika > (duration * 3600))
		return 1;
	return 0;
}

void otkazi()
{
	system("cls");
	printf("Unesite koju igru zelite otkazati.\n");
	printf("1. Pogadjanje broja\n");
	printf("2. Kviz\n");
	printf("3. Loto\n");
	printf("4. BlackJack\n");
	int n;
	scanf("%d", &n);
	status[n - 1] = 0;
	FILE *dat;
	if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
	{
		for (int z = 0; z < 4; z++)
			fprintf(dat, "%d ", status[z]);
		fclose(dat);
	}
	printf("Uspjesno ste otkazali %d. igru\n", n);
	getchar();
	getchar();
}