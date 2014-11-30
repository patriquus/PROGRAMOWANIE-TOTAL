// placenew2.cpp -- new, miejscowa wersja new, bez delete
#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s = "Obiekt testowy", int n = 0)
        {words = s; number = n; cout << words << " skonstruowany\n"; }
        ~JustTesting() { cout << words << " usunięty\n";}
        void Show() const { cout << words << ", " << number << endl;}
};

int main()
{
    char * buffer = new char[BUF];        // przydział bloku pamięci do testów

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;       // umieszcza nowy obiekt w buforze
    pc2 = new JustTesting("Sterta1", 20); // umieszcza nowy obiekt na stercie

    cout << "Adresy bloków pamięci:\n" << "bufor: "
        << (void *) buffer << "  sterta: " << pc2 <<endl;
    cout << "Zawartość pamięci:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
    // poprawiony przydział miejscową wersją new
    pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Lepszy pomysł", 6);
    pc4 = new JustTesting("Sterta2", 10);

    cout << "Zawartość pamięci:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                           // zwolnienie Sterta1
    delete pc4;                           // zwolnienie Sterta2
    // jawne wywołania destruktorów obiektów przydzielanych miejscową wersją new
    pc3->~JustTesting();                  // zwolnienie obiektu wskazywanego przez pc3
    pc1->~JustTesting();                  // zwolnienie obiektu wskazywanego przez pc1
    delete [] buffer;                     // zwolnienie bufora
    cout << "Fajrant\n";

    return 0;
}

