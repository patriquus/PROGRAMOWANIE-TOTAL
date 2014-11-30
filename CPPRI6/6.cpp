#include <cstdlib>
#include <iostream>

using namespace std;

double lata(double);

int main(int argc, char *argv[]) {
	
	double l;	
	cout << "Podaj liczbe lat swietlnych: ";
	cin >> l;
	
	double ja = lata(l);
	cout << l << " lat swietlnych = " << ja << " jednostek astronomicznych";
	cin.get();
	return 0;
}

double lata(double l) {
	double ja = l * 63240;
	return ja;
}
