#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
    long int i,m=0;
    char input[100000];

    while(gets(input))
    {
        for(i=0;i<strlen(input);i++)
        {
            if(input[i]=='"')
            {
                m++;
                if(m%2==1)
                    cout<<"``";
                else
                    cout<<"''";
            }
            else
                cout<<input[i];
        }
        cout<<endl;
    }
    return 0;
}
