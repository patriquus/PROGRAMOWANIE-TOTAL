WITH Ada.Integer_Text_IO, Ada.Text_IO, Ada.Float_Text_IO;
USE Ada.Integer_Text_IO, Ada.Text_IO, Ada.Float_Text_IO;
   
PROCEDURE Pensja IS
   
   wyplata: Float;
   podatek : constant float := 0.19;
   
BEGIN
   Put("Podaj swoja pensje brutto w PLN: ");
   Get(Wyplata);  
   New_Line;
   Put("Otrzymasz wyplate w wysokosci: ");
   Wyplata:= Wyplata-Wyplata*Podatek;
   Put(Wyplata, Aft=> 2, Exp => 0);
   Put(" PLN");

end pensja;
