#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int strcmp2(char a[], char b[])
{
	for (int i=0; i<n; i++)
	{
		if (a[i]=b[i])
	}
}

int main(int argc, char *argv[])
{	
	char s1[12] = "Ala ma kota";
	char s2[4] = "Kot";
	char s3[12] = "\0";
	
	strncpy(s3, s1);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	
	cout<<strcmp(s3, s1);
		
	system("pause");
	return 0;
}
