
#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>
#include <iostream>
using namespace std;

class Complex
{
public:
	Complex();
	Complex(int a, int b);
	int getA() const;
	int getB() const;
	Complex add(const Complex& secondComplex) const;
	Complex subtract(const Complex& secondComplex) const;
	Complex multiply(const Complex& secondComplex) const;
	string toString() const;

	Complex& operator+=(const Complex& secondComplex);
	Complex& operator-=(const Complex& secondComplex);
	Complex& operator*=(const Complex& secondComplex);


	// Define function operator []
	int& operator[](int index);

	// Define function operators for prefix ++ and --
	Complex& operator++();
	Complex& operator--();


	// Define function operators for unary + and -
	Complex operator+();
	Complex operator-();

	// Define the << and >> operators
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);

private:
	int a;
	int b;
};

// Define nonmember function operators for arithmetic operators
Complex operator+(const Complex& r1, const Complex& r2);
Complex operator-(const Complex& r1, const Complex& r2);
Complex operator*(const Complex& r1, const Complex& r2);


#endif