program for6;
uses crt;
var i,s:integer;
z:char;

begin
clrscr;
writeln('Wybierz wariant');
writeln('1 Suma od 1 do 10');
writeln('2 Suma od 10 do 20');
writeln('3 Suma od 20 do 30');
read(z);

case z of
'1':
begin
s:=0;
for i:=1 to 10 do
s:=i+s;
writeln(s);
end;

'2':
begin
s:=0;
for i:=10 to 20 do
s:=i+s;
writeln(s);
end;

'3':
begin
s:=0;
for i:=20 to 30 do
s:=i+s;
writeln(s);
end;
end;
readkey;
end.

