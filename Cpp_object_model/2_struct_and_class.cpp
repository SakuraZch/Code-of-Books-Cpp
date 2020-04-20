
// 2020/4/20 //

#include <iostream>
#include <cstdlib>

// right
template <class T>
class C2
{
    private:
        int num_;
    public:
        C2(num):
            num_(num) {}
        ~C2() {}
};

// right
template <typename T>
class C2
{
    private:
        int num_;
    public:
        C2(num):
            num_(num) {}
        ~C2() {}
};

// ! wrong
// template <struct T>
// class C3
// {
//     private:
//         int num_;
//     public:
//         C3(num):
//             num_(num) {}
//         ~C3() {}
// };

