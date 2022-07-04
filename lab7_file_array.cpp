#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <array>
#include <algorithm>
#include <iomanip>
using namespace std;

// function to validate string
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

int main()
{

    ifstream wordfile("test_file001.txt"); // read wordfile

    // validating file is opened
    if (!wordfile.is_open())
    {
        cout << "Couldn't open file!" << endl;
        return 0;
    }

    string word = "", arr_word[1000], line, uni_word[1000];

    int i = 0;
    int size = 0;
    int uni_size = 0;

    // extracting string from file by line
    while (getline(wordfile, line))
    {
        // remove symbol from text
        line.erase(remove(line.begin(), line.end(), ','), line.end());
        line.erase(remove(line.begin(), line.end(), '?'), line.end());
        line.erase(remove(line.begin(), line.end(), '.'), line.end());
        
        for (auto x : line)
        {
            // converting all char into lower case
            x = tolower(x);

            // seperate each word by space
            if (isspace(x))
            {
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
            // if (checkNotAlpha(word))
            // {
            //     cout << "Input must be a string" << endl;
            //     exit(0);
            // }
        }
    }
    // extract unique string from array

    string temp = "";
    for (int s = 0; s <= size; s++)
    {
        temp = arr_word[s];
        bool isDuplicate = false;
        int j;
        for (j = 0; j < s; j++)
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

    // print the occurance of each unique string
    int count = 0;
    for (int p = 0; p < uni_size; p++)
    {
        for (int r = 0; r < size + 1; r++)
        {
            if (uni_word[p] == arr_word[r])
            {
                count++;
            }
        }

        cout << setw(15) << left << uni_word[p] << setw(15) << left << "appears" << setw(10) << left << count << "time(s)" << endl;
        count = 0;
    }
    cout << "Total word is: " << size + 1 << endl;
    wordfile.close();

    ofstream writefile("text_file001.txt", ios::app);
    int file_count = 0;
    for (int p = 0; p < uni_size; p++)
    {
        for (int r = 0; r < size + 1; r++)
        {
            if (uni_word[p] == arr_word[r])
            {
                file_count++;
            }
        }

        writefile << setw(15) << left << uni_word[p] << setw(15) << left << "appears" << setw(10) << left << file_count << "time(s)" << endl;
        file_count = 0;
    }
    writefile << "Total word is: " << size + 1 << endl;
    writefile.close();

    return 0;
}
