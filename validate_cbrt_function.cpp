#include <iostream>
#include <cmath>
using namespace std;


double samnang_cuberoot(double num)
{
    double result;
    result = cbrt(num);
    return result;
}

int main()
{
    long double x;
    cout << "Enter number: ";
    cin >> x;
    
    cout << "The root number of " << x << " is " << samnang_cuberoot(x) <<endl;
    return 0;
}
