///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///// 04.11.2014 //////////////////////////////////////////////////////////////////////////////////
///// SPOTKANIE GRUPY .NET UL NA WFIIS: KURS C# CZESC 1 ///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// KLASA
class Piesel {
	public bool ogon;
	public int  ilosc_skrzydel;
	public string imie;

// FUNKCJE
	public void szczekaj() {
		Console.Writeline("wow! wow!"); 
	}

	public double dodaj_piesku(double a, double b) {
		return a+b;
	}
	
// KONSTRUKTOR
	public Piesel(bool czy_ogon, int skrzydla, string name) {
		ogon = czy_ogon;
		ilosc_szkrzydel = skrzydla;
		imie = name;
	}
}	

class Main {

/*
// TWORZYMY NOWY OBIEKT PIESEL
	Piesel Marek = new Piesel();
	Marek.ogon = true;
	Marek.imie = "Marek";
	Marek.ilosc_skrzydel = 7;
*/
	
// TWORZYMY NOWY OBIEKT PIESEL, ALE SZYBCIEJ - Z UZYCIEM KONSTRUKTORA	
	Piesel Marek = new Piesel(true, 7, "Marek");	

// UZYWAMY FUNKCJI	
	Marek.szczekaj();
	
	double x,y,suma;
	x = 2;
	y = 3;
	suma = Marek.dodaj_piesku(x,y);
}
