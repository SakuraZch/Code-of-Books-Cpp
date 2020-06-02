
// 2020/6/2 //

#include <iostream>
#include <cstdlib>

class Rational
{
    private:
        double numerator_;
        double denominator_;

    public:
        Rational(double numerator = 0, double denominator = 1):
            numerator_(numerator), denominator_(denominator) {}
        void PrintRational() const
        {
            std::cout << this->numerator_/this->denominator_ << std::endl;
        }
        friend inline const Rational operator*(const Rational& lhs, 
                                                const Rational& rhs)
        {
            return Rational(lhs.numerator_*rhs.numerator_, 
                            lhs.denominator_*rhs.denominator_);
        }
};

int main()
{
    Rational num1 = 10;
    Rational num2(20, 10);
    Rational num3 = num1*num2;
    num1.PrintRational();
    num2.PrintRational();
    num3.PrintRational();

    system("pause");
    return 0;
}