program pole_trojkata_funkcja;
uses crt;
var a,h:integer;
p:real;

procedure czyscekran;
begin
clrscr;
end;

procedure wczytajdane;
begin
writeln('Podaj dlugosc podstawy a');
repeat;
read(a);
until a>0;
writeln('Podaj dlugosc wysokosci h');
repeat;
read(h);
until h>0;
end;

function oblicz:real;
begin
p:=(a*h)/2;
oblicz:=p;
end;

procedure wynik;
begin
writeln('Pole trojkata to ', p:7:0);
repeat until keypressed;
end;

begin
czyscekran;
wczytajdane;
oblicz;
wynik;
end.