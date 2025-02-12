#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

    double f_temp;
    double c_temp;
    double k_temp;
    cout << " please enter temperature in fehrenite " << endl;
    cin >> f_temp;
    c_temp = (f_temp - 32) * (static_cast<double>(5.0) / 9);
    k_temp = c_temp + 273.15;
    cout << " Temperature in celcius is " << c_temp << endl;
    if (k_temp >= 373.15)
    {
        cout << " more than boiling " << endl;
    }
    else if (k_temp <= 273.15)
    {
        cout << " below freezing point " << endl;
    }
    else
    {
        cout << " Normal Temperature " << endl;
    }

    return 0;
}
