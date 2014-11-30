program walec;
uses crt;
var r,h,s:real;
var n:integer;
const pi=3.1415;

begin
clrscr;
writeln('Co chcesz obliczy†?');
writeln;
writeln('1 - Pole powierzchni bocznej walca');
writeln('2 - Objetosc walca');
readln(n);

case n of

1:
begin
writeln('Program do obliczania pola powierzchni bocznej walca');
writeln('Podaj promien podstawy walca');
repeat;
read(r);
until r>0;
writeln('Podaj wysokosc walca');
repeat;
read(h);
until h>0;
s:=2*pi*r*h;
writeln('Pole powierzchni bocznej walca wynosi ', s:2:2);
readkey;
end;

2:
begin
writeln('Program do obliczania objetosci walca');
writeln('Podaj promien podstawy walca');
repeat;
read(r);
until r>0;
writeln('Podaj wysokosc walca');
repeat;
read(h);
until h>0;
s:=pi*r*r*h;
writeln('Objetosc walca wynosi ', s:2:2);
readkey;
end;

end;
end.


