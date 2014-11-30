// DeadTV - efekt zepsutego telewizora ;)

#include <string>
#include <ctime>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// zmiennoœæ efektu
// (liczba pikseli zmienianych z ka¿dym przebiegiem)
const unsigned ZMIENNOSC = 2500;

// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HWND g_hwndOkno;			// uchwyt okna
HDC g_hdcOkno;				// uchwyt kontekstu urz¹dzenia okna
RECT g_rcObszarKlienta;		// prostok¹t obszaru klienta


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			// koñczymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja wykonywana w ka¿dym przebiegu efektu ---
void Pracuj()
{
	POINT ptPiksel;
	BYTE byOdcien;

	// wybieramy pewn¹ iloœæ pikseli i zmieniamy ich kolory
	for (unsigned i = 0; i < ZMIENNOSC; ++i)
	{
		// losujemy wspó³rzêdne zmienianego piksela
		ptPiksel.x = rand() % g_rcObszarKlienta.right;
		ptPiksel.y = rand() % g_rcObszarKlienta.bottom;

		// losujemy odcieñ szaroœci
		byOdcien = rand() % 256;

		// zmieniamy piksel
		SetPixelV (g_hdcOkno, ptPiksel.x, ptPiksel.y, 
				   RGB(byOdcien, byOdcien, byOdcien));
	}
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
	KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	KlasaOkna.style = CS_OWNDC					// w³asny kontekst urz¹dzenia okna
					  | CS_HREDRAW | CS_VREDRAW;
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	g_hwndOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
								g_strKlasaOkna.c_str(),	// klasa okna
								"Zepsuty telewizor",		// tekst na pasku tytu³u
								WS_OVERLAPPED | WS_BORDER
								| WS_CAPTION | WS_SYSMENU,
								CW_USEDEFAULT,			// wspó³rzêdna pozioma
								CW_USEDEFAULT,			// wspó³rzêdna pionowa
								400,						// szerokoœæ
								300,						// wysokoœæ
								NULL,					// uchwyt do okna nadrzêdnego
								NULL,					// uchwyt do menu
								hInstance,				// uchwyt do instancji aplikacji
								NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (g_hwndOkno, nCmdShow);


	/* przygotowujemy siê do rysowania efektu */

	// pobieramy uchwyt do kontekstu urz¹dzenia obszaru klienta okna
	g_hdcOkno = GetDC(g_hwndOkno);

    // pobieramy prostok¹t tego¿ obszaru
	// (poniewa¿ okno jest sta³ych rozmiarów, nie zmieni siê on)
	GetClientRect (g_hwndOkno, &g_rcObszarKlienta);

	// inicjujemy generator liczb pseudolosowych
	srand (static_cast<unsigned>(time(NULL)));


	/* pêtla komunikatów */

	MSG msgKomunikat;
	msgKomunikat.message = WM_NULL;
	while (msgKomunikat.message != WM_QUIT)
	{
		if (PeekMessage(&msgKomunikat, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage (&msgKomunikat);
			DispatchMessage (&msgKomunikat);
		}
		else
			Pracuj();
	}

	// zwracamy kod wyjœcia
	return static_cast<int>(msgKomunikat.wParam);
}