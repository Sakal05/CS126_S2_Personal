#include <iostream>
#include <fstream>
#include <cctype>
#include <ctype.h>

using namespace std;


string caps(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;    
}


int main()
{

    ifstream twister("test_file001.txt");

    int wordcount = 1;
    char c;

    while (!twister.eof())
    {
        twister.get(c);
        if (isspace(c))
        {
            wordcount++;
        }
    }
    twister.close();

    twister.open("test_file001.txt");
    twister.seekg(ios::beg);

    string word[wordcount], x;
    int p = 0;

    while (getline(twister, x))
    {
        int length = x.length();
        int start = 0, end = 0, cut = 0;

        for (int i = 0; i < length; i++)
        {   // keep looping until it hits the condition or keep looping until it's not a character
            if (isspace(x[i]) || i == length - 1) // if it a space or it looped until the last character
            {
                if (x[i-1] == ',' || x[i-1] == '.' || x[i-1]== '?') // the reason why i-1 cuz and comma or period is before a space so it checks that part
                {
                    end = i-1;
                }

                else
                {
                    end = i;
                }

                cut = end - start;
                word[p] = x.substr(start, cut); // substr is just cutting the word, Start means where the starting position is and Cut is how many words to cut
                
                word[p] = caps(word[p]); // making all the words capitalize

                p++;

                start = i + 1; // new starting position is the next letter after the space
            }    
        }    
    }
    
    
    int appearance[wordcount];
    for (int q = 0; q < 100; q++)
    {
        appearance[q] =0;
    }
    int counter;

    for (int i = 0; i < wordcount; i++)
    {
        counter = 0;
        for (int j = 0; j < wordcount; j++)
        {
            if (word[i] == word[j])
            {
                if (i <= j)
                {
                    counter++;
                }

                else
                {
                    break;
                }
            }
        }
        appearance[i] = counter;
    }
    twister.close();    

    cout << "\nThe total number of words are: " << wordcount;
    cout << "\nThe words appeared in the text file are: \n";

    for (int i = 0; i < wordcount-1; i++)
    {
        if (appearance[i] > 0)
        {
            cout << "The word " << "(" << word[i] << ")" << " appeared: " << appearance[i] << " time(s)" << " in the text." <<endl;
        } 
    }

    ofstream write("olo\\test_file.txt",ios::app);
    write.seekp(0, ios::end);

    write << "\nThe total number of words are: " << wordcount;
    write << "\nThe words appeared in the text file are: \n";

    for (int i = 0; i < wordcount; i++)
    {
        if (appearance[i] > 0)
        {
            write << "\nThe word " << "(" << word[i] << ")" << " appeared: " << appearance[i] << " time(s)" << " in the text.";
        }  
    }
    
    write.close();

    return 0;
}