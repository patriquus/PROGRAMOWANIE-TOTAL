#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	int rozmiar;
	cin >> rozmiar;
	int *t = new int(rozmiar);
	
	t[1] = 5;
	cout << t[1] << endl;
	
	delete t;
	
	return 0;
}
