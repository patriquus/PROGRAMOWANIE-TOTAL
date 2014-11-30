program dec_to_bin;
uses crt;
var R,x,i:integer;

begin
clrscr;
writeln('Program zamienia liczby dziesietne na binarne');
writeln;
writeln('Podaj liczbe dziesietna');
read(x);

i:=0; {stan poczatkowy licznika}
repeat;
R:=x mod 2;
x:=x/2;
i:=i+1; {licznik}
until x<>0;

writeln('W postaci binarnej ta liczba to: ', R);
writeln('P©tla powtorzona ', i, 'razy');
writeln;
writeln('Dziekuje za uzycie programu, Patryk Gradys');
readkey;
end.
