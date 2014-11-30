// ClientMove - przeci�ganie okna za jego obszar klienta

#include <string>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>


// nazwa klasy okna
std::string g_strKlasaOkna = "od0dogk_Window";


// --- procedura zdarzeniowa okna ---

LRESULT CALLBACK WindowEventProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_NCHITTEST:
		{
			// w reakcji na ten komunikat dokonuje si� ca�a "magia"
			// dokonujemy tutaj drobnego oszustwa, przekonuj�c system, �e nastapi�o
			// klikni�cie w pasek tytu�u okna, gdy w rzeczywisto�ci klikni�ty
			// zosta� jego obszar klienta. Dzi�ki temu okna mo�na przesuwa�, przeci�gaj�c
			// za jego wn�trze (a tak�e maksymalizowa� poprzez dwukrotne klikni�cie)

			/* sprawdzamy, czy podana pozycja kursora jest obszarze klienta */

			// uzyskujemy pozycj� kursora
			POINT ptKursor = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

			// pobieramy prostok�t obszaru klienta okna
			RECT rcObszarKlienta;
			GetClientRect (hWnd, &rcObszarKlienta);

			// je�eli kursor nie jest w obszarze klienta, to zwracamy domy�lny rezultat
			// wygenerowany przez DefWindowProc()
			// sprawdzenia dokonujemy poprzez prost� funkcj� PtInRect()
			if (!PtInRect(&rcObszarKlienta, ptKursor))
				return DefWindowProc(hWnd, uMsg, wParam, lParam);

			// powy�szych kilka linijek mo�e by� te� zast�pionych poprzez pojedyncze
			// wywo�anie DefWindowProc(), sprawdzenie jego rezultatu (chcemy HTCLIENT)
			// oraz zwr�cenie go jako wyniku przetwarzania WM_NCHITTEST w przypadku, gdy
			// nie mamy doczynienia z klikni�ciem w obszarze klienta:
			//	if ((LRESULT lResult = DefWindowProc(hWnd, uMsg, wParam, lParam)) != HTCLIENT)
			//		return lResult;
			// samodzielnie sprawdzanie jest chyba jednak bardziej przejrzyste...
			// no i dzi�ki temu uczymy si� pos�ugiwa� funkcjami Windows API :D

			/* gdy wiemy, �e klikni�cie nast�pi�o w obszarze klienta, "oszukujemy"
			   Windows i "wmawiamy" mu, �e tak naprawd� klikni�to w pasek tytu�u */
			return HTCAPTION;
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
	KlasaOkna.hbrBackground = (HBRUSH) COLOR_WINDOW;
	
	// rejestrujemy klas� okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj� CreateWindowEx
	HWND hOkno;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Okno przesuwane przez obszar klienta",
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