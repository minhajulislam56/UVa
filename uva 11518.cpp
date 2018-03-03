#include<bits/stdc++.h>
using namespace std;
#define MAX 10009
bool visited[MAX];
int total;
vector <int> tiles[MAX];

void clr()
{
    for(int i=0;i<MAX;i++)
        tiles[i].clear();
}
void dfs(int s)
{
    for(int i=0;i<tiles[s].size();i++){
        int v=tiles[s][i];
        if(!visited[v]){
            visited[v]=true;
            total++;
            dfs(v);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,l;
        cin>>n>>m>>l;
        clr();
        memset(visited, 0, sizeof visited);
        int x,y;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            tiles[x].push_back(y);
        }
        total=0;
        for(int i=0;i<l;i++){
            int z;
            cin>>z;
            if(!visited[z]){
                visited[z]=true;
                total++;
            }
            dfs(z);
        }
        cout<<total<<endl;
    }

    return 0;
}
