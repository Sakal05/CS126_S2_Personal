
#include<iostream>
using namespace std;

int main(){
    
char a[100];
int x,m = 0,p;

cout<<"Enter a sentence"<<endl;
gets(a);

for(x=0;a[x]!='\0';x++)
{
        if(a[x]== ' ')
        {
                   for(p=m;p <= x;p++)
                           cout<<a[p];
                   m = x + 1;//For not writing the space character at the //word's lead.You may do m = x;
        }

cout<<endl; 
}

for(p = m; p <= x;p++)
     cout<<a[p];

return 0;

}
