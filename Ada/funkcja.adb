WITH Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
Use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE funkcja IS
   
   A,B : Integer;
   x : float;

BEGIN
   
   Put_line("ax+b=0" );
   Put_line("Podaj a i b: ");
   Put("a: "); Get(A);
   Put("b: "); Get(B);
   
   IF A=0 and b/=0 THEN
      Put("Rownanie jest sprzeczne");
   ELSIF A=0 AND B=0 THEN
      Put("Rownanie ma nieskonczenie wiele rozwiazan");
   ELSIF A/=0 THEN
      X:= Float(-B)/float(A);
      Put("Rozwiazaniem rownania jest: ");
      put(x, exp=>0);
   end if;      
   
END funkcja;

