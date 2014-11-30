#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

void strncpy2(char a[], char b[], int n)
{
	for (int i=0; i<n; i++)
		a[i]=b[i];
}

int main(int argc, char *argv[])
{	
	char s1[12] = "Ala ma kota";
	char s2[4] = "Kot";
	char s3[12] = "\0";
	
	strncpy2(s3, s1, 1);
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
		
	system("pause");
	return 0;
}
