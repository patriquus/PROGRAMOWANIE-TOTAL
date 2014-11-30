#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	int a = 5, b = 100;
	int *p = &a;
	p = &b;

	cout << "WARTOSC ZMIENNEJ a= " << a << endl;
	cout << "ADRES ZMIENNEJ &a = " << p << endl;
	cout << "WARTOSC WSKAZNIKA *p = " << *p << endl; 
	cout << "ADRES WSKAZNIKA &p = " << &p << endl;
	
	return 0;
}
