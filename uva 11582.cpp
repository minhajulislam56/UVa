#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define ULL unsigned long long
int dp[1000010];
ULL a,b,mod;
int bigMod(ULL a,ULL n,ULL m)
{
    if(n==0) return 1;
    ULL x = bigMod(a,n/2,m);
    ULL ans = (ULL)x * x % m;
    if(n%2==1)   ans = ans*a%m;
    return (int)ans;
}

int main()
{
    //freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>a>>b>>mod;
        dp[0]=0, dp[1]=1%mod;
        int sz=2;
        for(int i=2;i<=mod*mod+10;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
            if(dp[i]==dp[1] && dp[i-1]==dp[0])
                break;
            sz++;
        }
        //cout<<sz<<endl;
        sz-=1;
        cout<<dp[(bigMod(a%sz,b,sz))%sz]<<endl;
    }
    return 0;
}
