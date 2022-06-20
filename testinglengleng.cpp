#include <iostream>
#include <iomanip>

// #include <windows.h>
// #include <conio.h>
using namespace std;
void SetLocation(int x, int y){
	COORD CRD;
	CRD.X=x;
	CRD.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}
struct student{
    string Fname;
    string Lname;
    string month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int Y_month;
    int day;
    int year;
    int age;
    long int studentid;
    string major[3]={"CS", "MIS", "BUS"};
    int Y_major;
};
int main(){
	int n;
	cout << "Enter Number of Students you want to entered : "; cin >> n;
    struct student std[n];
    for (int i=0; i<n; i++){
        cout << "---------------------------" << endl;
        cout << "Student #" << i+1 << endl;
        cout << "Lastname : "; cin >> std[i].Lname;
        cout << "Firstname : "; cin >> std[i].Fname;
        cout << "Birthmonth : "; cin >> std[i].Y_month;
        cout << "Birthday : "; cin >> std[i].day;
        cout << "Birthyear : "; cin >> std[i].year;
        cout << "Student ID : "; cin >> std[i].studentid;
        
        cout << "-> 1. CS" << endl;
        cout << "-> 2. MIS" << endl;
        cout << "-> 3. BUS" << endl;
        cout << "Major : "; cin >> std[i].Y_major;
        
        for (int j=0; j<sizeof(std[i].Lname); j++){
            std[i].Lname[j] = toupper(std[i].Lname[j]);
        }
    }
	cout << "---------------------------" << endl;
    for (int i=0; i<n; i++){
        if (std[i].Y_month <= 6){
            if (std[i].day <= 15){
                std[i].age = 2022 - std[i].year;
            }
            else {
                std[i].age = 2022 - std[i].year - 1;
            }
        }
        else {
            std[i].age = 2022 - std[i].year - 1;
        }
    }
    cout << "Press any key to view the info" << endl;
    //getch();
    system("read");
    int y=1;
    SetLocation(1,y); cout << "No";
    SetLocation(10,y); cout << "Name";
    SetLocation(30,y); cout << "Birthdate";
    SetLocation(50,y); cout << "Age";
    SetLocation(60,y); cout << "Major";
    for (int i=0; i<n; i++){
        y++;
        SetLocation(1,y); cout << i+1;
        SetLocation(10,y); cout << std[i].Fname << " " << std[i].Lname;
        SetLocation(30,y); cout << std[i].month[std[i].Y_month-1] << " " << std[i].day << "," << std[i].year;
        SetLocation(50,y); cout << std[i].age;
        SetLocation(60,y); cout << std[i].major[std[i].Y_major-1];
    }
    return 0;
}