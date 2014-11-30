#include <cstdlib>
#include <iostream>

using namespace std;

class A {
	public: int aa;
	A(){};
};

int main(int argc, char *argv[]) {

	A *ob2 = new A();
	ob2 -> aa = 50;
	(*ob2).aa = 2;
	
	cout << ob2 -> aa << endl;

	return 0;
}
