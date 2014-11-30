program dziewczyny_while;
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

while x=1 do

begin
writeln('Wybrales Agate');
writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
halt;
end;

while x=2 do
begin
writeln('Wybrales Marceline');
writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
halt;
end;

while x>2 do

begin
writeln('Zly wybor, sproboj ponownie');
readkey;
goto poczatek;
end;

readkey;
end.

