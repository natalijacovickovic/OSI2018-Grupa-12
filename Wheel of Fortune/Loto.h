#ifndef LOTO_H_INCLUDED
#define LOTO_H_INCLUDED

#include "Libraries.h"
#include "Namjestanje.h"
void startLoto();
void spinNumbers(int *);
void animation1();

void startLoto()
{
    int dozvoljeno=provjera();
    int sviBrojevi[46],i;
    for (i = 0; i < 46; i++)
        sviBrojevi[i] = i;
    shuffle(sviBrojevi, 46);
    int korisnikoviBrojevi[7]={0};
    printf("Unesite 7 brojeva (od 0 do 45): ");
    for (i = 0; i < 7; i++) // ogranicenje unosa samo na brojeve u odgovarajucem opsegu
    {
        do
        {
            if (scanf("%d", &korisnikoviBrojevi[i]) != 1)
            {
                char chr = getchar();
                printf("Pogresan unos, pokusajte ponovo.\n");
                int uslov = 0,j;
                for (j = 0; j < i; j++)
                    if (korisnikoviBrojevi[j] == korisnikoviBrojevi[i])
                        uslov = 1;
                if (uslov)
                    i--;
            }
            else if (korisnikoviBrojevi[i] > 45 || korisnikoviBrojevi[i] < 0)
                printf("Pogresan unos, pokusajte ponovo.\n");
            else if (korisnikoviBrojevi[i] < 46 || korisnikoviBrojevi[i] > -1)
            {
                int uslov = 0;
                int j;
                for (j = 0; j < i; j++)
                    if (korisnikoviBrojevi[j] == korisnikoviBrojevi[i])
                        uslov = 1;
                if (uslov)
                {
                    printf("Vec ste unijeli dati broj.\n");
                    i--;
                }
            }
            else
                break;

        }
        while (korisnikoviBrojevi[i] < 0 || korisnikoviBrojevi[i]>45);
    }
    printf("\n");
    printf("Vasi brojevi su: ");
    int z;
    for ( z = 0; z < 7; z++)
        printf("%d ", korisnikoviBrojevi[z]);
    int pronadjeniBroj;
    animation1(); // "animacija"
    int bodovi = 0;
    int p=0;
    int brojPogodjenih = 0;
    int brojac=0;
    do
    {
        spinNumbers(sviBrojevi);// "animacija"
LABEL:;
        pronadjeniBroj = sviBrojevi[p];
        for(z=0; z<7; z++)
            if(pronadjeniBroj==korisnikoviBrojevi[z])
            {
                brojPogodjenih++;
                bodovi+=brojPogodjenih*10;
            }
        if(bodovi>dozvoljeno)
        {
            bodovi-=brojPogodjenih*10;
            brojPogodjenih--;
            p++;
            goto LABEL;
        }
        else
        {
            printf("%d ",pronadjeniBroj);
            brojac++;
            p++;
        }

    }while(brojac<20);
    printf("\nPogodili ste %d %s i osvojili %d bodova.\n", brojPogodjenih, brojPogodjenih == 1 ? "broj" : (brojPogodjenih < 5 ? "broja" : "brojeva"), bodovi);
    upisiBodoveudat(bodovi, 3);
    printf("Imate ukupno %d bodova.\n", brojBodova);
    upisiBodove(brojBodova);
    printOut();
    system("cls");
}

void spinNumbers(int *sviBrojevi) // "animacija" promjene brojeva
{
    int j;
    for ( j = 0; j < 46; j++)
    {
        if (sviBrojevi[j] < 10)
        {
            printf("%d\b", sviBrojevi[j]);
            Sleep(55);
        }
        else
        {
            printf("%d\b\b", sviBrojevi[j]);
            Sleep(55);
        }
    }
}


void animation1()
{
    printf("\nIzvlacenje pocinje za "); // "animacija"
    printf("3");
    Sleep(1000);
    printf("\b");
    printf("2");
    Sleep(1000);
    printf("\b");
    printf("1");
    Sleep(1000);
    int i;
    for (i = 0; i < 50; i++) // ciscenje posljednjeg reda u konzoli
        printf("\b");
    for (i = 0; i < 50; i++)
        printf(" ");
    //for (int i = 0; i < 51; i++)
    //printf("\b");
    printf("\n");
}

#endif // LOTO_H_INCLUDED

