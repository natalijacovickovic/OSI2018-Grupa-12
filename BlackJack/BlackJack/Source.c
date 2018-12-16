#include "BlackJack.h"
#include <time.h>


int main()
{
	srand((unsigned int)time(0));
	//printWelcome();
	printMenu();
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
	do
	{
		do {                        //igrac bira da li ce vuci kartu ili ostaje pri onome sto ima
			result = printOptions();
		} while (optionCheck(result) == 0);

		if (result == 1)
		{
			hit(&playerCards);
			printPlayerCards(playerCards);
		}
		if (result == 2)
			break;
		if (playerCards.sumOfCards > 21)
		{
			printf("\nBUST - SORRY YOU LOSE\n");
			//skidanje poena.....
			//result = 3;
			getchar();
			getchar();
			getchar();
			return 0;
			//break;
		}
	} while (stand != 1);

	//if (result != 3)
	//{
		printDealerCards(dealerCards);
		result = dealerCardsCheck(dealerCards);
		if (result == 1)
		{
			getchar();
			return 0;
		}
		while (dealerCards.sumOfCards <= 16 && dealerCards.sumOfCards <= 21)
		{
			hit(&dealerCards);
			printDealerCards(dealerCards);
		}

		result = dealerCardsCheck(dealerCards);
		if (result == 1)
		{
			getchar();
			return 0;
		}

		result = winnerCheck(dealerCards, playerCards);
	//}

	getchar();
	getchar();
	return 0;
}