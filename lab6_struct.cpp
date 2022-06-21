#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;



typedef struct personal_info
{
    string lastname, firstname, fullname;
    int b_y; // getting the year from user
    int age; // for age result calculation
    string studentID, b_d, year;
    int count;
    string major;   // for storing major
    string T_month; // storing month
    string birthdate;
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
} info;     //nickname for struct personal_info

int main()
{
    info p[5];  //declare variable for struct
    //system("clear");
    int count_rep = 0;
    int month_rep, major_rep; // indicating the index for array of the month

    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // getting local time

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter following information" <<endl;
        cout << "\nEnter your first name: ";
        cin >> p[i].firstname;
        cout << "Enter your last name: ";
        cin >> p[i].lastname;
        for (int j=0; j<sizeof(p[i].lastname); j++){
            p[i].lastname[j] = toupper(p[i].lastname[j]);
        }
        
        p[i].fullname = p[i].firstname + " " + p[i].lastname;
    enter_month:
        cout << "Enter your date of birth in this format (mm dd yyyy): ";
        cin >> month_rep >> p[i].b_d >> p[i].b_y;
        if (p[i].b_y > 2022 || p[i].b_y < 1022)
        {
            cout << "\nWrong Format or Invalid date of birth. Please Enter again!!\n"
                 << endl;
            goto enter_month;
        }
        else if (month_rep > 12 || month_rep < 1)
        {
            cout << "\nWrong Format or Invalid date of birth. Please Enter again!!\n"
                 << endl;
            goto enter_month;
        }
        else
        {
            p[i].T_month = p[i].month[month_rep - 1]; // matching month input to month in the array
            p[i].year = to_string(p[i].b_y);          // converting the year from int into string
            p[i].birthdate = p[i].b_d + " " + p[i].T_month + " " + p[i].year;
            p[i].age = (timePtr->tm_year + 1900) - p[i].b_y; // calculate the age
        }
        cout << "Enter your studentID: ";
        cin >> p[i].studentID;

    backmajor:
        cout << "Major " << endl;
        cout << "\t[1]. CS" << endl;
        cout << "\t[2]. MIS" << endl;
        cout << "\t[3]. BUS" << endl;
        cout << "\t[4]. CE" << endl;

        cout << "Enter your major: ";
        cin >> major_rep;
        if (major_rep > 4)
        {
            goto backmajor;
        }
        else
        {

            switch (major_rep)
            {
            case 1:
                p[i].major = "CS";
                break;
            case 2:
                p[i].major = "MIS";
                break;
            case 3:
                p[i].major = "BUS";
                break;
            case 4:
                p[i].major = "CE";
                break;
            default:
                // p[i].major = "Invalid";
                break;
            }
        }
        count_rep += 1;
        p[i].count = count_rep;
    }
    system("clear");
    cout << "\n\t\t\t\t======= List of information =======" << endl;
    cout << setw(9)
         << left
         << "\nNo"
         << setw(25)
         << left
         << "Name"
         << setw(24)
         << left
         << "Birth-date"
         << setw(12)
         << left
         << "AGE"
         << setw(13)
         << left
         << "Student ID"
         << "Major" << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << setw(8)
             << left
             << p[j].count
             //  << setw(8)
             //  << left
             << setw(25)
             << left
             << p[j].fullname
             << setw(24)
             << left
             << p[j].birthdate
             //<< p[j].b_d << " " << p[j].T_month << " " << p[j].b_y
             << setw(12)
             << left
             << p[j].age
             << setw(13)
             << left
             << p[j].studentID
             << setw(13)
             << left
             << p[j].major
             << endl;
    }
    return 0;
}
