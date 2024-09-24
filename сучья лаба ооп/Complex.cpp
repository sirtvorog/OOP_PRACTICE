#include "number.h"
#include "Complex.h"

#include <iostream>
using namespace std;

TComplex::TComplex(double re, double im) {
	this->re = re;
	this->im = im;
}

TComplex TComplex::operator+(TComplex secOperand) {
	re = re + secOperand.re;
	im = im + secOperand.im;
	return TComplex(re, im);
}

TComplex TComplex::operator-(TComplex secOperand) {
	re = re - secOperand.re;
	im = im - secOperand.im;
	return TComplex(re, im);
}

TComplex TComplex::operator*(TComplex secOperand) {
	re = re * secOperand.re - im * secOperand.im;
	im = re * secOperand.im - im * secOperand.re;
	return TComplex(re, im);
}

TComplex TComplex::operator/(TComplex secOperand) {
	double piska = (re * secOperand.re + im * secOperand.im) / (secOperand.re * secOperand.re + secOperand.im * secOperand.im);
	double siska = (secOperand.re * im - re * secOperand.im) / (secOperand.re * secOperand.re + secOperand.im * secOperand.im);
	re = piska;
	im = siska;
	return TComplex(re, im);
}

TComplex TComplex::operator+=(TComplex secOperand) {
	re += secOperand.re;
	im += secOperand.im;
	return TComplex(re, im);
}

TComplex TComplex::operator-=(TComplex secOperand) {
	re -= secOperand.re;
	im -= secOperand.im;
	return TComplex(re, im);
}

TComplex TComplex::operator*=(TComplex secOperand) {
	re = re * secOperand.re - im * secOperand.im;
	im = re * secOperand.im - im * secOperand.re;
	return TComplex(re, im);
}

TComplex TComplex::operator/=(TComplex secOperand) {
	double piska = (re * secOperand.re + im * secOperand.im) / (secOperand.re * secOperand.re + secOperand.im * secOperand.im);
	double siska = (secOperand.re * im - re * secOperand.im) / (secOperand.re * secOperand.re + secOperand.im * secOperand.im);
	re = piska;
	im = siska;
	return TComplex(re, im);
}

bool TComplex::operator==(TComplex& second) const {
	if (re == second.re && im == second.im) return true;
	return false;
}


bool TComplex::operator!=(TComplex& second) const {
	if (re != second.re || im != second.im) return true;
	return false;
}

double TComplex::module(TComplex* complex) {

	double reSquared, imSquared;
	reSquared = pow(complex->re, 2);
	imSquared = pow(complex->im, 2);

	return pow(reSquared + imSquared, 0.5);

}

bool TComplex::operator>(TComplex secOperand) {
	if (module(this) > module(&secOperand)) return true;
	return false;
}

bool TComplex::operator<(TComplex secOperand) {
	if (module(this) < module(&secOperand)) return true;
	return false;
}

TComplex pow(TComplex complex, double n) {
	double argZ;
	
	if (complex.re == 0 && complex.im < 0) argZ = -3.14 / 2;
	else if (complex.re < 0 && complex.im >= 0) argZ = 3.14 + atan(complex.im / complex.re);
	else if (complex.re < 0 && complex.im < 0) argZ = -3.14 + atan(complex.im / complex.re);
	else if (complex.re == 0 && complex.im > 0) argZ = 3.14 / 2;
	else argZ = atan(complex.im / complex.re);
	return TComplex(std::pow(complex.module(&complex), n) * cos(argZ * n),
					std::pow(complex.module(&complex), n) * sin(argZ * n));
	
}

std::ostream& operator<<(std::ostream& os, const TComplex& complex) {
	if (complex.im < 0 && complex.re != 0) {
		os << complex.re << complex.im << "i";
	}
	else if (complex.im != 0 && complex.re == 0) {
		os << complex.im << "i";
	}
	else if (complex.im > 0 && complex.re != 0) {
		os << complex.re << "+" << complex.im << "i";
	}
	else if (complex.im == 0 && complex.re != 0) {
		os << complex.re;
	}
	else {
		os << "0";
	}
	return os;
}

std::istream& operator>>(std::istream& in, TComplex& complex) {
	in >> complex.re >> complex.im;
	return in;
}

