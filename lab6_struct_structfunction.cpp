#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


struct student
{
    string lastname, firstname, fullname, major, studentID, birth_day, temp_month, birthdate, s_year;
    int birth_year, age, count;
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
};
void displayData(student); 
student getdata(student p[5]);

student getdata(student p[5])
{
    int count_rep = 0;
    int month_rep, major_rep; // indicating the index for array of the month
    int t_day;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t); // getting local time
    for (int i = 0; i < 1; i++)
    {
        cout << "\nEnter following information" << endl;
        cout << "\nEnter your last name: ";
        cin >> p[i].lastname;
        cout << "Enter your first name: ";
        cin >> p[i].firstname;
        p[i].fullname = p[i].lastname + " " + p[i].firstname;
    enter_datebirth:
        cout << "Enter your date of birth in this format (mm dd yyyy): ";
        cin >> month_rep >> p[i].birth_day >> p[i].birth_year;
        t_day = stoi(p[i].birth_day);
        if (p[i].birth_year > 2022 || p[i].birth_year < 1922)
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
            p[i].temp_month = p[i].month[month_rep - 1]; // matching month input to month in the array
            p[i].s_year = to_string(p[i].birth_year);    // converting the year from int into string
            p[i].birthdate = p[i].birth_day + " " + p[i].temp_month + " " + p[i].s_year;
            p[i].age = (timePtr->tm_year + 1900) - p[i].birth_year; // calculate the age
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
        //count_rep += 1;
        p[i].count = i + 1;
        return p[i];
    }
}

void displayData(student p[2])
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
}

int main()
{

    student p[5], temp[5];
    for (int i = 0; i < 2; i++)
    {
    temp[i] = getdata(p);
    p[i] = temp[i];
    }

    displayData(p);
    
    return 0;
}