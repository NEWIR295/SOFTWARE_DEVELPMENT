#include <iostream>
#include <memory>

class Book{
    std::string name;
    public:
    Book(std::string name): name(name){}
    void read (void){
        std::cout << "Book Name: " + name << std::endl;
    }
};

int main(void){
    Book myBook("Newir");
    std::shared_ptr<Book> ptr1 = std::make_shared<Book>(myBook);
    std::cout << "count = " << ptr1.use_count() << std::endl;

    // std::shared_ptr<Book> ptr2 = std::make_shared<Book>(myBook);
    std::shared_ptr<Book> ptr2 = ptr1;
    std::cout << "count = " << ptr2.use_count() << std::endl;
    ptr1.reset();
    std::cout << "count = " << ptr1.use_count() << std::endl;
    Book *ptr = ptr2.get();
    
    // ptr1->read();
    ptr2->read();
    ptr ->read();

    return 0;
}