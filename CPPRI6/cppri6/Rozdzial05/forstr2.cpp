#include <iostream>
#include <string>
int main()
{
    using namespace std;
    cout << "Podaj słowo: ";
    string word;
    cin >> word;

    // fizycznie modyfikujemy obiekt string
    char temp;
    int i, j;
    for (j = 0, i = word.size() - 1; j < i; --i, ++j)
    {                       // początek bloku
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }                       // koniec bloku
    cout << word << "\nGotowe\n";
    return 0; 
}
