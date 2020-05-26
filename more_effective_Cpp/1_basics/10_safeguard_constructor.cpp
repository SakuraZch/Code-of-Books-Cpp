
// 2020/5/26 //

#include <iostream>
#include <cstdlib>

// a simple auto pointer
template <typename T>
class A_ptr
{
    private:
        T* ptr_;
    
    public:
        A_ptr(T* ptr = nullptr):
            ptr_(ptr) {}
        ~A_ptr()
        {
            delete this->ptr_;
        }
        T& operator*() const
        {
            return *(this->ptr_);
        }
        T* operator->()
        {
            return ptr_;
        }
};

class Image
{
    private:
        std::string imageDataFileName_;
    
    public:
        Image(const std::string& imageDataFileName):
            imageDataFileName_(imageDataFileName) {}
        void PrintImage() const
        {
            std::cout << "Image File Name: " << this->imageDataFileName_ << std::endl;
        }
};

class AudioClip
{
    private:
        std::string audioDataFileName_;
    
    public:
        AudioClip(const std::string& audioDataFileName):
            audioDataFileName_(audioDataFileName) {}
        void PrintAudioClip() const
        {
            std::cout << "Audio Clip File Name: " << this->audioDataFileName_ << std::endl;
        }
};

class BookEntry
{
    private:
        std::string name_;
        std::string addr_;
        const A_ptr<Image> image_;
        const A_ptr<AudioClip> audioClip_;

    public:
        BookEntry(const std::string& name, 
            const std::string& addr, 
            const std::string& imageFileName, 
            const std::string& audioFileName);
        ~BookEntry();
        void PrintBookEntry() const;
};

BookEntry::BookEntry(const std::string& name, 
    const std::string& addr, 
    const std::string& imageFileName, 
    const std::string& audioFileName):
        name_(name), addr_(addr), 
        image_(imageFileName != "" ? new Image(imageFileName) : nullptr), 
        audioClip_(audioFileName != "" ? new AudioClip(audioFileName) : nullptr) {}

BookEntry::~BookEntry() {}

void BookEntry::PrintBookEntry() const
{
    std::cout << "Name: " << this->name_ << std::endl;
    std::cout << "Address: " << this->addr_ << std::endl;
    (*this->image_).PrintImage(); // can not use "->" operator
    (*this->audioClip_).PrintAudioClip();
}

int main()
{
    A_ptr<std::string> test(new std::string("10"));
    std::cout << *test << " " << test->size() << std::endl;

    BookEntry book1("A", "B", "CCC", "DDD");
    book1.PrintBookEntry();

    system("pause");
    return 0;
}