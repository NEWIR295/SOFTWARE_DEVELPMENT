
#include <iostream>
#include <tuple>

int square(int x)
{
    return x * x;
}

std::tuple<bool, int> check(int x)
{
    std::tuple<bool, int> t;
    
    if (x % 2 == 0)
    {
        t = {true, square(x)};
    }
    else
    {
        t = {false, x};
    }
    return t;
}

int main(void)
{

    auto val = 10;
    auto [checkV, value] = check(val);
    if (checkV == true)
    {
        std::cout << val << " is even and X^2 = " << value << std::endl;
    }
    else
    {
        std::cout << value << " is odd\n";
    }
}
