#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

void strcpy2(char a[], char b[])
{
	for (int i=0; b[i]!='\0'; i++)
		a[i]=b[i];
}

int main(int argc, char *argv[])
{	
	char s1[4] = "Ala";
	char s2[4] = "Kot";
	char s3[4] = "\0";
	
	strcpy2(s3, s1);
	cout<<s3;
	
	system("pause");
	return 0;
}
