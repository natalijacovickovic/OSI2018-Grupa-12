#include "TrajanjeKljuceva.h"

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
	printf("0. Povratak na glavni meni\n");
	int n = 0;
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
		if (input < 0 || input>4)
		{
			printf("Unesena vrijednost nije validna. Pokusajte ponovo.\n");
			goto START;
		}
		n = input;
		break;
	} while (1);
	status[n - 1] = 0;
	FILE *dat;
	if (dat = fopen("Status.txt", "w")) // promjena statusa u datoteci
	{
		for (int z = 0; z < 4; z++)
			fprintf(dat, "%d ", status[z]);
		fclose(dat);
	}
	printf("Uspjesno ste otkazali %d. igru\n", n);
	printf("Pritisnite taster Enter za povratak na glavni meni.\n");
	getchar();
}