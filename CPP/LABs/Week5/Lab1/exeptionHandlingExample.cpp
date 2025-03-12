#include <iostream>

class DivideByZero : public std::exception {
    private:
        std::string message;
    public:
        DivideByZero(){}
        DivideByZero(const std::string &message): message(message){

        }
        const char *what() const noexcept  override{
            return message.c_str();
        }

};

double divide (double x , double y){
    if (y == 0){
        throw DivideByZero("Error: divide by zero");
    }
    return x/y;
    
}

int main (void){
    try
    {
        /* code */
        double div = divide (1,0);
        std::cout << "division process = " << div <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}