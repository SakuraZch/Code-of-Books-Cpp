
// 2020/5/29 //

#include <iostream>
#include <cstdlib>
#include <string>

class Exception
{
    public:
        std::string st_;
        Exception(const std::string& st):
            st_(st) {}
        void PrintException() const
        {
            std::cout << st_ << std::endl;
        }
        virtual std::string What() const throw()
        {
            return "Description: " + st_;
        }
};

class ValidationError: public Exception
{
    public:
        ValidationError(const std::string& st):
            Exception(st) {}
        virtual std::string What() const throw()
        {
            return "Validation " + Exception::What();
        }
};

void SomeFunction1()
{
    static Exception ex1("Static Variable"); // static variable will not be destruct
    Exception ex2("Auto Variable"); // auto variable will be destruct

    throw &ex1;
}

void DoSomething1()
{
    try
    {
        SomeFunction1();
    }
    catch(Exception* ex)
    {
        ex->PrintException();
    }
}

void SomeFunction2()
{
    ValidationError ve("Valid Error");

    throw ve; // throw a instance of ValidationError
}

void DoSomething2()
{
    try
    {
        SomeFunction2();
    }
    catch(const Exception& ex) // catch as Exception
    {
        std::cout << ex.What() << std::endl; // call function "What()" dynamically
    }
}

int main()
{
    DoSomething1();
    DoSomething2();

    system("pause");
    return 0;
}