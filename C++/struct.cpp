#include <cstdlib>
#include <iostream>

using namespace std;

struct Nazwa
{
	int a;
	float b;
	char c;
};

int main(int argc, char *argv[])
{
	Nazwa s1,s2;
	
	s1.a = 5;
	s1.b = 3.5;
	s1.c = 'a';
	s2.a=10;
	
	cout<<s1.a<<endl;
	cout<<s1.b<<endl;
	cout<<s1.c<<endl;
	cout<<s2.a<<endl;
	system("pause");
	return 0;
}
