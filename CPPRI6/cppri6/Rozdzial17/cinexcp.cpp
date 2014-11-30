// cinexcp.cpp -- obiekt cin zgłaszający wyjątek
#include <iostream>
#include <exception>

int main()
{
    using namespace std;
    // zgłaszanie wyjątku wskutek ustawienia bitu failbit
    cin.exceptions(ios_base::failbit);
    cout << "Podaj liczby: ";
    int sum = 0;
    int input;
    try {
        while (cin >> input)
        {
            sum += input;
        }
    } catch(ios_base::failure & bf)
    {
        cout << bf.what() << endl;
        cout << "O! Tragedia!\n";
    }

    cout << "Ostatnia wprowadzona wartość = " << input << endl;
    cout << "Suma = " << sum << endl;

    return 0;
}

