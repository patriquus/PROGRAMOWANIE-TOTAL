program porownanie_dwoch_liczb;
uses crt;
var a,b:integer;

begin
clrscr;

writeln('Podaj liczbe a');
read(a);
writeln('Podaj liczbe b');
read(b);

if a=b then
writeln('Obie liczby sa rowne');

if a<b then
writeln('Liczba a jest mniejsza od liczby b');

if a>b then
writeln('Liczba a jest wieksza od liczby b');

writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;

end.

