program kalkulator; {nazwa programu}
uses crt; {deklaracja uzycia modulu crt}
var a,b,r,h,s:real;
    oczyp:byte;
    wybierz:byte; {deklaracja zmiennych}
const tytul='PROGRAM KALKULATOR BETA ver. 0.7.12 Patryk Gradys IIITE';
      PI=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;
      {deklaracja stalych}
label tobegin;

{PATRYK GRADYS, IIITE}
begin
tobegin:
textbackground(black);
textcolor(lightgreen);
clrscr;

gotoxy(5,1);
writeln(tytul);
gotoxy(1,4);

repeat;

writeln('Co chcesz obliczyc?');
writeln;
writeln('[1] Pole powierzchni');
writeln('[2] Objetosc bryl');
writeln('[3] Zakoncz');
writeln;

read(oczyp);
until (oczyp=1) or (oczyp=2) or (oczyp=3);

clrscr;
gotoxy(25,1);
writeln(tytul);
gotoxy(1,4);

case oczyp of

1:
begin
repeat;
writeln('Wybierz figure, ktorej pole chcesz obliczyc');
writeln;

writeln('[1] - pole kwadratu');
writeln('[2] - pole trojkata');
writeln('[3] - pole trapezu');
writeln('[4] - pole rownolegloboku');
writeln;

read(wybierz);
until (wybierz=1) or (wybierz=2) or (wybierz=3) or (wybierz=4);

clrscr;
gotoxy(5,1);
writeln(tytul);
gotoxy(1,4);

case wybierz of

1:
begin
writeln('Obliczanie pola kwadratu');
writeln;
repeat;

writeln('Wprowadz dlugosc boku a');
writeln;
read(a);
until a>0;

s:=a*a;
writeln;
writeln('Pole powierzchni kwadratu to ', s:2:2);
readkey;

goto tobegin;
end;

2:
begin
writeln('Obliczanie pola trojkata');
writeln;
repeat;

writeln('Wprowadz dlugosc podstawy a');
writeln;
read(a);
until a>0;

writeln('Wprowadz dlugosc wysokosci h');
writeln;
repeat;
read(h);
until h>0;

s:=1/2*a*h;
writeln;
writeln('Pole powierzchni trojkata ', s:2:2);
readkey;

goto tobegin;
end;

3:
begin
writeln('Obliczanie pola trapezu');
writeln;
repeat;

writeln('Wprowadz dlugosc podstawy a');
writeln;
read(a);
until a>0;
repeat;

writeln('Wprowadz dlugosc podstawy b');
writeln;
read(b);
until b>0;
repeat;

writeln('Wprowadz dlugosc wysokosci h');
writeln;
read(h);
until h>0;

s:=1/2*h*(a+b);
writeln;
writeln('Pole powierzchni trapezu ', s:2:2);
readkey;

goto tobegin;
end;

4:
begin
writeln('Obliczanie pola rownolegloboku');
writeln;
repeat;

writeln('Wprowadz dlugosc podstawy a');
writeln;
read(a);
until a>0;

writeln('Wprowadz dlugosc wysokosci h');
writeln;
repeat;
read(h);
until h>0;

s:=a*h;
writeln;
writeln('Pole powierzchni rownolegloboku ', s:2:2);
readkey;

goto tobegin;
end;

end;
end;

2:
begin
repeat;
writeln('Wybierz bryle, ktorej objetosc chcesz obliczyc');
writeln;

writeln('[1] - objetosc kuli');
writeln('[2] - objetosc walca');
writeln('[3] - objetosc stozka');
writeln('[4] - objetosc szescianu');
writeln;

read(wybierz);
until (wybierz=1) or (wybierz=2) or (wybierz=3) or (wybierz=4);

clrscr;
gotoxy(5,1);
writeln(tytul);
gotoxy(1,4);

case wybierz of

1:
begin
writeln('Obliczanie objetosci kuli');
writeln;
repeat;

writeln('Wprowadz dlugosc promienia r');
writeln;
read(r);
until r>0;

s:=4/3*PI*r*r*r;
writeln;
writeln('Objetosc kuli to ', s:2:2);
readkey;

goto tobegin;
end;

2:
begin
writeln('Obliczanie objetosci walca');
writeln;
repeat;

writeln('Wprowadz dlugosc promienia r');
writeln;
read(r);
until r>0;
repeat;

writeln;
writeln('Wprowadz wysokosc walca h');
read(h);
until h>0;

s:=PI*r*r*h;
writeln;
writeln('Objetosc walca to ', s:2:2);
readkey;

goto tobegin;
end;

3:
begin
writeln('Obliczanie objetosci stozka');
writeln;
repeat;

writeln('Wprowadz dlugosc promienia podstawy r');
writeln;
read(r);
until r>0;
repeat;

writeln;
writeln('Wprowadz wysokosc stozka h');
read(h);
until h>0;

s:=1/3*PI*r*r*h;
writeln('Objetosc stozka to ', s:2:2);
readkey;

goto tobegin;
end;

4:
begin
writeln('Obliczanie objetosci szescianu');
writeln;
repeat;

writeln('Wprowadz dlugosc boku a');
writeln;
read(a);
until a>0;

s:=a*a*a;
writeln('Objetosc szescianu to ', s:2:2);
readkey;

goto tobegin;
end;
end;

end; {koniec instrukcji case of dla bryl}

3:
begin
clrscr;
gotoxy(25,3);
writeln('(C) 2011 Patryk Gradys, IIITE');
gotoxy(15,10);
writeln('Wcisnij dowolny klawisz, aby zakonczyc program');
repeat until keypressed;
end;
end; {koniec instrukcji case of dla oczyp}

end.
