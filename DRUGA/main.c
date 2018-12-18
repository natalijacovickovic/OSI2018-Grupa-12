#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


void odbrojavanje()
{
    FILE *dat;
    int i;
    if((dat=fopen("tri.txt","r"))!=NULL)
    {
         while((i=fgetc(dat))!=EOF)
            printf("%c",i);
        fclose(dat);
    }
    Sleep(1000);
    system("cls");

    if((dat=fopen("dva.txt","r"))!=NULL)
    {
         while((i=fgetc(dat))!=EOF)
            printf("%c",i);
        fclose(dat);
    }
    Sleep(1000);
    system("cls");

    if((dat=fopen("jedan.txt","r"))!=NULL)
    {
         while((i=fgetc(dat))!=EOF)
            printf("%c",i);
        fclose(dat);
    }
    Sleep(1000);
    system("cls");
}

void naziv()
{
    FILE *dat;
    int i;
    if((dat=fopen("druga.txt","r"))!=NULL)
    {
        while((i=fgetc(dat))!=EOF)
        {
            printf("%c",i);
        }
        fclose(dat);
    }
}

int main()
{
    system("color 07");
    naziv();
    Sleep(3000);
    system("cls");
    odbrojavanje();
    return 0;
}
