#include<bits/stdc++.h>
using namespace std;
#define MAX 1001
int main()
{
    char number[MAX];
    int tc;
    int x[MAX];
    cin>>tc;
    getchar();
    for(int t=1;t<=tc;t++)
    {
        gets(number);
        for(int i=0;i<strlen(number);i++)
        {
            x[i]=number[i]-'0';
        }

    }
    return 0;
}
