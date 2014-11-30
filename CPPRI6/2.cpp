#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "Podaj odleglosc w milach morskich: ";
	int mile;
	cin >> mile;
	cout << mile << " NM to " << 1852*mile << " metrow";
	cin.get();
	return 0;
}
