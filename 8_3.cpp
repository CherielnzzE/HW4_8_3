#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class Complex {


public:

    //constructor of the class
    Complex() :real(0), imaginary(0) {};

    //constructor of the class
    Complex(double realPart, double imaginaryPart) :real(realPart), imaginary(imaginaryPart) {};

    //constructor of the class
    Complex(double realPart) :real(realPart), imaginary(0) {};

    //setter of real
    void setReal(double real) { this->real = real; };

    //setter of imaginary
    void setImaginary(double imaginary) { this->imaginary = imaginary; };

    //getter of real
    double getReal() const { return  real; };

    //getter of imaginary
    double getImaginary() const { return imaginary; };

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

	return Complex(real, imaginary);
}

const Complex operator *(const Complex& num1, const Complex& num2) {
	double real, imaginary;
	real = num1.real * num2.real - num1.imaginary * num2.imaginary;
	imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;

	return Complex(real, imaginary);
}


ostream& operator <<(Complex& num, ostream& outputStream) {

    outputStream << num.real;

    if (num.imaginary > 0) {

        if (num.imaginary == 1) {
            outputStream << "i" << endl;
        }
        else {
            outputStream << num.imaginary << "i" << endl;
        }
    }
    else {
        if (num.imaginary == -1) {
            outputStream << "-i" << endl;
        }
        else {
            outputStream << "-" << abs(num.imaginary) << "i" << endl;
        }
    }

    return(outputStream);
}

istream& operator>>(Complex& num, istream& inputStream) {

    char plus;
    inputStream >> num.real >> plus >> num.imaginary;
    if (getchar() != 'i') {
        cout << "Input Error ! " << endl;
        exit(1);
    }

    if (plus == '+') {

        num.imaginary = num.imaginary;
    }
    else {

        num.imaginary = -num.imaginary;
    }

    return(inputStream);
}



int main() {

    Complex num1;
    Complex num2;
    cout << "Enter a complex number (form:a +/- bi): " << endl;
    cin >> num1;
    cout << "Enter another complex numebr(form: a +/- bi): " << endl;
    cin >> num2;

    Complex sum = num1 + num2;
    cout << "(" << num1 << ")+(" << num2 << ")=" << sum << endl;
    sum = num1 - num2;
    cout << "(" << num1 << ")-(" << num2 << ")=" << sum << endl;
    sum = num1 * num2;
    cout << "(" << num1 << ")*(" << num2 << ")=" << sum << endl;

    return 0;
}

