#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> num;
    int count =0;
    for (int i = 0; i <10; i++)
    {
        num.push_back(i+1);
        count++;
    }

    for (auto x : num)
    {
        cout << x << " ";

    }
    cout << endl;
    
    cout << "The size of vector is: " << count <<endl;

    cout << "vector after pop off: ";
    for (auto o : num)
    {
        num.pop_back();
    }
    for (auto p : num)
    {
        cout << p << " ";

    }
    cout << endl;
    return 0;
}

