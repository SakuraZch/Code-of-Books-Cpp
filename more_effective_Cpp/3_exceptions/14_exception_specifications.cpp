
// 2020/5/29 //

#include <iostream>
#include <cstdlib>
#include <exception>

typedef void (*CallBackPtr) (int eventXLocation, 
                             int enventYLocation, 
                             void* dataToPassBack) throw();

class CallBack
{
    private:
        CallBackPtr func_;
        void* data_;

    public:
        CallBack(CallBackPtr fPtr, void* dataToPassBack = nullptr):
            func_(fPtr), data_(dataToPassBack) {}
        void MakeCallBack(int eventXLocation, 
                          int enventYLocation) const throw()
        {
            this->func_(eventXLocation, enventYLocation, this->data_);
        }
};

void CallBackFunc1(int eventXLocation, 
                   int enventYLocation, 
                   void* dataToPassBack) {} // without exception specification
void CallBackFunc2(int eventXLocation, 
                   int enventYLocation, 
                   void* dataToPassBack) throw() {}

class UnexpectedException {};

void ConvertUnexpected()
{
    throw UnexpectedException();
}

void DoSomething()
{
    std::set_unexpected(ConvertUnexpected); // replace function to handle unexpected exception
}

int main()
{   
    // CallBack cb1(CallBackFunc1); // failed to match
    CallBack cb2(CallBackFunc2); // match successfully

    system("pause");
    return 0;
}