#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	for (int i=0; i<3; i++)
		{
			for(int j=0; j<5; j++)
		{
			cout<<"Petla zewnetrzna nr:"<<i<<" ";
			cout<<"Petla wewnetrzna nr:"<<j<<endl;
		}
		}
	system("pause");
	return 0;
}


	


