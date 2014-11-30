with ada.Text_IO, ada.Integer_Text_IO;
USE Ada.Text_IO, Ada.Integer_Text_IO;
PROCEDURE Zakres IS
   PACKAGE Ii IS NEW Ada.Text_IO.Float_Io(Short_Float);
   USE Ii;

   PACKAGE Jj IS NEW  Ada.Text_Io.Float_Io(Long_Float);
   USE Jj;

   PACKAGE kk IS NEW  Ada.Text_Io.Float_Io(long_Long_Float);
   USE kk;

   PACKAGE ll IS NEW  Ada.Text_Io.integer_Io(short_integer);
   USE ll;
      PACKAGE mm IS NEW  Ada.Text_Io.integer_Io(long_integer);
   USE mm;
      PACKAGE nn IS NEW  Ada.Text_Io.integer_Io(long_Long_integer);
   USE nn;
         PACKAGE oo IS NEW  Ada.Text_Io.integer_Io(short_short_integer);
   USE oo;


BEGIN
   Put("integer min: ");
   Put(Integer'First);
   new_line;
   Put("integer max: ");
   Put(Integer'Last);
   New_Line(2);

   Put("long_integer min: ");
   mm.Put(long_Integer'First);
   new_line;
   Put("long_integer max: ");
   mm.Put(long_Integer'Last);
   New_Line(2);

   Put("long_long_integer min: ");
   nn.Put(long_long_Integer'First);
   new_line;
   Put("long_long_integer max: ");
   nn.Put(long_long_Integer'Last);
   New_Line(2);

   Put("short_integer min: ");
   Put(short_Integer'First);
   new_line;
   Put("short_integer max: ");
   Put(short_Integer'Last);
   New_Line(2);

   Put("short_short_integer min: ");
   oo.Put(short_short_Integer'First);
   new_line;
   Put("short_short_integer max: ");
   oo.Put(short_short_Integer'Last);
   New_Line(2);

   Put("float min: ");
   Put(float'first);
   new_line;
   Put("float max: ");
   Put(float'last);
   New_Line(2);

   Put("short_float min: ");
   Put(short_float'first);
   new_line;
   Put("short_float max: ");
   Put(short_float'last);
   New_Line(2);

   Put("long_float min: ");
   jj.Put(long_float'first);
   new_line;
   Put("long_float max: ");
   jj.Put(long_float'last);
   New_Line(2);

   Put("long_long_float min: ");
   kk.Put(long_long_float'first);
   new_line;
   Put("long_long_float max: ");
   kk.Put(long_long_float'last);
   New_Line(2);

end zakres;