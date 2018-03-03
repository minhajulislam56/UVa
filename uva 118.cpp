#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int n,m,chk[110][110];
    char d;
    cin>>n>>m;
    int x,y;
    while(cin>>x>>y>>d){
        char cmd[110];
        bool flag=false;
        cin>>cmd;
        for(int i=0;cmd[i];i++){
            if(cmd[i]=='F'){
                (d=='E')?x++:(d=='W')?x--:(d=='N')?y++:y--;
            }
            else if(cmd[i]=='L'){
                (d=='E')?d='N':(d=='N')?d='W':(d=='W')?d='S':d='E';
            }
            else
                (d=='E')?d='S':(d=='S')?d='W':(d=='W')?d='N':d='E';

            if(x<0 || y<0 || x>n || y>m){
                (d=='E')?x--:(d=='W')?x++:(d=='N')?y--:y++;
                if(chk[x][y]==1)
                    continue;
                chk[x][y]=1;
                flag=true;
                break;
            }
        }

        if(flag)
             cout<<x<<" "<<y<<" "<<d<<" LOST"<<endl;
        else
            cout<<x<<" "<<y<<" "<<d<<endl;
    }

    return 0;
}
