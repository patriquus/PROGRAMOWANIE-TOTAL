program pole_obwod_t_rownobocznego_case;
uses crt;
var a,h,s:real;
    wybor:byte;
    koniec:integer;

begin
textbackground(green);
textcolor(yellow);
clrscr;

writeln('Chcesz obliczyc pole czy obwod trojkata rownobocznego?');
writeln('[1] Pole powierzchni');
writeln('[2] Obwod');

read(wybor);

case wybor of

1:
begin
repeat;
clrscr;

writeln('Obliczanie pola trojkata rownobocznego');
repeat;
writeln('Wprowadz dlugosc boku a');
read(a);
until a>0;

repeat;
writeln('Wprowadz wysokosc h');
read(h);
until h>0;

writeln('1/2*a*h');
writeln;
s:=1/2*a*h;

writeln('Pole trojkata rownobocznego to ', s:2:2);
writeln('Czy zakonczyc dzialanie programu?');
writeln('[1] Tak [2] Nie');

read(koniec);
until koniec=1;
end;

2:
begin
repeat;
clrscr;

writeln('Obliczanie obwodu trojkata rownobocznego');
repeat;
writeln('Wprowadz dlugosc boku a');
read(a);
until a>0;

writeln('3a');
s:=3*a;

writeln('Obwod trojkata rownobocznego to ', s:2:2);
writeln('Czy zakonczyc dzialanie programu?');
writeln('[1] Tak [2] Nie');

read(koniec);
until koniec=1;
end;

end; {konczy case}
end.

