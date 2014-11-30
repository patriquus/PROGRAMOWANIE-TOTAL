#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i;
	cout<<"Wprowadz rok"<<endl;
	cin>>i;
	
	if (i%4==0 && i%100!=0 || i%400==0)
	{
		cout<<"Rok przestepny"<<endl;
		}

	else
		cout<<"Rok nieprzestepny"<<endl;

	system("pause");
	return 0;
}

