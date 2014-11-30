WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Rok_Przestepny IS
   I : Integer;
BEGIN
   Put("Wprowadz rok: ");
   Get(I);

   IF I mod 4 = 0 AND (I mod 100 /= 0 OR I mod 400 = 0) THEN
      Put("Rok przestepny");
   ELSE
      Put("Rok nieprzestepny");
   END IF;
END Rok_Przestepny;
