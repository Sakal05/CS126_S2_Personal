#include <iostream>
#include <math.h>
#include <string>
using namespace std;

double samnang_cubic_root(long double num)
{
    long double result;
    result = pow(num, 1.0 / 3);
    return result;
}


// function for input validation
bool samnang_isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == true)
            return true;

    return false;
}

int main()
{
    long int num;
    string n;
    cout << "Enter a number: ";
    getline(cin, n);

    while (1)
    {
        if (samnang_isNumber(n) == true)
        {
            num = stoi(n); // converting from string to integer
            if (num <0)
            {
                num = 0 - num;
                cout << "Cubic root of " << n << " is " << "-" << samnang_cubic_root(num) << endl;
                exit(0);
            }
            else{
            cout << "Cubic root of " << n << " is " << samnang_cubic_root(num) << endl;
            exit(0);
            }
        }
        else
        {
            cout << "Invalid Input!" << endl;
            cin.clear();
            cin.ignore();
            main();
        }
    }
    return 0;
}