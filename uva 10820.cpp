#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define LL long long
LL phi(int n)
{
    LL res=n;
    for(int i=2;i*i<=n;i++){
        if(gcd(i,n)!=1){
            while(n%i==0)
                n=n/i;
            res=res-res/i;
        }
    }
    if(n>1)
        res=res-(res/n);
    return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    LL sum[60009];
    sum[1]=1;
    for(int i=2;i<60007;i++){
        sum[i]=sum[i-1]+phi(i);
    }
    while(cin>>n && n!=0){
        cout<<sum[n]*2-1<<endl;
    }

    return 0;
}
