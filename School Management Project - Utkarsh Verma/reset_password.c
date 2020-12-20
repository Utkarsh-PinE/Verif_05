#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include <windows.h>
#define SIZE 32

void resetpassword()
{
    char pw[SIZE],c,rpw[SIZE];
    short int count,error;
    int option;

    Enter: printf("\nENETR NEW PASSWORD: ");
    int p=0,i=0;
    while((pw[p]=getch())!='\r')
    {

            if(pw[p]=='\b' && p>0)
            {
                p=p-2;
                printf("\b \b");
            }
            else if(pw[p]!='\b')
            printf("*");
        p++;
    }
    pw[p-1]='\0';
    FILE *fp;
        printf("\nRECONFIRM PASSWORD: ");
        while( (c=getch()) !='\r')
        {
            rpw[i]=c;
            putchar('*');
            i++;
        }
        rpw[i]='\0';
        //printf("\nComparing %s and %s.\n",pw,rpw);
        if(strcmp(pw,rpw)==0)
        {
            fp=fopen("./pswrd","wb");
            fprintf(fp, "%s", rpw);
            fclose(fp);
            printf("\n\n*******************************");
            printf("\nPASSWORD RESET SUCESSFULLY");
            printf("\n*******************************");
            Sleep(1000);
            system("cls");
        }
        else
        {
                printf("\nERROR: Password does not match");
                goto Enter;
        }
}
