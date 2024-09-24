
#pragma once
#include <iostream>
using namespace std;


class TComplex {

private:
    double re, im;

public:
    TComplex(double re=0, double im=0);
    TComplex operator+(TComplex secOperand);
    TComplex operator-(TComplex secOperand);
    TComplex operator*(TComplex secOperand);
    TComplex operator/(TComplex secOperand);
    TComplex operator+=(TComplex secOperand);
    TComplex operator-=(TComplex secOperand);
    TComplex operator*=(TComplex secOperand);
    TComplex operator/=(TComplex secOperand);
    double module(TComplex* complex);
    bool operator>(TComplex secOperand);
    bool operator<(TComplex secOperand);
    bool operator==(TComplex& second) const;
    bool operator!=(TComplex& second) const;


    friend TComplex pow(TComplex complex, double n);
    friend istream& operator >> (istream& in, TComplex& c);
    friend ostream& operator << (ostream& os, const TComplex& c);

};