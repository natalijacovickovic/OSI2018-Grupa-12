#include "BlackJack.h"

void printWelcome()
{
	printf("***************************\n");
	printf("*  WELCOME TO BLACK JACK  *\n");
	printf("*       GOOD LUCK :)	  *\n");
	printf("* You have ~~~ Points lef *\n");
	printf("***************************\n");
}

void printMenu()
{
	int i = 0;
	do
	{
		switch (i)
		{
		case 0:
			system("COLOR 04");
			printWelcome();
			Sleep(800);
			system("cls");
			break;
		case 1:
			system("COLOR 09");
			printWelcome();
			Sleep(800);
			system("cls");
			break;
		case 2:
			system("COLOR 06");
			printWelcome();
			Sleep(800);
			system("cls");
			break;
		case 3:
			system("COLOR 05");
			printWelcome();
			Sleep(800);
			system("cls");
			break;
		case 4:
			system("COLOR 07");
			printWelcome();
			Sleep(800);
			//system("cls");
			break;
		default:
			break;
		}
		i++;
	} while (i < 5);
}

int dealCards(CARD *dealerCards, CARD *playerCards) //inicijalne 2 karte
{
	printf("\nDEALING BEGINS: \n");
	dealerCards->cards = (int)malloc(2 * sizeof(int));              //2 karte su minimalne 
	dealerCards->numOfCards = dealerCards->sumOfCards = 0;     
	playerCards->cards = (int)malloc(2 * sizeof(int)); 
	playerCards->sumOfCards = playerCards->numOfCards = 0;
	
	//inicijalno dijeljenje za dealera

	dealerCards->cards[0] = rand() % 11 + 1;
	if (dealerCards->cards[0] == 1)
		dealerCards->cards[0] = 11;
	//if (dealerCards->cards[0] == 12 || dealerCards->cards[0] == 13 || deaerlCards->cards[0] == 14)
	//	dealerCards->cards[0] == 10;
	dealerCards->numOfCards++;
	dealerCards->sumOfCards += dealerCards->cards[0];
	dealerCards->cards[1] = rand() % 11 + 1;
	if (dealerCards->cards[1] == 1 && (dealerCards->sumOfCards <= 11))
		dealerCards->cards[1] = 11;
	//else if (dealerCards->cards[1] == 11 && dealerCards->sumOfCards > 11) //ako je 
	//	dealerCards->cards[1] = 1;
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
	//else if (playerCards->cards[1] == 1 && playerCards->sumOfCards > 11)
	//	playerCards->cards[1] = 1;
	playerCards->numOfCards++;
	playerCards->sumOfCards += playerCards->cards[1];

	printCards(*dealerCards, *playerCards);

	if (dealerCards->sumOfCards == 21 && playerCards->sumOfCards != 21)  //provjera za inicijalni black jack dealera ili igraca
	{
		printf("DEALER CARDS:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("DEALER GOT A BLACK JACK\n");
		//oduzimanje poena -100...
		return 1;
	}
	if (playerCards->sumOfCards == 21 && dealerCards->sumOfCards != 21)
	{
		printf("DEALER CARDS:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("CONGRATULATIONS YOU GOT BLACK JACK\n");
		//dodavanje poena +100......
		return 1;
	}
	if (dealerCards->sumOfCards == 21 && playerCards->sumOfCards == 21)
	{
		printf("DEALER CARDS:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("YOU ARE TIED\n");
		//poeni ostaju na 0
		return 1;
	}
	if (playerCards->sumOfCards > 21 && dealerCards->sumOfCards < 22)
	{
		printf("DEALER CARDS:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], 2, dealerCards->cards[1]);
		printf("\nBUST - SORRY YOU LOSE\n");
		//oduzimanje poena -100...
		return 1;
	}
	return 0;
}

void printCards(CARD card1, CARD card2)         //ispis inicijalnih karata
{
	printf("\n");
	printf("DEALER CARDS:\n");
	printf("%d. %d \n%d. X\n", 1, card1.cards[0], 2);
	printf("YOUR CARDS: \n");
	printf("%d. %d \n%d. %d \n", 1, card2.cards[0], 2, card2.cards[1]);
}

void printPlayerCards(CARD cards)         //ispis igracevih karti
{
	printf("\nYOUR CARDS: \n");
	for (int i = 0; i < cards.numOfCards; i++)
		printf("%d. %d\n", i + 1, cards.cards[i]);
}

void printDealerCards(CARD cards)      //dealerove karte
{
	printf("DEALER CARDS:\n");
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
	int result;
	printf("\n~~~~~~~ PRESS ~~~~~~~~~~\n");
	printf("<1> TO HIT \n<2> TO STAND \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	scanf("%d", &result);
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


int dealerCardsCheck(CARD cards)    //provjera dealerovih karata
{
	if (cards.sumOfCards > 21)
	{
		printf("\nDEALER BUST - CONGRATULATIONS\n");
		//dodjela poena....
		return 1;
	}

	if (cards.sumOfCards == 21)
	{
		//stand = 1;
		printf("\nSORRY, DEALER GOT A BLACK JACK - YOU LOSE\n");
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
		printf("\nCONGRATULATIONS YOU WIN\n");
		//dodjela poena....
		return 1;
	}
	if (playerCards.sumOfCards < dealerCards.sumOfCards)
	{
		printf("\nSORRY YOU LOSE\n");
		//oduzimanje poena....
		return -1;
	}
	if (playerCards.sumOfCards == dealerCards.sumOfCards)
	{
		printf("YOU ARE TIED\n");
		//poeni ostaju na istom....
		return 0;
	}
}
