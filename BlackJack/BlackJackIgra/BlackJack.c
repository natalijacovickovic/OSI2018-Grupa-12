#include "BlackJack.h"

int startBlackJack()
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
			printf("\nPrekoracenje, nazalost izgubili ste.\n");
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

	//free(dealerCards.cards);
	//free(playerCards.cards);

	//getchar();
	getchar();
	return 0;
}

void printWelcome()
{
	printf("****************************\n");
	printf("*  DOBRODOSLI U BLACKJACK  *\n");
	printf("*       PUNO SRECE :)	   *\n");
	printf("* Ostalo vam je ~~~ poena  *\n");
	printf("****************************\n");
}

void printOptionsHelp()
{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Unesite komandu: \n");
	printf("Da povucete kartu...............[1]\n");
	printf("Ostanite na trenutnom...........[2]\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int dealCards(CARD *dealerCards, CARD *playerCards) //inicijalne 2 karte
{
	printf("\nDjeljenje pocinje \n");
	Sleep(1200);
	//dealerCards->cards = (int *)malloc(2 * sizeof(int));              //2 karte su minimalne 
	dealerCards->numOfCards = dealerCards->sumOfCards = 0;
	//`playerCards->cards = (int *)malloc(2 * sizeof(int));
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
		printf("Protivnikove karte:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("Izjednaceni ste! \n");
		//poeni ostaju na 0
		return 1;
	}
	if (playerCards->sumOfCards > 21 && dealerCards->sumOfCards < 22)
	{
		printf("Protivnikove karte:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("\nPrekoracili ste limit, nazalost vi gubite.\n");
		//oduzimanje poena -100...
		return 1;
	}
	return 0;
}

void printCards(CARD card1, CARD card2)         //ispis inicijalnih karata
{
	printf("\n");
	printf("Protivnikove karte:\n");
	printf("%d. %d \n%d. X\n", 1, card1.cards[0], 2);    //jedna karta djelioca je sakrivena
	printf("Vase karte: \n");
	printf("%d. %d \n%d. %d \n", 1, card2.cards[0], 2, card2.cards[1]);
}

void printPlayerCards(CARD cards)         //ispis igracevih karti
{
	printf("\nVase karte: \n");
	for (int i = 0; i < cards.numOfCards; i++)
		printf("%d. %d\n", i + 1, cards.cards[i]);
}

void printDealerCards(CARD cards)       //dealerove karte
{
	printf("Protivnikove karte: \n");
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

int printOptions()      //ispis opcija hit or stand
{
	char input[20];
	input[0] = '0';
	input[1] = '\0';
	int result = 0;
	printf("Unesite komandu: ");
	while (result == 0)
	{
		scanf("%s", input);
		if (input[0] != '1' || input[1] != '\0')               //kontrola unosa na smo 1 i 2
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
	//int *temp = (int *)malloc(cards->numOfCards * sizeof(int));
	//for (int i = 0; i < cards->numOfCards; i++)
		//temp[i] = cards->cards[i];
	//cards->cards = (int *)realloc(cards->cards, (cards->numOfCards + 1));      //realokacija broja karata i dodjela vrijednosti sledeceoj karti
	cards->cards[cards->numOfCards] = rand() % 11 + 1;                       //^
	if (cards->cards[cards->numOfCards] == 1 && cards->sumOfCards <= 11)
		cards->cards[cards->numOfCards] = 11;
	if (cards->cards[cards->numOfCards] == 11 && cards->sumOfCards > 11)
		cards->cards[cards->numOfCards] = 1;
	cards->sumOfCards += cards->cards[cards->numOfCards];
	//for (int i = 0; i < cards->numOfCards; i++)
	//	cards->cards[i] = temp[i];
	cards->numOfCards++;
}

int dealerCardsCheck(CARD cards, CARD player)    //provjera dealerovih karata
{
	if (cards.sumOfCards > 21)
	{
		printf("\nProtivnik je prekoracio limit, pobjedili ste!\n");
		//dodjela poena....
		return 1;
	}
	if (cards.sumOfCards == 21 && player.sumOfCards != 21)
	{
		//stand = 1;
		printf("\nNazalost, protivnik je dobio BlackJack - izgubili ste.\n");
		//skidanje poena.....
		return 1;
	}
	//if (cards.sumOfCards <= 21)
	else
		return 0;
}

int winnerCheck(CARD dealerCards, CARD playerCards)  //provjera pobjednika
{
	if (playerCards.sumOfCards > dealerCards.sumOfCards)
	{
		printf("\nCestitamo pobjedili ste!\n");
		//dodjela poena....
		return 1;
	}
	if (playerCards.sumOfCards < dealerCards.sumOfCards)
	{
		printf("\nNazalost, izgubili ste.\n");
		//oduzimanje poena....
		return -1;
	}
	//if (playerCards.sumOfCards == dealerCards.sumOfCards)
	else
	{
		printf("Izjednaceni ste!\n");
		//poeni ostaju na istom....
		return 0;
	}
}