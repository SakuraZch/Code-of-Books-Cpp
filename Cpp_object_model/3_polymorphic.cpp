
// 2020/4/22 //

#include <iostream>
#include <cstdlib>
#include <vector>
#include <typeinfo>

class Base
{
    private:
        int num_;
    public:
        Base(int num):
            num_(num) {}
        virtual ~Base() {}
        int GetNum() const
        {
            return this->num_;
        }
        virtual void Print() const
        {
            std::cout << "Base" << std::endl;
        }
};

class Derived: public Base
{
    private:
        char ch_;
    public:
        Derived(int num, char ch):
            Base(num), ch_(ch) {}
        virtual ~Derived() {}
        virtual void Print() const
        {
            std::cout << "Derived" << std::endl;
        }
        void DerivedPrint()
        {
            std::cout << Base::GetNum() << " " << this->ch_ << std::endl;
        }
};

void ClassPrint(Derived dt, const Base& ref, Base* ptr)
{
    dt.Print();
    ref.Print();
    ptr->Print();
}

int main()
{
    Base bs1(1);
    Derived dd1(2, 'a');
    Derived dd2(3, 'c');

    // static cast: implicit conversion
    Base dd3 = static_cast<Base>(dd2); 
    std::cout << (static_cast<Base>(dd2)).GetNum() << std::endl;
    if(Base* bs2 = dynamic_cast<Base*>(&dd2))
    {
        bs2->Print();
    }

    // dynamic cast: conversion from pointer to base class to pointer to derived class
    Base* bPtr1 = &dd1;
    Derived* dd4 = dynamic_cast<Derived*>(bPtr1); 
    bPtr1->Print();
    dd4->DerivedPrint();

    // test of virtual functions
    std::vector<Base*> vec = {&bs1, &dd1, &dd3};
    for(auto elem : vec)
    {
        elem->Print();
    }

    Base* bPtr2 = &bs1;
    ClassPrint(dd1, dd1, bPtr2);

    // test of typeid
    std::cout << typeid(bPtr1).name() << " " << typeid(dd4).name() << " " << typeid(&bs1).name() << std::endl;

    // test of slice
    Derived dd5(5, 'p');
    Base bs3 = dd5;
    bs3.Print();
    std::cout << bs3.GetNum() << std::endl;

    system("pause");
    return 0;
}