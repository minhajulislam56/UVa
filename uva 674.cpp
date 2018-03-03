#include<bits/stdc++.h>
using namespace std;
int coins[]={50,25,10,5,1};
int n;
int dp[6][7489+5];
int making(int i, int amount)
{
    if(i>=5){
        if(amount==0) return true;
        else return false;
    }
    int one,two;
    one=two=0;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    if(amount-coins[i]>=0)
        one=making(i,amount-coins[i]);
    two=making(i+1,amount);
    dp[i][amount]=one+two;
    return dp[i][amount];
}

int main()
{
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    while(cin>>n){
        cout<<making(0,n)<<endl;
    }

    return 0;
}
