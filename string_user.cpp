#include<string>
#include<iostream>

bool isNumber(char ch) {
    //this function will determine if a character is a number.
    //this allows the function to use an ASCLL value
    if (int i = ch >= '0' && ch <= '9') {
        
        return true;
    } 
    else {
         
        return false;
    } 
} 

bool isUpperCase(char ch) {
    //this function will determine if a character is upper case.
    //this allows the function to use an ASCLL value
    if (int i = ch >= 'A' && ch <= 'Z') {
        
        return true;
    }
    else {
        return false;
        
    }
}

bool isLowerCase(char ch) {
   
    if (int i = ch >= 'a' && ch <= 'z') {
        //If character found is anything from a-z operation will return the condition true.
        return true;
    }//ends the statement
    else {
        return false;
        //else return the condition false
    }//ends the statement

}//ends the function

void processData(char text[], int size) {

    int upperCase = 0;
    int lowerCase = 0;
    int numbers = 0;
    int i;
    text[size];
    for (i = 0; i <= text[size]; i++) {

        if (isNumber(text[i]) == true) {
            numbers++;
        }
        else if (isUpperCase(text[i]) == true) {
            upperCase++;
        }
        else if (isUpperCase(text[i]) == true) {
            lowerCase++;
        }

    }
    std::cout << "Upper " << upperCase << std::endl;
    std::cout << "Lower " << lowerCase <<std::endl;
    std::cout << "Digit " << numbers << std::endl;

}

int main()
{

    std::cout << "Enter a string: ";
    std::string s;
    std::getline(std::cin, s);

    int size = sizeof(s);
    char text[sizeof(s)];


    processData(text, size);

    return 0;
}