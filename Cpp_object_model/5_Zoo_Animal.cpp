
// 2020/4/25 //

#include <iostream>
#include <cstdlib>
#include <string>

class ZooAnimal
{
    private:
        std::string type_; // solution1: included a member object which has a copy constructor

    public:
        ZooAnimal(const std::string& type):
            type_(type) {}
        explicit ZooAnimal(const ZooAnimal& item):
            type_(item.type_) {}
        virtual ~ZooAnimal() {};
        virtual void draw()
        {
            std::cout << this->type_ << std::endl;
        }
};

// solution2: the class derived from a base class which has a copy constructor
// solution3: the class which assigned one or more virtual functions
// solution4: the class derived from one or more virtual base class
class Bear: public ZooAnimal 
{
    private:
        int num_;
        char* cStr_; // bitwise copy

    public:
        Bear(const std::string& type, int num, char* cStr):
            ZooAnimal(type), num_(num), cStr_(cStr) {}
        // Bear(const Bear& item):
        //     ZooAnimal(item), num_(item.num_), cStr_(item.cStr_) {}
        virtual ~Bear() {};
        virtual void draw()
        {
            ZooAnimal::draw();
            std::cout << this->num_ << " " << &this->cStr_ << " " << this->cStr_ << std::endl;
        }
        char* GetCStr()
        {
            return cStr_;
        }
        void RewriteValue(char val, int ind)
        {
            this->cStr_[ind] = val;
        }
};

int main()
{
    ZooAnimal zA1("Snake");
    char str[5] = {'t', 'e', 's', 't'};
    Bear b1("Bear", 1, str);
    zA1.draw();
    b1.draw();

    Bear b2 = b1;
    char* ptr1 = b2.GetCStr();
    b2.RewriteValue('A', 0);
    std::cout << "Address: " << &ptr1 << " Value: " << ptr1 << std::endl;

    b1.draw();
    b2.draw(); // call function "draw()" of class Bear
    ZooAnimal zA2(static_cast<ZooAnimal>(b1));
    zA2.draw();// call function "draw()" of class ZooAnimal

    system("pause");
    return 0;
}