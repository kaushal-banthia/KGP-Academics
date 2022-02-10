#include <iostream>
#include <cmath>
using namespace std;

//************************
//this file has the class definition and inline functions implemented here.
//it also has the definitions to the non inline functions and the static constants
//************************


class Fraction
{
    //numerator and denominator
    int p, q;

    public:

    //static constant for fraction 1/1
    static const Fraction sc_fUnity;
    //static constant for fraction 0/1
    static const Fraction sc_fZero;

    //inline static function that takes 0 arguments and returns the precision constant (return type: int)
    inline static int precision()
    {
        return (int)pow(10, 8);
    }

    //static function that takes 2 integer arguments and returns their greatest common divisor (return type: int)
    static int gcd(int a, int b);

    //static function that takes 2 integer arguments and returns their least common multiple (return type: int)
    static int lcm(int a, int b);

    //function that takes an implicit 'this' pointer as argument and normalises the fraction to its reduced form (return type: void)
    void normalise();

    //constructor that takes an implcit 'this' pointer and 2 integer arguments (can take 1 or 0 arguments also, because it has default parameters) and initialises the Fraction object
    explicit Fraction(int m = 1, int n = 1);

    //overloaded constructor that takes an implicit 'this' pointer and 1 double argument and initialises the Fraction object
    explicit Fraction(double d);

    //copy constructor that takes an implicit 'this' pointer and one const Fraction object as input and sets the member variables of the 'this' pointer to the same value as the const Fraction object
    Fraction(const Fraction &f); 

    //copy assignment that takes an implicit 'this' poiner and one const Fraction object as input and returns reference to another object that has its member variables set to the same value as those of the const Fraction object (return type: reference to Fraction)
    Fraction& operator=(const Fraction &f);

    //inline const function that overloads the unary minus operator. Takes in an implicit 'this' pointer and returns another object that has the negated value of the 'this' pointer.
    //This function is const as we dont expect any change in the 'this' pointer's object (return type: Fraction)
    inline Fraction operator-() const
    {
        return Fraction(-this->p, this->q);
    }

    //inline const function that overloads the unary plus operator. Takes in an implicit 'this' pointer and returns another object that has the same value of the 'this' pointer.
    //This function is const as we dont expect any change in the 'this' pointer's object (return type: Fraction)
    inline Fraction operator+() const
    {
        return *this;
    }

    //function that overloads the prefix decrement operator. Takes in an implicit 'this' pointer and returns reference to decremented 'this' pointer (return type: reference to Fraction)
    Fraction &operator--();

    //function that overloads the prefix increment operator. Takes in an implicit 'this' pointer and returns reference to incremented 'this' pointer (return type: reference to Fraction)
    Fraction &operator++();

    //function that overloads the postfix decrement operator. Takes in an implicit 'this' pointer and returns reference to a copy of the 'this' pointer. Also, decrements the 'this' pointer (return type: Fraction)
    Fraction operator--(int);

    //function that overloads the postfix increment operator. Takes in an implicit 'this' pointer and returns reference to a copy of the 'this' pointer. Also, increments the 'this' pointer (return type: Fraction)
    Fraction operator++(int);

    //friend function that overloads the binary + operator. Takes two Fraction objects as inputs and returns their sum. (return type: Fraction)
    friend Fraction operator+(const Fraction a, const Fraction b);

    //friend function that overloads the binary - operator. Takes two Fraction objects as inputs and returns their difference. (return type: Fraction)
    friend Fraction operator-(const Fraction a, const Fraction b);

    //friend function that overloads the binary * operator. Takes two Fraction objects as inputs and returns their multiplication. (return type: Fraction)
    friend Fraction operator*(const Fraction a, const Fraction b);
    
    //friend function that overloads the binary / operator. Takes two Fraction objects as inputs and returns their divison. (return type: Fraction)
    friend Fraction operator/(const Fraction a, const Fraction b);

    //friend function that overloads the binary % operator. Takes two Fraction objects as inputs and returns their remainder. (return type: Fraction)
    friend Fraction operator%(const Fraction a, const Fraction b);

    //inline const function that overloads the == operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if they are equal. Else returns false
    //checks for equality 
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator==(const Fraction a) const
    {
        return (a.p == p) && (a.q == q);
    }

    //inline const function that overloads the != operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if they are not equal. Else returns false
    //checks for inequality
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator!=(const Fraction a) const
    {
        return !(*this == a);
    }

    //inline const function that overloads the < operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if the 'this' pointer's fraction is less than the const Fraction object. Else returns false
    //checks for the 'less than' condition
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator<(const Fraction a) const
    {
        Fraction c(*this - a);
        return c.p < 0;
    }

    //inline const function that overloads the <= operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if the 'this' pointer's fraction is less than or equal to the const Fraction object. Else returns false
    //checks for the 'less than or equal to' condition
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator<=(const Fraction a) const
    {
        return (*this < a) || (*this == a);
    }

    //inline const function that overloads the > operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if the 'this' pointer's fraction is greater than the const Fraction object. Else returns false
    //checks for the 'greater than' condition
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator>(const Fraction a) const
    {
        return !(*this <= a);
    }

    //inline const function that overloads the >= operator. Takes in an implicit 'this' pointer and a const Fraction object and returns true if the 'this' pointer's fraction is greater than or equal to the const Fraction object. Else returns false
    //checks for the 'greater than or equal to' condition
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: bool)
    inline bool operator>=(const Fraction a) const
    {
        return (*this > a) || (*this == a);
    }

    //inline const function that overloads the ! operator. Takes in an implicit 'this' pointer and returns the reciprocal of the fraction
    //this function is const as we dont expect any change in the 'this' pointer's object (return type: Fraction)
    inline Fraction operator!() const
    {
        if (this->p == 0)
        {
            cout<<"Cannot invert this Fraction";
            exit(1);
        }

        Fraction inverse(this->p, this->q);
        return inverse;
    }

    //friend function that overloads the << operator. It takes in a Fraction object and prints it to the console. (return type: reference to ostream)
    friend ostream& operator<<(ostream &output, Fraction a);

    //friend function that overloads the >> operator. It takes in a reference to a Fraction object and then goes on to take input from the console.
    //Assigns the Fraction object the input values(return type: reference to istream)
    friend istream& operator>>(istream &input, Fraction &a);

    // destructor
    ~Fraction()
    {}
};