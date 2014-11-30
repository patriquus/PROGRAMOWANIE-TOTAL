#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


struct Adres {
	char ulica[30];
	int nr_domu;
	int nr_mieszkania;
};

struct Ludzie {
	string imie;
	string nazwisko;
	float wiek;
	Adres mieszkanie;
};


int main(int argc, char *argv[])
{
	
	Ludzie czlowiek1, czlowiek2, czlowiek3;
	
	czlowiek1.imie="Kamil";
	czlowiek1.nazwisko="Pawelec";
	czlowiek1.wiek=25;
	strcpy(czlowiek1.mieszkanie.ulica, "Maratonska");
	czlowiek1.mieszkanie.nr_domu=1;
	czlowiek1.mieszkanie.nr_mieszkania=2;
	
	czlowiek2.imie="Patryk";
	czlowiek2.nazwisko="Gradys";
	czlowiek2.wiek=20;
	strcpy(czlowiek2.mieszkanie.ulica, "Rzgowska");
	czlowiek2.mieszkanie.nr_domu=3;
	czlowiek2.mieszkanie.nr_mieszkania=4;	
	
	czlowiek3.imie="Maciek";
	czlowiek3.nazwisko="Nowak";
	czlowiek3.wiek=15;
	strcpy(czlowiek3.mieszkanie.ulica, "Ciolkowskiego");
	czlowiek3.mieszkanie.nr_domu=5;
	czlowiek3.mieszkanie.nr_mieszkania=6;	
	

	cout<<czlowiek1.imie<<" "<<czlowiek1.nazwisko<<" ("<<czlowiek1.wiek<<" l.)"<<endl;
	cout<<czlowiek1.mieszkanie.ulica<<" "<<czlowiek1.mieszkanie.nr_domu<<" m. "<<czlowiek1.mieszkanie.nr_mieszkania<<endl<<endl;
	
	cout<<czlowiek2.imie<<" "<<czlowiek2.nazwisko<<" ("<<czlowiek2.wiek<<" l.)"<<endl;	
	cout<<czlowiek2.mieszkanie.ulica<<" "<<czlowiek2.mieszkanie.nr_domu<<" m. "<<czlowiek2.mieszkanie.nr_mieszkania<<endl<<endl;
		
	cout<<czlowiek3.imie<<" "<<czlowiek3.nazwisko<<" ("<<czlowiek3.wiek<<" l.)"<<endl;
	cout<<czlowiek3.mieszkanie.ulica<<" "<<czlowiek3.mieszkanie.nr_domu<<" m. "<<czlowiek3.mieszkanie.nr_mieszkania<<endl<<endl;	

	float sr=0;
	sr=(czlowiek1.wiek+czlowiek2.wiek+czlowiek3.wiek)/3;
	cout<<"Sredni wiek tych osob to: "<<setprecision(4)<<sr<<endl;
	
	system("pause");
	return 0;
}
