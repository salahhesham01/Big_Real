#pragma once
#include "BigDecimalIntClass.h"
class BigReal
{
private:
    BigDecimalInt Number;
    BigDecimalInt Decimal;
    string RealNumber;

public:
    BigReal(double realNumber = 0.0); // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal(const BigReal& other); // Copy constructor
    BigReal(BigReal&& other); // Move constructor
    BigReal operator+ (BigReal& other);
    BigReal& operator= (BigReal&& other); // Move assignment
    friend ostream& operator << (ostream& out, BigReal num);
    void addZros(string& str,  string& str2);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int Size();
    int Sign();
    friend istream& operator >> (istream& out, BigReal num);
};