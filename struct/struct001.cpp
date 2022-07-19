#include <iostream>
using namespace std;

struct laptop
{
    string name;
    int studentID;
    string major;

};

int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    // cout << "\n\nEnter the following data" << endl;
    // cout << "\nEnter the name: ";
    // getline(cin, L.name);
    // cin.clear();
    // cout << "Enter a Student ID: ";
    // cin >> L.studentID;
    // cout << "Major: ";
    // cin >> L.major;
    laptop L = {"Sakal Samnang", 1231212, "CS"};
    cout << "You have entered: " << endl;
    cout << "\tName: " << L.name << endl;
    cout << "\tStudent ID: " << L.studentID << endl;
    cout << "\tMajor: " << L.major << endl;
    // cin.clear();
    // cin.ignore();
    //}

    return 0;
}