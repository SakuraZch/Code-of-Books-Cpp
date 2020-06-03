
// 2020/6/3 //

#include <iostream>
#include <cstdlib>

class UPInt
{
    private:
        int num_;

    public:
        UPInt(int num):
            num_(num) {}
        ~UPInt() {}

        // using overload technique to avoid type conversions
        friend const UPInt operator+(const UPInt& lhs, 
                                     const UPInt& rhs) // edition1
        {
            return UPInt(lhs.num_ + rhs.num_);
        }

        friend const UPInt operator+(const UPInt& lhs, int rhs) // edition2
        {
            return UPInt(lhs.num_ + rhs);
        }

        friend const UPInt operator+(int lhs, const UPInt& rhs) // edition3
        {
            return UPInt(rhs.num_ + lhs);
        }

        friend std::ostream& operator<<(std::ostream& os, const UPInt& item)
        {
            os << item.num_;
            return os;
        }
};

int main()
{
    UPInt upi1(1);
    UPInt upi2(2);

    UPInt upi3 = upi1 + upi2;
    std::cout << upi3 << std::endl;

    upi3 = 1 + upi1;
    std::cout << upi3 << std::endl;

    upi3 = upi2 + 4;
    std::cout << upi3 << std::endl;

    system("pause");
    return 0;
}