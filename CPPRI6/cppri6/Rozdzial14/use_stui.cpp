// use_stui.cpp -- korzystanie z klasy z dziedziczeniem prywatnym
// kompilacja z plikiem studenti.cpp
#include <iostream>
#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] = 
    {Student(quizzes), Student(quizzes), Student(quizzes)};

    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);
    cout << "\nLista studentów:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;
    cout << "\nWyniki:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "średnia: " << ada[i].Average() << endl;
    }
    cout << "Koniec.\n";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Wpisz imię i nazwisko studenta: ";
    getline(cin, sa);
    cout << "Wpisz " << n << " wyników testów:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}

