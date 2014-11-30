#include <cstdlib>
#include <iostream>

using namespace std;

class A {
	public: int aa;
};

int main(int argc, char *argv[]) {
	{
	A ob1;
	A ob2 = new A()
	ob1.aa = 100;
	cout << ob1.aa;
	}

	cout << ob2.aa << endl;
	
	return 0;
}
