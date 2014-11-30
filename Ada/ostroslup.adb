WITH Ada.Integer_Text_IO, Ada.Text_IO, Ada.Float_Text_IO;   
   USE Ada.Integer_Text_IO, Ada.Text_IO, Ada.Float_Text_IO;
   
   PROCEDURE prostopadloscian IS
      a,b,c, pp, pb, pc : Integer;
      V : Float;
   
BEGIN
   Put("Podaj dlugosc krawedzi a: ");
   Get(a);  
   New_Line;
   
   Put("Podaj dlugosc krawedzi b: ");
   Get(b);  
   New_Line;
   
   Put("Podaj dlugosc krawedzi c: ");
   Get(c);  
   New_Line; 
 
   Put("Pole podstawy prostopadloscianu wynosi: ");
   Pp:=A*B;
   Put(Pp);
   
   Put("Pole boczne prostopadloscianu wynosi: ");
   Pb:=4*A*B;
   Put(Pb);
    
   Put("Pole calkowite prostopadloscianu wynosi: ");
   Pb:=2*Pp+Pb;
   Put(Pb);
   
   Put("Objetosc prostopadloscianu wynosi: ");
   V:=float(Pp)*float(c);
   Put(V, exp => 0);  
   New_Line;

end prostopadloscian;
