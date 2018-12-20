#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct Card
{
	//int *cards;
	int cards[20];
	int sumOfCards;
	int numOfCards;
} CARD;

int startBlackJack();

void printWelcome();
void printOptionsHelp();
int printOptions();
int dealCards(CARD *, CARD *);
void printCards(CARD, CARD);
void printPlayerCards(CARD);
void printDealerCards(CARD);
int optionCheck(int);

void hit(CARD *);
int dealerCardsCheck(CARD, CARD);

int winnerCheck(CARD, CARD);
