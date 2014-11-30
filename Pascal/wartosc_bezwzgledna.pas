program wartosc_bezwzgledna;
uses crt;
var a:integer;

begin
clrscr;
writeln('Obliczanie wartosci bezwzglednej');
writeln;
writeln('Podaj liczbe');
read(a);

if a>=0 then
writeln('Wartosc bezwzgledna podanej liczby to ', a);

if a<0 then
writeln('Wartosc bezwzgledna podanej liczby to ', -a);

writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;

end.

