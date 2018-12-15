#include "BlackJack.h"


int main()
{
	printWelcome();
	CARD dealerCards;
	CARD playerCards;
	dealCards(&dealerCards, &playerCards);
	int result, stand = 0;
	do
	{
		do {                                         //igrac bira da li ce vuci kartu ili ostaje pri onome sto ima
			result = printOptions();
		} while (optionCheck(result) == 0);
		if (result == 1)
			{
				hit(&playerCards);
				printPlayerCards(playerCards);
			}
		else
			stand = 1;
		if (playerCards.sumOfCards > 21)
		{
			//stand = 1;
			printf("\nBUST - GUBITE POENE\n");
			//skidanje poena.....
			result = 3;
			break;
		}                    
	} while (stand != 1); 

	if (result != 3)
	{
		printDealerCards(dealerCards);
		result = dealerCardsCheck(dealerCards);
		if (result == 1)
			return 0;
		while (dealerCards.sumOfCards <= 16 && dealerCards.sumOfCards <= 21)
		{
			hit(&dealerCards);
			printDealerCards(dealerCards);
		}

		result = dealerCardsCheck(dealerCards);
		if (result == 1)
			return 0;

		result = winnerCheck(dealerCards, playerCards);
	}
	




	getchar();
	getchar();
	return 0;
}