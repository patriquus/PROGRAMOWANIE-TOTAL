#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	const int rozmiar=10;
	int tab1[rozmiar]={0};
	
/*	tab1[0]=10;
	tab1[1]=20;
	tab1[2]=30;
	tab1[3]=40;
	tab1[4]=50;
		
	cout<<tab1[0]<<endl;
	cout<<tab1[1]<<endl;
	cout<<tab1[2]<<endl;
	cout<<tab1[3]<<endl;
	cout<<tab1[4]<<endl;	*/
	
	for (int i=0; i<5; i++)
		{
		cout<<"Podaj "<<i<<" element: ";
		cin>>tab1[i];
		cout<<endl;
			}
	
	for(int i=0; i<rozmiar; i++)
	cout<<tab1[i]<<endl;
	
	system("pause");
	return 0;
}
