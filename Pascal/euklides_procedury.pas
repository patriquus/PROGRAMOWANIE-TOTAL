program euklides_funkcje;
uses crt;
var a,b,s:integer;

procedure czyscekran;
begin
clrscr;
end;

procedure wprowadzdane;
begin
writeln('Wprowadz a');
read(a);
writeln('Wprowadz b');
read(b);
end;

procedure porownajliczby;
begin
while a<>b do
if a>b then
a:=a-b
else
b:=b-a;
end;

function wynik:integer;
begin
s:=a;
writeln('Wynik to ', s);
repeat until keypressed;
end;

begin
czyscekran;
wprowadzdane;
porownajliczby;
wynik;
end.