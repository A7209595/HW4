
#include "Complex.h"
#include <sstream> // Used in toString to convert numbers to strings
#include <cstdlib> // For the abs function
Complex::Complex()
{
	a = 0;
	b = 0;
}

Complex::Complex(int a, int b)
{
	this->a=a;
	this->b=b;
}

int Complex::getA() const
{
	return a;
}

int Complex::getB() const
{
	return b;
}


Complex Complex::add(const Complex& secondComplex) const
{
	int c = a + secondComplex.getA();
	int d = b + secondComplex.getB();
	return Complex(c, d);
}

Complex Complex::subtract(const Complex& secondComplex) const
{
	int c = a - secondComplex.getA();
	int d = b - secondComplex.getB();
	return Complex(c, d);
}

Complex Complex::multiply(const Complex& secondComplex) const
{
	int c, d;
	c = a*secondComplex.getA() + b*secondComplex.getB()*-1.0;
	d = a*secondComplex.getB() + b*secondComplex.getA();
	
	return Complex(c, d);
}



string Complex::toString() const
{
	stringstream ss;
	if (b < 0) {
		ss << a << "" << b << "i";
	}
	else {
		ss << a << "+" << b << "i";
	}
	
	return ss.str();
}

// Define function operators for augmented operators
Complex& Complex::operator+=(const Complex& secondComplex)
{
	*this = add(secondComplex);
	return *this;
}

Complex& Complex::operator-=(const Complex& secondComplex)
{
	*this = subtract(secondComplex);
	return *this;
}

Complex& Complex::operator*=(const Complex& secondComplex)
{
	*this = multiply(secondComplex);
	return *this;
}


// Define function operator []
int& Complex::operator[](int index)
{
	if (index == 0)
		return a;
	else
		return b;
}

// Define function operators for prefix ++ and --
Complex& Complex::operator++()
{
	a += 1;
	return *this;
}

Complex& Complex::operator--()
{
	a -= 1;
	return *this;
}



// Define function operators for unary + and -
Complex Complex::operator+()
{
	return *this;
}

Complex Complex::operator-()
{
	return Complex(-a, b);
}

// Define the output and input operator
ostream& operator<<(ostream& out, const Complex& Complex)
{
	if(Complex.getB()<0)
		out << Complex.a << "" << Complex.b << "i";
	else
		out << Complex.a << "+" << Complex.b << "i";

	
	return out;
}

istream& operator>>(istream& in, Complex& Complex)
{
	cout << "Enter a: ";
	in >> Complex.a;

	cout << "Enter b: ";
	in >> Complex.b;
	return in;
}



// Define non-member function operators for arithmetic operators
Complex operator+(const Complex& r1, const Complex& r2)
{
	return r1.add(r2);
}

Complex operator-(const Complex& r1, const Complex& r2)
{
	return r1.subtract(r2);
}

Complex operator*(const Complex& r1, const Complex& r2)
{
	return r1.multiply(r2);
}