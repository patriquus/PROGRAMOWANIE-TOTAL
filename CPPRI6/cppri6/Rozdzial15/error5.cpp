// error5.cpp -- rozwijanie stosu
#include <iostream>
#include <cmath> // lub math.h; użytkownicy systemu UNIX mogą potrzebować opcji -lm
#include <string>
#include "exc_mean.h"

class demo
{
    private:
        std::string word;
    public:
        demo (const char * str)
        {
            word = str;
            std::cout << "Obiekt demo " << word << " utworzony\n";
        }
        ~demo()
        {
            std::cout << "Obiekt demo " << word << " usunięty\n";
        }
        void show() const
        {
            std::cout << "Obiekt demo " << word << " żyje\n";
        }
};

// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;
    {
        demo d1("z bloku zagnieżdżonego w funkcji main()");
        cout << "Podaj dwie liczby: ";
        while (cin >> x >> y)
        {
            try {   // początek bloku try
                z = means(x, y);
                cout << "Średnia średnich liczb " << x << " i " << y
                    << " wynosi " << z << endl;
                cout << "Podaj kolejną parę liczb: ";
            }   // koniec bloku try
            catch (bad_hmean & bg) // początek bloku catch
            {
                bg.mesg();
                cout << "Spróbuj ponownie.\n";
                continue;
            }
            catch (bad_gmean & hg)
            {
                cout << hg.mesg();
                cout << "Użyte wartości: " << hg.v1 << ", "
                    << hg.v2 << endl;
                cout << "Niestety, to koniec zabawy.\n";
                break;
            } // koniec bloku catch
        }
        d1.show();
    }
    cout << "Koniec\n";
    cin.get();
    cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

double means(double a, double b)
{
    double am, hm, gm;
    demo d2("z funkcji means()");
    am = (a + b) / 2.0; // średnia arytmetyczna
    try
    {
        hm = hmean(a, b);
        gm = gmean(a, b);
    }
    catch (bad_hmean & bg) // początek bloku catch
    {
        bg.mesg();
        std::cout << "Przechwycony w means()\n";
        throw; // ponownie zgłasza wyjątek
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}

