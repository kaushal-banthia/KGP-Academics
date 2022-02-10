# include "Fraction.hxx"

//************************
//this file has the static constants and the non inline function implemented here
//************************

const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);

int Fraction::gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int Fraction::lcm(int a, int b)
{
    return (int)(a*b/gcd(a, b));
}

void Fraction::normalise()
{
    if (p == 0)
        q = 1;
    else
    {
        int g_c_d = gcd(abs(p), abs(q));
        p /= g_c_d;
        q /= g_c_d;
    }
}

Fraction::Fraction(int m, int n)
{
    if (n == 0)
        exit(1);
    if (m == 0)
        n = 1;
    
    p = m;
    q = n;
    this->normalise();
}

Fraction::Fraction(double d)
{
    p = int(floor((double)d * precision()));
    q = int(precision());

    this->normalise();
}

Fraction::Fraction(const Fraction &f)
{
    p = f.p;
    q = f.q;

    this->normalise();
}

Fraction& Fraction::operator=(const Fraction &f)
{
    p = f.p;
    q = f.q;

    this->normalise();
    return *this;
}

Fraction& Fraction::operator--()
{
    p = p - q;

    this->normalise();
    return *this;
}

Fraction& Fraction::operator++() //prefix
{
    p = p + q;

    this->normalise();
    return *this;
}

Fraction Fraction::operator--(int) //postfix
{
    Fraction f(*this);
    p = p - q;

    this->normalise();
    return f;
}

Fraction Fraction::operator++(int) //postfix
{
    Fraction f(*this);
    p = p + q;

    this->normalise();
    return f;
}

Fraction operator+(const Fraction a, const Fraction b)
{
    Fraction c;
    int lcm = Fraction::lcm(a.q, b.q);
    c.p = (a.p * lcm / a.q) + (b.p * lcm / b.q);
    c.q = lcm;

    c.normalise();
    return c;
}

Fraction operator-(const Fraction a, const Fraction b)
{
    Fraction c;
    int lcm = Fraction::lcm(a.q, b.q);
    c.p = (a.p * lcm / a.q) - (b.p * lcm / b.q);
    c.q = lcm;

    c.normalise();
    return c;
}

Fraction operator*(const Fraction a, const Fraction b)
{
    Fraction c;
    c.p = a.p * b.p;
    c.q = a.q * b.q;

    c.normalise();
    return c;
}

Fraction operator/(const Fraction a, const Fraction b)
{
    if (b == Fraction::sc_fZero)
    {
        cout<<"Division by 0 error"<<endl;
        exit(1);
    }

    Fraction c;
    c.p = a.p * b.q;
    c.q = b.p * a.q;

    c.normalise();
    return c;
}

Fraction operator%(const Fraction a, const Fraction b)
{
    if (b == Fraction::sc_fZero)
    {
        cout<<"Division by 0 error"<<endl;
        exit(1);
    }

    double divisor = (double) b.p/ (double) b.q;
    double dividend = (double) a.p/ (double) a.q;

    int quotient = (int) floor(dividend/divisor);
    Fraction q(quotient);

    Fraction remainder(a - q * b);

    remainder.normalise();
    return remainder;    
}

ostream& operator<<(ostream &output, Fraction a)
{
    if (a.q == 1)
        output<<a.p;
    else
        output<<a.p<<"/"<<a.q;
    return output;
}

istream& operator>>(istream &input, Fraction &a)
{
    int p, q;
    cout<<"Enter numerator"<<endl;
    input>>p;
    cout<<"Enter denominator"<<endl;
    input>>q;

    a.p = p;
    a.q = q;

    a.normalise();
    return input;
}