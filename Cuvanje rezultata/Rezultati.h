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

void header(FILE *dat,int n)
{
    if(n==1)
    {
        fprintf(dat,"================   ==========\n");
        fprintf(dat,"Pogadjanje broja   Rezultat\n");
        fprintf(dat,"================   ==========\n");
    }
    else if(n==2)
    {
        fprintf(dat,"====   ==========\n");
        fprintf(dat,"Kviz   Rezultat\n");
        fprintf(dat,"====   ==========\n");
    }
    else if(n==3)
    {
        fprintf(dat,"====   ==========\n");
        fprintf(dat,"Loto   Rezultati\n");
        fprintf(dat,"====   ==========\n");
    }
    else if(n==4)
    {
        fprintf(dat,"=========   ==========\n");
        fprintf(dat,"BlackJack   Rezultat\n");
        fprintf(dat,"=========   ==========\n");
    }
}

void upis(FILE *dat,PODATAK *novi,int n)
{
    int i;
    if(n==1)
    {
        for(i=0; i<10; i++)
        {
            fprintf(dat,"%22d\n", novi[i].broj);
            fprintf(dat, "%21d.%d.%d\n\n",novi[i].vrijeme.tm_mday,novi[i].vrijeme.tm_mon,novi[i].vrijeme.tm_year);
        }
    }
    else if(n==2)
    {
        for(i=0; i<10; i++)
        {
            fprintf(dat,"%10d\n", novi[i].broj);
            fprintf(dat, "%9d.%d.%d\n\n",novi[i].vrijeme.tm_mday,novi[i].vrijeme.tm_mon,novi[i].vrijeme.tm_year);
        }
    }
    else if(n==3)
    {
        for(i=0; i<10; i++)
        {
            fprintf(dat,"%10d\n", novi[i].broj);
            fprintf(dat, "%9d.%d.%d\n\n",novi[i].vrijeme.tm_mday,novi[i].vrijeme.tm_mon,novi[i].vrijeme.tm_year);
        }
    }
    else if(n==4)
    {
        for(i=0; i<10; i++)
        {
            fprintf(dat,"%15d\n", novi[i].broj);
            fprintf(dat, "%14d.%d.%d\n\n",novi[i].vrijeme.tm_mday,novi[i].vrijeme.tm_mon,novi[i].vrijeme.tm_year);
        }
    }
}


void upisiBodove(int broj, int redniBroj)
{
    char**ime=(char*)calloc(4,sizeof(char*));
    ime[1]=(char)calloc(17,sizeof(char));
    ime[1]="Pogadjanje broja";
    ime[2]=(char)calloc(5,sizeof(char));
    ime[2]="Kviz";
    ime[3]=(char)calloc(5,sizeof(char));
    ime[3]="Loto";
    ime[4]=(char)calloc(11,sizeof(char));
    ime[4]="BlackJack";
    char r[9]="Rezultat";
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

    if(dat=fopen(naziv, "w"))
    {
        header(dat,redniBroj);
        fclose(dat);
    }
    if(dat=fopen(naziv,"a"))
    {
        upis(dat,novi,redniBroj);
        fclose(dat);
    }
    for(i=1; i<5; i++)
        free(ime[i]);
    free(niz);
    free(novi);


}

void ispisRezultata(int brojIgrice)
{
    FILE *dat;
    int i;
    char naziv[20]="Rezultati";
    char b[2];
    itoa(brojIgrice, b, 10);
    strcat(naziv,b);
    strcat(naziv, ".txt");
    if(dat=fopen(naziv,"r"))
    {
        while((i=fgetc(dat))!=EOF)
        {
            printf("%c",i);
        }
        fclose(dat);
    }

}

void cvs()
{
    char**ime=(char*)calloc(4,sizeof(char*));
    ime[1]=(char)calloc(17,sizeof(char));
    ime[1]="Pogadjanje broja";
    ime[2]=(char)calloc(5,sizeof(char));
    ime[2]="Kviz";
    ime[3]=(char)calloc(5,sizeof(char));
    ime[3]="Loto";
    ime[4]=(char)calloc(11,sizeof(char));
    ime[4]="BlackJack";
    int i,j=0;
    PODATAK *niz=(PODATAK*)calloc(40,sizeof(PODATAK));
    FILE *dat;
    char pom[150];
    char naziv[20]="Rezultati";
    char b[2];
    for(j=1; j<=4; j++)
    {
        itoa(j, b, 10);
        strcat(naziv,b);
        strcat(naziv, ".txt");
        if(dat=fopen(naziv,"r"))
        {
            fgets(pom, 150,dat);
            fgets(pom, 150,dat);
            fgets(pom, 150,dat);
            for(i=(j-1)*10; i<((j-1)*10)+10; i++)
            {
                fscanf(dat,"%d\n",&niz[i].broj);
                fscanf(dat,"%d.%d.%d\n",&niz[i].vrijeme.tm_mday,&niz[i].vrijeme.tm_mon,&niz[i].vrijeme.tm_year);

            }
            fclose(dat);
            strcpy(naziv,"Rezultati");
        }
    }
    if(dat=fopen("Rezultati.csv","a"))
    {
        for(j=1; j<=4; j++)
        {
            fprintf(dat,"%s\n",ime[j]);
            for(i=(j-1)*10; i<((j-1)*10)+10; i++)
            {
                fprintf(dat,"%d,", niz[i].broj);
                fprintf(dat, "%d.%d.%d\n",niz[i].vrijeme.tm_mday,niz[i].vrijeme.tm_mon,niz[i].vrijeme.tm_year);
            }
        }
        fclose(dat);
    }
    for(i=1;i<5;i++)
        free(ime[i]);
    free(niz);
}