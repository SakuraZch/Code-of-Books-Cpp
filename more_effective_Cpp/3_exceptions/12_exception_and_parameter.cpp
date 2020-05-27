
// 2020/5/27 //

#include <iostream>
#include <cstdlib>

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

void PassAndThrowWidget1()
{
    SpecialWidget localSpecialWidget;
    Widget& rw = localSpecialWidget;
    throw rw;
}

void PassAndThrowWidget2()
{
    SpecialWidget localSpecialWidget;
    SpecialWidget& rw = localSpecialWidget;
    throw rw;
}

void PassAndThrowWidget3(Widget* wptr)
{
    throw wptr;
}

int main()
{
    try
    {
        PassAndThrowWidget1(); // throw by static type, i.e. Widget
    }
    catch(SpecialWidget& sw) // not catch
    {
        std::cout << "SpecialWidget" << std::endl;
    }
    catch(Widget& w) // catch
    {
        std::cout << "Widget" << std::endl;
    }
    
    //-----
    try
    {
        PassAndThrowWidget2();
    }
    catch(Widget& w) // derived class can be recognized as well
    {
        std::cout << "Widget" << std::endl;
    }

    //-----
    Widget* pw = new Widget();
    try
    {
        PassAndThrowWidget3(pw);
    }
    catch(const void* ptr) // catch attribute pointer exception
    {
        std::cout << "Pointer" << std::endl;
        delete pw;
    }

    system("pause");
    return 0;
}