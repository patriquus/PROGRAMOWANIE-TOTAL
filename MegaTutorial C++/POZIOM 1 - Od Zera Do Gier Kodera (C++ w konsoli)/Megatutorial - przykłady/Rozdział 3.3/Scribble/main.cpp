// Scribble - okienkowy szkicownik

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";

// dane okna
HDC g_hdcOkno;		// uchwyt kontekstu urz¹dzenia okna


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_LBUTTONDOWN:
			// przejmujemy myszkê
			SetCapture (hWnd);

			// przesuwamy pióro (s³u¿¹ce do rysowania po oknie) w punkt klikniêcia
			MoveToEx (g_hdcOkno, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), NULL);

			// zwracamy zero
			return 0;

		case WM_MOUSEMOVE:
			// je¿eli nasze okno posiada myszkê
			if (GetCapture() == hWnd)
				// rysujemy linie od poprzedniego do aktualnego miejsca kursora myszki
				LineTo (g_hdcOkno, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			
			// zwracamy zero
			return 0;

		case WM_LBUTTONUP:
			// oddajemy w³adzê nad myszk¹ do systemu
			ReleaseCapture();
			return 0;

		//--------------------------------------------------------------------------------

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
	KlasaOkna.style = CS_OWNDC;					// w³asny kontekst urz¹dzenia okna
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	HWND hOkno = NULL;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Szkicownik",			// tekst na pasku tytu³u
						   WS_OVERLAPPEDWINDOW,		// styl okna
						   CW_USEDEFAULT,			// wspó³rzêdna pozioma
						   CW_USEDEFAULT,			// wspó³rzêdna pionowa
						   CW_USEDEFAULT,			// szerokoœæ
						   CW_USEDEFAULT,			// wysokoœæ
						   NULL,					// uchwyt do okna nadrzêdnego
						   NULL,					// uchwyt do menu
						   hInstance,				// uchwyt do instancji aplikacji
						   NULL);					// dodatkowe dane

	// pobieramy uchwyt do kontekstu urz¹dzenia obszaru klienta okna
	g_hdcOkno = GetDC(hOkno);
	
	// pokazujemy nasze okno
	ShowWindow (hOkno, nCmdShow);


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