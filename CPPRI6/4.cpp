#include <cstdlib>
#include <iostream>

using namespace std;

int wiek(int);

int main(int argc, char *argv[]) {
	
	int l;
	cout << "Podaj swoj wiek: ";
	cin >> l;
	int m = wiek(l);
	cout << "Twoj wiek w miesiacach wynosi " << m;
	cin.get();
	return 0;
}

int wiek(int l) {
	int m = l * 12;
	return m;
}
