// ClientMove - przeci¹ganie okna za jego obszar klienta

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
			// w reakcji na ten komunikat dokonuje siê ca³a "magia"
			// dokonujemy tutaj drobnego oszustwa, przekonuj¹c system, ¿e nastapi³o
			// klikniêcie w pasek tytu³u okna, gdy w rzeczywistoœci klikniêty
			// zosta³ jego obszar klienta. Dziêki temu okna mo¿na przesuwaæ, przeci¹gaj¹c
			// za jego wnêtrze (a tak¿e maksymalizowaæ poprzez dwukrotne klikniêcie)

			/* sprawdzamy, czy podana pozycja kursora jest obszarze klienta */

			// uzyskujemy pozycjê kursora
			POINT ptKursor = { GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) };

			// pobieramy prostok¹t obszaru klienta okna
			RECT rcObszarKlienta;
			GetClientRect (hWnd, &rcObszarKlienta);

			// je¿eli kursor nie jest w obszarze klienta, to zwracamy domyœlny rezultat
			// wygenerowany przez DefWindowProc()
			// sprawdzenia dokonujemy poprzez prost¹ funkcjê PtInRect()
			if (!PtInRect(&rcObszarKlienta, ptKursor))
				return DefWindowProc(hWnd, uMsg, wParam, lParam);

			// powy¿szych kilka linijek mo¿e byæ te¿ zast¹pionych poprzez pojedyncze
			// wywo³anie DefWindowProc(), sprawdzenie jego rezultatu (chcemy HTCLIENT)
			// oraz zwrócenie go jako wyniku przetwarzania WM_NCHITTEST w przypadku, gdy
			// nie mamy doczynienia z klikniêciem w obszarze klienta:
			//	if ((LRESULT lResult = DefWindowProc(hWnd, uMsg, wParam, lParam)) != HTCLIENT)
			//		return lResult;
			// samodzielnie sprawdzanie jest chyba jednak bardziej przejrzyste...
			// no i dziêki temu uczymy siê pos³ugiwaæ funkcjami Windows API :D

			/* gdy wiemy, ¿e klikniêcie nast¹pi³o w obszarze klienta, "oszukujemy"
			   Windows i "wmawiamy" mu, ¿e tak naprawdê klikniêto w pasek tytu³u */
			return HTCAPTION;
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
	KlasaOkna.hbrBackground = (HBRUSH) COLOR_WINDOW;
	
	// rejestrujemy klasê okna
	RegisterClassEx (&KlasaOkna);


	/* tworzymy okno */

	// tworzymy okno funkcj¹ CreateWindowEx
	HWND hOkno;
	hOkno = CreateWindowEx(NULL,					// rozszerzony styl okna
						   g_strKlasaOkna.c_str(),	// klasa okna
						   "Okno przesuwane przez obszar klienta",
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