WITH Ada.Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions, Ada.Float_Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions, Ada.Float_Text_IO, Ada.Integer_Text_IO;

PROCEDURE Liczba IS
   N : Integer;

BEGIN
   Put("Wprowadz liczbe: ");
   Get(N);

   IF N mod 2 = 0 THEN
      Put(N**3);
   ELSE
      Put(Float(N)**(1.0/3.0), Exp=>0);
   END IF;

END Liczba;
      


