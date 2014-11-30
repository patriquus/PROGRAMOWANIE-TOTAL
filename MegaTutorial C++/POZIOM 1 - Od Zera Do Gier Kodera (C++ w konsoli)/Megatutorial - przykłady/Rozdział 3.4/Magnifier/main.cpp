// Magnifier - lupa do ogl�dania pulpitu Windows

#include <string>
#include <ctime>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


// wsp�czynnik powi�kszenia
const float ZOOM = 2.0f;

// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HWND g_hwndOkno;			// uchwyt okna
HDC g_hdcOkno;				// uchwyt kontekstu urz�dzenia okna

// inne dane
HDC g_hdcEkran;				// uchwyt kontekstu urz�dzenia ekranu


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			// ko�czymy program
			PostQuitMessage (0);
			return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


// --- funkcja wykonywana w ka�dym przebiegu programu ---
void Pracuj()
{
	/* obliczamy prostok�t, kt�ry zostanie powi�kszony */

	// w jego �rodku jest kursor myszy, natomiast wymiary s� dobrane tak,
	// aby powi�kszony region zajmowa� ca�y obszar klienta okna programu

	// pobieramy prostok�t obszaru klienta
	RECT rcKlient;
	GetClientRect (g_hwndOkno, &rcKlient);

	// obliczamy wymiary powi�kszanego prostok�ta
	SIZE cPowiekszenie;
	cPowiekszenie.cx = static_cast<LONG>(rcKlient.right / ZOOM);
	cPowiekszenie.cy = static_cast<LONG>(rcKlient.bottom / ZOOM);

	// liczymy wsp�rz�dne powi�kszanego prostok�ta (kursor jest w jego �rodku)
	POINT ptKursor; GetCursorPos (&ptKursor);
	POINT ptPowiekszenie = { ptKursor.x - cPowiekszenie.cx / 2,
							 ptKursor.y - cPowiekszenie.cy / 2 };

	// zmieniamy te wsp�rz�dne tak, aby powi�kszany prostok�t nie wyje�d�a� poza ekran
	if (ptPowiekszenie.x < 0) ptPowiekszenie.x = 0;
	if (ptPowiekszenie.y < 0) ptPowiekszenie.y = 0;
	SIZE cEkran = { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
	if (ptPowiekszenie.x + cPowiekszenie.cx > cEkran.cx)
		ptPowiekszenie.x = cEkran.cx - cPowiekszenie.cx;
	if (ptPowiekszenie.y + cPowiekszenie.cy > cEkran.cy)
		ptPowiekszenie.y = cEkran.cy - cPowiekszenie.cy;


	/* rysujemy powi�kszony obszar ekranu w oknie programu */

	// wywo�ujemy StretchBlt()
	StretchBlt (g_hdcOkno,			// docelowy kontekst - okno
			    0,					// docelowa wsp�rz�dna X
			    0,					// docelowa wsp�rzedna Y
			    rcKlient.right,		// docelowa szeroko��
			    rcKlient.bottom,	// docelowa wysoko��
			    g_hdcEkran,			// �r�d�owy kontekst - ekran
			    ptPowiekszenie.x,	// �r�d�owa wsp�rzedna X
			    ptPowiekszenie.y,	// �r�d�owa wsp�rzedna Y
				cPowiekszenie.cx,	// �r�d�owa szeroko��
				cPowiekszenie.cy,	// �r�d�owa wysoko��
				SRCCOPY);			// operacja rastrowa
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
	KlasaOkna.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
	KlasaOkna.style = CS_OWNDC					// w�asny kontekst urz�dzenia okna
					  | CS_HREDRAW | CS_VREDRAW;
	
	// rejestrujemy klas� okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj� CreateWindowEx
	g_hwndOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
								g_strKlasaOkna.c_str(),	// klasa okna
								"Lupa",					// tekst na pasku tytu�u
								WS_OVERLAPPEDWINDOW,	// styl okna
								0,						// wsp�rz�dna pozioma
								0,						// wsp�rz�dna pionowa
								200,					// szeroko��
								100,					// wysoko��
								NULL,					// uchwyt do okna nadrz�dnego
								NULL,					// uchwyt do menu
								hInstance,				// uchwyt do instancji aplikacji
								NULL);					// dodatkowe dane
	
	// pokazujemy nasze okno
	ShowWindow (g_hwndOkno, nCmdShow);


	/* przygotowania */

	// pobieramy uchwyt do kontekstu urz�dzenia obszaru klienta okna
	g_hdcOkno = GetDC(g_hwndOkno);

	// pobieramy hDC ekranu
	g_hdcEkran = GetDC(NULL);


	/* p�tla komunikat�w */

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

	/* ko�czymy */

	// zwalniamy kontekst ekranu
	ReleaseDC (NULL, g_hdcEkran);

	// zwracamy kod wyj�cia
	return static_cast<int>(msgKomunikat.wParam);
}