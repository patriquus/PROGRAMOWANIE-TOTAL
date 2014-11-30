#include <cstdlib>
#include <iostream>

using namespace std;

void zamiana1(int x, int y) {
	int pom = x;
	x = y;
	y = pom;
}

// PRZEZ REFERENCJE:
void zamiana2(int &x, int &y) {
	int pom = x;
	x = y;
	y = pom;
}

// PRZEZ WSKAZNIK:
void zamiana3(int *x, int *y) {
	int pom = *x;
	*x = *y;
	*y = pom;
}

int main(int argc, char *argv[]) {
	
	int x = 1, y = 2000;
	
	cout << "1. wywolanie: ";
	cout << "x = " << x << " y = " << y << endl;
	
//	zamiana2(x, y)	przez referencje (x, y)
	zamiana3(&x, &y);	//przez wskaznik (&x, &y)
	
	cout << "2. wywolanie: ";
	cout << "x = " << x << " y = " << y << endl;
	
	return 0;
}
