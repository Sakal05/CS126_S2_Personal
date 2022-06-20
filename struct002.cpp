#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define MAXX 3
struct student
{
    string name;
    int stuid;
    char courses[4][20] = {"CS126", "ECON201", "KHM102", "MATH241"};
    double grade[4];
    double gen_average[MAXX];
} students[MAXX];
int main()
{
    int course_index;
    double sum;
    cout << "Please enter student's name and their grade for the ff courses " << endl;
    for (int i = 0; i < MAXX; i++)
    {
        cout << "Student's name : ";
        getline(cin, students[i].name);
        course_index = sum = 0;
        while (course_index < 4)
        {
            cout << "\t" << students[i].courses[course_index] << ": ";
            cin >> students[i].grade[course_index];
            sum = sum + students[i].grade[course_index];
            course_index++;
        }
        students[i].gen_average[i] = sum / 4;
        cin.ignore();
    }
    for (int i = 0; i < MAXX; i++)
    {
        cout << "the general average of " << students[i].name << " is : " << students[i].gen_average[i] << endl;
    }
    return 0;
}