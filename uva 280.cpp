#include<bits/stdc++.h>
using namespace std;
vector <int> adj[110];
bool visited[110];
int cnt;
int dfs(int sc)
{
    int u=sc;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!visited[v]){
            visited[v]=true;
            cnt++;
            //cout<<"count "<<cnt<<endl;
            dfs(v);
        }
    }
    return cnt;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,st,to;
    while(cin>>n && n){
        for(int i=0;i<=110;i++)
            adj[i].clear();

        while(cin>>st && st){
            while(cin>>to && to){
                adj[st].push_back(to);
            }
        }
        int qr, chk;
        cin>>qr;
        for(int i=0;i<qr;i++){
            cin>>chk;
            memset(visited,0,sizeof visited);
            cnt=0;
            cout<<n-dfs(chk);
            for(int j=1;j<=n;j++){
                if(!visited[j])
                    cout<<" "<<j;
            }
            cout<<endl;
        }
    }

    return 0;
}
