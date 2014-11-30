program for4;
uses crt;
var i:integer;

begin
begin
clrscr;
for i:=1 to 100 do
if i mod 2=1 then writeln(i);
end;

begin
gotoxy(20,1);
for i:=1 to 100 do
if i mod 2=0 then writeln(i);
readln;
end;
end.
