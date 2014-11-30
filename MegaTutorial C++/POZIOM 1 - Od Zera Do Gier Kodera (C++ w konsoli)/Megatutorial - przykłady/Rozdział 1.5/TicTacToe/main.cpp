// TicTacToe - wielki projekt gry typu "k�ko i krzy�yk"

#include <iostream>
#include <conio.h>
#include "game.h"

int main()
{
	// rozpoczynamy gr�
	StartGry();

	// p�tla niesko�czona - cz�sty element w grach
	// wyjdziemy z niej przy pomocy break w odpowiednim momencie
	for (;;)
	{
		// rysujemy plansz�
		RysujPlansze();

		// sprawdzamy stan gry i czynimy odpowiednie dzia�ania
		if (g_StanGry == GS_MOVE)
		{
			// ruch kt�rego� gracza
			// pobieramy go wi�c i wywo�ujemy funkcj� Ruch()
			unsigned uNumerPola;
			std::cin >> uNumerPola;
			Ruch (uNumerPola);
		}
		else if (g_StanGry == GS_WON || g_StanGry == GS_DRAW)
			// koniec gry (wygran� lub remisem)
			// wtedy przerywamy p�tl�
			break;
	}

	// czekamy na dowolny klawisz
	getch();
}
