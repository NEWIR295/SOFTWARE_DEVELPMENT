#include <iostream>

template<typename...Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;

    std::cout << "Arguments: ";

    /* lw 3ayzoh ypqa fe nfs el satr */
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}


int main() {
    print("Hello", " ", "World", "!");
    print(1, 2, 3, 4, 5);
    print("The answer is", 42);
    return 0;
}