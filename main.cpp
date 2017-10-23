#include <iostream>

using namespace std;

struct complex_t
{
    float real;
    float imag;
};
complex_t add(complex_t rhs,complex_t lhs)
{
    complex_t result;
    result.real=rhs.real+lhs.real;
    result.imag=rhs.imag+lhs.imag;
    return result;
}
complex_t sub(complex_t rhs,complex_t lhs)
{
    complex_t result;
    result.real=rhs.real-lhs.real;
    result.imag=rhs.imag-lhs.imag;
    return result;
}
complex_t mul(complex_t rhs,complex_t lhs)
{
    complex_t result;
    result.real=rhs.real*lhs.real-rhs.imag*lhs.imag;
    result.imag=rhs.imag*lhs.real+rhs.real*lhs.imag;
    return result;
}
complex_t div(complex_t rhs,complex_t lhs)
{
    complex_t result;
    result.real=(rhs.real*lhs.real+rhs.imag*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    result.imag=(rhs.imag*lhs.real-rhs.real*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    return result;
}
istream & read( istream & stream, complex_t & complex )
{
    char q,w,e;
    float real;
    float imag;
    if (stream >> q && q == '(' && stream >> real && stream >> w && w == ',' && stream >> imag && stream >> e && e == ')')
    {
        complex.real = real;
        complex.imag = imag;
    }
    else
    {
        stream.setstate(ios::failbit);
    }

    return stream;
}
ostream & write( ostream & stream, complex_t complex )
{
    stream << "(" << complex.real << ", " << complex.imag << ")";
    return stream;
}
int main()
{
    char op;
    complex_t a,b;

    if(read(cin,a) && (cin >> op) && read(cin,b))
    {
        switch(op)
        {
            case '+':
                write(cout,add(a,b));
                break;

            case '-':
                write(cout,sub(a,b));
                break;

            case '*':
                write(cout,mul(a,b));
                break;

            case '/':
                write(cout,div(a,b));

                break;

            default: cout << endl << "An error has occured while reading input data";
                break;
        }
    }
    else
    {
        cout << endl << "An error has occured while reading input data";
    }
    return 0;
}