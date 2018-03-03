#include<bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
int n,cap,cost[1010], weight[1010], dp[1010][35];
int solve(int i, int w)
{
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(i==n+1)
        return 0;
    int profit1,profit2;
    if(w+weight[i]<=cap){
        profit1=cost[i]+solve(i+1,w+weight[i]);
    }
    else
        profit1=0;
    profit2=solve(i+1,w);

    return dp[i][w]=max(profit1,profit2);
}
int main()
{
    int tc;
    si(tc);
    while(tc--){
        si(n);
        for(int i=1;i<=n;i++){
            sii(cost[i],weight[i]);
        }

        int g;
        si(g);
        int sum=0;
        while(g--){
            si(cap);
            memset(dp,-1,sizeof dp);
            sum+=solve(1,0);
        }
        cout<<sum<<endl;
    }

    return 0;
}
