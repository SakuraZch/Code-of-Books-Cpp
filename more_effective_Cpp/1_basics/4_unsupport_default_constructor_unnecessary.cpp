
// 2020/5/23 //

#include <iostream>
#include <cstdlib>

class EquipmentPiece
{
    private:
        int idNum_;

    public:
        EquipmentPiece(int idNum):
            idNum_(idNum) {}
        ~EquipmentPiece() {}
        friend std::ostream& operator<<(std::ostream& os, const EquipmentPiece& item)
        {
            os << item.idNum_;

            return os;
        }
};

int main()
{
    // EquipmentPiece bestPiece1[10]; // error: class Equipment has not default constructor
    // EquipmentPiece* bestPiece2 = new EquipmentPiece[10]; // error: either

    // solution1: using non-heap array
    int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5;
    EquipmentPiece bestPiece3[] = {
        EquipmentPiece(1),
        EquipmentPiece(2),
        EquipmentPiece(3),
        EquipmentPiece(4),
        EquipmentPiece(5),
    };
    for(int i = 0; i < sizeof(bestPiece3)/sizeof(EquipmentPiece); i++)
    {
        std::cout << bestPiece3[i] << " ";
    }
    std::cout << std::endl;

    //-----
    // solution2: using pointer array
    typedef EquipmentPiece* ptr2EP;
    ptr2EP bestPiece4[5];
    ptr2EP* bestPiece5 = new ptr2EP[5];
    delete bestPiece5;

    // allocate memory earlily
    int len = 5;
    void* rawMemory = operator new[](len*sizeof(EquipmentPiece));
    EquipmentPiece* bestPiece6 = static_cast<EquipmentPiece*>(rawMemory);
    std::cout << sizeof(rawMemory) << " " << sizeof(bestPiece6) << std::endl; // result: 4 4
    for(int i = 0; i < len; i++)
    {
        new(&bestPiece6[i]) EquipmentPiece(i + 10); // asign value
        std::cout << bestPiece6[i] << " "; // print result
    }std::cout << std::endl;

    // recycle memory
    for(int i = len; i >= 0; i--)
    {
        bestPiece6[i].~EquipmentPiece();
    }
    operator delete[](rawMemory);

    system("pause");
    return 0;
}