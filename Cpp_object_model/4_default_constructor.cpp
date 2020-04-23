
// 2020/4/23 //

#include <iostream>
#include <cstdlib>

// it will have no default constructor to initialize member variables to zero value
class Foo1
{
    public:
        int val_;
        Foo1* pNext_;
};

void Foo1Bar1()
{
    Foo1 bar;
    if(bar.val_ != 0 || bar.pNext_ != nullptr)
    {
        std::cout << bar.val_ << " " << bar.pNext_ << std::endl;
        std::cout << "Val of bar is not empty!" << std::endl;
    }
}

class Foo2
{
    public:
        int num_;
        Foo2(): num_(0) {}
};

// this class has default constructor
class Bar2
{
    public:
        Foo2 foo_; // it will be constructed by complier
        char* chPtr_; // it should be constructed by programmer
};

int main()
{
    Foo1Bar1();
    
    Bar2 bar1;
    std::cout << bar1.foo_.num_ << std::endl;
    if(bar1.chPtr_ == nullptr)
    {
        std::cout << "NULL" << std::endl;
    }

    system("pause");
    return 0;
}