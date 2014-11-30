#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int x,y;
	
	cout<<"Podaj x"<<endl;
	cin>>x;
	cout<<"Podaj y"<<endl;
	cin>>y;
	
	if(x>0 && y>0)
	{
		cout<<"Punkt lezy w I cwiartce ukladu wspolrzednych"<<endl;
		}
	
	else if(x<0 && y>0)
	{
		cout<<"Punkt lezy w II cwiartce ukladu wspolrzednych"<<endl;
		}

	else if(x<0 && y<0)
	{
		cout<<"Punkt lezy w III cwiartce ukladu wspolrzednych"<<endl;
		}

	else if(x>0 && y<0)
	{
		cout<<"Punkt lezy w IV cwiartce ukladu wspolrzednych"<<endl;
		}
			
	else if(x==0 && y!=0)
	{
		cout<<"Punkt lezy na osi y"<<endl;
		}
		
	else if(x!=0 && y==0)
	{
		cout<<"Punkt lezy na osi x"<<endl;
		}	
	
	else
	{
		cout<<"Punkt lezy na srodku ukladu wspolrzednych"<<endl;
		}
						
	system("pause");
	return 0;
}
