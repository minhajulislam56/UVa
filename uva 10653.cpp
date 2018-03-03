#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
int adj[MAX][MAX];
int visited[MAX][MAX];
int gridX[5]={-1,0,1,0};
int gridY[5]={0,-1,0,1};
int row, colm;
void bfs(int src, int src2)
{
    queue <int> q;
    q.push(src);
    q.push(src2);
    visited[src][src2]=1;

    while(!q.empty()){
        int ux=q.front();
        q.pop();
        int uy=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int vx=ux+gridX[i];
            int vy=uy+gridY[i];

            if((vx>=0&&vx<=row) && (vy>=0&&vy<=colm) && adj[vx][vy]==0){
                if(visited[vx][vy]==0){
                    visited[vx][vy]=visited[ux][uy]+1;
                    q.push(vx);
                    q.push(vy);
                }
            }
        }
    }
}
int main()
{

    while(cin>>row>>colm && row!=0 && colm!=0){
        memset(adj,0,sizeof adj);
        memset(visited,0,sizeof visited);
        int test;
        cin>>test;
        while(test--){
            int t1,t2;
            cin>>t1>>t2;
            for(int i=0;i<t2;i++){
                int y;
                cin>>y;
                adj[t1][y]=1;
            }
        }
        int src,src2,des,des2;
        cin>>src>>src2;
        bfs(src,src2);
        cin>>des>>des2;
        cout<<--visited[des][des2]<<endl;
    }

    return 0;
}
