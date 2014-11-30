WITH Ada.Text_IO, ada.Numerics, Ada.Float_Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, ada.Numerics, Ada.Float_Text_IO, Ada.Integer_Text_IO;

PROCEDURE Kula IS
   R, n : Integer;
   P, V : Float;
   
BEGIN
   
      
   Put_line("Oblicz");
   Put_line("1. Pole powierzchni kuli");
   Put_Line("2. Objetosc kuli");
   Get(N);
   
   IF N=1 THEN
      Put("Podaj promien kuli: ");
      Get(R);
       if r>0 then
         p:=4.0 * pi * float(r)**2;
         Put("Pole powierzchni kuli kuli wynosi: ");
         put(p, exp=>0);
      ELSE
         Put("Promien musi byc wiekszy od 0");
      END IF;
           
   ELSIF N=2 THEN
      Put("Podaj promien kuli: ");
      Get(R);
      if r>0 then
         V:=4.0/3.0 * Pi * float(R)**3;
         Put("Objetosc kuli wynosi: ");
         put(v, exp=>0);
      ELSE
         Put("Promien musi byc wiekszy od 0");
         end if;
   ELSE
      Put("Bledny wybor");
   END IF;

end kula;