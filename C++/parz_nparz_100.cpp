#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i=1;
	for	( ; i <= 100; i++)
	{
		if(i%2!=0){
		
		continue;
	}
		cout<<i<<endl;
		}	
	
cout<<endl<<endl;
	int x=100;
	for	( ; x >0;x--)
	{
		if(x%2==0){
		
		continue;
	}
		cout<<x<<endl;
		}	
	system("pause");
	return 0;
}

