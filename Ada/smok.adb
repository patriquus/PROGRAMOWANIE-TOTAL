WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Smok IS

   Dzien,
   Ilosc,
   I,suma     : Integer;
BEGIN
   Put("Podaj dzien: ");
   Get(Dzien);
   I:=-1;
   Ilosc:=1;
suma:=0;
      LOOP
         Ilosc:=Ilosc+i+1;
      I:=I+1;
      suma:=suma+ilosc;
         EXIT WHEN I=DZIEN;
      END LOOP;
   put("Smok zjadl tego dnia tyle owiec: "); Put(Ilosc, width=>0);
   New_Line;
   put("Smok zjadl razem przez tyle dni tyle owiec: "); put(suma, width=>0);

   END Smok;

