// studenti.h -- klasa Student zdefiniowana za pomocą dziedziczenia wielokrotnego
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <valarray>
#include <string>
class Student : private std::string, private std::valarray<double>
{
    private:
        typedef std::valarray<double> ArrayDb;
        // prywatna metoda do wyświetlania ocen
        std::ostream & arr_out(std::ostream & os) const;
    public:
        Student() : std::string("Brak"), ArrayDb() {}
        explicit Student(const std::string & s)
            : std::string(s), ArrayDb() {}
        explicit Student(int n) : std::string("Brak"), ArrayDb(n) {}
        Student(const std::string & s, int n)
            : std::string(s), ArrayDb(n) {}
        Student(const std::string & s, const ArrayDb & a)
            : std::string(s), ArrayDb(a) {}
        Student(const char * str, const double * pd, int n)
            : std::string(str), ArrayDb(pd, n) {}
        ~Student() {}
        double Average() const;
        double & operator[](int i);
        double operator[](int i) const;
        const std::string & Name() const;
        // funkcje zaprzyjaźnione
        // obsługa wejścia
        friend std::istream & operator>>(std::istream & is,
                Student & stu); // 1 słowo
        friend std::istream & getline(std::istream & is,
                Student & stu); // 1 linia
        // obsługa wyjścia
        friend std::ostream & operator<<(std::ostream & os,
                const Student & stu);
};

#endif 

