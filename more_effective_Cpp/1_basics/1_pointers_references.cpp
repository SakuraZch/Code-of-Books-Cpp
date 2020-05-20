
// 2020/5/20 //

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    char* pc1 = nullptr;
    char& pc2 = *pc1; // fault
    // std::cout << pc2 << std::endl; // segmentation default

    std::string s1("Nancy");
    std::string s2("Clancy");
    std::string& rs = s1;
    std::string* ps = &s1;
    rs = s2; // value of "s1" has been changed
    ps = &s2;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    system("pause");
    return 0;
}