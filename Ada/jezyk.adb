WITH Ada.Text_IO, Ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;

PROCEDURE Jezyk IS
   TYPE Miesiac IS
         (Styczen,
          Luty,
          Marzec,
          Kwiecen,
          Maj,
          Czerwiec,
          Lipiec,
          Sierpien,
          Wrzesien,
          Pazdziernik,
          Listopad,
          Grudzien);
   TYPE Month IS
         (January,
          February,
          March,
          April,
          May,
          June,
          July,
          August,
          September,
          October,
          November,
          December);
   TYPE Mes IS
         (Enero,
          Febrero,
          Marzo,
          Abril,
          Mayo,
          Junio,
          Julio,
          Agosto,
          Septiembre,
          Octumbre,
          Noviembre,
          Diciembre);
   TYPE Lang IS
         (En,
          Es);


   PACKAGE Plio IS NEW Ada.Text_IO.Enumeration_IO(Miesiac);
   USE Plio;

   PACKAGE Enio IS NEW Ada.Text_IO.Enumeration_IO(Month);
   USE Enio;

   PACKAGE Esio IS NEW Ada.Text_IO.Enumeration_IO(Mes);
   USE Esio;

   PACKAGE Langio IS NEW Ada.Text_IO.Enumeration_IO(Lang);
   USE Langio;

   M   : Miesiac;
   Jez : Lang;

BEGIN
   Put("Podaj nazwe miesiaca po polsku: ");
   Get(M);
   Put("Chcesz poznac nazwe tego miesiaca po angielsku (en) czy po hiszpansku (es)?");
   New_Line;
   Get(Jez);

   CASE Jez IS
      WHEN En =>
         Put(Month'Val(Miesiac'Pos(M)), Set=>Lower_Case);
      WHEN Es =>
         Put(Mes'Val(Miesiac'Pos(M)), Set=>Lower_Case);
      WHEN OTHERS =>
         Put("Nieobslugiwany jezyk");
   END CASE;
END Jezyk;
