#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	
	int *t = new int(100);
	
	t[1] = 5;
	cout << t[1] << endl;
	
	return 0;
}
