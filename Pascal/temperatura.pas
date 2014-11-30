program temperatura;
uses crt;
var tabelka:array[1..7] of real;
    indeks:integer;
    suma,srednia:real;

begin
clrscr;
tabelka[1]:=39.1;
tabelka[2]:=38.9;
tabelka[3]:=39.2;
tabelka[4]:=30.3;
tabelka[5]:=37.6;
tabelka[6]:=36.9;
tabelka[7]:=36.3; {zdefiniowane elementy tablicy}

writeln('Wybierz dzien: (1..7)');
read(indeks);
writeln;

writeln('Temperatura:', tabelka[indeks]:2:1);
writeln;
if (tabelka[indeks] < 37.0) then writeln('ZDROWY!')
else write('Za wysoka temperatura!');
writeln;
writeln;

writeln('Elementy zbioru:');
for indeks:=1 to 7 do
writeln(tabelka[indeks]:2:1);
writeln;

suma:=0;
for indeks:=1 to 7 do
suma:=suma+tabelka[indeks];

srednia:=suma/7;

writeln('Srednia tygodniowa temperatura ', srednia:3:1);

readkey;
end.
