#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, d, x1, x2, x;
    int rpt=1;
    do
    {
        system("cls");
        printf("ROWNANIE KWADRATOWE\n");
        printf("Wprowadz a\n");

        scanf("%f", &a);
        printf("Wprowadz b\n");
        scanf("%f", &b);
        printf("Wprowadz c\n");
        scanf("%f", &c);

        d=b*b-4*a*c;
        printf("\nDelta wynosi\n");
        printf("%10.2f", d);

        if (d>=0)
        {
            x1=(-b+sqrt(d)/(2*a));
            printf("\n\nx1 wynosi\n");
            printf("%10.2f", x1);

            x2=(-b-sqrt(d)/(2*a));
            printf("\n\nx2 wynosi\n");
            printf("%10.2f", x2, "\n");
            getch();
        }

        else
        {
            printf("\n Rownanie sprzeczne\n");
            getch();
        }

    }
    while(rpt != 0);
    printf("\n(C) 05.2012 Patryk Gradys\n\n");
    return 0;
}

