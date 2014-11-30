#include <cstdlib>
#include <iostream>
using namespace std;

void time(int, int);

int main(int argc, char *argv[]) {
	int h;
	cout << "Podaj liczbe godzin: ";
	cin >> h;
	int m;
	cout << "Podaj liczbe minut: ";
	cin >> m;
	time(h, m);	
	cin.get();
	return 0;
}

void time(int h, int m) {
	cout << "Czas: " << h << ":" << m;
}
