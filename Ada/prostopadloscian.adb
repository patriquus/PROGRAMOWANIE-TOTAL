WITH Ada.Integer_Text_IO, Ada.Text_IO;
   USE Ada.Integer_Text_IO, Ada.Text_IO;
   
   PROCEDURE prostopadloscian IS
      a,b,c, pp, pb, pc, v : integer;
   
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
   Put(Pp, width => 0);
   New_Line;
   
   Put("Pole boczne prostopadloscianu wynosi: ");
   Pb:=4*A*B;
   Put(Pb, width => 0);
   New_Line;   
    
   Put("Pole calkowite prostopadloscianu wynosi: ");
   Pc:=2*Pp+Pb;
   Put(Pc, width => 0);
   New_Line;
      
   Put("Objetosc prostopadloscianu wynosi: ");
   V:=Pp*c;
   Put(V,  width => 0);  
   New_Line;

end prostopadloscian;
