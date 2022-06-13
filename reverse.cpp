#include<iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
  
  string str1;
cout <<"Enter a string: ";
getline (cin, str1);
  string new_str1;

  for(int n = str1.length()-1; n >= 0; n--){
    new_str1.push_back(str1[n]);
  }
  
  cout<<"Reversed string: "<< new_str1 << endl;
  
   
 
    int n = new_str1.length();
 
    // declaring character array
    char char_array[n + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, new_str1.c_str());
    
    int n1 = str1.length();
 
    // declaring character array
    char char_array1[n + 1];
   strcpy(char_array1, str1.c_str());

    if (strcmp(char_array1, char_array) == 0)
        cout << "\nBoth the input strings are same." << endl;
    else
        cout << "The input strings are not same.";
 
}