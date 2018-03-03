#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int prime(int n)
{
    int i,flag=0;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

 if(flag==0){
    return 1;
 }
 else
    return 0;
}

int main()
{
    int i,n,x,y, flag;

    while(scanf("%d", &n)==1)
    {
        if(n==0)
            break;
        flag=0;
        for(i=3;i<=n;i++)
        {
            x=prime(i);
            y=prime(n-i);

            if(x==1 && y==1){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<n<<" "<<"= "<<i<<" + "<<n-i<<endl;
        }
        else
            cout<<"Goldbach's conjecture is wrong."<<endl;
    }
    return 0;
}
