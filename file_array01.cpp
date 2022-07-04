#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <array>
using namespace std;

// driver code
int main()
{

    // filestream variable file
    // fstream file;
    // string word, t, filename, q, wordlist[100];

    // // filename of the file
    // filename = "test_file001.txt";

    // // opening file
    // file.open(filename.c_str());

    // // extracting words from the file

    // while (file >> word)
    // {
    //     int i = 0;
    //     // displaying content
    //     cout << word << endl;
    //     word = wordlist[i];
    //     //word = wordlist[i];

    //     // for (i =0; (!file.eof()); i++)
    //     // {
    //     //     word = wordlist[i];
    //     //     cout << wordlist[i] << endl;
    //     // }

    //     // for (i=0; i< 10; i++)
    //     // {
    //     //     word = wordlist[i];
    //     // }
    //     // cout << word << endl;
    //     // for (j=0; j < i; j++)
    //     // {
    //     //     cout << wordlist[j] <<endl;
    //     // }
    // }
    //     for (j=0; j < i; j++)
    //     {
    //         cout << wordlist[j] <<endl;
    //     }

    // ifstream file;
    // file.open("test_file001.txt");
    // string word;
    // char x;
    // word.clear();

    // while (!file.eof())
    // {
    //     i = 0;
    //     x = file.get();

    //     while (x != ' ')
    //     {
    //         word = word + x;
    //         x = file.get();
    //     }
    //     if (strncmp(word, wordlist[i]) == 0)
    //     {
    //         cout << (word);
    //     }
    //     cout << word << endl;
    //     word.clear();
    // }

    // string word = "", arr_word[100];
    // char c[50] = "";
    // char temp[50] = "";
    // int i = 0, j = 0;
    // int word_count = 1;
    // ifstream wordfile("test_file001.txt"); // read wordfile

    // wordfile.seekg(ios::beg);

    // while (!wordfile.eof())
    // {

    //     wordfile.get(c[j]);
    //     temp[j] += c[j];

    //     if (c[j] == ' ')
    //     {

    //         i++;
    //         word = temp[j];
    //         cout << word <<endl;
    //         arr_word[i] = word;
    //         word_count++;

    //     }
    //     wordfile.tellg();
    //     //word = word + c[j];
    //     j++;
    // }
    // wordfile.close();

    // for (int k = 0; k < sizeof(arr_word); k++)
    // {
    //     cout << arr_word[k] << endl;
    // }

    // cout << "Word count: " << word_count <<endl;

    ifstream wordfile("test_file001.txt"); // read wordfile

    if (!wordfile.is_open())
    {
        cout << "Couldn't open file!" << endl;
        return 0;
    }

    string word = "", arr_word[30], line, uni_word[20];
    getline(wordfile, line);

    int i = 0;
    int size = 0;
    for (auto x : line)
    {

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
    }

    // extract unique string from array
    int uni_size = 0;

    string temp;
    for (int s = 0; s < size + 1; s++)
    {
        temp = arr_word[s];
        bool isDuplicate = false;
        int j;
        for (j = 0; j < uni_size; j++)
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

    // for (int y =0; y < uni_size; y++)
    // {
    //     if (uni_word[y] == "")
    //     {
    //         for ( int z = uni_size-y; z<uni_size; z++)
    //         {
    //             if (uni_word[z] == "")
    //             {
    //                 uni_word[z+1] = uni_word[y];
    //             }
    //         }
    //     }
    // }
    for (auto o : uni_word)
    {
        cout << o << " ";
    }
    cout << endl;
    // for (int u = 0; u<size+1; u++)
    // {
    //     cout << uni_word[u] << "\t";
    // }
    int count = 0;
    // int arr_size = sizeof(uni_word)/sizeof(uni_word[0]);

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