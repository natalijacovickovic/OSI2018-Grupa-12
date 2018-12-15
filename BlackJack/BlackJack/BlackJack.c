#include "BlackJack.h"

void printWelcome()
{
	printf("WELCOME TO BLACK JACK\n");
	printf("     GOOD LUCK :)	  \n\n");
	printf("You have ~~~ Points lef\n");
}



void dealCards(CARD *dealerCards, CARD *playerCards) //inicijalne 2 karte
{
	printf("\nIGRA POCINJE: \n");
	//CARD dealerCards;                                              //trenutne karte aplikacije
	dealerCards->cards = (int)malloc(2 * sizeof(int));              //2 karte su minimalne 
	dealerCards->numOfCards = dealerCards->sumOfCards = 0;
	//CARD playerCards;                                         //trenutne karte igraca
	playerCards->sumOfCards = playerCards->numOfCards = 0;
	playerCards->cards = (int)malloc(2 * sizeof(int));

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
	if (dealerCards->cards[1] == 11 && (dealerCards->sumOfCards > 11)) //ako ima zbir 11 ili vise sledeci kec se racuna kao 1
		dealerCards->cards[1] = 1;
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
	if (playerCards->cards[1] == 11 && (playerCards->sumOfCards > 11))
		playerCards->cards[1] = 1;
	playerCards->sumOfCards += playerCards->cards[1];

	printCards(*dealerCards, *playerCards);

	if (dealerCards->sumOfCards == 21 && playerCards->sumOfCards != 21)  //provjera za inicijalni black jack dealera ili igraca
	{
		printf("KARTE DEALERA SU:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], dealerCards->cards[1]);
		printf("DEALER IMA BLACK JACK I VI STE IZGUBILI\n");
		//oduzimanje poena -100...
		return;
	}
	if (playerCards->sumOfCards == 21 && dealerCards->sumOfCards != 21)
	{
		printf("CESTITAMO IMATE BLACK JACK\n");
		//dodavanje poena +100......
		return;
	}
	if (dealerCards->sumOfCards == 21 && playerCards->sumOfCards == 21)
	{
		printf("KARTE DEALERA SU:\n");
		printf("%d. %d \n%d. %d\n", 1, dealerCards->cards[0], dealerCards->cards[1]);
		printf("IMATE PODJEDNAK REZULTAT\n");
		//poeni ostaju na 0
		return;
	}
}

void printCards(CARD card1, CARD card2)         //ispis inicijalnih karata
{
	printf("\n");
	printf("KARTE DEALERA SU:\n");
	printf("%d. %d \n%d. X\n", 1, card1.cards[0], 2);
	printf("VASE KARTE SU: \n");
	printf("%d. %d \n%d. %d \n", 1, card2.cards[0], 2, card2.cards[1]);
}

void printPlayerCards(CARD cards)         //ispis igracevih karti
{
	printf("\nVASE KARTE SU: \n");
	for (int i = 0; i < cards.numOfCards; i++)
		printf("%d. %d\n", i + 1, cards.cards[i]);
}

void printDealerCards(CARD cards)      //dealerove karte
{
	printf("\nKARTE DEALERA SU: \n");
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
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nPRITISNITE <1> To hit <2> to stand: \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

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
	if (cards->cards[cards->numOfCards] == 1)
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
		printf("\nDEALER BUST - CESTITAMO\n");
		//dodjela poena....
		return 1;
	}

	if (cards.sumOfCards == 21)
	{
		//stand = 1;
		printf("\nDEALER IMA BLACK JACK - GUBITE POENE\n");
		//skidanje poena.....
		return 1;
	}

	if (cards.sumOfCards > 21)
	{
		printf("\nDEALER BUST - CESTITAMO\n");
		//dodjela poena....
		return 1;
	}
}

int winnerCheck(CARD dealerCards, CARD playerCards)  //provjera pobjednika
{
	if (playerCards.sumOfCards > dealerCards.sumOfCards)
	{
		printf("\nCESTITAMO POBJEDILI STE\n");
		//dodjela poena....
		return 1;
	}
	if (playerCards.sumOfCards < dealerCards.sumOfCards)
	{
		printf("\nNAZALOST STE IZGUBILI\n");
		//oduzimanje poena....
		return -1;
	}
	if (playerCards.sumOfCards == dealerCards.sumOfCards)
	{
		printf("IMATE ISTI REZULTAT - OSTAJE VAM ISTI BROJ POENA\n");
		//poeni ostaju na istom....
		return 0;
	}
}
