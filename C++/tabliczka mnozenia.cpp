#include <cstdlib>
#include <iostream>
#include <iomanip>>

using namespace std;

void funkcja(int,int);

int main(int argc, char *argv[])
{
	int x,y;
	funkcja(x,y);
	system("pause");
	return 0;
}

void funkcja(int x, int y)
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10; j++)
		{
			cout<<setw(4)<<i*j;		
		}
		cout<<endl;
	}	
}

	


