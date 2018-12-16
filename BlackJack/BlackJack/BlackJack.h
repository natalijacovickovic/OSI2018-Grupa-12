#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

typedef struct Card
{
	int *cards;
	int sumOfCards;
	int numOfCards;
} CARD;

void printWelcome();
void printMenu();
int printOptions();
int dealCards(CARD *, CARD *);
void printCards(CARD, CARD);
void printPlayerCards(CARD);
void printDealerCards(CARD);
int optionCheck(int);

void hit(CARD *);
int dealerCardsCheck(CARD);

int winnerCheck(CARD, CARD);
