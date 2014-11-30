program dziweczyny_case;
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
     	
case x of
1: writeln('Wybrales Agate');
2: writeln('Wybrales Marceline');
else

begin
writeln;
writeln('Zly wybor, sproboj ponownie');
readkey;
goto poczatek;
end;

end;
writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
end.  		
