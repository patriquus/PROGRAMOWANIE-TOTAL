// Zeros - szukanie miejsc zerowych funkcji

#include <iostream>
#include <cmath>
#include <conio.h>

// granica toleracji
const double EPSILON = 0.0001;

// rozpieto�� badanego przedzia�u
const double PRZEDZIAL = 100;

// wsp�czynniki funkcji f(x) = k * log_a(x - p) + q
double g_fK, g_fA, g_fP, g_fQ;

//-------------------------------------------------------------------------

// badana funkcja
double f(double x)	{ return g_fK * (log(x - g_fP) / log(g_fA)) + g_fQ; }

// algorytm wyszukuj�cy miejsca zerowe funkcji podanej poprzez wska�nik pfnF
// w przedziale <fX1; fX2>. Wynik zwraca poprzez wska�nik fZero, za� warto��
// logiczna b�d�ca rezultatem funkcji okre�la, czy miejsce zerowe zosta�o znalezione,
// czy te� nie
bool SzukajMiejscaZerowego(double fX1, double fX2, double (*pfnF)(double), double* pfZero)
{
	// najpierw badamy ko�ce podanego przedzia�u
	if (fabs(pfnF(fX1)) < EPSILON)
	{
		*pfZero = fX1;
		return true;
	}
	else if (fabs(pfnF(fX2)) < EPSILON)
	{
		*pfZero = fX2;
		return true;
	}

	// dalej sprawdzamy, czy funkcja na ko�cach obu przedzia��w jest r�nych znak�w;
	// je�eli nie, to nie ma miejsc zerowych
	if ((pfnF(fX1)) * (pfnF(fX2)) > 0) return false;

	// nast�pnie dzielimy przedzia� na p� i sprawdzamy, czy w ten spos�b
	// nie otrzymali�my pierwiastka
	double fXp = (fX1 + fX2) / 2;
	if (fabs(pfnF(fXp)) < EPSILON)
	{
		*pfZero = fXp;
		return true;
	}

	// je�li otrzymany przedzia� jest wystarczaj�co ma�y, to rozwi�zaniem
	// jest jego punkt �rodkowy
	if (fabs(fX2 - fX1) < EPSILON)
	{
		*pfZero = fXp;
		return true;
	}

	// jezeli nadal nic z tego, to wybieramy t� po��wk� przedzia�u, w kt�rej zmienia
	// si� znak funkcji
	if ((pfnF(fX1)) * (pfnF(fXp)) < 0)
		fX2 = fXp;
	else
		fX1 = fXp;

	// przeszukujemy ten przedzia� tym samym algorytmem
	return SzukajMiejscaZerowego(fX1, fX2, pfnF, pfZero);
}

//-------------------------------------------------------------------------

// funkcja main()
void main()
{
	std::cout << "   POSZUKIWANIE MIEJSC ZEROWYCH   " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;

	// wyja�nienie
	std::cout << "Program poszukuje miejsca zerowego funkcji" << std::endl;
	std::cout << "o wzorze f(x) = k * log_a(x - p) + q" << std::endl;
	std::cout << "w przedziale <-" << PRZEDZIAL << "; " << PRZEDZIAL << ">" << std::endl;
	std::cout << std::endl;

	
	/* pobranie wsp�czynnik�w */

	// wsp�czynnik k (czynnik skaluj�cy)
	std::cout << "Podaj wspolczynnik k: ";
	std::cin >> g_fK;
	if (g_fK == 0.0)
	{
		std::cout << "k musi byc rozne od zera!";
		getch();
		return;
	}

	// wsp�czynnik a (podstawa logarytmu)
	std::cout << "Podaj wspolczynnik a: ";
	std::cin >> g_fA;
	if (g_fA < 0.0 || g_fA == 1.0)
	{
		std::cout << "a musi byc dodatnie i rozne od jedynki!";
		getch();
		return;
	}

	// wsp�czynnik p (przesuni�cie w poziomie)
	std::cout << "Podaj wspolczynnik p: ";
	std::cin >> g_fP;

	// wsp�czynnik q (przesuniecie w pionie)
	std::cout << "Podaj wspolczynnik q: ";
	std::cin >> g_fQ;


	/* znalezienie i wy�wietlenie miejsca zerowego */

	// zmienna na owo miejsce
	double fZero;

	// szukamy miejsca i je wy�wietlamy
	std::cout << std::endl;
	if (SzukajMiejscaZerowego(g_fP > -PRZEDZIAL ? g_fP : -PRZEDZIAL, PRZEDZIAL, f, &fZero))
		std::cout << "f(x) = 0  <=>  x = " << fZero << std::endl;
	else
		std::cout << "Nie znaleziono miejsca zerowego." << std::endl;

	// czekamy na dowolny klawisz
	getch();
}