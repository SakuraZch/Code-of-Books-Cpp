
// 2020/5/26 //

#include <iostream>
#include <cstdlib>

// a simple auto pointer
template <typename T>
class A_ptr
{
    private:
        T* ptr_;
    
    public:
        A_ptr(T* ptr = nullptr):
            ptr_(ptr) {}
        ~A_ptr()
        {
            delete this->ptr_;
        }
        void PrintA_ptr() const
        {
            std::cout << *this->ptr_ << std::endl;
        }
};

double Div(int num1, int num2)
{
    if(num2 == 0)
    {
        throw "Division by zero condition!";
    }
    else if(num2 == -1)
    {
        throw -1;
    }

    return num1/num2;
}

int main()
{
    A_ptr<int> testPtr(new int(-11));
    testPtr.PrintA_ptr();

    //-----
    int x = 50, y = -1;
    double z = 0.0;

    try
    {
        z = Div(x, y);
        std::cout << z << std::endl;
    }
    catch(const char* msg)
    {
        std::cerr << msg << '\n';
    }
    catch(const int& num)
    {
        std::cerr << num << std::endl;
    }
    
    std::cout << "Successfully" << std::endl;

    system("pause");
    return 0;
}