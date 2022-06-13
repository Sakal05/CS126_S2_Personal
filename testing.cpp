#include <iostream>

using namespace std;



int main()
{
    char str[100];
    char input[1];
    int count = 0;
    cin >> str;
    cin.clear();
    cin >> input;
    int x = sizeof(str);
    for (int i = 0; i < x; i++)
    {
        if (str[i] == input[0])
        {
           count++;
        }
    }
    cout << count << endl;
    return 0;
}