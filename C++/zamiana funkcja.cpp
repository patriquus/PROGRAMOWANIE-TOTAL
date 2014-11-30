#include <cstdlib>
#include <iostream>

using namespace std;

void zamiana2(int &a, int &b) {
	int pom;
	pom = a;
	a = b;
	b = pom;
	
	cout << "w funkcji a=" << a << " b=" << b << endl;
}

void zamiana3(int *a, int *b) {
	int pom;
	pom = *a;
	*a = *b;
	*b = pom;
	
	cout << "w funkcji a=" << *a << " b=" << *b << endl;
}

int main(int argc, char *argv[])
{
	int x = 5, y = 10, pom;

	cout << "x=" << x << " y=" << y << endl;
	
	zamiana2(x,y);
	cout << "po zamianie x=" << x << " y=" << y << endl;	
	
	zamiana3(&x,&y);
	cout << "po 2 zamianie x=" << x << " y=" << y << endl;
				
	system("pause");
	return 0;
}
