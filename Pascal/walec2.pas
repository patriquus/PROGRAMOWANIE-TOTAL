program walec;
uses crt;
var r,h:real; T_N: char;
const pi=3.14;

begin

repeat;
clrscr;
repeat;
writeln('Podaj promien');
read(r);
if r<0 then writeln('Promien musi byc wiekszy od 0');
until r>0;

repeat;
writeln('Podaj wysokosc');
read(h);
if h<0 then writeln('Wysokosc musi byc wieksza od 0');
until h>0;

writeln('Objetosc tego walca wynosi ', pi*r*r*h:2:2);
writeln('Zakonczyc? (T)ak/(N)ie');
T_N:=upcase(readkey);
until not (T_N='N');
writeln('Autor: PG');
writeln('Nacisnij dowolny klawisz, aby zakonczyc');
repeat until keypressed;
end.