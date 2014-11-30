#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

main()

{
    int a,b;
    printf("Witaj w programie obliczajacym NWD\n\n");
    printf("Podaj a\n");
    scanf("%d", &a);
    printf("Podaj b\n");
    scanf("%d", &b);

    do
    {
        if (a>b)
        {
            a=a-b;
        }

        if (a<b)
        {
            b=b-a;
        }
    }

    while (a!=b);

    printf("NWD wynosi\n");
    printf("%d", a);
    printf("\n\nDziekuje za uzycie programu. Patryk Gradys\n\n");

    getch();
    return 0;
}
