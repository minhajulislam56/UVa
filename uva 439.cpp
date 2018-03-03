#include<bits/stdc++.h>
using namespace std;
int s,t;
int xx[]={1,2,-1,-2,-2,-1,2,1};
int yy[]={2,1,2,1,-1,-2,-1,-2};
bool visited[15][15];
int dis[15][15];
int main()
{
    string s1,s2;

    while(cin>>s1>>s2){

        int x=s1[0]-'a'+1;
        int y=s1[1]-'0';

        s=s2[0]-'a'+1;
        t=s2[1]-'0';

        queue<pair<int,int> > pairq;
        pair<int,int> pii;
        memset(visited,false,15*15*sizeof visited[0][0]);
        memset(dis,0,15*15*sizeof dis[0][0]);
        visited[x][y]=true;
        dis[x][y]=0;
        pairq.push(make_pair(x,y));
        while(!pairq.empty()){
            pii=pairq.front();
            pairq.pop();

            if(pii.first==s && pii.second==t){
                cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dis[s][t]<<" knight moves."<<endl;
                break;
            }
            for(int i=0;i<8;i++){
                int p=pii.first+xx[i];
                int q=pii.second+yy[i];
                if(!visited[p][q] && p>=1 && p<=8 && q>=1 && q<=8){
                    visited[p][q]=true;
                    dis[p][q]=dis[pii.first][pii.second]+1;
                    pairq.push(make_pair(p,q));
                }
            }
        }
    }

    return 0;
}
