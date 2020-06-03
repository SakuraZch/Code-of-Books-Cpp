
// 2020/6/3 //

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

        friend inline const Rational operator*(const Rational& lhs, 
                                                const Rational& rhs)
        {
            return Rational(lhs.numerator_*rhs.numerator_, 
                            lhs.denominator_*rhs.denominator_); // RVO
        }

        inline Rational& operator+=(const Rational& rhs)
        {
            this->numerator_ += rhs.numerator_;
            this->denominator_ += rhs.denominator_;
            return *this;
        }
        inline Rational& operator-=(const Rational& rhs)
        {
            this->numerator_ -= rhs.numerator_;
            this->denominator_ -= rhs.denominator_;
            return *this;
        }

        friend inline const Rational operator+(const Rational& lhs,
                                 const Rational& rhs) // achieve by "operator+="
        {
            return Rational(lhs) += rhs; // RVO
        }
        friend inline const Rational operator-(const Rational& lhs,
                                 const Rational& rhs) // achieve by "operator-="
        {
            return Rational(lhs) -= rhs; // RVO
        }
        void PrintRational() const
        {
            std::cout << this->numerator_ << '/' << this->denominator_ << std::endl;
        }
        
};

int main()
{
    Rational num1(1, 1), num2(2, 1), num3(3, 1), num4(4, 1);
    Rational num5(num1 + num2);
    num5.PrintRational();
    num5 -= num3;
    num5.PrintRational();
    Rational num6 = num1 + num2 + num3 + num4;
    num6.PrintRational();

    system("pause");
    return 0;
}