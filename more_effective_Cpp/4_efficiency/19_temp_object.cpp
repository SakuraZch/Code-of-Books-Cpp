
// 2020/6/2 //

#include <iostream>
#include <cstdlib>
#include <string>

int ConutChar1(const std::string& str)
{
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        count++;
    }
    return count;
}

int ConutChar2(std::string& str)
{
    int count = 0;
    for(int i = 0; i < str.size(); i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char str[] = "abcdefghij";
    std::cout << ConutChar1(str) << std::endl; // correct
    // std::cout << ConutChar2(str) << std::endl; // error

    system("pause");
    return 0;
}