// W³aœciwy kod gry

#include <iostream>
#include <ctime>
#include "game.h"


// zmienne
//--------

// plansza w postaci tablicy 3x3
FIELD g_aPlansza[3][3] = { { FLD_EMPTY, FLD_EMPTY, FLD_EMPTY },
						   { FLD_EMPTY, FLD_EMPTY, FLD_EMPTY },
						   { FLD_EMPTY, FLD_EMPTY, FLD_EMPTY } };

// stan gry (nie rozpoczêta, ruch gracza, wygrana lub remis)
GAMESTATE g_StanGry = GS_NOTSTARTED;

// znak aktualnego gracza (kó³ko lub krzy¿yk)
SIGN g_AktualnyGracz;


//----------------------------------------------------------------------------------------


// funkcje
//--------

// funkcja wywo³ywana na starcie gry
bool StartGry()
{
	// najpierw sprawdzamy, czy gra ju¿ nie trwa;
	// je¿eli tak, to funkcja koñczy siê pora¿k¹
	if (g_StanGry != GS_NOTSTARTED) return false;

	// losujemy gracza, który bêdzie zaczyna³
	srand (static_cast<unsigned>(time(NULL)));
	g_AktualnyGracz = (rand() % 2 == 0 ? SGN_CIRCLE : SGN_CROSS);

	// ustawiamy stan gry na ruch graczy
	g_StanGry = GS_MOVE;

	// wszystko siê uda³o, zatem zwracamy true
	return true;
}

// rysowanie (albo raczej wypisywanie) pola gry
bool RysujPlansze()
{
	// tak¿e sprawdzamy, czy aby na pewno gra rozpoczê³as iê
	if (g_StanGry == GS_NOTSTARTED)	return false;

	// czyœcimy okienko konsoli przy pomocy polecenia systemowego CLS
	system ("cls");

	// pokazujemy szyld tytu³owy
	std::cout << "   KOLKO I KRZYZYK   " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	
	// nastêpnie wypisujemy w³aœciw¹ planszê
	// oczywiœcie, czynimy to przy pomocy dwóch pêtli for
	std::cout << "        -----" << std::endl;
	for (int i = 0; i < 3; ++i)
	{
		// lewa czêœæ ramki
		std::cout << "        |";

		// wiersz
		for (int j = 0; j < 3; ++j)
		{
			// sprawdzamy, czy dane pole jest puste
			if (g_aPlansza[i][j] == FLD_EMPTY)
				// wtedy wyœwietlamy jego numerek
				// tak, ¿eby u¿ytkownik wiedzia³, jak¹ liczbê wpisaæ, gdy bêdzie
				// chcia³ postawiæ na nim kó³ko lub krzy¿yk :)
				std::cout << i * 3 + j + 1;
			else
				// je¿eli natomiast pole jest zajête,
				// wyœwietlamy odpowiadaj¹cy mu znak;
				// korzystamy tu ze sztuczki z odpowiednimi wartoœciami sta³ych typu
				// FIELD; dziêki niej unikamy dodatkowego if'a (tudzie¿ operatora ?:)
				std::cout << static_cast<char>(g_aPlansza[i][j]);
		}

		// prawa czêœæ ramki
		std::cout << "|" << std::endl;
	}
	std::cout << "        -----" << std::endl;
	std::cout << std::endl;

	// wreszcie, pokazujemy dolny komunikat
	// jest on albo proœb¹ o podanie ruchu, albo informacj¹ o stanie gry
	// wszystko zale¿y o tego¿ stanu, a zatem stosujemy instrukcjê switch
	switch (g_StanGry)
	{
		case GS_MOVE:
			// ruch gracza, a wiêc gra trwa

			// musimy wiêc poprosiæ o ruch
			std::cout << "Podaj numer pola, w ktorym" << std::endl;
			std::cout << "chcesz postawic ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ? "kolko" : "krzyzyk") << ": ";

			break;
		case GS_WON:
			// gra zakoñczona, ktoœ wygra³ :)

			// wyœwietlamy odpowiedni¹ informacjê
			std::cout << "Wygral gracz stawiajacy ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ? "kolka" : "krzyzyki") << "!";

			break;
		case GS_DRAW:
			// mo¿e te¿ siê zdarzyæ remis

			// tak¿e pokazujemy wiadomoœæ
			std::cout << "Remis!";

			break;
	}

	// wszystko posz³o OK, zatem powiadamiamy o tym
	return true;
}

