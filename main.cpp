#include <iostream>
using namespace std;

struct complex_t {
    float real;
    float imag;

    complex_t add(complex_t other) const {
        complex_t result;
        result.real = real + other.real;
        result.imag = imag + other.imag;
        return result;
    }

    complex_t sub(complex_t other) const {
        complex_t result;
        result.real = real - other.real;
        result.imag = imag - other.imag;
        return result;
    }
    complex_t mul(complex_t other) const {
        complex_t result;
        result.real = real*other.real - imag*other.imag;
        result.imag = real*other.imag + other.real*imag;
        return result;
    }
    complex_t div(complex_t other) const {
        complex_t result;
        result.real = (real*other.real + imag*other.imag) / (other.real*other.real + other.imag*other.imag);
        result.imag = (imag*other.real - real*other.imag) / (other.real*other.real + other.imag*other.imag);
        return result;
    }

    istream & read(istream & stream) {
        char q, w, e;
        float real_st, imag_st;
        if (stream >> q && q == '(' && stream >> real && stream >> w && w == ',' && stream >> imag && stream >> e && e == ')') {
            real = real_st;
            imag = imag_st;
        }
        else {
            stream.setstate(ios::failbit);
        }
        return stream;
    }
    ostream & write(ostream & stream) {
        stream << '(' << real << ", " << imag << ')' << endl;
        return stream;
    }

} result;

int main() {

    char op;
    complex_t a,b;

    if (a.read(cin) && (cin >> op) && b.read(cin)) {

        switch (op) {
            case '+':
                result = a.add(b);
                result.write(cout);
                break;
            case '-':
                result = a.sub(b);
                result.write(cout);
                break;
            case '*':
                result =  a.mul(b);
                result.write(cout);
                break;
            case '/':
                result = a.div(b);
                result.write(cout);
                break;
            default:
                cout << '\n' << "An error has occured while reading input data";
                break;
        }
    }
    else {
        cout << endl << "An error has occured while reading input data";
    }

    return 0;
}