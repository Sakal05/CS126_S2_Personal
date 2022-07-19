#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream myfile;
    myfile.open("myfile.txt", ios::out);
    if (!myfile)
    {
        cout << "Cannot create File...";
    }
    else
    {
        cout << "New file created" << endl;
        myfile << "This is file input output tutorial";

        cout << "Initial File Pointer Position at: " << myfile.tellp() << endl;

        myfile.seekp(-1, ios::cur);

        cout << "After seekp(-1, ios::cur), File Pointer Position at: " << myfile.tellp() << endl;

        myfile.close();
    }
    myfile.open("myfile.txt", ios::in);
    if (!myfile)
    {
        cout << "Cannot open File...No such file";
    }
    else
    {
        char ch;
        myfile.seekg(5, ios::beg);
        cout << "After seekg(5, ios::beg), File Pointer at: " << myfile.tellg() << endl;
        cout << ch << endl;
        cout << endl;

        myfile.seekg(1, ios::cur);
        cout << "After seekg(1, ios::cur), File Pointer at: " << myfile.tellg() << endl;
        cout <<ch <<endl;
        myfile.close();
    }

    return 0;
}