
// 2020/5/27 //

#include <iostream>
#include <cstdlib>

class Session
{
    public:
        Session();
        ~Session();

    private:
        static int times_;

        static void LogCreation(Session* objAddr = nullptr);
        static void LogDestruction(Session* objAddr = nullptr);
};

Session::Session()
{
    try
    {
        this->LogCreation(this);
    }
    catch(const char* str)
    {
        std::cerr << str << std::endl;
    }
}

Session::~Session()
{
    try
    {
        this->LogDestruction();
    }
    catch(const char* str) {} // avoid termination
}

void Session::LogCreation(Session* objAddr)
{
    if(objAddr == nullptr)
    {
        throw "Null Pointer to Construct";
    }
}

void Session::LogDestruction(Session* objAddr)
{
    if(objAddr == nullptr)
    {
        throw "Null Pointer to Destruct";
    }
}

int main()
{
    Session test;

    system("pause");
    return 0;
}