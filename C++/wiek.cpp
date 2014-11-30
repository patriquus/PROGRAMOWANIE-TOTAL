#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
int wiek;
char powt;

do{
cout<<"Podaj swoj wiek"<<endl;
cin>>wiek;

while (wiek<0 || wiek>122) 
{
cout<<"Wprowadziles zly wiek (ewentualnie jeszcze sie nie urodziles albo juz umarles), podaj wiek ponownie"<<endl;
cin>>wiek;
}

{
	
if (wiek<=3)
{
	cout<<"Prawdopodobnie uczysz sie chodzic i mowic"<<endl;	
}

else if (wiek > 3 && wiek < 7)
{
	cout<<"Chodzisz do przedszkola"<<endl;
}

else if (wiek >= 7 && wiek < 13)
{
	cout<<"Chodzisz do podstawowki"<<endl;	
}

else if (wiek >= 13 && wiek < 16)
{
	cout<<"Jestes gimbusem"<<endl;
}

else if (wiek >= 16 && wiek < 19)
{
	cout<<"Chodzisz do liceum"<<endl;
}

else if (wiek >= 19 && wiek < 25)
{
	cout<<"Prawdopodobnie jestes studentem"<<endl;
}

else if (wiek >= 25 && wiek < 40)
{
	cout<<"Pracujesz i zakladasz rodzine"<<endl;
}

else if (wiek >= 40 && wiek < 65)
{
	cout<<"Masz kryzys wieku sredniego"<<endl;
}

else if (wiek >= 65 && wiek < 100)
{
	cout<<"Dziadziejesz"<<endl;
}

else if (wiek==100)
{
	cout<<"Masz 100% znizki w Vision Express"<<endl;
}

else if (wiek > 100 && wiek < 122)
{
	cout<<"Jestes umierajacy, a przy okazji doplacaja ci do okularow w Vision Express"<<endl;
}

cout<<"Czy chcesz powtorzyc pytanie? t/n"<<endl;
cin>>powt;
while(powt=='t');
}
	system("pause");
	return 0;}
}
