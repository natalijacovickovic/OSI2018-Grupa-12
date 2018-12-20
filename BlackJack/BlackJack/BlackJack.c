#include "BlackJack.h"

void startBlackJack()
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
			printf("\nBROJ KARATA VECI OD 21. IZGUBILI STE!\n");
			//skidanje poena.....
			getchar();
			getchar();
			getchar();
			return 0;
		}
	} while (stand != 1);

	printDealerCards(dealerCards);
	Sleep(1800);
	result = dealerCardsCheck(dealerCards, playerCards);
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

	result = dealerCardsCheck(dealerCards, playerCards);
	if (result == 1)
	{
		getchar();
		getchar();
		return 0;
	}

	result = winnerCheck(dealerCards, playerCards);

	getchar();
	getchar();
}

void printWelcome()
{
	printf("******************************\n");
	printf("*  DOBRO DOSLI U BLACK JACK  *\n");
	printf("*       SRECNO! :)	     *\n");
	printf("*     Imate ~~~ bodova       *\n");
	printf("******************************\n");
}

void printOptionsHelp()
{
	printf("\n~~~~~~~ ODABERITE OPCIJU ~~~~~~~~~~\n");
	printf("<1> POVUCI JOS JEDNU KARTU \n<2> DALJE \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int dealCards(CARD *dealerCards, CARD *playerCards) //inicijalne 2 karte
{
	printf("\nDIJELJENJE POCINJE: \n");
	Sleep(1200);
	dealerCards->cards = (int)malloc(2 * sizeof(int));              //2 karte su minimalne 
	dealerCards->numOfCards = dealerCards->sumOfCards = 0;
	playerCards->cards = (int)malloc(2 * sizeof(int));
	playerCards->sumOfCards = playerCards->numOfCards = 0;

	//inicijalno dijeljenje za dealera

	dealerCards->cards[0] = rand() % 11 + 1;
	if (dealerCards->cards[0] == 1)
		dealerCards->cards[0] = 11;
	dealerCards->numOfCards++;
	dealerCards->sumOfCards += dealerCards->cards[0];
	dealerCards->cards[1] = rand() % 11 + 1;
	if (dealerCards->cards[1] == 1 && (dealerCards->sumOfCards <= 11))
		dealerCards->cards[1] = 11;
	dealerCards->numOfCards++;
	dealerCards->sumOfCards += dealerCards->cards[1];

	//inicijalno dijeljenje za igraca

	playerCards->cards[0] = rand() % 11 + 1;
	if (playerCards->cards[0] == 1)
		playerCards->cards[0] = 11;
	playerCards->numOfCards++;
	playerCards->sumOfCards += playerCards->cards[0];
	playerCards->cards[1] = rand() % 11 + 1;
	if (playerCards->cards[1] == 1 && (playerCards->sumOfCards <= 11))
		playerCards->cards[1] = 11;
	playerCards->numOfCards++;
	playerCards->sumOfCards += playerCards->cards[1];

	printCards(*dealerCards, *playerCards);

	if (dealerCards->sumOfCards == 21 && playerCards->sumOfCards == 21)
	{
		printf("PROTIVNIKOVE KARTE:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("IZJEDNACENI STE\n");
		//poeni ostaju na 0
		return 1;
	}
	if (playerCards->sumOfCards > 21 && dealerCards->sumOfCards < 22)
	{
		printf("PROTIVNIKOVE KARTE:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("\nIZGUBILI STE!\n");
		//oduzimanje poena -100...
		return 1;
	}
	return 0;
}

void printCards(CARD card1, CARD card2)         //ispis inicijalnih karata
{
	printf("\n");
	printf("PROTIVNIKOVE KARTE:\n");
	printf("%d. %d \n%d. X\n", 1, card1.cards[0], 2);    //jedna karta djelioca je sakrivena
	printf("VASE KARTE: \n");
	printf("%d. %d \n%d. %d \n", 1, card2.cards[0], 2, card2.cards[1]);
}

void printPlayerCards(CARD cards)         //ispis igracevih karti
{
	printf("\nVASE KARTE: \n");
	for (int i = 0; i < cards.numOfCards; i++)
		printf("%d. %d\n", i + 1, cards.cards[i]);
}

void printDealerCards(CARD cards)      //dealerove karte
{
	printf("PROTIVNIKOVE KARTE:\n");
	for (int i = 0; i < cards.numOfCards; i++)
		printf("%d. %d\n", i + 1, cards.cards[i]);
}

int optionCheck(int result)
{
	if (result == 1)
		return 1;
	if (result == 2)
		return 1;
	return 0;
}

int printOptions()  //ispis opcija hit or stand
{
	char input[20];
	input[0] = '0';
	input[1] = '\0';
	int result = 0;
	printf("ODABRANA OPCIJA: ");
	while (result == 0)
	{
		scanf("%s", input);
		if (input[0] != '1' || input[1] != '\0')       //kontrola unosa na smo 1 i 2
			if (input[0] != '2' || input[1] != '\0')
			{
				printf("Pogresan unos, pokusajte ponovo\n");
				continue;
			}
			else
			{
				result = 2;
			}
		else
		{
			result = 1;
		}
	}
	return result;
}

void hit(CARD *cards) //funkcija u slucaju kada vucemo sledecu kartu
{
	int *temp = (int)malloc(cards->numOfCards * sizeof(int));
	for (int i = 0; i < cards->numOfCards; i++)
		temp[i] = cards->cards[i];
	cards->cards = (int)realloc(cards->cards, (cards->numOfCards + 1));      //realokacija broja karata i dodjela vrijednosti sledeceoj karti
	cards->cards[cards->numOfCards] = rand() % 11 + 1;                       //^
	if (cards->cards[cards->numOfCards] == 1 && cards->sumOfCards <= 11)
		cards->cards[cards->numOfCards] = 11;
	if (cards->cards[cards->numOfCards] == 11 && cards->sumOfCards > 11)
		cards->cards[cards->numOfCards] = 1;
	cards->sumOfCards += cards->cards[cards->numOfCards];
	for (int i = 0; i < cards->numOfCards; i++)
		cards->cards[i] = temp[i];
	cards->numOfCards++;
}


int dealerCardsCheck(CARD cards, CARD player)    //provjera dealerovih karata
{
	if (cards.sumOfCards > 21)
	{
		printf("\nPOBIIJEDILI STE! CESTITAMO!\n");
		//dodjela poena....
		return 1;
	}

	if (cards.sumOfCards == 21 && player.sumOfCards != 21)
	{
		//stand = 1;
		printf("\nPROTIVNIK IMA BLACK JACK!  IZGUBILI STE!\n");
		//skidanje poena.....
		return 1;
	}
	if (cards.sumOfCards <= 21)
		return 0;
}

int winnerCheck(CARD dealerCards, CARD playerCards)  //provjera pobjednika
{
	if (playerCards.sumOfCards > dealerCards.sumOfCards)
	{
		printf("\nCESTITAMO! POBIJEDILI STE!\n");
		//dodjela poena....
		return 1;
	}
	if (playerCards.sumOfCards < dealerCards.sumOfCards)
	{
		printf("\nIZGUBILI STE!\n");
		//oduzimanje poena....
		return -1;
	}
	if (playerCards.sumOfCards == dealerCards.sumOfCards)
	{
		printf("\nIZJEDNACENI STE!\n");
		//poeni ostaju na istom....
		return 0;
	}
}