program menu_wyboru_if_else;
uses crt;
var x:integer;

begin
clrscr;

writeln('Wybierz figure');
writeln('[1] Kolo');
writeln('[2] Kwadrat');
read(x);

if x=1 then writeln('Wybrales kolo')

else writeln('Wybrales kwadrat');

readkey;
end.



