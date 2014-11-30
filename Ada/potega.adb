WITH Ada.Text_IO, Ada.Numerics, ada.Numerics.Elementary_Functions, ada.Numerics.generic_Elementary_Functions, Ada.Integer_Text_IO, ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Numerics,  ada.Numerics.Elementary_Functions, Ada.Integer_Text_IO, ada.Float_Text_IO;

PROCEDURE Potega IS

   X:Integer;
BEGIN
   Put("Podaj liczbe calkowita: ");
   Get(X);

   IF (X mod 2 = 0) THEN
      Put(X**3);
   ELSE
      Put(float(X)**(1.0/3.0), exp=>0);
   END if;

   END Potega;


