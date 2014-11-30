program for5;
uses crt;
var i:integer;

begin

clrscr;
for i:=1 to 100 do
if i mod 2=1 then write(i,' ');
writeln;
writeln;

for i:=1 to 100 do
if i mod 2=0 then write(i, ' ');
readln;
end.
