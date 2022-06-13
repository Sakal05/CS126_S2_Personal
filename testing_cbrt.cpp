#include <iostream>
#include <math.h>
using namespace std;
 
// This is the function to return the absolute value of n-mid*mid*mid
double samnang_diff(double n,double mid)
{
    if (n > (mid*mid*mid))
        return (n-(mid*mid*mid));
    else
        return ((mid*mid*mid) - n);
}
 
// cubic root function to returns cube root of n
double samnang_cubicRoot(double n)
{
    double start = 0, end = n;
    // Set precision
    double e = 0.0000001;
 
    while (true)
    {
        double mid = (start + end)/2;
        double error = samnang_diff(n, mid);
 
        // If error is less than e then mid is
        // our answer so return mid
        if (error <= e)
            return mid;
 
        // If mid*mid*mid is greater than n set
        // end = mid
        if ((mid*mid*mid) > n)
            end = mid;
 
        // If mid*mid*mid is less than n set
        // start = mid
        else
            start = mid;
    }
}
 
// double converting(double num)
// {
//     double result;
//     result = pow(num, 1/3);
//     return result;
// }

int main()
{
    long double n;
    cout << "Enter a number: ";
    cin >> n;
    //cout << "Cubic root of " << n << " is " << converting(n) << endl;
    cout << "Cubic root of " << n << " is " << samnang_cubicRoot(n) << endl;
    return 0;
}