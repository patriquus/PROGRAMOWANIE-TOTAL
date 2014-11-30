// Division - dzielenie przy u�yciu wska�nika przekazywanego do funkcji

#include <iostream>
#include <conio.h>

// funkcja oblicza ca�kowity iloraz dw�ch liczb oraz jego reszt�
int Podziel(int nDzielna, int nDzielnik, int* const pnReszta)
{
	// zapisujemy reszt� w miejscu pami�ci, na kt�re pokazuje wska�nik
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

	// wy�wietlenie rezultatu
	std::cout << std::endl;
	std::cout << nDzielna << " / " <<nDzielnik << " = " << nIloraz << " r " << nReszta;
	getch();
}