#include <stdio.h>
#include <stdlib.h>

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    int n=rand()%101;
    int i=1,broj;
    printf("Pogodite zamisljen broj!\n");
    while(i<=5)
    {
        printf("%d.pokusaj: ",i);
        scanf("%d",&broj);
        if(broj>n)
            {
                if(i!=5)
                    printf("Vas broj je veci od trazenog.\n");
                i++;
            }
        else if(broj<n)
            {
                if(i!=5)
                    printf("Vas broj je manji od trazenog.\n");
                i++;
            }
        else if(broj==n)
            break;

    }
    if(i<=5)
    {
        int bodovi=100/i;
        if(i==3)
            bodovi=35;
        printf("Cestitamo!  Pogodili ste broj!\n");
        printf("Osvojili ste %d bodova",bodovi);
    }
    else
        printf("Niste pogodili");

    return 0;
}
