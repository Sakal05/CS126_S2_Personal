#include <iostream>

using namespace std;

void vowel_count (string input)
{
    int vowel = 0;
    int con = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if ((input[i] >= 'a' and input[i] <= 'z') || (input[i] >= 'A' and input[i] <= 'Z') || (input[i] >= '0' and input[i] <= '9'))
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
            {
                vowel++;
                
            }
            else
            {
                con++;
            }
        }
    }
    cout << "Total vowel is: " << vowel << endl;
    cout <<  "Total con is: " << con <<endl;
}





int main()
{
    string word;
    cout << "Enter a sentence: ";
    getline(cin, word);
    vowel_count(word);
    return 0;
}