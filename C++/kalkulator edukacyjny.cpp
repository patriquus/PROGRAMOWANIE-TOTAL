#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
	srand(time(0));
	int c;
	char t;
	int i,p=0;

	do	{
		int dzialanie=rand()%4;
		int a=rand()%10;
		int b=rand()%10;
		
		if (dzialanie==3 && b==0)
	    b=rand()%9+1;
				
		cout<<"Powiedz mi ile to jest"<<endl;	
		i++;
		switch (dzialanie)
		
			{
			case 0:
				cout<<a<<"+"<<b<<endl;
				cin>>c;
				if (a+b==c)
				   {
					cout<<"Dobrze!"<<endl;
					p++;				   		   
				   }
				else
					cout<<"Zle! "<<a<<"+"<<b<<"="<<a+b<<endl;
				break;	
					
			case 1:
				cout<<a<<"-"<<b<<endl;
				cin>>c;
				if (a-b==c)
				   {
					cout<<"Dobrze!"<<endl;
					p++;				   		   
				   }
				else
					cout<<"Zle! "<<a<<"-"<<b<<"="<<a-b<<endl;
				break;	
				
			case 2:
				cout<<a<<"*"<<b<<endl;
				cin>>c;
				if (a*b==c)
				   {
					cout<<"Dobrze!"<<endl;
					p++;				   		   
				   }
				else
					cout<<"Zle! "<<a<<"*"<<b<<"="<<a*b<<endl;
				break;
									
			case 3:	
				cout<<a<<"/"<<b<<endl;
				cin>>c;
				
				if (a/b==c)
				{
					cout<<"Dobrze!"<<endl;
					cout<<"Ile zostaje reszty?"<<endl;
					cin>>c;
						   if (a%b==c)
						   {
  	  		  			   cout<<"Brawo! Jestes dobry!"<<endl;
						   p++;
						   }
						   else
						   cout<<"Niestety! Reszta wynosi "<<a%b<<endl;						   
				}		 
						     
				else
					cout<<"Zle! "<<a<<"/"<<b<<"="<<a/b<<" reszty "<<a%b<<endl;
				break;									
			}	
	
	cout<<"Masz "<<p<<" pkt na "<<i<<" mozliwych"<<endl;			
	cout<<"Czy chcesz nastepne zadanie? T/N"<<endl;
	cin>>t;

	}
	while (tolower(t)=='t');
			
	system("pause");
	return 0;
}
