#include<bits/stdc++.h>
using namespace std;
#define MAX 30
int visited[MAX];
vector <int> adj[MAX];

void bfs(int source)
{
    queue <int> q;
    q.push(source);
    visited[source]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            int y=adj[x][i];
            if(visited[y]==0){
                visited[y]=visited[x]+1;
                q.push(y);
            }
        }
    }
}

int main()
{
    int elements;
    int board=1,casee=1;
    while(scanf("%d",&elements)!=EOF){
        for(int i=0;i<elements;i++){
            int x;
            scanf("%d",&x);
            adj[x].push_back(board);
            adj[board].push_back(x);
        }
        if(board==19){
            int query;
            scanf("%d",&query);
            printf("Test Set #%d\n",casee++);
            for(int i=0;i<query;i++){
                int src,des;
                memset(visited,0,sizeof visited);
                scanf("%d%d",&src,&des);
                bfs(src);
                printf("%2d to %2d: %d\n",src,des,abs(visited[des]-visited[src]));
            }
            printf("\n");
            for(int i=0;i<MAX;i++)
                adj[i].clear();

            board=0;
        }
        board++;
    }

    return 0;
}
