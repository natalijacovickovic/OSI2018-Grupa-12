#include <stdio.h>
#include <stdlib.h>
#include "Windows.h"
void hellomessage();
int main()
{
	hellomessage();
	printf("Izaberite opciju!\n");
	printf("1. Igraj igru!\n");
	printf("2.Opcije!\n");
	printf("3.Izlaz!\n");
	return 0;
}
void hellomessage()
{
	for (int i = 0; i < 4; i++)
	{
		printf("**************************\n");
		printf("***The Wheel of Fortune***\n");
		printf("**************************\n");
		Sleep(300);
		system("cls");
		Sleep(300);
	}

	printf("**************************\n");
	printf("***The Wheel of Fortune***\n");
	printf("**************************\n");
}
