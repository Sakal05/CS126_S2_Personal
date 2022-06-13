#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[100] = {'W', 'o', 'r', 'l', 'd', '\0'};
    char str3[100] = "";

    int len;
    strcpy(str3, str1);   //str3 is the destination, str1 is the source, str3 is being copied from str1
    //strcmpi() compare without case sensitivity
    cout << "str3: " << str3 << endl;

    strcat(str1, str2);
    cout << "str1 + str2: " << str3 << endl;

    len = strlen(str1);
    cout << "The length of str3 is: " <<len <<endl;

    // string sentence;

    // cout << "What is ur favorite subject?" <<endl;
    // getline(cin, sentence);

    // cout << "If you " << sentence << "  Bye bye!!" <<endl;
    //char reverse[100] = strrev(str3);
    char greeting[5] = {'D', 'o', 'o', 'r', '\0'};
    cout << greeting <<endl;

    char test1[100] = "Hello";
    char test2[100] = "hello";

    if (strcmp(test1, test2) == 0)
    {
        cout << "they are the same" <<endl;
    }
    if (strcmp(test1, test2) > 0)
    {
        cout << "test1 is greater than test2" <<endl;
    }
    else 
    {
        cout << "test2 is greater than test1" <<endl;
    }
}