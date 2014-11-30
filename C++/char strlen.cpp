#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{	
	char s[12]="Ala ma kota";
	
	for(int i=0; i<12; i++)
	{
	cout<<s[i]<<endl;
	}
	cout<<strlen(s)<<endl;


int licz = 0;
int i = 0;
for(i=0; s[i]!='\0'; i++)
{
	if (s[i]=='a' || s[i]=='A')
	{
		licz++;
	}
}

cout<<"W zdaniu sa "<<licz<<" litery A"<<endl;
	
	system("pause");
	return 0;
}
