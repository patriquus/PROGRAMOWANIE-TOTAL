#include <cstdlib>
#include <iostream>

using namespace std;

int mileNaMetry(int);

int mileNaMetry(int mile) {
	int metry;
	metry = mile * 1852;
	return metry;
}


int main(int argc, char *argv[]) {
	int mile;
	cout << "Podaj odleglosc w milach morskich: ";
	cin >> mile;
	int metry = mileNaMetry(mile);
	cout << mile << " mil = ";
	cout << metry << " m";
	cin.get();
	return 0;
}
