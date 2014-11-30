#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int r,m,d;
	cout<<"Wprowadz dzien"<<endl;
	cin>>d;	
	
	cout<<"Wprowadz miesiac"<<endl;
	cin>>m;	
	
	if (m>12 || m<1)
	{
	cout<<"Podales zly miesiac"<<endl;
	system("pause");
	return 0;
	}
	
	cout<<"Wprowadz rok"<<endl;
	cin>>r;
		
	if (m==1)
	cout<<d<<endl;	
	
	if (m==2)
	d=d+31;
	
	if (m==3)
	d=d+59;
	
	if (m==4)
	d=d+89;
	
	if (m==5)
	d=d+120;
	
	if (m==6)
	d=d+150;
	
	if (m==7)
	d=d+181;
	
	if (m==8)
	d=d+212;
	
	if (m==9)
	d=d+242;
	
	if (m==10)
	d=d+273;
	
	if (m==11)
	d=d+303;
	
	if (m==12)
	d=d+334;

	{
		if (r%4==0 && r%100!=0 || r%400==0)
		cout<<d+1<<endl;
		else
		cout<<d<<endl;
		}	
		
	
		system("pause");
	return 0;
}

