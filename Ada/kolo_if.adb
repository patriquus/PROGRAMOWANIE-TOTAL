WITH Ada.Text_IO, Ada.Numerics, Ada.Integer_Text_IO, Ada.Float_Text_IO, ada.numerics.Elementary_Functions;
Use Ada.Text_IO, Ada.Numerics, Ada.Integer_Text_IO, Ada.Float_Text_IO, ada.numerics.Elementary_Functions;

PROCEDURE kolo_if IS
   
   P : Float;
   r : integer;

BEGIN
   
   Put("Podaj promien kola: " );
   Get(R);
   
   if r>0 then
   P:=Pi * float(R) ** 2;
   Put("Pole kola wynosi: ");
   Put(P, Exp=>0);
      
   ELSE
      put("Zla dana");
   End if;
      
END kolo_if;

