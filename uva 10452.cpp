#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        char st[10][10];
        int m,n;
        cin>>m>>n;
        for(int i=-1;i<=m+1;i++)
            for(int j=-1;j<=n+1;j++)
                st[i][j]='%';
        for(int i=0;i<m;i++)
            scanf("%s",&st[i]);

        int x,y,l=0;
        char s[]="IEHOVA";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(st[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        while(1){
            if(st[x-1][y]=='#' && l>5){
                cout<<"forth"<<endl;
                break;
            }
            else if(st[x][y-1]=='#' && l>5){
                cout<<"left"<<endl;
                break;
            }
            else if(st[x][y+1]=='#' && l>5){
                cout<<"right"<<endl;
                break;
            }
            else if(st[x-1][y]==s[l]){
                cout<<"forth"<<" ";
                x=x-1;
            }
            else if(st[x][y-1]==s[l]){
                cout<<"left"<<" ";
                y=y-1;
            }
            else if(st[x][y+1]==s[l]){
                cout<<"right"<<" ";
                y=y+1;
            }
            l++;
        }

    }

    return 0;
}

