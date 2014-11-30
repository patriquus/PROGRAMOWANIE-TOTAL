#include <cstdlib>
#include <iostream>

using namespace std;

class A {
	public: int aa;
	A(){};
	A(int a) {this -> aa = a;}
	~A() {cout << "obiekt zostal zniszczony\n";
	}
};

int main(int argc, char *argv[]) {

{
	A x, y, z;
	x.aa = 5000;
	cout << x.aa << endl;
}

	A *ob2 = new A();
	ob2 -> aa = 50;
	cout << ob2 -> aa << endl;
	delete ob2;	

	return 0;
}
