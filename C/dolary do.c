#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{

    int x;

    printf("Ile chcesz dolarow?\n");
    scanf("%d", &x);

    do

    {
        printf("$");
        x--;
    }

        while (x>0);

    printf("\n\nDziekuje, do widzenia :)");
    getch();
    return 0;
}
