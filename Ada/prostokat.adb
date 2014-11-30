   WITH Ada.Integer_Text_IO, ada.Text_IO;   
   USE Ada.Integer_Text_IO, Ada.Text_IO;
   
   PROCEDURE Prostokat IS
   Bok1, Bok2, P, Obw : Integer;
   
BEGIN
   Put("Podaj dlugosc boku prostokata: ");
   Get(Bok1);  
   New_Line;
   
   Put("Podaj dlugosc drugiego boku prostokata: ");
   Get(Bok2);
   
   New_Line;
   
   Put("Pole prostokata wynosi: ");
   Put(Bok1*Bok2, width => 0);
   P:=Bok1*Bok2;
   
   New_Line;   
   
   Put("Obwod prostokata wynosi: ");
      Obw:=2*Bok1+2*Bok2;
   putobw, width => 0);

   
   New_Line;  
   
   Put("Pieciokrotnosc obwodu wynosi: ");
   Put(5*Obw);

end prostokat;
