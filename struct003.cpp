#include <iostream>
#include <ctime>
using namespace std;

struct personal_info
{
    string lastname, firstname;
    int b_y; // getting the year from user
    int age; // for age result calculation
    string studentID, b_d;
    int count;
    string major;   // for storing major
    string T_month; // storing month
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
} p[5];

int main()
{
    int count_rep = 0;
    int month_rep, major_rep; // indicating the index for array of the month

    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // getting local time
    for (int i = 0; i < 5; i++)
    {

        cout << "\nEnter your last name: ";
        cin >> p[i].lastname;
        cout << "Enter your first name: ";
        cin >> p[i].firstname;
        cout << "Enter your date of birth in this format (mm dd yyyy): ";
        cin >> month_rep >> p[i].b_d >> p[i].b_y;
        p[i].T_month = p[i].month[month_rep - 1];
        p[i].age = (timePtr->tm_year + 1900) - p[i].b_y; // calculate the age
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
    cout << "\n\t\t\t\t\t\t======= List of information =======" << endl;
    cout << "\nNo"
         << "\tName"
         << "\t\t\t\tBrith-date"
         << "\t\t\t\tAGE"
         << "\t\t\tStudent ID"
         << "\t\tMajor" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << p[j].count << "\t" << p[j].lastname << " " << p[j].firstname << "\t\t\t" << p[j].b_d << " " << p[j].T_month << " " << p[j].b_y << "\t\t\t" << p[j].age << "\t\t\t" << p[j].studentID << "\t\t\t" << p[j].major << endl;
    }
    return 0;
}
