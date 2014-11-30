WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE czy_wolny IS

   TYPE Dni IS
         (Poniedzialek,
          Wtorek,
          Sroda,
          Czwartek,
          Piatek,
          Sobota,
          Niedziela);

   PACKAGE Dio IS NEW Ada.Text_IO.Enumeration_IO(Dni);
   USE Dio;

   X : Dni;
   Y : Integer;
BEGIN
   Put("Podaj dzien tygodnia ");
   Get(X);
   IF X IN Poniedzialek..Piatek THEN
      Put("Dzien roboczy");
   ELSIF X IN Sobota..Niedziela THEN
      Put("Dzien wolny");
   ELSE
      Put("Podales zle dane");
   END IF;

   New_Line(2);
   Y:=Dni'Pos(Sobota)-Dni'Pos(X);
   Put("Do weekendu zostalo ");
   Put(Y);
   Put_Line(" dni");

   Put("Jutro bedzie ");
   --Put(Dni'Succ(X));
   Put(Dni'Val((Dni'Pos(X)+1) mod 7));
   New_Line;
   Put("Pojutrze bedzie ");
   Put(Dni'Val((Dni'Pos(X)+2) mod 7));
   New_Line;
   Put("Wczoraj byl(a)");
   Put(Dni'Val((Dni'Pos(X)-1) mod 7));
   New_Line;
   Put("Przedwczoraj byl(a) ");
   Put(Dni'Val((Dni'Pos(X)-2) mod 7));
   New_Line;

END czy_wolny;
