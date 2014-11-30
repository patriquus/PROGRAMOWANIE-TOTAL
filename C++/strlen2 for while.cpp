#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int strlen2(char s[]){
int i = 0;

//for (i=0; s[i]!='\0'; i++)
while(s[i]!='\0');
{
	i++;
}

return i;
}

int main(int argc, char *argv[])
{	
	const int r=4;
	char s1[r]="Kot";
	char s2[r]={'A', 'l', 'a', '\0'};
	
	for(int i=0; i<r; i++)
	{
	cout<<s1[i]<<endl;
	}
	
	for(int i=0; i<r; i++)
	{
	cout<<s2[i]<<endl;
	}	
	
	cout<<strlen(s1)<<endl;
	cout<<strlen2(s2)<<endl;	
	
	system("pause");
	return 0;
}
