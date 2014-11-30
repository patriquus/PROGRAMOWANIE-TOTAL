#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int x;

    printf("Ile chcesz dolarow?\n");
    scanf("%d", &x);

    for (x>0; x--;)
    {
        printf("$");
    }

    printf("\n\nDziekuje, do widzenia :)");
    getch();
    return 0;
}
