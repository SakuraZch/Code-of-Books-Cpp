
// 2020/5/20 //

#include <iostream>
#include <cstdlib>
#include <string>

class Widget 
{
    public:
        virtual ~Widget() {}
};
class SpecialWidget: public Widget
{
    public:
        virtual ~SpecialWidget() {}
};

void update(SpecialWidget* psw) {}
int doSomething() {}

int main()
{
    int num1 = 1, num2 = 2;
    double result1 = (double)num1 / num2; // cast of C
    double result2 = static_cast<double>(num1) / num2; // cast of Cpp
    std::cout << result1 << " " << result2 << std::endl;
    
    // -----
    SpecialWidget sw;
    const SpecialWidget& csw = sw;
    Widget* pw = new SpecialWidget;

    // update(csw); // "csw" is const
    update((SpecialWidget*)&csw);
    update(const_cast<SpecialWidget*>(&csw));
    // update(pw); // "pw" is not point to a "Widget" class
    // update(const_cast<SpecialWidget*>(pw)); // const cast can not transit type
    update(dynamic_cast<SpecialWidget*>(pw)); // the class of dynamic cast must equipped with virtual functions
    delete pw;

    // -----
    typedef void (*FuncPtr)();
    FuncPtr funcPtrArr[10];
    // funcPtrArr[0] = &doSomething; // type error
    funcPtrArr[0] = reinterpret_cast<FuncPtr>(&doSomething); // reinterpert cast can transmit function pointer type

    system("pause");
    return 0;
}