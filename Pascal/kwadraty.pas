program kwadraty;
uses crt,graph;
var
driver,mode,po,pis,psl,rp:integer;
a,b,c,d,e,f:integer;

Begin
clrscr;
repeat
writeln('Podaj procent poparcia PO w procentach (1-100).');
readln(po)
until (po>=0)and(po<=100);
repeat
writeln('Podaj procent poparcia PIS w procentach (1-100).');
readln(pis);
until (pis>=0)and(pis<=100);
repeat
writeln('Podaj procent poparcia PSL w procentach (1-100).');
readln(psl);
until (psl>=0)and(psl<=100);
repeat
writeln('Podaj procent poparcia Ruchu Palikota w procentach (1-100).');
readln(rp);
until (rp>=0)and(rp<=100);

driver:=Detect;
mode:=0;
InitGraph(driver,mode,'');

Line(50,50,50,900);
Line(10,850,1200,850);
SetColor(red);
for f:=1 to 100 do
Bar3D(100,po,200,850,50,true);
Bar3D(300,pis,400,850,50,true);
Bar3D(500,psl,600,850,50,true);
Bar3D(700,rp,800,850,50,true);

readln;
Closegraph;
end.