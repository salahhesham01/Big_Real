#include "BigReal.h"


// Default constructor
BigReal::BigReal(double realNumber)
{
    RealNumber = to_string(realNumber);
    for (int i = 0; i < RealNumber.length(); i++)
    {
        if (RealNumber[i] == '.')
        {
            Number = RealNumber.substr(0, i);
            Decimal = RealNumber.substr(i + 1, RealNumber.length() - i - 1);
            break;
        }
    }
}

BigReal::BigReal(string realNumber)
{
    RealNumber = realNumber;
    for (int i = 0; i < RealNumber.length(); i++)
    {
        if (RealNumber[i] == '.')
        {
            Number = RealNumber.substr(0, i);
            Decimal = RealNumber.substr(i + 1, RealNumber.length() - i - 1);
            break;
        }
    }
}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    RealNumber = bigInteger.getNumber();
    Number = bigInteger;
    Decimal = BigDecimalInt("0");

}

// Assignment operator
BigReal& BigReal::operator=(BigReal& other)
{
    Number = other.Number;
    Decimal = other.Decimal;
    RealNumber = other.RealNumber;
    return *this;
}

// Copy constructor
BigReal::BigReal(const BigReal& other)
{
    Number = other.Number;
    Decimal = other.Decimal;
    RealNumber = other.RealNumber;
}

// Move constructor
BigReal::BigReal(BigReal&& other)
{
    Number = other.Number;
    Decimal = other.Decimal;
    RealNumber = other.RealNumber;
}

// Move assignment
BigReal& BigReal::operator=(BigReal&& other)
{
    Number = other.Number;
    Decimal = other.Decimal;
    RealNumber = other.RealNumber;
    return *this;
}

void BigReal::addZros( string& str, string& str2)
{
    int diff;
    if (str.length() > str2.length())
    {
        diff = str.length() - str2.length();
        for (int i = 0; i < diff; i++)
        {
            str2 += '0';
        }
    }
    else if (str.length() < str2.length())
    {
        diff = str2.length() - str.length();
        for (int i = 0; i < diff; i++)
        {
            str += '0';
        }
    }
}

BigReal BigReal :: operator+ (BigReal& other)
{
    BigReal a;
    a.Number = Number + other.Number;
    string str = Decimal.getNumber();
    string str2 = other.Decimal.getNumber();
    addZros(str, str2);
    string str1;
    int carry = 0;

    if (Number.sign() == 1 && other.Number.sign() == 1)
    {
        a.Decimal = BigDecimalInt(str) + BigDecimalInt(str2);
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x + y > 9)
        {
            a.Number = a.Number + BigDecimalInt("1");
        }

    }
    else if (Number.sign()==0 && other.Number.sign()==0)
    {
        a.Decimal = BigDecimalInt(str) + BigDecimalInt(str2);
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x + y > 9)
        {
            a.Number = a.Number - BigDecimalInt("1");
        }
    }
    else if (Number.sign() == 1 && other.Number.sign() == 0)
    {

        for (int i = str.length() - 1; i >= 0; i--)
        {
            int x = str[i] - '0';
            int y = str2[i] - '0';
            int z = x - y - carry;
            if (z < 0)
            {
                z += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            str1 += to_string(z);
        }
        reverse(str1.begin(), str1.end());
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x - y < 0)
        {
            a.Number = a.Number - BigDecimalInt("1");
        }
        a.Decimal = BigDecimalInt(str1);

    }
    else if (Number.sign() == 0 && other.Number.sign() == 1)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            int x = str[i] - '0';
            int y = str2[i] - '0';
            int z = y-x - carry;
            if (z < 0)
            {
                z += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            str1 += to_string(z);
        }
        reverse(str1.begin(), str1.end());
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (y - x < 0)
        {
            a.Number = a.Number - BigDecimalInt("1");
        }
        a.Decimal = BigDecimalInt(str1);

    }
    return a;
}

BigReal BigReal :: operator- (BigReal& other)
{
    BigReal a;
    a.Number = Number - other.Number;
    string str = Decimal.getNumber();
    string str2 = other.Decimal.getNumber();
    addZros(str, str2);
    string str1;
    int carry = 0;
    if (Number.sign() == 1 && other.Number.sign() == 1)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            int x = str[i] - '0';
            int y = str2[i] - '0';
            int z = x - y - carry;
            if (z < 0)
            {
                z += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            str1 += to_string(z);
        }
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x - y < 0)
        {
            a.Number = a.Number - BigDecimalInt("1");
        }
        reverse(str1.begin(), str1.end());
        a.Decimal = BigDecimalInt(str1);
    }
    else if (Number.sign() == 0 && other.Number.sign() == 0)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            int x = str[i] - '0';
            int y = str2[i] - '0';
            int z = x - y - carry;
            if (z < 0)
            {
                z += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            str1 += to_string(z);
        }
        reverse(str1.begin(), str1.end());
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x - y < 0)
        {
            a.Number = a.Number + BigDecimalInt("1");
        }
        a.Decimal = BigDecimalInt(str1);
    }
    else if (Number.sign() == 1 && other.Number.sign() == 0)
    {
        a.Decimal = BigDecimalInt(str) + BigDecimalInt(str2);
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x + y > 9)
        {
            a.Number = a.Number + BigDecimalInt("1");
        }
    }
    else if (Number.sign() == 0 && other.Number.sign() == 1)
    {
        a.Decimal = BigDecimalInt(str) + BigDecimalInt(str2);
        int x = str[0] - '0';
        int y = str2[0] - '0';
        if (x + y > 9)
        {
            a.Number = a.Number + BigDecimalInt("1");
        }
    }
    return a;
}

// operator < overloading function.
bool BigReal :: operator< (BigReal anotherReal) {
    if (Number < anotherReal.Number) {
        return true;
    }
    else if (Number > anotherReal.Number) {
        return false;
    }
    else {
        if (Decimal < anotherReal.Decimal) {
            return true;
        }
        else if (Decimal > anotherReal.Decimal) {
            return false;
        }
    }
}
bool BigReal :: operator> (BigReal anotherReal) {
    if (Number < anotherReal.Number) {
        return false;
    }
    else if (Number > anotherReal.Number) {
        return true;
    }
    else {
        if (Decimal < anotherReal.Decimal) {
            return false;
        }
        else if (Decimal > anotherReal.Decimal) {
            return true;
        }
    }
}
bool BigReal :: operator== (BigReal anotherReal) {
    if (Number == anotherReal.Number && Decimal == anotherReal.Decimal) {
        return true;
    }
    else {
        return false;
    }
}
int BigReal::Size() {
    if (RealNumber[0] == '+' || RealNumber[0] == '-')
    {
        return RealNumber.size() - 2;
    }
    else
    {
        return RealNumber.size() - 1;
    }

}
int BigReal::Sign() {
    if (RealNumber[0] == '-') {
        return 0;
    }
    else {
        return 1;
    }
}
// operator << overloading function
ostream& operator << (ostream& out, BigReal num)
{
    out << num.Number << "." << num.Decimal;
    return out;
}
// operator >> overloading function.
istream& operator >> (istream& in, BigReal num)
{

    in >> num.Number>>num.Decimal;

    return in;
}

