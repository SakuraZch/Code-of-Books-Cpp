
// 2020/5/4 //

#include <iostream>
#include <cstdlib>

class X 
{
    public:
        int x_;

        X(int x = 0):
            x_(x) {}
        void PrintX() const
        {
            std::cout << "X x_: " << this->x_ << std::endl;
        }
};

class Y: public virtual X 
{
    public:
        Y(int x = 0):
            X(x) {}
        void PrintY() const
        {
            std::cout << "Y x_: " << this->x_ << std::endl;
        }
};

class Z: public virtual X
{
    public:
        Z(int x = 0):
            X(x) {}
        void PrintZ() const
        {
            std::cout << "Z x_: " << this->x_ << std::endl;
        }
};

class Concrete
{
    private:
        int val_;
        char ch1_;
        char ch2_;
        char ch3_;
    
    public:
        Concrete(int val, char ch1, char ch2, char ch3):
            val_(val), ch1_(ch1), ch2_(ch2), ch3_(ch3) {}
        ~Concrete() {}
};

class Concrete1
{
    private:
        int val_;
        char ch1_;
    
    public:
        Concrete1(int val, char ch1):
            val_(val), ch1_(ch1) {}
        ~Concrete1() {}
};

class Concrete2: public Concrete1
{
    private:
        char ch2_;
    
    public:
        Concrete2(int val, char ch1, char ch2):
            Concrete1(val, ch1), ch2_(ch2) {}
        ~Concrete2() {}
};

class Concrete3: public Concrete2
{
    private:
        char ch3_;
    
    public:
        Concrete3(int val, char ch1, char ch2, char ch3):
            Concrete2(val, ch1, ch2), ch3_(ch3) {}
        ~Concrete3() {}
};

int main()
{
    X x1;
    x1.x_ = 1; // static execute
    x1.PrintX();
    Y y1;
    X* ptr1 = &y1;
    ptr1->x_ = 2; // execution time execute
    ptr1->PrintX();

    // -----
    std::cout << "Concrete: " << sizeof(Concrete) << std::endl; // "8", correct
    std::cout << "Concrete1: " << sizeof(Concrete1) << " Concrete2: " << sizeof(Concrete2) << " Concrete3: " << sizeof(Concrete3) << std::endl; // "8 8 8", which indicates the complier did not execute alignment

    system("pause");
    return 0;
}