// wykonanie ruchu i sprawdzenie jego rezultatu
bool Ruch(unsigned uNumerPola)
{
	// znowu¿ musimy sprawdziæ stan gry
	if (g_StanGry != GS_MOVE) return false;

	// nastêpnie sprawdzamy, czy numer pola mieœci siê w przedziale <1; 9>
	if (!(uNumerPola >= 1 && uNumerPola <= 9)) return false;

	// jeœli doszliœmy dot¹d, to wszystko jest w porz¹dku i mo¿emy wykonaæ ruch;
	// przeliczamy wiêc numer pola na indeksy tablicy i przypisujemy znak gracza;
	// (tylko wtedy, gdy pole jest puste)
	// po raz któryœ-tam z kolei u¿ywamy przy tym sztuczki z wartoœciami enumów
	unsigned uY = (uNumerPola - 1) / 3;
	unsigned uX = (uNumerPola - 1) % 3;
	if (g_aPlansza[uY][uX] == FLD_EMPTY)
		g_aPlansza[uY][uX] = static_cast<FIELD>(g_AktualnyGracz);
	else
		// je¿eli próbowano dwukrotnie postawiæ znak w tym samym miejscu,
		// to niestety nie mo¿emy na to pozwoliæ :)
		return false;

	// no i teraz nastêpuje najbardziej zakrêcona czêœæ programu :))
	// (taaak, poprzednia linijka wcale ni¹ nie by³a :DD)
	// musimy mianowicie okreœliæ stan gry na podstawie planszy;
	// mog³o siê przecie¿ zdarzyæ, ¿e któryœ gracz u³o¿y³ liniê poziom¹, pionow¹
	// lub ukosn¹ i wygra³, prawda? :) tutaj musimy to okreœliæ
	// mo¿na to zrobiæ na kilka sposobów: najprostszy do wymyœlenia, ale najbardziej
	// pogmatwany jest zwyk³y ci¹g instrukcji warunkowych, kontroluj¹cych ka¿de pole...
	// sprytniejsz¹ metod¹ jest jednak u¿ycie tablicy przegl¹dowej i pêtli for
	const int LINIE[][3][2] = { { { 0, 0 }, { 0, 1 }, { 0, 2 } },	// górna pozioma
							{ { 1, 0 }, { 1, 1 }, { 1, 2 } },	// œrodkowa pozioma
							{ { 2, 0 }, { 2, 1 }, { 2, 2 } },	// dolna pozioma
							{ { 0, 0 }, { 1, 0 }, { 2, 0 } },	// lewa pionowa
							{ { 0, 1 }, { 1, 1 }, { 2, 1 } },	// œrodkowa pionowa
							{ { 0, 2 }, { 1, 2 }, { 2, 2 } },	// prawa pionowa
							{ { 0, 0 }, { 1, 1 }, { 2, 2 } },	// przek¹tna backslashowa
							{ { 2, 0 }, { 1, 1 }, { 0, 2 } } };	// przek¹tna slashowa
	FIELD Pole, ZgodnePole;
	unsigned uLiczbaZgodnychPol;
	for (int i = 0; i < 8; ++i)
	{
		// i przebiega po kolejnych mo¿liwych liniach (jest ich osiem)
		
		// zerujemy zmienne pomocnicze
		Pole = ZgodnePole = FLD_EMPTY;	// obie zmienne zostan¹ ustawione na FLD_EMPTY
		uLiczbaZgodnychPol = 0;

		for (int j = 0; j < 3; ++j)
		{
			// j przebiega po trzech polach w ka¿dej linii

			// pobieramy rzeczone pole
			// to zdecydowanie najbardziej pogmatwane wyra¿enie :)
			Pole = g_aPlansza[LINIE[i][j][0]][LINIE[i][j][1]];

			// je¿eli sprawdzane pole ró¿ni siê od tego, które ma siê zgadzaæ...
			if (Pole != ZgodnePole)
			{
				// to zmieniamy zgadzane pole na to aktualne
				ZgodnePole = Pole;
				uLiczbaZgodnychPol = 1;
			}
			else
				// jeœli natomiast oba pola siê zgadzaj¹, no to inkrementujemy
				// licznik takich zgodnych pól
				++uLiczbaZgodnychPol;
		}

		// teraz sprawdzamy, czy uda³o nam siê zgodziæ liniê
		if (uLiczbaZgodnychPol == 3 && ZgodnePole != FLD_EMPTY)
		{
			// je¿eli tak, no to ustawiamy stan gry na wygran¹
			g_StanGry = GS_WON;

			// przerywamy pêtlê i funkcjê
			return true;
		}
	}

	// istnieje jeszcze mo¿liwoœæ, ¿e nast¹pi³ remis
	// wtedy funkcja dojdzie tutaj i ca³a plansza bêdzie pokryta krzy¿ykami i kó³kami
	// sprawdzamy to przy pomocy odpowiedniej pêtli, zliczaj¹cej zape³nione pola
	// je¿eli jest ich tyle, ile wszystkich, no to koñczymy remisem
	unsigned uLiczbaZapelnionychPol = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (g_aPlansza[i][j] != FLD_EMPTY)
				++uLiczbaZapelnionychPol;
	if (uLiczbaZapelnionychPol == 3*3)
	{
		// ustawiamy stan gry na remis
		g_StanGry = GS_DRAW;

		// koñczymy funkcjê
		return true;
	}

	// oczywiœcie, mo¿e siê zdarzyæ, i¿ gra po prostu toczy siê dalej
	// w takim wypadku zmieniamy jedynie aktualnego gracza
	g_AktualnyGracz = (g_AktualnyGracz == SGN_CIRCLE ? SGN_CROSS : SGN_CIRCLE);

	// zwracamy true
	return true;
}
