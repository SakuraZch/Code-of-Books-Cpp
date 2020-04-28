
// 2020/4/28 //

#include <iostream>
#include <cstdlib>

class X
{
    private:
        int i_;
        int j_;
    
    public:
        X(int val):
            j_(val), i_(j_) {}
        ~X() {}
        void PrintX() const
        {
            std::cout << this->i_ << " " << this->j_ << std::endl;
        }
};

class Y
{
    private:
        int i_;
        int j_;
    
    public:
        Y(int val):
            j_(val)
        {
            i_ = j_;
        }
        ~Y() {}
        void PrintY() const
        {
            std::cout << this->i_ << " " << this->j_ << std::endl;
        }
};

class Z
{
    private:
        int i_;
        int j_;
    
    public:
        Z():
            i_(InitNum()), j_(0) {} // call function "InitNum" to do initialize
        Z(int val):
            i_(val), j_(val) {}
        ~Z() {};
        int InitNum() const
        {
            return -2;
        }
        void PrintZ() const
        {
            std::cout << this->i_ << " " << this->j_ << std::endl;
        }
};

class DeriveZ: public Z
{
    private:
        int fVal_;

    public:
        DeriveZ(int val):
            fVal_(val), Z(GetFVal()) {} // using the ingredient of derived class to initialize base class
        ~DeriveZ() {}
        int GetFVal() const
        {
            return this->fVal_;
        }
        void PrintDeriveZ() const
        {
            Z::PrintZ();
            std::cout << fVal_ << std::endl;
        }
};

int main()
{
    X(1).PrintX(); // the value of "i_" is a random number 
    Y(2).PrintY(); // the value of "i_" is 2

    Z().PrintZ(); // you can call function to supply value to do initialize
    DeriveZ(10).PrintDeriveZ(); // the ingredient of base class is random number

    system("pause");
    return 0;
}