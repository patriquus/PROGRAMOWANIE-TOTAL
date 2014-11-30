WITH Ada.Text_IO, ada.Integer_Text_IO;
USE Ada.Text_IO, ada.Integer_Text_IO;

PROCEDURE Zadanie1 IS

TYPE Dnity IS (Poniedzialek,Wtorek,Sroda,Czwartek,Piatek,Sobota,Niedziela);
PACKAGE Dni IS NEW Ada.Text_IO.Enumeration_IO(Dnity);
USE Dni;
Dz: Dnity;
pozycja_jutra : integer;

BEGIN

Put("podaj dzien tygodnia");
new_line ; Get(Dz);

--put(dz);put("jest wczesniejszym dniem niz "); put(dnity'succ(dz));
IF Dz IN Poniedzialek..Piatek THEN
Put("jest to dzien roboczym"); new_line;
Put("do weekendu zostalo:"); new_line;
Put (Dnity'Pos(Sobota) - Dnity'Pos(Dz)); Put("dni");

ELSE Put("to jest weekend");
END IF;

Pozycja_Jutra:=(Dnity'Pos(Dz)+1) mod 7 ; New_Line;

Put("jutro bedzie: " ); Put(Dnity'Val(Pozycja_Jutra)); New_Line;
pozycja_jutra:=(Dnity'pos(dz)-1) mod 7 ; new_line;
put("wczoraj byl : "); put(dnity'val(pozycja_jutra));
Pozycja_Jutra:=(Dnity'Pos(Dz)+2 ) mod 7 ; New_Line;
put("pojutrze bedzie : " ); put ( dnity'val(pozycja_jutra));

END Zadanie1;