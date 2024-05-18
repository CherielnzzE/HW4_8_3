#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Complex {
public:
	Complex() :real(0), imaginary(0) {};
	Complex(double realPart, double imaginaryPart) :real(realPart), imaginary(imaginaryPart) {};
	Complex(double realPart) :real(realPart), imaginary(0) {};

	void setReal(double real) {
		this->real = real;
	}

	void setImaginary(double imaginary) {
		this->imaginary = imaginary;
	}

	double getReal() const {
		return real;
	}

	double getImaginary() const {
		return imaginary;
	}

	friend const Complex operator +(const Complex& num1, const Complex& num2);
	friend const Complex operator -(const Complex& num1, const Complex& num2);
	friend const Complex operator *(const Complex& num1, const Complex& num2);
	friend bool operator ==(const Complex& num1, const Complex& num2);
	friend ostream& operator <<(Complex& num, ostream& outputStream);
	friend istream& operator >>(Complex& num, istream& inputStream);
private:
	double real;
	double imaginary;
};
const Complex i(0, 1);

bool operator ==(const Complex& num1, const Complex& num2) {
	return (num1.real == num2.real && num1.imaginary == num2.imaginary);
}

const Complex operator +(const Complex& num1, const Complex& num2) {
	double real, imaginary;

	real = num1.real + num2.real;
	imaginary = num1.imaginary + num2.imaginary;

	return Complex(real, imaginary);
}

const Complex operator -(const Complex& num1, const Complex& num2) {
	double real, imaginary;

	real = num1.real - num2.real;
	imaginary = num1.imaginary - num2.imaginary;
}

const Complex operator *(const Complex& num1, const Complex& num2) {
	double real, imaginary;
	real = num1.real * num2.real - num1.imaginary * num2.imaginary;
	imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;

	return Complex(real, imaginary);
}