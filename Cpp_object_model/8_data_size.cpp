
// 2020/5/1 //

#include <iostream>
#include <cstdlib>

class X {};
class Y: public virtual X {};
class Z: public virtual X {};
class F: public Y, public Z {};

int x = 10;

class Point3d
{
    // defensive style1: declare variables here
    // defensive stype2: move all inline functions to the outer place of class
    public:
        Point3d(float x, float y, float z):
            x(x), y(y), z(z) {}
        float X() const
        {
            return x;
        }
        void RenewX(int newX)
        {
            x = newX;
        }
        void PrintPoint3d() const
        {
            std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
        }

    private:
        int x;
        int y;
        int z;
};

typedef int length;

class Point1d
{
    // if you want to use float type of length, you should put your typedef declaration here:
    // typedef float length;
    public:
        Point1d(length val): // "length": global
            val_(val) {}
        void mumble(length val) // "length": global
        {
            this->val_ = val;
        }
        length mumble() const // "length": global
        {
            return this->val_;
        }
        void PrintPoint1d() const
        {
            std::cout << "(" << this->val_ << ")" << std::endl;
        }

    private:
        typedef float length;
        length val_;
};

int main()
{
    X x1;
    Y y1;
    Z z1;
    F f1;

    // output: "1, 4, 4, 8", which is different from "1, 8, 8, 12"
    std::cout << sizeof(x1) << ", " << sizeof(y1) << ", " 
        << sizeof(z1) << ", " << sizeof(f1) << std::endl; // this result indicate g++ has done optimization for the memory
    
    X x2, x3; // object "X" uses one byte to equip an unique address for each object instance
    if(&x2 == &x3)
    {
        std::cout << "Address equal" << std::endl;
    }
    else
    {
        std::cout << "Address not equal" << std::endl;
    }
    
    // -----
    Point3d p1(1, 2, 3);
    p1.PrintPoint3d();
    std::cout << "global x: " << x << std::endl;
    p1.RenewX(x);
    p1.PrintPoint3d();

    // -----
    Point1d p2(10.6);
    p2.PrintPoint1d();

    system("pause");
    return 0;
}