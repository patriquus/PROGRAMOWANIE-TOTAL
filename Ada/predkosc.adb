WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use ada.Text_IO, ada.Integer_Text_IO, ada.Float_Text_IO;
   PROCEDURE Predkosc IS
      DlugoscKm, CzasMin: Integer;
      czasH, predkosc : float;
   BEGIN
      Put("Podaj dlugosc trasy: ");
      Get(Dlugosckm);
      
      Put("Podaj czas przebycia w minutach: ");
      Get(Czasmin);
      czasH:= float(czasmin) /60.0;
      
      Predkosc:=Float(Dlugosckm)/CzasH;
      Put("Predkosc wynosi (km/h): ");
      Put(predkosc, aft => 2, exp => 0);
   END Predkosc;
   
      

      
