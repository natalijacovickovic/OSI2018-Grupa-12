#include "Namjestanje.h"

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

    int n=((40*brojBodova)/100)+brojBodova;
    if(izgubljeno<n)
        return 0;
    else
       return abs(n-izgubljeno);

}