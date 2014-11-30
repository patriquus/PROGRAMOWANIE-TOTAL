#include <cstdlib>
#include <iostream>

using namespace std;

void zamiana(int &x, int &y) {
	int pom = x;
	x = x * 100;
	y = y + x;
}

int main(int argc, char *argv[]) {
	
	int x = 1, y = 2000;
	
	cout << "1. wywolanie: ";
	cout << "x = " << x << " y = " << y << endl;
	
	zamiana(x, y);
	
	cout << "2. wywolanie: ";
	cout << "x = " << x << " y = " << y << endl;
	
	return 0;
}
