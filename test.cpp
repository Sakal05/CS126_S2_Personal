#include <iostream>
using namespace std;

// void samnang_wordprocess(string str)
// {

//     int upper = 0;
//     int lower = 0;
//     int digit = 0;
//     int other = 0;
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (isupper(str[i]))
//         {
//             upper++;
//         }
//         else if (islower(str[i]))
//         {
//             lower++;
//         }
//         else if (isdigit(str[i]))
//         {
//             digit++;
//         }
//         else
//         {
//             other++;
//         }
//     }
    
//     cout << "Lowercasee: " << upper << endl;
//     cout << "Uppercase: " << lower << endl;
//     cout << "Digit: " << digit << endl;
//     cout << "Others: " << other << endl;
// }

bool isNumber(string number)
{
    for (int i = 0; i < number.length(); i++)
    {
        if (isdigit(number[i]))
        {
            return true;
        }
        else
        {

            return false;
        }
    }
}

bool isUpperCase(string upper)
{

    for (int i = 0; i < upper.length(); i++)
    {
        if (isupper(upper[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool isLowerCase(string lower)
{

    for (int i = 0; i < lower.length(); i++)
    {
        if (islower(lower[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int samnang_isupper(string str)
{
    int upper = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            upper++;
        }
    }
    return upper;
    cout << upper << endl;
}
int samnang_islower(string str)
{
    int lower = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
        {
            lower++;
        }
    }
    return lower;
    cout << "Lower: " << lower << endl;
}
int samnang_isdigit(string str)
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
    cout << "digit: " << digit << endl;
}

string samnang_reverse(string str){
    char ch;
    int len = str.length();
    for (int i = 0; i < len/2; i++) {
      ch = str[i];
      str[i] = str[len-1-i];
      str[len-1-i] = ch;
   }
    return str;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    //samnang_wordprocess(str);
    
    if (isUpperCase(str) == true)
    {
        cout << "Upper: " << samnang_isupper(str);
    }
    if (isLowerCase(str) == true)
    {
        cout << "Lower: " << samnang_islower(str);
    }
    if (isNumber(str) == true)
    {
        cout << "digit: " << samnang_isdigit(str);
    }
    
    return 0;
}
