// Zeros - szukanie miejsc zerowych funkcji

#include <iostream>
#include <cmath>
#include <conio.h>

// granica toleracji
const double EPSILON = 0.0001;

// rozpietoœæ badanego przedzia³u
const double PRZEDZIAL = 100;

// wspó³czynniki funkcji f(x) = k * log_a(x - p) + q
double g_fK, g_fA, g_fP, g_fQ;

//-------------------------------------------------------------------------

// badana funkcja
double f(double x)	{ return g_fK * (log(x - g_fP) / log(g_fA)) + g_fQ; }

// algorytm wyszukuj¹cy miejsca zerowe funkcji podanej poprzez wskaŸnik pfnF
// w przedziale <fX1; fX2>. Wynik zwraca poprzez wskaŸnik fZero, zaœ wartoœæ
// logiczna bêd¹ca rezultatem funkcji okreœla, czy miejsce zerowe zosta³o znalezione,
// czy te¿ nie
bool SzukajMiejscaZerowego(double fX1, double fX2, double (*pfnF)(double), double* pfZero)
{
	// najpierw badamy koñce podanego przedzia³u
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

	// dalej sprawdzamy, czy funkcja na koñcach obu przedzia³ów jest ró¿nych znaków;
	// je¿eli nie, to nie ma miejsc zerowych
	if ((pfnF(fX1)) * (pfnF(fX2)) > 0) return false;

	// nastêpnie dzielimy przedzia³ na pó³ i sprawdzamy, czy w ten sposób
	// nie otrzymaliœmy pierwiastka
	double fXp = (fX1 + fX2) / 2;
	if (fabs(pfnF(fXp)) < EPSILON)
	{
		*pfZero = fXp;
		return true;
	}

	// jeœli otrzymany przedzia³ jest wystarczaj¹co ma³y, to rozwi¹zaniem
	// jest jego punkt œrodkowy
	if (fabs(fX2 - fX1) < EPSILON)
	{
		*pfZero = fXp;
		return true;
	}

	// jezeli nadal nic z tego, to wybieramy tê po³ówkê przedzia³u, w której zmienia
	// siê znak funkcji
	if ((pfnF(fX1)) * (pfnF(fXp)) < 0)
		fX2 = fXp;
	else
		fX1 = fXp;

	// przeszukujemy ten przedzia³ tym samym algorytmem
	return SzukajMiejscaZerowego(fX1, fX2, pfnF, pfZero);
}

//-------------------------------------------------------------------------

// funkcja main()
void main()
{
	std::cout << "   POSZUKIWANIE MIEJSC ZEROWYCH   " << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;

	// wyjaœnienie
	std::cout << "Program poszukuje miejsca zerowego funkcji" << std::endl;
	std::cout << "o wzorze f(x) = k * log_a(x - p) + q" << std::endl;
	std::cout << "w przedziale <-" << PRZEDZIAL << "; " << PRZEDZIAL << ">" << std::endl;
	std::cout << std::endl;

	
	/* pobranie wspó³czynników */

	// wspó³czynnik k (czynnik skaluj¹cy)
	std::cout << "Podaj wspolczynnik k: ";
	std::cin >> g_fK;
	if (g_fK == 0.0)
	{
		std::cout << "k musi byc rozne od zera!";
		getch();
		return;
	}

	// wspó³czynnik a (podstawa logarytmu)
	std::cout << "Podaj wspolczynnik a: ";
	std::cin >> g_fA;
	if (g_fA < 0.0 || g_fA == 1.0)
	{
		std::cout << "a musi byc dodatnie i rozne od jedynki!";
		getch();
		return;
	}

	// wspó³czynnik p (przesuniêcie w poziomie)
	std::cout << "Podaj wspolczynnik p: ";
	std::cin >> g_fP;

	// wspó³czynnik q (przesuniecie w pionie)
	std::cout << "Podaj wspolczynnik q: ";
	std::cin >> g_fQ;


	/* znalezienie i wyœwietlenie miejsca zerowego */

	// zmienna na owo miejsce
	double fZero;

	// szukamy miejsca i je wyœwietlamy
	std::cout << std::endl;
	if (SzukajMiejscaZerowego(g_fP > -PRZEDZIAL ? g_fP : -PRZEDZIAL, PRZEDZIAL, f, &fZero))
		std::cout << "f(x) = 0  <=>  x = " << fZero << std::endl;
	else
		std::cout << "Nie znaleziono miejsca zerowego." << std::endl;

	// czekamy na dowolny klawisz
	getch();
}