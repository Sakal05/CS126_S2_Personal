#include <iostream>
#include <ctype.h>

using namespace std;

bool Upper_validate (char word)
{
    if (isupper(word))
    {
        return true;
    }
    else {
        return false;
    }
}

int isupper_count (char Uword[10])
{
    int up_count = 0;
    int low_count =0;
    for (int i = 0; Uword[i]; i++)
    {
        if (Uword[i] >= 'A' && Uword[i] <= 'Z')
        {
            up_count++;
        }
    }
    return up_count;
}
int islower_count (char Lword[10])
{
    int low_count =0;
    for (int i = 0; Lword[i]; i++)
    {
        if ( Lword[i] >= 'a' && Lword[i] <= 'z')
        {
            low_count++;
        }
    }
    
    return low_count;
}

int main()
{
    char input_word[10];
    cout << "Enter a word: ";
    cin >> input_word;
    
    cout << "Number of upper case are: " << isupper_count(input_word) << endl;
     cout << "Number of lower case are: " << islower_count(input_word) << endl;
}