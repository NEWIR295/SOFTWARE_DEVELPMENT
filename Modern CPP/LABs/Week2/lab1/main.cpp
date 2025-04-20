#include <iostream>

template <typename T>
class SmartPtr
{

private:
public:
    T *ptr;

    SmartPtr() : ptr(nullptr)  {

    }
    SmartPtr(T& val){
        ptr = new T(val);
    }
    ~SmartPtr()
    {
        if(ptr != nullptr){
            delete ptr;
            ptr = nullptr;
        }
    }

    SmartPtr(const SmartPtr &other)
    {
        this->ptr = new T(*(other.ptr));
    }

    SmartPtr &operator=(const SmartPtr &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete ptr;
        ptr = new T;
        *ptr = *other.ptr;
        return *this;
    }

    SmartPtr(SmartPtr &&other) noexcept
    {
        this->ptr = other.ptr;
        other.ptr = nullptr;
    }

    SmartPtr &operator=( SmartPtr &&other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        delete ptr;
        ptr = other.ptr; // مفيش نيو عشان بشاور علي نفس المكان
        other.ptr = nullptr;
        return *this;
    }
};


int main(void){

    int x =5 ;
    SmartPtr<int> s1(x);
    std::cout << *s1.ptr << std::endl;
    SmartPtr<int> s2 = s1;
    std::cout << *s2.ptr << std::endl;

    SmartPtr<int> s3 = std::move(s1);
    std::cout << *s3.ptr << std::endl;
    std::cout << s1.ptr << std::endl;


    s3 = std::move(s2);
    std::cout << *s3.ptr << std::endl;
    std::cout << s2.ptr << std::endl;

    return 0;
}