#include <cstdlib>
#include <iostream>

using namespace std;

void f1();
int f2();

void f1()
{
	cout<<"Uruchomiono funkcje f1"<<endl;
}

int f2(int x, int y)
{
	return x+y;
}

int main(int argc, char *argv[])
{
	f1();
	cout<<f2(5,10)<<endl;
	system("pause");
	return 0;
}
