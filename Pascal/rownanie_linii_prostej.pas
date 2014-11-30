program rownanie_linii_prostej;
uses crt;
var a,b,x1,x2,y1,y2:integer;

begin
clrscr;
writeln('Podaj a');
read(a);
writeln('Podaj b');
read(b);

y1:=b;
x2:=(-b) div a;

writeln;
writeln('y=',a,'x+', b);
writeln;
writeln('Rozwiazaniem rownania jest para punktow:');
writeln('P1 ma wspolrzedne (', 0,',', y1,')');
writeln('P2 ma wspolrzedne (', x2,',', 0,')');
writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
end.

