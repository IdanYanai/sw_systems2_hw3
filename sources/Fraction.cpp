#include <iostream>

using namespace std;

#include "Fraction.hpp"

namespace ariel {
    Fraction::Fraction(float num) {
        num *= 1000;
        int inum = static_cast<int>(num);
        this->denominator = 1000;
        this->numerator = inum;
    }

    // All comparison operations -------------------

    bool operator<=(const Fraction& num1, const Fraction& num2) {
        int nume1 = num1.numerator*num2.denominator;
        int nume2 = num2.numerator*num1.denominator;
        return (nume1 <= nume2);
    }

    bool operator>=(const Fraction& num1, const Fraction& num2) {
        int nume1 = num1.numerator*num2.denominator;
        int nume2 = num2.numerator*num1.denominator;
        return (nume1 >= nume2);
    }

    bool operator<(const Fraction& num1, const Fraction& num2) {
        int nume1 = num1.numerator*num2.denominator;
        int nume2 = num2.numerator*num1.denominator;
        return (nume1 < nume2);
    }

    bool operator>(const Fraction& num1, const Fraction& num2) {
        int nume1 = num1.numerator*num2.denominator;
        int nume2 = num2.numerator*num1.denominator;
        return (nume1 > nume2);
    }

    // All math operations -------------------

    Fraction operator+(const Fraction& num1, const Fraction& num2) {
        int nume = num1.getNumerator()*num2.getDenominator() + num2.getNumerator()*num1.getDenominator();
        int deno = num1.getDenominator()*num2.getDenominator();

        Fraction toReturn = Fraction(nume, deno);
        toReturn.reduce();
        return toReturn;
    }

    Fraction operator-(const Fraction& num1, const Fraction& num2) {
        int nume = num1.getNumerator()*num2.getDenominator() - num2.getNumerator()*num1.getDenominator();
        int deno = num1.getDenominator()*num2.getDenominator();

        Fraction toReturn = Fraction(nume, deno);
        toReturn.reduce();
        return toReturn;
    }

    Fraction operator*(const Fraction& num1, const Fraction& num2) {
        int nume = num1.getNumerator()*num2.getNumerator();
        int deno = num1.getDenominator()*num2.getDenominator();

        Fraction toReturn = Fraction(nume, deno);
        toReturn.reduce();
        return toReturn;
    }

    Fraction operator/(const Fraction& num1, const Fraction& num2) {
        int nume = num1.getNumerator()*num2.getDenominator();
        int deno = num1.getDenominator()*num2.getNumerator();

        Fraction toReturn = Fraction(nume, deno);
        toReturn.reduce();
        return toReturn;
    }

    // All IO operations -------------------

    ostream& operator<< (ostream& output, const Fraction& num) {
        return (output << num.numerator << "/" << num.denominator);
    }

    istream& operator>> (istream& input, Fraction& num) {
        input >> num.numerator;
        input >> num.denominator;
        return input;
    }
}