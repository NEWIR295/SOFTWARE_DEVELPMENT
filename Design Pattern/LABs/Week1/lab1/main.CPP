#include <iostream>
#include <memory>

class  OS{

public:
    virtual void drawTheme() = 0;
};

class Linux: public OS{
    public:
    void drawTheme() override{
        std::cout << "Linux Draw" << std::endl;
    }
};

class Windows: OS{
    public:
    void drawTheme() override{
        std::cout << "Windows Draw" << std::endl;
    }
};

class Theme{
    public:
        std::shared_ptr<OS> os;
        Theme(std::shared_ptr<OS> os) : os(os){}
        virtual void  
};