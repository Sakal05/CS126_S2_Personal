#include <iostream>
#include <string>

using namespace std;

string reverse_word (string str)
{
    int beg;
 
    
    string rev_str = str;
    int last = rev_str.length()-1;
    for (beg = 0; last>=0; beg++)
    {
        str[beg] = rev_str[last];
        last--;
    }
    return str;
}

int main()
{
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    cout << "The reverse word is " << reverse_word(word) << endl;

    return 0;
}