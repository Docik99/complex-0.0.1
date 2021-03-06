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
        if (stream >> q && q == '(' && stream >> real_st && stream >> w && w == ',' && stream >> imag_st && stream >> e && e == ')') {
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

} a, b;

int main() {
    char op;

    if (a.read(cin) && (cin >> op) && b.read(cin)) {

        switch (op) {
            case '+':
                (a.add(b)).write(cout);
                break;
            case '-':
                (a.sub(b)).write(cout);
                break;
            case '*':
                (a.mul(b)).write(cout);
                break;
            case '/':
                (a.div(b)).write(cout);
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