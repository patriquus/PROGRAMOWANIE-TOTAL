program trojkat2;
uses crt;
var a,b,c,p,S:real;

procedure dane_wejsciowe;
begin
clrscr;

repeat
write('a =');
readln(a);
until a>0;

repeat
write('b = ');
readln(b);
until b>0;

repeat
write('c = ');
readln(c);
until c>0;
end;

procedure licz_boki_trojkata;
begin
{sprawdzenie warunku mozliwosci zbudowania trojkata z podanych wartosci bokow:}
if (a>=b+c) or (b>=a+c) or (c>=a+b) then
write('TE LICZBY NIE MOGA BYC DLUGOSCIAMIM BOKOW TROJKATA')

else
begin
p:=(a+b+c)/2;
s:=sqrt(p*(p-a)*(p-b)*(p-c));
end;
end;

procedure dane_wyjsciowe;
begin
writeln('POLE TROJKATA =', s:7:2);
repeat until keypressed;
end;

begin
dane_wejsciowe;
licz_boki_trojkata;
dane_wyjsciowe;
end.
