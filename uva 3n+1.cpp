#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n,i,j,count,count_test,temp;

    while(scanf("%d%d", &m, &n)==2){
    count=0;
    cout<<m<<" "<<n<<" ";
    if(m>n)
    {
        temp=m;
        m=n;
        n=temp;
    }

    for(i=m;i<=n;i++)
    {
        count_test=1;
        j=i;
        while(j!=1)
        {
            if(j%2==0)
                j=j/2;
            else
                j=j*3+1;
            count_test++;
        }
        if(count_test>=count)
            count=count_test;
    }
        cout<<count<<endl;
    }
    return 0;
}
