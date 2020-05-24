
// 2020/5/24 //

#include <iostream>
#include <cstdlib>

class Rational
{
    private:
        double numerator_;
        double denominator_;

    public:
        Rational(double numerator = 0, double denominator = 1):
            numerator_(numerator), denominator_(denominator) {}
        double AsDouble() const // explicit conversion
        {
            return this->numerator_/this->denominator_;
        }
        operator double() const // implicit conversion
        {
            return this->numerator_/this->denominator_;
        }
};

template<typename T>
class Array
{
    private:
        T* arr_;
        int size_;

    public:
        class ArraySize // a proxy class
        {
            private:
                int arraySize_; // variable packaged in a class

            public:
                ArraySize(int num):
                    arraySize_(num) {}
                int Size() const
                {
                    return this->arraySize_;
                }
        };

        explicit Array(int size): // solution1: add "explicit" to avoid error
            size_(size)
        {
            this->arr_ = new T[size];
        }
        Array(ArraySize size): // solution2: use proxy class to transmit message
            size_(size.Size())
        {
            this->arr_ = new T[this->size_];
        }
        ~Array()
        {
            delete[] this->arr_;
        }
        T& operator[](int ind)
        {
            if(ind < 0 || ind > this->size_ - 1)
            {
                this->~Array();
                std::cout << "Index Error" << std::endl;
                system("pause");
                exit(-1);
            }
            
            return arr_[ind];
        }
        friend bool operator==(const Array<int>& lhs, const Array<int>& rhs)
        {
            if(lhs.size_ != rhs.size_)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
};

int main()
{
    Rational r1(0.5, 1);
    double db1 = 0.5*r1;
    std::cout << r1 << std::endl; // attention: you didn't overload "<<" operator
    std::cout << r1.AsDouble() << std::endl;
    std::cout << db1 << std::endl;

    //-----
    Array<int> arr1(10);
    Array<int> arr2(10);
    for(int i = 0; i < 10; i++)
    {
        // if(arr1 == arr2[i]) {} // ! error
        // if(arr1[i] == arr2[i]) {}
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}