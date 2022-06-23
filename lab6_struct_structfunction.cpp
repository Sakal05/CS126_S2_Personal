#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

struct student
{
    string lastname, firstname, fullname, major, studentID, birth_day, temp_month, birthdate, s_year;
    int birth_year, age, count = 0;
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
} p[5];
void displayData(student);
student getdata(student p);

student getdata(student p)
{

    int count_rep = 0;
    int month_rep, major_rep; // indicating the index for array of the month
    int t_day;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // getting local time
    //  for (int i = 0; i < 2; i++)
    //  {
    cout << "\nEnter following information" << endl;
    cout << "\nEnter your last name: ";
    cin >> p.lastname;
    cout << "Enter your first name: ";
    cin >> p.firstname;
    p.fullname = p.lastname + " " + p.firstname;
enter_datebirth:
    cout << "Enter your date of birth in this format (mm dd yyyy): ";
    cin >> month_rep >> p.birth_day >> p.birth_year;
    t_day = stoi(p.birth_day);
    if (p.birth_year > 2022 || p.birth_year < 1922)
    {
        cout << "\nWrong Format or Invalid date of birth. Please Enter again!!\n"
             << endl;
        goto enter_datebirth;
    }
    else if (month_rep > 12 || month_rep < 1)
    {
        cout << "\nWrong Format or Invalid date of birth. Please Enter again!!\n"
             << endl;
        goto enter_datebirth;
    }
    else if (t_day > 31 || t_day < 1)
    {
        cout << "\nWrong Format or Invalid date of birth. Please Enter again!!\n"
             << endl;
        goto enter_datebirth;
    }
    else
    {
        p.temp_month = p.month[month_rep - 1]; // matching month input to month in the array
        p.s_year = to_string(p.birth_year);    // converting the year from int into string
        p.birthdate = p.birth_day + " " + p.temp_month + " " + p.s_year;
        p.age = (timePtr->tm_year + 1900) - p.birth_year; // calculate the age
    }
    cout << "Enter your studentID: ";
    cin >> p.studentID;

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
            p.major = "CS";
            break;
        case 2:
            p.major = "MIS";
            break;
        case 3:
            p.major = "BUS";
            break;
        case 4:
            p.major = "CE";
            break;
        default:
            // p[i].major = "Invalid";
            break;
        }
    }
    // count_rep += 1;

    return p;
    // continue;
    // }
}

void displayData(student p[5])
{
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
    for (int j = 0; j < 5; j++)
    {
        // cout << p[j].count << "\t" << p[j].lastname << " " << p[j].firstname << "\t\t\t" << p[j].b_d << " " << p[j].T_month << " " << p[j].b_y << "\t\t\t" << p[j].age << "\t\t\t" << p[j].studentID << "\t\t\t" << p[j].major << endl;

        cout << setw(8)
             << left
             << j + 1
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
}

int main()
{

    student p[5], temp[5];
    system("clear");
    for (int i = 0; i < 5; i++)
    {
        temp[i] = getdata(p[i]);
        p[i] = temp[i];
    }

    system("clear");
    displayData(p);

    return 0;
}