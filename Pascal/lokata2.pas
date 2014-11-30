program lokata2;
uses crt;
var suma:real;

procedure czyscekran;
begin
clrscr;
end;

procedure drukujcorobisz;
begin
writeln('Oblicze ile bedzie w banku za 10 lat, podaj sume:');
end;

procedure wczytajdane;
begin
readln(suma);
end;

{procedure oblicz;
var i:integer;
begin
for i:=1 to 10 do
suma:=suma*1.08;
end;}

function oblicz:real; {poczatek funkcji}
var i:integer; {deklaracja zmiennej}
begin
for i:=1 to 10 do
suma:=suma*1.08;
oblicz:=suma;
end;

procedure wydrukuj(wynik:real);
begin
writeln('------------------');
writeln('Obliczylem, po 10 latach masz: ', wynik:5:2);
end;

procedure poczekaj;
begin
writeln('Koniec liczenia, nacisnij cokolwiek...');
readkey;
end;

begin
czyscekran;
drukujcorobisz;
wczytajdane;
oblicz;
wydrukuj(suma);
poczekaj;
end.
