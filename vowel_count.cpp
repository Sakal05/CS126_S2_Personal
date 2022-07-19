#include <iostream>

using namespace std;

void count_vowel(string str)
{
    int vowel_count = 0;
    int con_count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        
        if ((str[i] >= 'a' and str[i] <= 'z') || (str[i] >= 'A' and str[i] <= 'Z'))
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            {
                vowel_count++;
            }
            else
            {
                con_count++;
            }
        }
    }

    cout << "number of vowel character are " << vowel_count << endl;
    cout << "number of con character are " << con_count << endl;
}

int main()
{
    char word[20];
    cout << "Enter string: ";
    cin >> word;
    count_vowel(word);

    return 0;
}