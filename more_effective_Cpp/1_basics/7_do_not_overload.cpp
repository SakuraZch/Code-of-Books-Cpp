
// 2020/5/26 //

#include <iostream>
#include <cstdlib>
#include <cstring>

void Reverse(char s[])
{
    for(int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        std::swap(s[i], s[j]);
    }
}

int Result()
{
    int i = -2, j = 0;
    return i++, --j;
}

int main()
{
    char s[] = "zhangcanhui";
    Reverse(s);
    std::cout << s << std::endl;

    std::cout << Result() << std::endl; // return the value of "j"

    system("pause");
    return 0;
}