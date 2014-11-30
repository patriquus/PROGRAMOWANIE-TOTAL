with ada.Text_IO, ada.Integer_Text_IO, ada.Float_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

PROCEDURE Temp IS

c,k,f: Float;
BEGIN
   Put("Podaj temperature w st. C: ");
   Get(C);

   K:=273.15+C;
   F:=32.0+9.0/5.0*C;

   Put(C,4,2,0); Put(" st. C = ");
   Put(K,4,2,0); Put(" K = ");
   Put(F,4,2,0); Put(" st. F");
   end temp;