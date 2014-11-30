// RandomRects - inwazja losowych prostok¹tów

#include <string>
#include <ctime>
#define _WIN32_WINNT 0x500		// aby dzia³a³ elastyczny pêdzel
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HDC g_hdcOkno;		// uchwyt kontekstu urz¹dzenia okna


// --- pomocnicza funkcja zwracaj¹ca liczbê losow¹ z podanego zakresu ---

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

			// generujemy wspó³rzêdne nowego prostok¹ta;
			// praw¹ i doln¹ krawêdŸ dobieramy tak, aby zawsze by³a po³o¿ona
			// miedzy lew¹/górn¹ krawêdzi¹ prostok¹ta i praw¹/doln¹ krawêdzi¹
			// obszaru klienta okna
			RECT rcProstokat;
			rcProstokat.left = Random(0, rcObszarKlienta.right);
			rcProstokat.right = Random(rcProstokat.left, rcObszarKlienta.right);
			rcProstokat.top = Random(0, rcObszarKlienta.bottom);
			rcProstokat.bottom = Random(rcProstokat.top, rcObszarKlienta.bottom);

			// ustawiamy losowy kolor pêdzla
			SetDCBrushColor (g_hdcOkno,
							 RGB(Random(0, 255), Random(0, 255), Random(0, 255)));

			// rysujemy prostok¹t
			Rectangle (g_hdcOkno, rcProstokat.left, rcProstokat.top,
								  rcProstokat.right, rcProstokat.bottom);

			return 0;
		}

		case WM_DESTROY:
			// koñczymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja WinMain() ---

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	/* rejestrujemy klasê okna */

	WNDCLASSEX KlasaOkna;
	
	// wype³niamy strukturê WNDCLASSEX
	ZeroMemory (&KlasaOkna, sizeof(WNDCLASSEX));
	KlasaOkna.cbSize = sizeof(WNDCLASSEX);
	KlasaOkna.hInstance = hInstance;
	KlasaOkna.lpfnWndProc = WindowEventProc;
	KlasaOkna.lpszClassName = g_strKlasaOkna.c_str();
	KlasaOkna.hCursor = LoadCursor(NULL, IDC_ARROW);
	KlasaOkna.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);	// bia³e t³o
	KlasaOkna.style = CS_OWNDC					// w³asny kontekst urz¹dzenia okna
					  | CS_HREDRAW | CS_VREDRAW;
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	HWND hOkno = NULL;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Prostok¹ty",			// tekst na pasku tytu³u
						   WS_OVERLAPPEDWINDOW,		// styl okna
						   CW_USEDEFAULT,			// wspó³rzêdna pozioma
						   CW_USEDEFAULT,			// wspó³rzêdna pionowa
						   CW_USEDEFAULT,			// szerokoœæ
						   CW_USEDEFAULT,			// wysokoœæ
						   NULL,					// uchwyt do okna nadrzêdnego
						   NULL,					// uchwyt do menu
						   hInstance,				// uchwyt do instancji aplikacji
						   NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (hOkno, nCmdShow);


	/* przygotowujemy siê do rysowania prostok¹tów */

	// pobieramy uchwyt do kontekstu urz¹dzenia obszaru klienta okna
	g_hdcOkno = GetDC(hOkno);

	// ustawiamy mu elastyczny pêdzel
	DeleteObject (SelectObject(g_hdcOkno, GetStockObject(DC_BRUSH)));

	// tworzymy stoper, aby generowa³ zdarzenie WM_TIMER co æwieræ sekundy
	SetTimer (hOkno, 1, 250 /* milisekund */, NULL);

	// inicjujemy generator liczb pseudolosowych
	srand (static_cast<unsigned>(time(NULL)));


	/* pêtla komunikatów */

	MSG msgKomunikat;
	while (GetMessage(&msgKomunikat, NULL, 0, 0))
	{
		TranslateMessage (&msgKomunikat);
		DispatchMessage (&msgKomunikat);
	}

	// zwracamy kod wyjœcia
	return static_cast<int>(msgKomunikat.wParam);
}