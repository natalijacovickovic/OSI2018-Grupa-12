#ifndef NAMJESTANJE_H_INCLUDED
#define NAMJESTANJE_H_INCLUDED
#include<stdio.h>

extern int dobijeno;
extern int izgubljeno;

void upisiDobijeno(int n)
{
    FILE *dat;
    if(dat=fopen("Dobijeno.txt","w"))
    {
        fprintf(dat,"%d",n);
        fclose(dat);
    }
}

void upisiIzgubljeno(int n)
{
    FILE *dat;
    if(dat=fopen("Izgubljeno.txt","w"))
    {
        fprintf(dat,"%d",n);
        fclose(dat);
    }
}

int provjera()
{

    int n=((40*dobijeno)/100)+dobijeno;
    if(izgubljeno<n)
        return 0;
    else
       return abs(n-izgubljeno);

}


#endif // NAMJESTANJE_H_INCLUDED

