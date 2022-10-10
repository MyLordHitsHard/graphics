#include <iostream>
#include<string.h>
using namespace std;

int main() 
{
    int t;
        int match[5];
        int ind=0,eng=0,dra=0;
        for(int i=0;i<5;i++)
        {
            cin>>match[i];
            if(match[i]==0)
            {
                dra++;
            }
            else if(match[i]==1)
            {
                ind++;
            }
            else if(match[i]==2)
            {
                eng++;
            }
        }
        if(ind>eng)
        {
            cout<<"INDIA"<<endl;
        }
        else if(eng>ind)
        {
            cout<<"ENGLAND"<<endl;
        }
        else
        {
            cout<<"DRAW"<<endl;
        }

	return 0;
}
