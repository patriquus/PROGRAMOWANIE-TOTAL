// textin4.cpp -- wczytywanie znaków za pomocą cin.get()
#include <iostream>
int main(void)
{
    using namespace std;
    int ch;                         // używamy typu int zamiast char
    int count = 0;

    while ((ch = cin.get()) != EOF) // sprawdzenie EOF
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << "wczytano " << count << " znaków\n";
    return 0; 
}
