#include<bits/stdc++.h>
using namespace std;
#define MAX 2010
bool notPossible;
int dp[MAX][MAX/2],one,two;
vector<int> dvec, color;
vector<vector<int> > edge;
void dfs(int u)
{
    (color[u]==1)?one++:two++;

    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(color[v]==-1){
            color[v]=1-color[u];
            dfs(v);
        }
        else if(color[u]==color[v]){
            notPossible=true;
            return;
        }
    }
}
bool checking(int in, int total)
{
    if(in>=dvec.size()){
        if(total==0)
            return true;
        else
            return false;
    }
    if(dp[in][total]!=-1)
        return dp[in][total];
    int ret1=0, ret2=0;
    if(total-dvec[in]>=0)
        ret1=checking(in+1,total-dvec[in]);
    else
        ret1=0;

    ret2=checking(in+1,total);

    return dp[in][total]=ret1||ret2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int tc;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>tc;
    while(tc--){
        edge.clear(),dvec.clear(), color.clear();
        int b,c,a;
        cin>>b>>c>>a;
        int n=b+c;
        edge.resize(n+5), color.assign(n+5, -1);
        for(int i=0;i<a;i++){
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int mini=0;
        notPossible=false;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                one=two=0;
                color[i]=1;
                dfs(i);
                if(two>one) swap(one,two);
                mini+=two;
                if(one-two>0) dvec.push_back(one-two);
            }
        }
        if(notPossible || b<mini || c<mini){
            cout<<"no"<<endl;
            continue;
        }
        memset(dp,-1,sizeof dp);
        if(checking(0,min(b,c)-mini))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
