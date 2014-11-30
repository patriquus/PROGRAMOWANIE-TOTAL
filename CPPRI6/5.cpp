#include <cstdlib>
#include <iostream>

using namespace std;

double temp(double);

int main(int argc, char *argv[]) {
	
	int c;
	cout << "Podaj temperature w stopniach Celsjusza: ";
	cin >> c;
	int f = temp(c);
	cout << c << " st. Celsjusza to " << f << " st. Farhrenheita";
	cin.get();
	return 0;
}

double temp(double c) {
	int f = 1.8 * c + 32;
	return f;

}
