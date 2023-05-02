#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

namespace ariel {
    class Fraction {
        private:
            int numerator, denominator;

        public:
            // inline
            Fraction() : numerator(1), denominator(1) {}
            Fraction(int nume, const int deno) : numerator(nume), denominator(deno) {}

            void setNumerator(int newNume) {this->numerator = newNume; }
            int getNumerator() const { return this->numerator; }
            void setDenominator(int newDeno) { this->denominator = newDeno; }
            int getDenominator() const { return this->denominator; }
            
            void reduce() {
                if((this->numerator<0) && (this->denominator<0)) {
                    this->numerator = abs(this->numerator);
                    this->denominator = abs(this->denominator);
                }

                int nume = abs(this->numerator);
                int deno = abs(this->denominator);

                int min = 1;
                if(nume < deno) {
                    min = nume;
                }
                else {
                    min = deno;
                }

                for(int i=min;(i>1) && (deno != 1) && (nume != 1);i--) {
                    if((deno%i==0) && (nume%i==0)) {
                        deno /= i;
                        nume /= i;

                        if(nume < deno) {
                            min = nume;
                        }
                        else {
                            min = deno;
                        }
                        i = min;
                    }     
                }

                if(this->numerator<0) {
                    this->numerator = -nume;
                }
                else {
                    this->numerator = nume;
                }
                
                if(this->denominator<0) {
                    this->denominator = -deno;
                }
                else {
                    this->denominator = deno;
                }
            }

            // postfix
            Fraction operator++(int dummyFlag) {
                Fraction copy = *this;
                this->numerator += this->denominator;
                this->reduce();
                return copy;
            }

            // prefix
            Fraction& operator++() {
                this->numerator += this->denominator;
                this->reduce();
                return *this;
            }

            // postfix
            Fraction operator--(int dummyFlag) {
                Fraction copy = *this;
                this->numerator -= this->denominator;
                this->reduce();
                return copy;
            }

            // prefix
            Fraction& operator--() {
                this->numerator -= this->denominator;
                this->reduce();
                return *this;
            }

            friend bool operator==(const Fraction& num1, const Fraction& num2) {
                int nume1 = num1.numerator*num2.denominator;
                int nume2 = num2.numerator*num1.denominator;
                return (nume1 == nume2);
            }

            // outline
            Fraction(float num);

            friend bool operator<=(const Fraction& num1, const Fraction& num2);
            friend bool operator>=(const Fraction& num1, const Fraction& num2);
            friend bool operator<(const Fraction& num1, const Fraction& num2);
            friend bool operator>(const Fraction& num1, const Fraction& num2);

            friend Fraction operator+(const Fraction& num1, const Fraction& num2);
            friend Fraction operator-(const Fraction& num1, const Fraction& num2);
            friend Fraction operator*(const Fraction& num1, const Fraction& num2);
            friend Fraction operator/(const Fraction& num1, const Fraction& num2);

            friend ostream& operator<< (ostream& output, const Fraction& num);
            friend istream& operator>> (istream& input, Fraction& num);
    };
}