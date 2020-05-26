
// 2020/5/26 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <new>

class Widget
{
    private:
        int widgetSize_;
    public:
        Widget(int widgetSize):
            widgetSize_(widgetSize) {}
        void PrintWidget() const
        {
            std::cout << this->widgetSize_ << std::endl;
        }
};

Widget* constructWidgetInBuffer(void* buffer, int widgetSize) // placement new
{
    return new (buffer) Widget(widgetSize);
}

int main()
{
    std::string* ps1 = new std::string("Memory Management");
    delete ps1;

    // things will be done in upper codes
    void* memory1 = operator new(sizeof(std::string)); // allocate raw memory
    // call the constructor of string class
    operator delete(memory1); // recycle raw memory

    void* memory2 = operator new(sizeof(Widget)); // allocate raw memory
    Widget* pWidget1 = constructWidgetInBuffer(memory2, 10); // construct object on raw memory
    pWidget1->PrintWidget();
    operator delete(memory2);
    pWidget1 = nullptr;

    //-----
    std::string *ps2 = new std::string[10];
    delete[] ps2;

    system("pause");
    return 0;
}