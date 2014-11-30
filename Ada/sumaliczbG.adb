WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE sumaliczbG IS

   G,
   I,
   N,
   Suma : Integer;

BEGIN

   I:=0;
   N:=0;
   Suma:=0;
   Put("Podaj calkowita liczbe dodatnia");
   Get(G);

   LOOP
      Suma:=Suma+N+1;
      N:=N+1;
      I:=I+1;
      EXIT WHEN SUMA >= G;
   END LOOP;
   Put(I);
END sumaliczbG;

