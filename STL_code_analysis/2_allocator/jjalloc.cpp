
// 2020/5/29 //

#include "jjalloc.h"
#include <vector>
#include <iostream>

int main()
{
    int ia[5] = {0, 1, 2, 3, 4};
    std::vector<int, JJ::allocator<int> > iv(ia, ia + 5);
    
    for(int i = 0; i < iv.size(); i++)
    {
        std:: cout << iv[i] << ' ';
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}