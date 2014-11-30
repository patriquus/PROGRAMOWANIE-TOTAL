// Magnifier - lupa do ogl¹dania pulpitu Windows

#include <string>
#include <ctime>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// wspó³czynnik powiêkszenia
const float ZOOM = 2.0f;

// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HWND g_hwndOkno;			// uchwyt okna
HDC g_hdcOkno;				// uchwyt kontekstu urz¹dzenia okna

// inne dane
HDC g_hdcEkran;				// uchwyt kontekstu urz¹dzenia ekranu


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


// --- funkcja wykonywana w ka¿dym przebiegu programu ---
void Pracuj()
{
	/* obliczamy prostok¹t, który zostanie powiêkszony */

	// w jego œrodku jest kursor myszy, natomiast wymiary s¹ dobrane tak,
	// aby powiêkszony region zajmowa³ ca³y obszar klienta okna programu

	// pobieramy prostok¹t obszaru klienta
	RECT rcKlient;
	GetClientRect (g_hwndOkno, &rcKlient);

	// obliczamy wymiary powiêkszanego prostok¹ta
	SIZE cPowiekszenie;
	cPowiekszenie.cx = static_cast<LONG>(rcKlient.right / ZOOM);
	cPowiekszenie.cy = static_cast<LONG>(rcKlient.bottom / ZOOM);

	// liczymy wspó³rzêdne powiêkszanego prostok¹ta (kursor jest w jego œrodku)
	POINT ptKursor; GetCursorPos (&ptKursor);
	POINT ptPowiekszenie = { ptKursor.x - cPowiekszenie.cx / 2,
							 ptKursor.y - cPowiekszenie.cy / 2 };

	// zmieniamy te wspó³rzêdne tak, aby powiêkszany prostok¹t nie wyje¿d¿a³ poza ekran
	if (ptPowiekszenie.x < 0) ptPowiekszenie.x = 0;
	if (ptPowiekszenie.y < 0) ptPowiekszenie.y = 0;
	SIZE cEkran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
	if (ptPowiekszenie.x + cPowiekszenie.cx > cEkran.cx)
		ptPowiekszenie.x = cEkran.cx - cPowiekszenie.cx;
	if (ptPowiekszenie.y + cPowiekszenie.cy > cEkran.cy)
		ptPowiekszenie.y = cEkran.cy - cPowiekszenie.cy;


	/* rysujemy powiêkszony obszar ekranu w oknie programu */

	// wywo³ujemy StretchBlt()
	StretchBlt (g_hdcOkno,			// docelowy kontekst - okno
			    0,					// docelowa wspó³rzêdna X
			    0,					// docelowa wspó³rzedna Y
			    rcKlient.right,		// docelowa szerokoœæ
			    rcKlient.bottom,	// docelowa wysokoœæ
			    g_hdcEkran,			// Ÿród³owy kontekst - ekran
			    ptPowiekszenie.x,	// Ÿród³owa wspó³rzedna X
			    ptPowiekszenie.y,	// Ÿród³owa wspó³rzedna Y
				cPowiekszenie.cx,	// Ÿród³owa szerokoœæ
				cPowiekszenie.cy,	// Ÿród³owa wysokoœæ
				SRCCOPY);			// operacja rastrowa
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
								"Lupa",					// tekst na pasku tytu³u
								WS_OVERLAPPEDWINDOW,	// styl okna
								0,						// wspó³rzêdna pozioma
								0,						// wspó³rzêdna pionowa
								200,					// szerokoœæ
								100,					// wysokoœæ
								NULL,					// uchwyt do okna nadrzêdnego
								NULL,					// uchwyt do menu
								hInstance,				// uchwyt do instancji aplikacji
								NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (g_hwndOkno, nCmdShow);


	/* przygotowania */

	// pobieramy uchwyt do kontekstu urz¹dzenia obszaru klienta okna
	g_hdcOkno = GetDC(g_hwndOkno);

	// pobieramy hDC ekranu
	g_hdcEkran = GetDC(NULL);


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

	/* koñczymy */

	// zwalniamy kontekst ekranu
	ReleaseDC (NULL, g_hdcEkran);

	// zwracamy kod wyjœcia
	return static_cast<int>(msgKomunikat.wParam);
}