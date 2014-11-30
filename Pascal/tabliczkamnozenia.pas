program TabliczkaMnozenia;
uses crt;
var i,j:integer;

procedure mnozenie;
begin

write('*');
for i:=1 to 9 do
write(i:3);
writeln;writeln;
for i:=1 to 9 do

begin
write(i);
for j:=1 to 9 do
write(i*j:3);
writeln;
end;
end;

procedure czyscekran;
begin
clrscr;
end;

begin
czyscekran;
mnozenie;
repeat until keypressed;
end.