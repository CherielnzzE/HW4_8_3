#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;



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





