#include <iostream>

#include <cstring>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    string str1, str2; 
    string str1_reverse[100];
    cout << "\nEnter a string: ";
    getline(cin, str1);
    //cout << str1 <<endl;
    // convert the str1 into reverse order
    str1_reverse = reverse(begin(str1), end(str1));
    
    cout<<"\nReverse order: "<< str1;
    cout <<endl;
    
    if (strcmp(str1, str2) == 0)
    {
        cout << "This is the same order" <<endl;
    }
    else 
    {
        cout << "This is not the same order" <<endl;
    }
    return 0;
}