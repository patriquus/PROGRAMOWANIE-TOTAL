WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO, Ada.Numerics, Ada.Numerics.Elementary_Functions;

PROCEDURE Rownanie_Kwadratowe IS
   A,
   B,
   C  : Integer;
   X,
   X1,
   X2,
   D  : Float;
BEGIN
   Put_Line("ax^2 + bx + c = 0");
   Put("Podaj a: ");
   Get(A);
   Put("Podaj b: ");
   Get(B);
   Put("Podaj c: ");
   Get(C);

   D := Float(B)**2-4.0*Float(A*C);

   IF D=0.0 THEN
      X := Float(-B)/2.0*Float(A);
   ELSIF D>0.0 THEN
      X1 := (Float(-B)+Sqrt(D))/2.0*Float(A);
      X2 := (Float(-B)-Sqrt(D))/2.0*Float(A);
   ELSE
      Put("Brak rozwiazan");
   END IF;
END Rownanie_Kwadratowe;

