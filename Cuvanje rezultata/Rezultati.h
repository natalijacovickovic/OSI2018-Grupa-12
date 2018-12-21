#ifndef REZULTATI_H_INCLUDED
#define REZULTATI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct podatak
{
    int broj;
    struct tm vrijeme;
}
PODATAK;


void upisiBodove(int broj, int redniBroj)
{
    int i,j=0;
    PODATAK *niz=(PODATAK*)calloc(10,sizeof(PODATAK));
    PODATAK *novi=(PODATAK*)calloc(10, sizeof(PODATAK));
    FILE *dat;
    char pom[150];
    char naziv[20]="Rezultati";
    char b[2];
    itoa(redniBroj, b, 10);
    strcat(naziv,b);
    strcat(naziv, ".txt");
    if(dat=fopen(naziv,"r"))
    {
        fgets(pom, 150,dat);
        fgets(pom, 150,dat);
        fgets(pom, 150,dat);
        for(i=0; i<10; i++)
        {
            fscanf(dat,"%d\n",&niz[i].broj);
            fscanf(dat,"%d.%d.%d\n",&niz[i].vrijeme.tm_mday,&niz[i].vrijeme.tm_mon,&niz[i].vrijeme.tm_year);

        }
        fclose(dat);
    }
    for(i=0;i<10;i++)
    {
        printf("%d ",niz[i].broj);
    }
    printf("\n");
    i=0;
    while(niz[i].broj>broj)
    {
        novi[i]=niz[i];
        j++;
        i++;
    }
    PODATAK p;
    p.broj=broj;
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    p.vrijeme=*timeinfo;
    p.vrijeme.tm_mon=p.vrijeme.tm_mon+1;
    p.vrijeme.tm_year=p.vrijeme.tm_year+1900;
    novi[i]=p;
    for(i+=1; i<10; j++,i++)
        novi[i]=niz[j];
    for(i=0;i<10;i++)
        printf("%d ",novi[i].broj);
    printf("\n\n");

    if(dat=fopen(naziv, "w"))
    {
        fprintf(dat,"================   ========\n");
        fprintf(dat,"Pogadjanje broja   Rezultat\n");
        fprintf(dat,"================   ========\n");
        fclose(dat);
    }
    if(dat=fopen(naziv,"a"))
    {
        for(i=0; i<10; i++)
        {
            fprintf(dat,"%22d\n", novi[i].broj);
            fprintf(dat, "%21d.%d.%d\n\n",novi[i].vrijeme.tm_mday,novi[i].vrijeme.tm_mon,novi[i].vrijeme.tm_year);
        }
        fclose(dat);
    }


}



#endif // REZULTATI_H_INCLUDED
