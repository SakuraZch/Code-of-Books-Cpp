
// 2020/5/24 //

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

        UPInt& operator+=(int num)
        {
            this->num_ += num;
            return *this;
        }
        UPInt& operator++()
        {
            *this += 1;
            return *this;
        }
        const UPInt operator++(int)
        {
            UPInt oldVal = this->num_;
            ++(*this);
            return *this;
        }
        UPInt& operator--()
        {
            *this += -1;
            return *this;
        }
        const UPInt operator--(int)
        {
            UPInt oldVal = this->num_;
            --(*this);
            return *this;
        }
        friend std::ostream& operator<<(std::ostream& os, const UPInt& item)
        {
            os << item.num_;
            return os;
        }
};

int main()
{
    UPInt test1(10);
    std::cout << test1++ << std::endl;
    std::cout << ++test1 << std::endl;

    system("pause");
    return 0;
}