program dziewczyny_if;
uses crt;
var x:integer;
label poczatek;

begin
poczatek:
clrscr;

writeln('Wybierz dziewczyne');
writeln('[1] Agata');
writeln('[2] Marcelina');
writeln('[3] Maciek');

read(x);

if x=1 then writeln('Wybrales Agate');

if x=2 then writeln('Wybrales Marceline');

if x>2 then

begin
writeln('Zly wybor, sproboj ponownie');
readkey;
goto poczatek;
end;

writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
end.
