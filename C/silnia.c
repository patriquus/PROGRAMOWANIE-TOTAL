#include <stdio.h>
#include <stdlib.h>

int n, silnia = 1;

int main()
{
    system("cls");
    printf("Program obliczajacy silnie\n");
    printf("---------------------------\n\n");
    printf("Podaj liczbe: ");
    scanf("%d", &n);

while (n>0)
{

    int i;
    for (i = 2; i <= n; ++i)
            silnia *= i;

        printf("%d! = %d\n", n, silnia);

    printf("\nDziekuje za uzycie programu\nPatryk Gradys (C)2012\n");
    getch();



    return 0;
    }
}
