
// 2020/6/7 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>

class NLComponent
{
    private:
        int mode_;

    public:
        virtual NLComponent* Clone() const = 0;
        virtual std::ostream& Print(std::ostream& os) const = 0;
        // virtualize non-member function
        friend inline std::ostream& operator<<(std::ostream& os, 
                                               const NLComponent& item)
        {
            return item.Print(os);
        }
};

class TextBlock: public NLComponent
{
    private:
        std::string txtStr_;

    public:
        TextBlock(const std::string& str):
            txtStr_(str) {}
        virtual TextBlock* Clone() const // virtualize constructor
        {
            return new TextBlock(*this);
        }
        virtual std::ostream& Print(std::ostream& os) const // virtual function to assist
        {
            os << "TextBlock: " << this->txtStr_ << std::endl;
            return os;
        }

};

class Graphic: public NLComponent
{
    private:
        std::string graStr_;

    public:
        Graphic(const std::string& str):
            graStr_(str) {}
        virtual Graphic* Clone() const // virtual constructor
        {
            return new Graphic(*this);
        }
        virtual std::ostream& Print(std::ostream& os) const // virtual function to assist
        {
            os << "Graphic: " << this->graStr_ << std::endl;
            return os;
        }
};

class NewsLetter
{
    private:
        std::list<NLComponent*> components_;
    
    public:
        NewsLetter(std::vector<std::string> vec) // a simple constructor
        {
            for(int i = 0; i < vec.size(); i++)
            {
                if(vec[i][0] == '0')
                {
                    TextBlock* tmp = new TextBlock(vec[i]);
                    this->components_.push_back(tmp);
                }
                else
                {
                    Graphic* tmp = new Graphic(vec[i]);
                    this->components_.push_back(tmp);
                }
            }
        }
        NewsLetter(const NewsLetter& rhs) // "virtual" copy constructor
        {
            for(std::list<NLComponent*>::const_iterator it = 
                rhs.components_.begin(); 
                it != rhs.components_.end(); 
                it++)
            {
                this->components_.push_back((*it)->Clone()); // call virtual constructor
            }
        }
        ~NewsLetter()
        {
            while(!this->components_.empty())
            {
                NLComponent* tmp = this->components_.front();
                delete tmp;
                this->components_.pop_front();
            }
        }
        void PrintContent() const
        {
            for(std::list<NLComponent*>::const_iterator it = 
                this->components_.begin(); 
                it != this->components_.end(); 
                it++)
            {
                std::cout << *(*it); // virtual print
            }
        }
};

int main()
{
    std::vector<std::string> vec1 = {
        "0a", "0b", "1a", "1b",
    };
    NewsLetter nl1(vec1);
    nl1.PrintContent();
    NewsLetter nl2(nl1);
    nl2.PrintContent();

    system("pause");
    return 0;
}