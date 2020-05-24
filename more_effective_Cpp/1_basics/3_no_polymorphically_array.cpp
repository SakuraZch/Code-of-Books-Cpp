
// 2020/5/23 //

#include <iostream>
#include <cstdlib>

class BST 
{
    private:
        char ch_;

    public:
        BST(char ch):
            ch_(ch) {}
        friend std::ostream& operator<<(std::ostream& os, const BST& item)
        {
            os << item.ch_;

            return os;
        }
};

class BalancedBST: public BST
{
    private:
        int num_;

    public:
        BalancedBST(char ch, int num):
            BST(ch), num_(num) {}
        friend std::ostream& operator<<(std::ostream& os, const BalancedBST& item)
        {
            operator<<(os, static_cast<BST>(item));
            os << " " << item.num_;

            return os;
        }
};

void PrintBSTArray(const BST array[], int len)
{
    for(int i = 0; i < len; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // test of two class
    // std::cout << sizeof(BST) << " " << sizeof(BalancedBST) << std::endl;
    // std::cout << BST('1') << std::endl;
    // std::cout << BalancedBST('1', 2) << std::endl;

    BST arrBST1[] = {
        BST('1'),
        BST('2'),
        BST('3'),
        BST('4'),
        BST('5'),
        BST('6'),
        BST('7'),
        BST('8'),
        BST('9'),
        BST('0'),
    };

    BalancedBST arrBalancedBST1[] = {
        BalancedBST('1', 1),
        BalancedBST('2', 2),
        BalancedBST('3', 3),
    };

    PrintBSTArray(arrBST1, sizeof(arrBST1)/sizeof(BST)); // correct
    PrintBSTArray(arrBalancedBST1, sizeof(arrBalancedBST1)/sizeof(BalancedBST)); // ! error

    // another situation: using "delete[]" to deconstruct array

    system("pause");
    return 0;
}