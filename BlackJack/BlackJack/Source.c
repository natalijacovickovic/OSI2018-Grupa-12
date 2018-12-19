#include "BlackJack.h"
#include <time.h>


int main()
{
	srand((unsigned int)time(0));
	printWelcome();
	CARD dealerCards;
	CARD playerCards;
	int cardsCheck = 0;
	cardsCheck = dealCards(&dealerCards, &playerCards);
	if (cardsCheck)
	{
		getchar();
		return 0;
	}
	int result, stand = 0;
	char input;
	printOptionsHelp();
	do
	{
		result = printOptions();

		if (result == 1)
		{
			hit(&playerCards);
			Sleep(1400);
			printPlayerCards(playerCards);
		}
		if (result == 2)
			break;
		if (playerCards.sumOfCards > 21)
		{
			printf("\nBUST - SORRY YOU LOSE\n");
			//skidanje poena.....
			getchar();
			getchar();
			getchar();
			return 0;
		}
	} while (stand != 1);

	printDealerCards(dealerCards);
	Sleep(1800);
	result = dealerCardsCheck(dealerCards);
	if (result == 1)
	{
		getchar();
		getchar();
		return 0;
	}
	while (dealerCards.sumOfCards <= 16 && dealerCards.sumOfCards <= 21)
	{
		hit(&dealerCards);
		printDealerCards(dealerCards);
		Sleep(800);
	}

	result = dealerCardsCheck(dealerCards);
	if (result == 1)
	{
		getchar();
		getchar();
		return 0;
	}

	result = winnerCheck(dealerCards, playerCards);

	getchar();
	getchar();
	return 0;
}