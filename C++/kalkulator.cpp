#include <stdio.h>
#include <conio.h>
#include <stdlib.h>     //biblioteka potrzebna do czyszczenia ekranu

int main()

{
    int  liczba;
    float a,b,r,h,s;
    const float PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;
        //deklaracje zmiennych i stalej
    do      //zastosowanie petli do ... while
    {
        system("cls");  //czyszczenie ekranu
        puts("Witaj w programie KALKULATOR \t\t(C)2012 Patryk Gradys\n\nWybierz, co chcesz obliczyc: \n");
        puts("[1] OBJETOSC KULI \n[2] OBJETOSC WALCA \n[3] POLE TRAPEZU \n[4] POLE KWADRATU \n[5] POLE KOLA \n");

        scanf("%d", &liczba);
        switch(liczba)  //zastosowanie instrukcji warunkowej switch

        {
        case 1:
        {
            puts("Wybrales kule");
            puts("Podaj promien kuli");
            scanf("%f", &r);
            float s=4/3*PI*r*r*r;
            printf("Objetosc kuli wynosi: \n");
            printf("%.2f", s);
        }
        break;

        case 2:
        {
            puts("Wybrales walec");
            puts("Podaj promien podstawy walca");
            scanf("%f", &r);

            puts("Podaj wysokosc walca");
            scanf("%f", &h);

            float s=PI*r*r*h;
            printf("Objetosc walca wynosi: \n");
            printf("%.2f", s);
        }
        break;

        case 3:
        {
            puts("Wybrales trapez");
            puts("Podaj wysokosc trapezu");
            scanf("%f", &h);

            puts("Podaj dlugosc podstawy a");
            scanf("%f", &a);

            puts("Podaj dlugosc podstawy b");
            scanf("%f", &b);

            float s=(a+b)*h/2;
            printf("Pole trapezu wynosi: \n");
            printf("%.2f", s);
        }
        break;

        case 4:
        {
            puts("Wybrales kwadrat");
            puts("Podaj dlugosc boku kwadratu");
            scanf("%f", &a);
            float s=a*a;
            printf("Pole kwadratu wynosi: \n");
            printf("%.2f", s);
        }
        break;

        case 5:
        {
            puts("Wybrales kolo");
            puts("Podaj promien kola");
            scanf("%f", &r);
            float s=PI*r*r;
            printf("Pole kola wynosi: \n");
            printf("%.2f", s);
        }
        break;

        default:
            puts("Wybrales zla liczbe!");
            break;

        }
        printf("\n\nAby zakonczyc wcisnij 0 i ENTER \n");
        printf("Aby wrocic do poczatku wcisnij dowolna liczbe i ENTER \n");
        scanf("%d",&liczba);
    }
    while(liczba!=0);
    return 0;
}

