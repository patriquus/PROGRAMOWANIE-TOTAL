// RandomRects - inwazja losowych prostok�t�w

#include <string>
#include <ctime>
#define _WIN32_WINNT 0x500		// aby dzia�a� elastyczny p�dzel
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HDC g_hdcOkno;		// uchwyt kontekstu urz�dzenia okna


// --- pomocnicza funkcja zwracaj�ca liczb� losow� z podanego zakresu ---

int Random(int nMin, int nMax)	{ return rand() % (nMax - nMin + 1) + nMin; }


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_TIMER:
		{
			// pobieramy obszar klienta
			RECT rcObszarKlienta;
			GetClientRect (hWnd, &rcObszarKlienta);

			// generujemy wsp�rz�dne nowego prostok�ta;
			// praw� i doln� kraw�d� dobieramy tak, aby zawsze by�a po�o�ona
			// miedzy lew�/g�rn� kraw�dzi� prostok�ta i praw�/doln� kraw�dzi�
			// obszaru klienta okna
			RECT rcProstokat;
			rcProstokat.left = Random(0, rcObszarKlienta.right);
			rcProstokat.right = Random(rcProstokat.left, rcObszarKlienta.right);
			rcProstokat.top = Random(0, rcObszarKlienta.bottom);
			rcProstokat.bottom = Random(rcProstokat.top, rcObszarKlienta.bottom);

			// ustawiamy losowy kolor p�dzla
			SetDCBrushColor (g_hdcOkno,
							 RGB(Random(0, 255), Random(0, 255), Random(0, 255)));

			// rysujemy prostok�t
			Rectangle (g_hdcOkno, rcProstokat.left, rcProstokat.top,
								  rcProstokat.right, rcProstokat.bottom);

			return 0;
		}

		case WM_DESTROY:
			// ko�czymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja WinMain() ---

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	/* rejestrujemy klas� okna */

	WNDCLASSEX KlasaOkna;
	
	// wype�niamy struktur� WNDCLASSEX
	ZeroMemory (&KlasaOkna, sizeof(WNDCLASSEX));
	KlasaOkna.cbSize = sizeof(WNDCLASSEX);
	KlasaOkna.hInstance = hInstance;
	KlasaOkna.lpfnWndProc = WindowEventProc;
	KlasaOkna.lpszClassName = g_strKlasaOkna.c_str();
	KlasaOkna.hCursor = LoadCursor(NULL, IDC_ARROW);
	KlasaOkna.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);	// bia�e t�o
	KlasaOkna.style = CS_OWNDC					// w�asny kontekst urz�dzenia okna
					  | CS_HREDRAW | CS_VREDRAW;
	
	// rejestrujemy klas� okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj� CreateWindowEx
	HWND hOkno = NULL;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Prostok�ty",			// tekst na pasku tytu�u
						   WS_OVERLAPPEDWINDOW,		// styl okna
						   CW_USEDEFAULT,			// wsp�rz�dna pozioma
						   CW_USEDEFAULT,			// wsp�rz�dna pionowa
						   CW_USEDEFAULT,			// szeroko��
						   CW_USEDEFAULT,			// wysoko��
						   NULL,					// uchwyt do okna nadrz�dnego
						   NULL,					// uchwyt do menu
						   hInstance,				// uchwyt do instancji aplikacji
						   NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (hOkno, nCmdShow);


	/* przygotowujemy si� do rysowania prostok�t�w */

	// pobieramy uchwyt do kontekstu urz�dzenia obszaru klienta okna
	g_hdcOkno = GetDC(hOkno);

	// ustawiamy mu elastyczny p�dzel
	DeleteObject (SelectObject(g_hdcOkno, GetStockObject(DC_BRUSH)));

	// tworzymy stoper, aby generowa� zdarzenie WM_TIMER co �wier� sekundy
	SetTimer (hOkno, 1, 250 /* milisekund */, NULL);

	// inicjujemy generator liczb pseudolosowych
	srand (static_cast<unsigned>(time(NULL)));


	/* p�tla komunikat�w */

	MSG msgKomunikat;
	while (GetMessage(&msgKomunikat, NULL, 0, 0))
	{
		TranslateMessage (&msgKomunikat);
		DispatchMessage (&msgKomunikat);
	}

	// zwracamy kod wyj�cia
	return static_cast<int>(msgKomunikat.wParam);
}