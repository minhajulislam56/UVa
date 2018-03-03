/*** RUNTIME ERROR ***/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
long long int mark[MAX][MAX];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m;
    while(cin>>n>>m){
        vector<int> adj[MAX];
        memset(mark,-1,sizeof mark);
        while(m--){
            long long int u,v,c;
            cin>>u>>v>>c;
            if(mark[u][v]==-1){
                adj[u].push_back(v);
                adj[v].push_back(u);
                mark[u][v]=mark[v][u]=c;
            }
            else{
                if(c<mark[u][v])
                    mark[u][v]=mark[v][u]=c;
            }
        }

        bool visited[MAX];
        memset(visited,false,sizeof visited);
        int level[MAX];
        memset(level,0,sizeof level);
        int parent[MAX];
        queue<int> qu;
        qu.push(1);
        visited[1]=true;
        parent[1]=-1;
        level[1]=0;
        long long int maxlv=LLONG_MAX;
        vector<int>sadj[MAX];
        int pos=0;
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            if(level[u]>maxlv)
                break;
            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];
                if(v==n){
                    maxlv=level[u];
                    sadj[u].push_back(v);
                    sadj[v].push_back(u);
                    //cout<<u<<" "<<v<<" first"<<endl;
                    int uu=u,vv;
                    while(parent[uu]!=-1){
                        vv=parent[uu];
                        //cout<<uu<<" "<<vv<<endl;
                        sadj[uu].push_back(vv);
                        sadj[vv].push_back(uu);
                        uu=vv;
                    }
                }
                else if(!visited[v]){
                    qu.push(v);
                    visited[v]=true;
                    level[v]=level[u]+1;
                    parent[v]=u;
                }
            }
        }
        qu=queue<int>();
        memset(visited,false,sizeof visited);
        visited[1]=true;
        qu.push(1);
        vector<long long int> ans;
        long long int minn, min2, tnode;
        while(!qu.empty()){
            int u=qu.front();
            qu.pop();
            minn=LLONG_MAX;
            for(int i=0;i<sadj[u].size();i++){
                int v=sadj[u][i];
                if(!visited[v]){
                    minn=min(mark[u][v],minn);
                }
            }
            ans.push_back(minn);
            for(int i=0;i<sadj[u].size();i++){
                int v=sadj[u][i];
                if(!visited[v]){
                    visited[v]=true;
                    if(mark[u][v]==minn){
                        qu.push(v);
                    }
                }
            }
            min2=LLONG_MAX;
            bool chk=false;
            while(!qu.empty()){
                int u=qu.front();
                qu.pop();
                long long int inmin=LLONG_MAX;
                for(int i=0;i<sadj[u].size();i++){
                    int v=sadj[u][i];
                    if(!visited[v]){
                        inmin=min(inmin,mark[u][v]);
                    }
                }
                if(inmin<min2){
                    tnode=u;
                    min2=inmin;
                }
                chk=true;
            }
            if(chk)
                qu.push(tnode);
        }
        cout<<ans.size()-1<<endl<<ans[0];
        for(int i=1;i<ans.size()-1;i++)
            cout<<" "<<ans[i];
        cout<<endl;
    }

    return 0;
}
