// Division - dzielenie przy u¿yciu wskaŸnika przekazywanego do funkcji

#include <iostream>
#include <conio.h>

// funkcja oblicza ca³kowity iloraz dwóch liczb oraz jego resztê
int Podziel(int nDzielna, int nDzielnik, int* const pnReszta)
{
	// zapisujemy resztê w miejscu pamiêci, na które pokazuje wskaŸnik
	*pnReszta = nDzielna % nDzielnik;

	// zwracamy iloraz
	return nDzielna / nDzielnik;
}

//---------------------------------------------------------------------------------------

// funkcja main()
void main()
{
	std::cout << "   DZIELENIE Z RESZTA   " << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

	// pobranie dzielnej
	int nDzielna;
	std::cout << "Podaj dzielna: ";
	std::cin >> nDzielna;

	// pobranie dzielnika
	int nDzielnik;
	std::cout << "Podaj dzielnik: ";
	std::cin >> nDzielnik;

	// obliczenie rezultatu
	int nIloraz, nReszta;
	nIloraz = Podziel(nDzielna, nDzielnik, &nReszta);

	// wyœwietlenie rezultatu
	std::cout << std::endl;
	std::cout << nDzielna << " / " <<nDzielnik << " = " << nIloraz << " r " << nReszta;
	getch();
}