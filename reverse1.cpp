#include <iostream>
#include<string> 
#include<algorithm>
#include <string.h>

using namespace std;

int main() {
    string input;
    string reverse_input;
    cout << "Enter a string: ";
    getline(cin, input);
    reverse_input = input;
    reverse(reverse_input.begin(), reverse_input.end());
    cout << "The reverse order: " << reverse_input << endl;

    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    reverse_input.erase(remove(reverse_input.begin(), reverse_input.end(), ' '), reverse_input.end());

    if(input == reverse_input) {
        cout << "The order of characters in both strings are the same.";
    }
    else {
        cout << "The order of characters in both strings are not the same.";
    }

    return 0;
}