#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int d,m;
	cout<<"Wprowadz miesiac"<<endl;
	cin>>m;	
	
	if (m>12)
	{
	cout<<"Podales zly miesiac"<<endl;
	system("pause");
	return 0;
	}
	
	cout<<"Wprowadz dzien"<<endl;
	cin>>d;
		
	if (m==1 || m==3 || m==5 || m==7  || m==8 || m==10  || m==12)
	{
		if (d<=31 && d>0)
		cout<<"Poprawny dzien miesiaca"<<endl;
		else
		cout<<"Podales zly dzien"<<endl;
		}
		
	if (m==2)
	{
		if (d<=28 && d>0)
		cout<<"Poprawny dzien miesiaca"<<endl;
		else
		cout<<"Podales zly dzien"<<endl;
		}
			
	if (m==4 || m==6 || m==9 || m==11)
	{
		if (d<=30 && d>0)
		cout<<"Poprawny dzien miesiaca"<<endl;
		else
		cout<<"Podales zly dzien"<<endl;
		}
	
	system("pause");
	return 0;
}

