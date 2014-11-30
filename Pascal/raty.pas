program raty;
uses crt;
var i:integer;
debet,suma,procenty,rata:real;

begin
clrscr;
debet:=1000;
procenty:=0.20/12;
suma:=0;
for i:=1 to 12 do
begin
debet:=debet*(1+procenty);
rata:=(1/13-i)*debet;
debet:=debet-rata;
writeln('rata za', i ,'Mies. ',rata:5:2, ' debet', debet);
suma:=suma-rata;