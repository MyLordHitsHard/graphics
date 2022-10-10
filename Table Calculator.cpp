#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,out;
    char ch;
    cout<<("Enter any number: ");
    cin>>a;
    cout<<endl;
    for(int i=1;i<=10;i++)
    {
        out=a*i;
        cout<<a<<"X"<<i<<"="<<out<<endl;
        
    }
    while(ans=='n')
    {
       cout<<("Want to print more? y/n ");
       gets(ch);
        goto for;
    }
    return 0;
}