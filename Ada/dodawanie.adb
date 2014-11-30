with ada.Text_IO, ada.Integer_Text_IO;

PROCEDURE dodawanie IS
BEGIN
   Ada.Text_IO.Put("Hello world!");

   Ada.Text_IO.New_Line(2);
   Ada.Text_IO.Put("2+2 = ");

   Ada.Integer_Text_IO.Put(2+2);
   Ada.Text_IO.New_Line(2);
   Ada.Text_IO.Put("2+2 = ");
   Ada.Integer_Text_IO.Put(2+2, Width => 0);
   Ada.Text_IO.New_Line(2);
   Ada.Text_IO.Put("2+2 = ");
   ada.Integer_Text_IO.put(2+2, 0);
END dodawanie;


