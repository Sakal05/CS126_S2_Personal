#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <array>
#include <algorithm>
#include <string_view>
using namespace std;

bool checkNotAlpha(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isalpha(str[i]))
        {
            return true;
        }
    }
}
// driver code
int main()
{

    ifstream wordfile("test_file001.txt"); // read wordfile

    if (!wordfile.is_open())
    {
        cout << "Couldn't open file!" << endl;
        return 0;
    }

    string word = "", arr_word[50], line, uni_word[50];
    getline(wordfile, line);

    int i = 0;
    int size = 0;
    // for_each(line.begin(), line.end(), [](char & c)
    // {
    //     c = tolower(c);
    // });
   
    
    for (auto x : line)
    {
         // converting all char into lower case
            x = tolower(x);
        if (x == ' ')
        {
            // cout << word << endl;
    
            arr_word[i] = word;
            i++;
            word = "";
            size++;

        }
        else
        {
         
            word = word + x;
        }
        arr_word[i] = word;

        // validating all input must be string
        if (checkNotAlpha(word))
        {
            cout << "Input must be a string" << endl;
            exit(0);
        }
    }

    // extract unique string from array
    int uni_size = 0;

    string temp = "";
    for (int s = 0; s <= size ; s++)
    {
        temp = arr_word[s];
        bool isDuplicate = false;
        int j;
        for (j = 0; j < s ; j++)
        {
            if (temp == arr_word[j])
            {
                
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
           
            uni_word[uni_size] = temp;
            uni_size++;
           
        }
        
    }

    cout << "This is a list of unique words: ";
    for (auto o : uni_word)
    {
        cout << o << " ";
    }
    cout << endl;

    int count = 0;

    // print the occurance of each unique string

    for (int p = 0; p < uni_size; p++)
    {
        for (int r = 0; r < size + 1; r++)
        {
            if (uni_word[p] == arr_word[r])
            {
                count++;
            }
        }

        cout << uni_word[p] << "\t\tappears\t" << count << endl;
        count = 0;
    }

    wordfile.close();
    return 0;
}
