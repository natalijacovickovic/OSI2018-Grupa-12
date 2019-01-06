#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <math.h>


void shuffle(int *niz, int n);
extern int dobijeno;
extern int izgubljeno;
extern int brojBodova;
extern int status[4]; // status igara (zakljucane/otkljucane)
extern int brojIgranja; // broj igranja prve igre
extern int uslovKorisnika; // pri povratku na pocetni ekran, provjera da li
						   // je korisnik tek usao u igru ili je samo zavrio sa trenutnom igrom

void upisiBodove(int bodovi); // cuvanje bodova u datoteci
void printOut(); // pomocna funkcija za ispis