// sayings2.cpp -- stosowanie wskaźników obiektów
// kompilować z plikiem string1.cpp
#include <iostream>
#include <cstdlib>   // (albo stdlib.h) -- funkcje rand(), srand()
#include <ctime>     // (albo time.h) -- funkcja time()
#include "string1.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;
    String name;

    cout << "Cześć, jak masz na imię?\n>> ";
    cin >> name;

    cout << name << ", wpisz do " << ArSize
        << " krótkich powiedzonek <pusty wiersz kończy wprowadzanie>:\n";
    String sayings[ArSize];
    char temp[MaxLen];       // tymczasowy obiekt ciągu
    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')     // czyżby pusty wiersz?
            break;                       // bez zwiększania i
        else
            sayings[i] = temp;           // przeciążone przypisanie
    }
    int total = i;                       // łączna liczba wczytanych wierszy

    if (total > 0)
    {
        cout << "Oto Twoje powiedzonka:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        // wskaźniki wskazujące szukane ciągi
        String * shortest = &sayings[0]; // inicjalizacja pierwszym obiektem
        String * first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)         // porównanie wartości
                first = &sayings[i];         // skopiowanie adresu
        }

        cout << "Najkrótsze powiedzonko:\n" << *shortest << endl;
        cout << "Powiedzonko alfabetycznie pierwsze:\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total;    // wybierz liczbę losową
        // wywołanie operatora new do przydziału nowego obiektu
        String * favorite = new String(sayings[choice]);
        cout << "Moje ulubione powiedzonko:\n" << *favorite << endl;
        delete favorite;
    }
    else
        cout << "Nie ma o czym gadać, co?\n";

    cout << "Żegnam.\n";

    return 0;
}

