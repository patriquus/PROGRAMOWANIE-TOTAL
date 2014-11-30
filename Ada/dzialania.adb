WITH Ada.Text_IO, Ada.Integer_Text_IO, ada.Float_Text_IO; -- biblioteki
use ada.Text_IO, ada.Integer_Text_IO, ada.Float_Text_IO; -- nie trzeba pisac tego przed kazdym poleceniem

PROCEDURE dzialania IS
BEGIN
   put_line("Dzialanie na liczbach calkowitych"); -- wyswietla tekst i przechodz do nastepnej linii
   Put("2*3 + 2^2 = "); -- wyswietla tekst (nie przechodzi do nastepnej linii)
   Put(2*3 + 2**2); -- ** to operator potegowania
   New_Line(2); -- przechodzi o dwie linie w dol
   put_line("Dzialanie na liczbach calkowitych");
   Put("2*3 + 2^2 = ");
   Put(2*3 + 2**2, 0); -- drugi argument odpowiada za ilosc przydzielonego miejsca do wyswietlania liczby; domyslnie 8 (stad przerwa wyzej, podczas uruchomienia); 0 - dopasowuje automatycznie
   New_Line(2);
   put_line("Dzialanie z wynikiem niecalkowitym");
   Put("10/3");
   Put(10/3); -- to co po przecinku zostanie obciete
   New_Line(2);
   put_line("Dzialanie na liczbach rzeczywistych");
   Put("10/3 + 2^2 = ");
   Put(10.0/3.0 + 2.0**2); -- przy dzialaniach na liczbach rzeczywistych nalezy pisac liczbe po przecinku, np. 10.0, a nie 10; nie dotyczy wykladnikow poteg
   New_Line(2);
   put_line("Dzialanie na liczbach rzeczywistych");
   Put("10/3 + 2^2 = ");
   put(10.0/3.0 + 2.0**2, fore => 0, aft => 2, exp => 0); -- fore - ilosc miejsc przed przecinkiem, aft - ilosc miejsc po przecinku, exp - dokladnosc wykladnika
   New_Line(2);
   Set_Col(5); -- ustawianie pozycji kursora w kolejnej kolumnie (dziala tylko w przod - nie mozna cofac kursora)
   Put("The");
   New_Line;
   Set_Col(10);
   put("End");
END dzialania;


