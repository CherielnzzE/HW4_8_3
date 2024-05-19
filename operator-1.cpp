#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

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

	return Complex(real, imaginary);
}

const Complex operator *(const Complex& num1, const Complex& num2) {
	double real, imaginary;
	real = num1.real * num2.real - num1.imaginary * num2.imaginary;
	imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;

	return Complex(real, imaginary);
}