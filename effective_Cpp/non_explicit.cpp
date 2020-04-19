
// 2020/3/28 //

#include <iostream>
#include <cstdlib>

struct Test
{
    int x;
    bool tag;

    explicit Test(int x = 0, bool tag = true);
    ~Test();
    void PrintTest() const;
};

Test::Test(int x, bool tag):
    x(x), tag(tag){}

Test::~Test(){}

void Test::PrintTest() const
{
    std::cout << x << " " << tag << std::endl;
}

void PrintTest(Test obj)
{
    std::cout << obj.x << std::endl;
    if(obj.tag == true)
    {
        std::cout << "True" << std::endl;
    }
    else if(obj.tag == false)
    {
        std::cout << "False" << std::endl;
    }
}

int main()
{
    PrintTest(Test(1));

    system("pause");
    return 0;
}