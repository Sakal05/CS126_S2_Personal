#include <iostream>
#include <string>

using namespace std;

int samnang_upper(string str)
{
    int uppercase = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            uppercase++;
        }
    }
    return uppercase;
}

int samnang_lower(string str)
{
    int lowercase = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
        {
            lowercase++;
        }
    }
    return lowercase;
}

int samnang_digit(string str)
{
    int digit = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            digit++;
        }
    }
    return digit;
}

int samnang_other(string str)
{
    int upper, lower, digit, other = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            upper++;
        }
        else if (islower(str[i]))
        {
            lower++;
        }
        else if (isdigit(str[i]))
        {
            digit++;
        }
        else
        {
            other++;
        }
    }
    return other;
}

string samnang_reverse(string str)
{
    char ch;
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        ch = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = ch;
    }
    return str;
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    cout << "Lowercase: " << samnang_lower(str) << endl;
    cout << "Uppercase: " << samnang_upper(str) << endl;
    cout << "Digits:    " << samnang_digit(str) << endl;
    cout << "Others:    " << samnang_other(str) << endl;
    cout << "The reverse of the string is: " << samnang_reverse(str) << endl;
    return 0;
}